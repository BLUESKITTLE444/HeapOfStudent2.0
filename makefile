# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Executable name
TARGET = students

# Object files
OBJS = main.o student.o address.o date.o

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cpp
main.o: main.cpp student.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile student.cpp
student.o: student.cpp student.h address.h date.h
	$(CXX) $(CXXFLAGS) -c student.cpp

# Compile address.cpp
address.o: address.cpp address.h
	$(CXX) $(CXXFLAGS) -c address.cpp

# Compile date.cpp
date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c date.cpp

# Run the program
run: $(TARGET)
	./$(TARGET)

# Check for memory leaks with Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Clean build files
clean:
	rm -f *.o $(TARGET)
