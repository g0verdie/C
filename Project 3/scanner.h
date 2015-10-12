/**********************************************************************
    Tokenizer for Java source.
 **********************************************************************/

#ifndef SCANNER_H
#define SCANNER_H

#include "reader.h"

typedef enum {
    T_EOF, 
    T_LITERAL,
    T_ADDOP,
    T_MULTOP,
    T_SEMIC,
    T_LPAREN,
    T_RPAREN,
    T_OTHER,
    T_INC,
    T_DEC,
    T_POW,
    T_SPACE

} token_class;

typedef struct {
    token_class tc;
    location_t location;
    int length;     /* length of token in characters (may span lines) */
} token_t;

void scan(location_t * loc, token_t * tok);
    /* Modify tok to describe next token of input.
        Update loc to refer to location immediately after tok. */
void scanTEMP(location_t * loc, token_t * tok);


#endif