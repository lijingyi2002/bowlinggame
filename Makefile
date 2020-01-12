CC = gcc
CFLAGS = -g
SRC = $(wildcard ./*.c)
INCL = -I$(PWD)
OBJS = $(patsubst %.c, %.o, $(SRC))
#OBJS = bowlinggame_main.o \
#       bowlinggame_test.o 
TARGET = bowlinggame.out
#all: $(TARGET)

bowlinggame: $(OBJS)
	echo "start complie"
	$(CC) $(INCL) $(OBJS) $(CFLAGS) -o $(TARGET) 
%.o: %.c
	$(CC) $(INCL) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -rf $(OBJS) $(TARGET)
