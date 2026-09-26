CXX := g++

CXXFLAGS := -Wall -Wextra -I./include

LDFLAGS := 
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system -ltinyxml2

TARGET := game

SOURCE := $(wildcard src/*.cpp src/engine/*.cpp)
OBJECTS := $(SOURCE:.cpp=.o)

.PHONY: all clean run 

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJECTS)