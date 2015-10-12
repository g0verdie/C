/*  Scanner recieves a location of the file where the next
token is. The scanner thus looks at the character at that location
and then follows the following rules:
1. If the next currecter is a white space - ignore - stay in the same state
2. If you see a number - move to a state "number" and 
*/

#include <stdlib.h>
#include <stdio.h>
#include "reader.h"
#include "scanner.h"
#include "char_classes.h"

static void print_location (token_t *tok)
{
    fprintf(stderr, " at line %d, column %d\n",
        tok->location.line->line_num, tok->location.column);
}

void scan (location_t *loc, token_t *tok)
{
	// These are the states: 
	enum {
		// starters 
		start,
		got_space,
		done,
		//number
		got_dot,
		got_digit,
		reading_decimal,
		//signs
		got_plus,
		got_minus,
		increment,
		decrement
	} state = start;

	location_t loc_save = *loc;
	token_class
	/* Standard way to recognize a token: put back lookahead character that
        isn't part of current token: */
    #define ACCEPT_REUSE(t) \
        *loc = loc_save;    \
        tok->length--;      \
        tok->tc = t;        \
        state = done;

    /* Shortcut to eliminate final states with no out transitions: go
        ahead and accept token in previous state, but don't put back the
        lookahead: it's actually part of the token: */
    #define ACCEPT(t) \
        tok->tc = t;  \
        state = done;

        tok->location = *loc;
        tok->length = 0;
        printf("Was here\n");

	while (state != done)
	{
		loc_save = *loc;
        int c = get_character(loc); //updating location
        tok->length++;

		switch (state)
		{
			case start:
				switch (char_classes[c])
				{
					CASE_SKIP:
						printf("found a white space");
						state = got_space;
						break; // leaving the swtich statement 
					case LPAREN:
						printf("found a left paren\n");
						ACCEPT(T_LPAREN);						
						break;
					case RPAREN:
						printf("found a right paren\n");
						ACCEPT(T_RPAREN);
						break;
					CASE_DIGIT:
						printf("Found a number \n");
						state = got_digit;
						break;
					case PLUS:
						printf("Found a plus \n");
						state = got_plus;
						break;
					case MINUS:
						state = got_minus;
						break;
					case STAR:
						print_location(tok);
						ACCEPT(T_MULTOP);
						break;
					case SLASH:
						ACCEPT(T_MULTOP);
						break;
					case SEMIC:
						printf("Found semicolon\n");
						ACCEPT(T_SEMIC);
						break;
					case OTHER:
						ACCEPT(T_OTHER);
						break;
					case MODULO:
						ACCEPT(T_MULTOP);
						break;
					case POW:
						printf("Found a ^\n");
						ACCEPT(T_POW);
						break;
					case END:
						ACCEPT(T_EOF);
						break;
					default:
						printf("Default \n");
						print_location (tok);
						break;

				}
			break;

			case got_space:
				switch (char_classes[c])
				{
					CASE_SKIP:
						break;
					CASE_DIGIT:
						ACCEPT_REUSE(T_SPACE);
						break;
					default:
						ACCEPT_REUSE(T_SPACE);
						break;
				}
			break;

			case got_digit:
				switch (char_classes[c])
				{
					CASE_DIGIT:
						printf("found next digit\n");
						break;
					case PLUS:
						ACCEPT_REUSE(T_LITERAL);
						break;
					case MINUS:
						ACCEPT_REUSE(T_LITERAL);
						break;
					case STAR:
						print_location(tok);
						printf("stooped on a star\n");
						ACCEPT_REUSE(T_LITERAL);
						break;
					case SLASH:
						ACCEPT_REUSE(T_LITERAL);
						break;
					case OTHER:
						ACCEPT_REUSE(T_LITERAL);
						break;
					case DOT:
						printf("found a dot\n");
						state = reading_decimal;
						break;
					case RPAREN:
						printf("Stooped on right paren \n" );
						ACCEPT_REUSE(T_LITERAL);
						break;
					default:
						printf("Doing default \n");
						print_location(tok);
						ACCEPT_REUSE(T_LITERAL);
						break;						
				}
			break;

			case reading_decimal:
				switch (char_classes[c])
				{
					CASE_DIGIT:
						break;
					case RPAREN:
						printf("Stooped on right paren \n" );
						print_location(tok);
						ACCEPT_REUSE(T_LITERAL);
						break;
					case STAR:
						print_location(tok);
						printf("stooped on a star\n");
						ACCEPT_REUSE(T_LITERAL);
						break;
					default: 
						printf("Doing default \n");
						print_location(tok);
						ACCEPT_REUSE(T_LITERAL);
						break;
				}
			break;

			case got_plus:
				switch (char_classes[c])
				{
					case PLUS:
						state = increment;
						break;
					default:
						printf("gave a plus to the parser\n");
						ACCEPT_REUSE(T_ADDOP);
						break;
				}
			break;

			case got_minus:
				switch (char_classes[c])
				{
					case MINUS:
						state = decrement;
						break;
					default:
						ACCEPT_REUSE(T_ADDOP);
						break;
				}
			break;

			// this is not safe but I am not expecting an erronuous test file
			case increment:
				printf ("found an increment\n");
				ACCEPT_REUSE(T_INC);
						break;

			// this is not safe but I am not expecting an erronuous test file
			case decrement:
				ACCEPT_REUSE(T_DEC);
						break;

		}
	}
    
}