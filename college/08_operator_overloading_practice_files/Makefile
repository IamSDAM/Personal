# executable file to create and its dependancies
prog : driver.o Money.o
	g++ -std=c++11 -o prog driver.o Money.o

# file dependencies
driver.o : Money.h
	g++ -std=c++11 -c driver.cpp
Money.o : Money.h
	g++ -std=c++11 -c Money.cpp	

# files to remove
clean:
	rm -f *.o
	rm prog