/**********************************************************************
    Java parser and pretty-printer.
 **********************************************************************/

#ifndef PARSER_H
#define PARSER_H

/*
struct half_exp{
	char sign;
	double num;
}*half_exp_t
*/
static double getNum();
static char getAddOp();
static char getMultOp();
//static char getOp();
double geometric();
static void match();
void parse();
double arithmetic();
double NegTail();
double expression();
static void error_rep();



    /* Scan source, identify structure, and print appropriately. */

#endif