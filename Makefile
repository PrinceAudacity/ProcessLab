TARGET = my3proc
SOURCES = main3.c
OBJS = $(SOURCES:.c=.o)
CC = gcc
OPTS = -Wall
LIBS =

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

