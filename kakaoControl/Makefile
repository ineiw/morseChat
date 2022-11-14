SRC_DIR = ~/morseChat/kakaoControl/src/

all : test

test : $(SRC_DIR)main.o $(SRC_DIR)client.o
	g++ $^ -o test

main.o : $(SRC_DIR)main.cpp $(SRC_DIR)client.h
	g++ -c $<

client.o : $(SRC_DIR)client.cpp $(SRC_DIR)client.h
	g++ -c $<

clean :
	rm -rf $(SRC_DIR)*.o
