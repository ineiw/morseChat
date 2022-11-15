SRC_DIR = ~/morseChat/kakaoRequest/src/

all : test

test : $(SRC_DIR)request.o $(SRC_DIR)client.o
	g++ $^ -o test

main.o : $(SRC_DIR)request.cpp $(SRC_DIR)client.h
	g++ -c $<

client.o : $(SRC_DIR)client.cpp $(SRC_DIR)client.h
	g++ -c $<

clean :
	rm -rf $(SRC_DIR)*.o
