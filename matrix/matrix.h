#ifndef _matrix_h
#define _matrix_h

/***************important matrix macro************/

#define e(m,i,j) m->mat[i][j]


/************ error codes ***********/

enum mat_err_no 
{   /*their values are ints!*/
    OK,   /* that is, zero! */
 	NILARG1,
    NILARG2,
    NILARG3,
    NILARG4,
    SINGULAR,
    NONSQUARE,
    NONCONFORM,
    NONAFFINE,
    ROWERROR,
    COLERROR,
    SIGNERROR,
    MULTMISMATCH
};  /* for use with exit(int n) */



/***************external matrix... incomplete... should add all
                     routines in matrix.c **************/
extern dvec dvector();
extern void dvec_free();
extern enum  mat_err_no mat_mpy();
extern matrix_t mat_new();
extern enum mat_err_no mat_pr();
extern void mat_free();
extern enum mat_err_no mat_add();
extern enum mat_err_no mat_mult();
extern enum mat_err_no mat_trans();
extern matrix_t mat_frd();


/*****************basics ****************/
#define max(x,y) x>y?x:y
#define min(x,y) x>y?y:x
/* #define abs(x) x>0?x:-x */

#define deg_to_rad ( (double) M_PI/180.0)

#define TRUE	-1
#define FALSE	0



/************ codes  for common vector row indices***********/
#define X 0
#define Y 1
#define Z 2
#define W 4



/************for fev field ***********/
#define MATRIX  13   /* arbitrary, used in Week 2*/



#endif
