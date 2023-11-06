CC = g++

SRC = src
OBJ = obj
BIN = bin
INC = include

all: clean obj bin

clean: cleanobj cleanbin

cleanobj:
	@if exist $(OBJ) del /q $(OBJ)

cleanbin:
	@if exist $(BIN) del /q $(BIN)

obj: Person Student Teacher School Course main

Person Student Teacher School Course main:
	@if not exist $(OBJ) md $(OBJ)
	$(CC) -c $(SRC)\$@.cpp -o $(OBJ)\$@.o -I$(INC)
	
bin: $(OBJ)\Person.o $(OBJ)\Student.o $(OBJ)\Teacher.o $(OBJ)\School.o $(OBJ)\Course.o $(OBJ)\main.o
	@if not exist $(BIN) md $(BIN)
	$(CC) -o $(BIN)\zadanie.exe $(OBJ)\Person.o $(OBJ)\Student.o $(OBJ)\Teacher.o $(OBJ)\School.o $(OBJ)\Course.o $(OBJ)\main.o
	

