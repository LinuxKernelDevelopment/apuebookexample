INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all:	6-2

%:	%.o
	$(CC) -o $@ $@.o -I $(INCLUDE) -L $(LIBRARY) -lapue

%.o: %.c
	$(CC) -c $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue
