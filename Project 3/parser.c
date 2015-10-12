#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "reader.h"
#include "scanner.h"
#include "parser.h"

static token_t     tok;
static location_t  loc;



static void parse_error()       //tells if there is a syntax error
{
    fprintf(stderr, "Syntax error");
    fprintf(stderr, " at line %d, column %d\n",
        tok.location.line->line_num, tok.location.column);
    exit(1);
}

static double getNum()      //retrieves a number based on the token provided info
{
    char *holder;
    holder = malloc(tok.length * sizeof(char));
    int j;
    location_t loc = tok.location;
    for(j = 0; j < tok.length; j++)     //puts the chars into a char array one by one
        holder[j] = get_character(&loc);

    printf("Get Num received: %d \n", tok.tc);
    fprintf(stderr, " Toc is at line %d, column %d\n",
        tok.location.line->line_num, tok.location.column);
    fprintf(stderr, " Loc is at line %d, column %d\n",
        loc.line->line_num, loc.column);
    printf("Toc length: %d \n", tok.length);
    printf("Get Num received: %f\n",atof(holder));        //prints out the resultant number
    match(T_LITERAL);
    printf("Get Num now gives out: %d \n", tok.tc);
    while(tok.tc==T_SPACE)
        match(T_SPACE);
    return atof(holder);
}
/*
static char getOp()      //returns the Multiplication Operator sign i.e. either + or -
{
    char holder;
    location_t loc = tok.location;
    holder = get_character(&loc);       //grab a sign using a given token
    //printf("Get Mult Op received: %d \n", tok.tc);
    //printf("Get Mult Op received: %c\n",holder);
    //printf("Toc length: %d \n", tok.length);
    //match(T_MULTOP);
    scan(&loc, &tok);
    //printf("Get Mult Op now gives out: %d \n", tok.tc);
    //printf("Toc length: %d \n", tok.length);
    while(tok.tc==T_SPACE)
        match(T_SPACE);
    return holder;
}
*/

static char getMultOp()      //returns the Multiplication Operator sign i.e. either + or -
{
    char holder;
    location_t loc = tok.location;
    holder = get_character(&loc);       //grab a sign using a given token
    printf("Get Mult Op received: %d \n", tok.tc);
    printf("Get Mult Op received: %c\n",holder);
    printf("Toc length: %d \n", tok.length);
    match(T_MULTOP);
    printf("Get Mult Op now gives out: %d \n", tok.tc);
    printf("Toc length: %d \n", tok.length);
    while(tok.tc==T_SPACE)
        match(T_SPACE);
    return holder;
}

static char getAddOp()      //returns the Addition Operator sign i.e. either + or -
{
    char holder;
    location_t loc = tok.location;
    holder = get_character(&loc);       //grab a sign using a given token
    printf("Get Add Op received: %d \n", tok.tc);
    printf("Get Add Op received: %c\n",holder);
    printf("Toc length: %d \n", tok.length);
    match(T_ADDOP);
    printf("Get Add Op now gives out: %d \n", tok.tc);
    printf("Toc length: %d \n", tok.length);
    while(tok.tc==T_SPACE)
        match(T_SPACE);
    return holder;
}

/********
    Scan source, identify structure, and print appropriately.
 ********/


void parse()
{
    set_to_beginning(&loc);     //sets the caret to the beginning
    FILE *FP;           //declared the file opener pointer
    double result;
    FP = fopen("output.txt", "w");      //initialized the file opener with a write option
    scan(&loc, &tok);       //reads the first character of a line
    fprintf(stderr, " Loc is at line %d, column %d\n",
        loc.line->line_num, loc.column);
    printf("Toc length: %d \n", tok.length);
    while(tok.tc!=T_EOF)
    {
        while(tok.tc==T_SEMIC)
            scan(&loc,&tok);

        result = expression();       //starts the actual parsing process
        printf("The result is...%lf\n", result);    //prints out the result of an equation
        fprintf(FP, "= %lf\n", result); //writes it into a file
        scan(&loc, &tok);  

    }
    printf("End of File\n"); 
}

double expression() //1st level of grammar
{
    printf("Expression\n");
    double result = 0, temp=0;      //some variable declarations/iniatializations
    char sign;
    double variable;
    printf("The token expression has is: %d \n", tok.tc);
    result=arithmetic();        //starts traversing to the left of the tree i.e. reading in the first terminal
    printf("Back in EXP from ARITH. First number is %lf\n", result);        
    while(tok.tc==T_SPACE)
        match(T_SPACE);
    if(tok.tc==T_ADDOP)     //start the arithmetic tail when you find either + or -
    {
        sign=getAddOp();
        //sign=getOp();
        temp=result;    //I just have to do this. C blows when it comes to algebra
        variable=expression();
        printf("Back in EXP from ARITH TAIL\n");
        switch(sign)       //performs a proper arithmetic operation based on the sign
        {
            case '+':
                result=temp+variable;
                break;
            case '-':
                result=temp-variable;
                break;
        }
    }
    printf("About to return full result which is %lf!\n", result);
    return result;      //returns the resultant number obv
}

