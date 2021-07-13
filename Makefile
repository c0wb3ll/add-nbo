CC = g++
CFLAGS = -Wall
TARGET = add-nbo
OBJS = add-nbo.o

all: $(TARGET)

clean:

	rm $(OBJS) $(TARGET)

$(TARGET): $(OBJS)

	$(CC) -o $@ $(OBJS)

$(OBJS): add-nbo.cpp

	$(CC) -c -o $(OBJS) add-nbo.cpp