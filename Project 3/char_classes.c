/**********************************************************************
    Character classes, to simplify switch statement labels.

    NB: These classes do NOT suffice for the assignment;
        you will need to modify this table.

 **********************************************************************/

#include "char_classes.h"

const char_class char_classes[128] = {
  END,        /* nul   ^@ */      /* returned by get_character at EOF */
  OTHER,      /* soh   ^A */
  OTHER,      /* stx   ^B */
  OTHER,      /* etx   ^C */
  OTHER,      /* eot   ^D */
  OTHER,      /* enq   ^E */
  OTHER,      /* ack   ^F */
  OTHER,      /* bel   ^G */
  OTHER,      /* bs    ^H */
  WHITE,      /* ht    ^I */
  EOLN,       /* nl    ^J */    /* 10 */
  OTHER,      /* vt    ^K */
  WHITE,      /* ff    ^L */
  EOLN,       /* cr    ^M */
  OTHER,      /* so    ^N */
  OTHER,      /* si    ^O */
  OTHER,      /* dle   ^P */
  OTHER,      /* dc1   ^Q */
  OTHER,      /* dc2   ^R */
  OTHER,      /* dc3   ^S */
  OTHER,      /* dc4   ^T */    /* 20 */
  OTHER,      /* nak   ^U */
  OTHER,      /* syn   ^V */
  OTHER,      /* etb   ^W */
  OTHER,      /* can   ^X */
  OTHER,      /* em    ^Y */
  OTHER,      /* sub   ^Z */
  OTHER,      /* esc   ^[ */
  OTHER,      /* fs    ^\ */
  OTHER,      /* gs    ^] */
  OTHER,      /* rs    ^^ */    /* 30 */
  OTHER,      /* us    ^_ */
  WHITE,      /* sp */
  OTHER,      /* ! */
  OTHER,      /* " */
  OTHER,      /* # */
  OTHER,      /* $ */
  MODULO,      /* % */
  OTHER,      /* & */
  OTHER,      /* ' */
  LPAREN,     /* ( */     /* for parser */
  RPAREN,     /* ) */     /* for parser */
  STAR,       /* * */     /* for parser */
  PLUS,       /* + */     /* for parser */
  OTHER,      /* , */
  MINUS,      /* - */     /* for parser */
  DOT,        /* . */
  SLASH,      /* / */     /* for parser */
  DIG_0,   /* 0 */        /* for parser */
  DIG_1,   /* 1 */        /* for parser */
  DIG_2,   /* 2 */        /* for parser */
  DIG_3,   /* 3 */        /* for parser */
  DIG_4,   /* 4 */        /* for parser */
  DIG_5,   /* 5 */        /* for parser */
  DIG_6,   /* 6 */        /* for parser */
  DIG_7,   /* 7 */        /* for parser */
  DIG_8,   /* 8 */        /* for parser */
  DIG_9,   /* 9 */        /* for parser */
  OTHER,      /* : */
  SEMIC,      /* ; */     /* for parser */
  OTHER,      /* < */
  OTHER,      /* = */
  OTHER,      /* > */
  OTHER,      /* ? */
  OTHER,      /* @ */
  OTHER,      /* A */
  OTHER,      /* B */
  OTHER,      /* C */
  OTHER,      /* D */
  OTHER,      /* E */
  OTHER,      /* F */
  OTHER,      /* G */
  OTHER,  /* H */
  OTHER,  /* I */
  OTHER,  /* J */
  OTHER,  /* K */
  OTHER,  /* L */
  OTHER,  /* M */
  OTHER,  /* N */
  OTHER,  /* O */
  OTHER,  /* P */
  OTHER,  /* Q */
  OTHER,  /* R */
  OTHER,  /* S */
  OTHER,  /* T */
  OTHER,  /* U */
  OTHER,  /* V */
  OTHER,  /* W */
  OTHER,  /* X */
  OTHER,  /* Y */
  OTHER,  /* Z */
  OTHER,  /* [ */
  OTHER,  /* \ */
  OTHER,  /* ] */
  POW,    /* ^ */
  OTHER,  /* _ */
  OTHER,  /* ` */
  OTHER,  /* a */
  OTHER,  /* b */   
  OTHER,  /* c */
  OTHER,  /* d */
  OTHER,  /* e */
  OTHER,  /* f */   
  OTHER,  /* g */
  OTHER,  /* h */
  OTHER,  /* i */
  OTHER,  /* j */
  OTHER,  /* k */
  OTHER,  /* l */
  OTHER,  /* m */
  OTHER,  /* n */   
  OTHER,  /* o */
  OTHER,  /* p */
  OTHER,  /* q */
  OTHER,  /* r */   
  OTHER,  /* s */
  OTHER,  /* t */   /* lc only, for escape sequences */
  OTHER,  /* u */   /* lc only, for escape sequences */
  OTHER,  /* v */
  OTHER,  /* w */
  OTHER,  /* x */
  OTHER,  /* y */
  OTHER,  /* z */
  OTHER,  /* { */
  OTHER,  /* | */
  OTHER,  /* } */
  OTHER,  /* ~ */
  OTHER   /* del   ^? */
};