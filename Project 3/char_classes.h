/**********************************************************************
    Character classes, to simplify switch statement labels.
 **********************************************************************/

#ifndef CHAR_CLASSES_H
#define CHAR_CLASSES_H

typedef enum {
    END,    /* NUL, returned by reader at end of file */

    DIG_0,      /* 0 - 9     */
    DIG_1,
    DIG_2,
    DIG_3,
    DIG_4,
    DIG_5,
    DIG_6,
    DIG_7,
    DIG_8,
    DIG_9,
                //а разве нам DIG_9 не нужен? ~Ilya - nu*en, I zabila ego
    WHITE,      /* space, tab, or form feed */
    EOLN,       /* newline or carriage return */

    LPAREN,     /* ( */
    RPAREN,     /* ) */
    STAR,       /* * */ // multop
    PLUS,       /* + */ //addop
    MINUS,      /* - */ //addop
    DOT,        /* . */
    SLASH,      /* / */ //multop
    SEMIC,      /* ; */
    MODULO,     /* % */
    POW,        /* ^ */

    //CARET,      /* ^ */

    OTHER       /* catchall for everything else */
} char_class;

extern const char_class char_classes[128];

/* definitions to make switch statements easier to write: */

#define CASE_DIGIT \
    case DIG_0:    \
    case DIG_1:    \
    case DIG_2:    \
    case DIG_3:    \
    case DIG_4:    \
    case DIG_5:    \
    case DIG_6:    \
    case DIG_7:    \
    case DIG_8:    \
    case DIG_9


#define CASE_SKIP       \
    case WHITE:          \
    case EOLN

#endif