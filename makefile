password-manager-plus: main.o manager.o generator.o
	g++ main.o manager.o generator.o -o password-manager-plus

main.o: main.cpp
	g++ -c main.cpp

manager.o: ./src/manager.cpp ./src/manager.hpp
	g++ -c ./src/manager.cpp

generator.o: ./src/generator.cpp ./src/generator.hpp
	g++ -c ./src/generator.cpp

