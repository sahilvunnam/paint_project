paint.out: main.o in_outfile.o setup.o input_validation.o play.o
	gcc -g -Wall -fsanitize=address -Werror -o paint.out setup.o main.o input_validation.o play.o in_outfile.o
main.o: main.c setup.h in_outfile.h input_validation.h play.h
	gcc -g -Wall -Werror -c main.c
in_outfile.o: in_outfile.c in_outfile.h setup.h play.h
	gcc -g -Wall -Werror -c in_outfile.c
setup.o: setup.c setup.h
	gcc -g -Wall -Werror -c setup.c
input_validation.o: input_validation.c input_validation.h setup.h play.h
	gcc -g -Wall -Werror -c input_validation.c
play.o: play.c play.h input_validation.h setup.h
	gcc -g -Wall -Werror -c play.c
clean:
	rm -f *.out *.o