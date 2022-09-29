CC=g++
CFLAGS=-Wall -Werror -Wextra
EXECUTABLE=exe
SOURCE=main.cpp barkengine.cpp protagonist.cpp
OBJECTS=$(SOURCE:.cpp=.o)

all: main

main: main.o barkengine.o
	$(CC) $(CFLAGS) main.o barkengine.o -lncursesw -o $(EXECUTABLE)

# main.o: main.cpp
# 	$(CC) -c $(CFLAGS) main.cpp -o main.o 

# barkengine.o: barkengine.cpp
# 	$(CC) -c $(CFLAGS) barkengine.cpp -o barkengine.o

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm *.o
	rm exe

rebuild: clean all
