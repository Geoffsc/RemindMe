# Makefile for remindme utility

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = remindme
SRC = remindme.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

install:
	install -m 0755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	rm -f /usr/local/bin/$(TARGET)
