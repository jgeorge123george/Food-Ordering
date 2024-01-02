CC = g++
CFLAGS = -std=c++11

# Add your source files here
SRCS = main.cpp

# Object files will be generated from the source files
OBJS = $(SRCS:.cpp=.o)

# Specify the name of your executable
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	 $(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS)

# Compile each source file into an object file
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)
