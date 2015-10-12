/**********************************************************************
    When completed, this program should read a Java program
    (assumed to be syntactically correct) and produce HTML output,
    with
        keywords in bold face black
        literals in bold face green
        identifier declarations in red
        comments in italics
        pretty-printed indentation and spacing

    At the moment it tokenizes correctly, but
        (1) it only finds some of the declarations
        (2) it doesn't do spacing right
        (3) it hardly does indentation at all

    Your task is to fix these problems.

 **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "reader.h"
#include "scanner.h"
#include "parser.h"

int main (int argc, char *argv[]) {
    FILE *fp;
    
    if (argc < 2) {
        printf("Usage: ./format infile\n");
        exit(1);
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: infile.txt does not exist.\n");
        exit(1);
    }
  
    initialize_reader(fp);
    
    // SASHA's error tasting
    
    // Do scan, parse, evaluate here 
    parse();
    
    finalize_reader();
    
    exit(0);
}