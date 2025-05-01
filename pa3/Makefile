
# Automatically generated Makefile
# Makefile-generator created by Hans de Nivelle, 2023

CPP = g++

Exec = .
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors

# Linking:

$(Exec)/main : $(Source)/map.o $(Source)/main.o
	$(CPP) $(Options) -o $(Exec)/main $(Source)/map.o $(Source)/main.o $(Libs)

# Compiling the source files:

$(Source)/map.o : $(Source)/map.cpp $(Source)/map.h
	$(CPP) -c $(Options) $(Source)/map.cpp -o $(Source)/map.o

$(Source)/main.o : $(Source)/main.cpp $(Source)/map.h
	$(CPP) -c $(Options) $(Source)/main.cpp -o $(Source)/main.o

