INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all:	e11-1

%:	%.c
	$(CC) -o $@ $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue -lpthread -lrt -lbsd