double arithmetic() //2nd level of grammar
{   
    char sign;
    printf("Arithmetic\n");
    double result = 0, temp = 0;
    printf("The token expression has is: %d \n", tok.tc);
    result = geometric();       //traverses to the left and gives my result variable a value
    double variable=0;
    printf("Back in ARITH from GEO. Result is %lf\n", result);
    printf("The token expression has is: %d \n", tok.tc);

    while(tok.tc==T_SPACE)
    {
        match(T_SPACE);
    }
    if(tok.tc==T_MULTOP)        //start a geometric tail if you see a mult operator i.e. * or /
    {
        sign=getMultOp();
        //sign=getOp();
        temp=result;
        variable=arithmetic();
        printf("Back in ARITH from GEO TAIL\n");
        switch(sign)       //same concept as in the expression
        {
            case '*':
                result=temp*variable;
                break;
            case '/':
                result=temp/variable;
                break;
            case '%':
                result=fmod(temp,variable);
        }
    }
    return result;
}
double geometric()  //3rd level of grammar (and also pretty much the lowest)
{
    double result=0;
    char sign;
    printf("Geometric\n");
    while(tok.tc==T_SPACE)
        match(T_SPACE);

    printf("The token geometric is holding: %d \n", tok.tc);
    switch(tok.tc)
    {

        case T_LPAREN:      //calls a negation tail if it sees a left parenthesis
            result=NegTail();
            printf("Back in GEO from NEG TAIL\n");
            break;
        case T_ADDOP:       //makes the terminal negative if the parser sees a minus sign before it
            sign = getAddOp();
            //sign=getOp();
            if(sign=='-')
            {
                return (0-NegTail());
                printf("Back in GEO from NEG TAIL...The result should be negative\n");
            }
            else if(sign=='+')
            {
                return NegTail();
                printf("Back in GEO from NEG TAIL...The result should be positive\n");
            }
            else
                error_rep();    //I don't allow +number=number notation
            break;
        case T_LITERAL:     //call a negative tail if the parses sees just a number
            result = NegTail();
            printf("Back in GEO from NEG TAIL...the result is %lf\n", result);
            break;
        case T_SEMIC:       //returns zero if the parser sees a semicolon
            result = 0;
            break;
        case T_EOF:         //returns zero if the parses sees an EOF
            result=0;
            break;
    }
    return result;
}
double NegTail()
{
    printf("Negation tail\n");
    double result=0, temp=0, power=0;
    while(tok.tc==T_SPACE)
        match(T_SPACE);

    printf("The token NegTail is holding: %d \n", tok.tc);
    switch(tok.tc)
    {
        case T_EOF:
            return 0;
            break;
        case T_SEMIC:
            return 0;
            break;
        case T_LPAREN:                      //start parsing expression when you hit the left parenthesis
            printf("Left Parenthesis\n");
            match(T_LPAREN);
            fprintf(stderr, " Loc is at line %d, column %d\n",
                loc.line->line_num, loc.column);
            printf("Toc length: %d \n", tok.length);
            result = expression();
            printf("Back to NEG TAIL from EXP\n");
            printf("The token NegTail is holding: %d \n", tok.tc);
            //scan(&loc, &tok);
            //printf("The token NegTail is holding now: %d \n", tok.tc);
            if(tok.tc == T_RPAREN)      //checks if expression ends with a proper parenthesis. If not, syntax error
            {
                printf("Looking for right Parenthesis");
                match(T_RPAREN);
                //scan(&loc, &tok);
                printf("Right Parenthesis");
                switch(tok.tc)       
                {
                    case T_INC:     //add 1 if parser sees an increment after the number
                        result++;
                        match(T_INC);
                        break;
                    case T_DEC:        //subtract 1 after parses sees a decrement after the number
                        result--;
                        match(T_DEC);
                        break;
                    case T_POW:         //LETS RAISE THINGS IN DA POWAH
                    /*Since apparently double pow(double a, double b) was written written well in C,
                        it will return random and incorrect value when tried with large numbers*/
                        printf("I see a power!\n");
                        temp=result;
                        match(T_POW);
                        power=NegTail();
                        printf("About to raise %lf in power of %lf\n",temp, power);
                        result=pow(temp,power);
                        printf("Power result is %lf\n", result);
                        break;
                }
                return result;
            }
            else
                error_rep();
            break;
        case T_LITERAL:     //pull a number off a line if the token id is a literal
            result = getNum();
            printf("result in NegTail is %lf\n", result);
            switch(tok.tc)       
            {
                case T_INC:     //add 1 if parser sees an increment after the number
                    result++;
                    match(T_INC);
                    break;
                case T_DEC:        //subtract 1 after parses sees a decrement after the number
                    result--;
                    match(T_DEC);
                    break;
                case T_POW:         //LETS RAISE THINGS IN DA POWAH
                /*Since apparently double pow(double a, double b) was written written well in C,
                    it will return random and incorrect value when tried with large numbers*/
                    printf("I see a power!\n");
                    temp=result;
                    match(T_POW);
                    power=NegTail();
                    printf("About to raise %lf in power of %lf\n",temp, power);
                    result=pow(temp,power);
                    printf("Power result is %lf\n", result);
                    break;
            }
            break;
    }
    return result;
}
/********
    A token of class tc is expected from the scanner.  Verify and print.
 ********/
static void match(token_class tc)   //checks if the token is correct. jumps forwards afterward
{
    if (tc != tok.tc)
        parse_error();
    scan(&loc, &tok);
}

static void error_rep()
{
    printf("Here's the token code %d\n",tok.tc);
    printf("syntax error\nI am seeing %c\n",get_character(&loc));
    exit(0);
}

