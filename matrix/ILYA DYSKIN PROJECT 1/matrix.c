#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "matrix_types.h"
#include "matrix.h"


/* 173 C week 1:
   here you add matrix functionality (e.g. addition, multiplication...
   see mat_test.c ) */

/*Vectors are columns*/



dvec dvector(int n)
{
dvec a;
return  (dvec) malloc(n*sizeof(double));

}

void dvec_free(dvec v)
{
free((char*) v);
}

/* dvec is double-precision vector data, used below for rows. dmat is
double-precision matrix data, the third field of a matrix struct.*/


/* create matrix by allocating r  c-long vectors for the rows,
   a vector of pointers to rows, and a pointer to the latter vector. */

matrix_t mat_new(int r,int c)  /*r rows, c cols*/
{
int i;
dmat m;
matrix_t a;
 m = (dmat) malloc( r*sizeof(double *));
 if (m == NULL) return NULL;
 for (i= 0; i<r; i++)
 {
 m[i] = (dvec) malloc( c*sizeof(double));
 if (m[i] == NULL) return NULL;
 }
 a =(matrix_t) malloc ( sizeof(struct matrix));
 if ( a == NULL) return NULL;
 a->r = r;
 a->c = c;
 a->mat = m;
 a-> fev_type = MATRIX;
 return a;
 }

/*  can't just free the pointer to the matrix, there's no garbage collection */

void mat_free(m)
matrix_t m;
{
int i,r;
r =m->r;
for (i = 0; i<r; i++) free ((char *) m->mat[i]);
free((char *) m->mat);
free((char *) m);
}

/* not much of an error function...*/
 void cberror (char *msg)
 {
         fprintf(stderr, "\n %s \n", msg);
 }


/* print out a matrix in a human-readable form */
enum mat_err_no  mat_pr(char *msg, matrix_t m)
  {
  int i,j;
  int r,c;
  if (msg == NULL) { cberror("null message arg in mat_pr"); return NILARG1;}
  if (m == NULL) { cberror("null matrix arg in mat_pr"); return NILARG2;
}
  r = m->r;
  c = m->c;
  printf("\nMATRIX: %s Type: %d , Dims %d, %d\n", msg,m->fev_type,r,c);
  for (i=0; i<r; i++)
  {
  printf("\n");
  for (j=0; j<c; j++)
  printf("%.3f ",m->mat[i][j]);
  }
  printf("\n");
  return OK;
  }
enum mat_err_no mat_add(matrix_t m1, matrix_t m2, matrix_t m_result, int sign)
{

                            //allows matrix addition, checks for the
                            //errors within the method itself
  int i,j;
  int r,c;

  if(m1==NULL || m2==NULL)
  {
    cberror("null martix argument");
    return NILARG2;
  }
  else if(m1->r != m2->r)
  {
    //int lol = m1->r;
    //int kip = m2->r;
    //printf("ROW %d ROW %d",lol, kip);
    cberror("row mismatch");
    return ROWERROR;
  }
  else if(m1->c != m2->c)
  {
    cberror("colunts aren't equal");
    return COLERROR;
  }
  else if(sign != 1 && sign != -1)
  {
    cberror("sign isn't proper");
    return SIGNERROR;
  }

  c = m2->c;
  r = m2->r;

  for(i=0; i<c; i++)
    for(j=0; j<r; j++)
      m_result->mat[i][j]=m1->mat[i][j]+(sign * m2->mat[i][j]);

  return OK;
}
enum mat_err_no mat_mult(matrix_t m1, matrix_t m2, matrix_t m_result)
{   //basic matrix by matrix multiplication method
  int i,j,k;
  int r,c;
  int sum;
  if(m1==NULL || m2==NULL)
  {
    cberror("null martix argument");
    return NILARG2;
  }
  if(m1->c != m2->r)
  {
    cberror("col1 doesn't equal row2");
    return MULTMISMATCH;
  }
  r = m1->r;
  c = m2->c;
  m_result->r = r;
  m_result->c = c;
  for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    {
      for(k=0; k<m1->c; k++)
        sum = sum + m1->mat[i][k]*m2->mat[k][j];
      m_result->mat[i][j] = sum;
      sum=0;
    }
  return OK;
}
enum mat_err_no mat_trans(matrix_t mat_arg, matrix_t mat_result)
{           //transposes the given matrix into a resultant one
  int i,j;
  int r,c;

  r = mat_result->r;
  c = mat_result->c;

  if(mat_arg==NULL)
  {
    cberror("null martix argument");
    return NILARG2;
  }
  else if(mat_result->r != mat_arg->c || mat_result->c != mat_arg->r)
  {
    cberror("row column mismatch");
    return ROWERROR;
  }

  for(i=0; i<r; i++)
    for(j=0; j<c; j++)
      mat_result->mat[i][j] = mat_arg->mat[j][i];

  return OK;
}
matrix_t mat_frd(char* fname)   //reads a matrix from a given filename
{
  matrix_t m_result;
  int r=0,c=0;
  int i,j;
  FILE *fp;
  fp = fopen(fname, "r");   //opens up a file with a read only flag
  fscanf(fp, "%d %d", &r, &c);

  m_result = mat_new(r,c);
  for(i=0; i<r; i++)
    for(j=0; j<c; j++)
      fscanf(fp, "%lf ", &m_result->mat[i][j]);
  fclose(fp);
  return m_result;
}

