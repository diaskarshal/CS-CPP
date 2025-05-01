
# Automatically generated Makefile
# Makefile-generator created by Hans de Nivelle, 2023

CPP = g++

Exec = .
Lexing = /home/nivelle/programs
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors

# Linking:

$(Exec)/calculator : $(Source)/calculator.o $(Source)/symbol.o $(Source)/tokenizer.o $(Source)/filereader.o
	$(CPP) $(Options) -o $(Exec)/calculator $(Source)/calculator.o $(Source)/symbol.o $(Source)/tokenizer.o $(Source)/filereader.o $(Libs)

# Compiling the source files:

$(Source)/calculator.o : $(Source)/calculator.cpp $(Source)/filereader.h $(Source)/location.h $(Source)/symbol.h $(Source)/syntax_error.h $(Source)/tokenizer.h
	$(CPP) -c $(Options) $(Source)/calculator.cpp -o $(Source)/calculator.o

$(Source)/symbol.o : $(Source)/symbol.cpp $(Source)/location.h $(Source)/symbol.h
	$(CPP) -c $(Options) $(Source)/symbol.cpp -o $(Source)/symbol.o

$(Source)/tokenizer.o : $(Source)/tokenizer.cpp $(Source)/dfa.h $(Source)/filereader.h $(Source)/location.h $(Source)/symbol.h $(Source)/tokenizer.h
	$(CPP) -c $(Options) $(Source)/tokenizer.cpp -o $(Source)/tokenizer.o

$(Source)/filereader.o : $(Source)/filereader.cpp $(Source)/filereader.h
	$(CPP) -c $(Options) $(Source)/filereader.cpp -o $(Source)/filereader.o

