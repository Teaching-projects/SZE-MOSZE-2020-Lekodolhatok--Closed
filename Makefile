OBJS := main.o character.o jsonparser.o
CFLAGS := -Wall -std=c++17
CC := g++-9

add: $(OBJS)
	$(CC) $(CFLAGS) -o play $(OBJS)

main.o: main.cpp character.h jsonparser.h
	$(CC) $(CFLAGS) -c main.cpp

character.o: character.cpp 
	$(CC) $(CFLAGS) -c character.cpp

jsonparser.o: jsonparser.cpp
	$(CC) $(CFLAGS) -c Monster.cpp

clean:
	rm -rf *.o play *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 cat | ./play

documentation:
	doxygen documentations/doxconf

