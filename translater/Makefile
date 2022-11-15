OBJ = main.o MorseTranslater.o

OBJ_DIR = ./obj/
SRC_DIR = ./src/

all : test 

test : main.o MorseTranslater.o
	g++ $^ -o test

main.o : $(SRC_DIR)main.cpp $(SRC_DIR)MorseTranslater.h
	g++ -c $<

MorseTranslater.o : $(SRC_DIR)MorseTranslater.cpp $(SRC_DIR)MorseTranslater.h
	g++ -c $<

clean:
	rm -rf ./*.o
