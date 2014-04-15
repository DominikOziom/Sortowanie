__start__: obj Sort
	./Sort

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall



obj:
	mkdir obj

Sort:  obj/sort.o 
	g++ ${LDFLAGS} -o Sort obj/sort.o

obj/sort.o: sort.cpp 
	g++ ${CPPFLAGS} -o obj/sort.o sort.cpp

clean:
	rm -f sort obj/* core*
