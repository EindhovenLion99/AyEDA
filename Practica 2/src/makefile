OBJS	= main.o celula.o tablero.o
SOURCE	= main.cpp celula.cpp tablero.cpp
HEADER	= celula.h tablero.h
OUT	= Life
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++17

celula.o: celula.cpp
	$(CC) $(FLAGS) celula.cpp -std=c++17

tablero.o: tablero.cpp
	$(CC) $(FLAGS) tablero.cpp -std=c++17


clean:
	rm -f $(OBJS) $(OUT)