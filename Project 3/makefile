#######################################################################
#
#	Makefile for Assignment 2 (Java scanner and formatter)
#	CSC 173, Fall 2000
#
#######################################################################

OBJS = main.o reader.o scanner.o parser.o char_classes.o
INCS = reader.h scanner.h parser.h char_classes.h
FLAGS =  -g

runtest:	$(OBJS)
		gcc -o runtest $(FLAGS) $(OBJS)


main.o:	main.c $(INCS)
		gcc -c $(FLAGS) main.c


reader.o:	reader.c $(INCS)
		gcc -c $(FLAGS) reader.c


scanner.o:       scanner.c $(INCS)
		gcc -c $(FLAGS) scanner.c

parser.o:	parser.c $(INCS)
		gcc -c $(FLAGS) parser.c

char_classes.o:		char_classes.c  $(INCS)
		gcc -c $(FLAGS) char_classes.c
 
clean:		
		rm *.o