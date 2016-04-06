RM     = rm -rf 

CC      = gcc

SRC_PATH:= .
CFLAGS:=-I./include
LDFLAGS:=-L/usr/lib64/mysql  -lmysqlclient -lzmq
SRCS+= $(wildcard $(SRC_PATH)/*.c)
OBJS:= $(SRCS:.c=.o) 


TARGET     := sspserver

all: clean build  
  
build:  
	$(CC) -c $(CFLAGS) $(SRCS)  
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)  
	$(RM) $(OBJS)  
  
clean:  
	$(RM) $(OBJS) $(TARGET)

