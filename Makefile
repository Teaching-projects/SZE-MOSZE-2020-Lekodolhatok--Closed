OBJS := main.o Hero.o Monster.o JSON.o
CFLAGS := -Wall -std=c++17
CC := g++-9

add: $(OBJS)
	$(CC) $(CFLAGS) -o play $(OBJS)

main.o: main.cpp Hero.h Monster.h JSON.h
	$(CC) $(CFLAGS) -c main.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h JSON.h
	$(CC) $(CFLAGS) -c Monster.cpp

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

clean:
	rm -rf *.o mosze_01 *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 cat | ./play

documentation:
	doxygen documentations/doxconf

