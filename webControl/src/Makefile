all : test

test : main.o client.o
	g++ $^ -o test

main.o : main.cpp client.h
	g++ -c $<

client.o : client.cpp client.h
	g++ -c $<

clean :
	rm -rf ./*.o
