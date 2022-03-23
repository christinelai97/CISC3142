CC = g++
CFLAGS  = -g -Wall
TARGET = lab2

all: $(TARGET)

$(TARGET) : clean compile run

compile: Calculator.cpp
	$(CC) $(CFLAGS) -std=c++11 -o $(TARGET) Calculator.cpp

clean:
	$(RM) $(TARGET)

run:
	./${TARGET}
