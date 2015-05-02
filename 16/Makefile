INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all: 16-9 16-16

%:	%.c
	$(CC) -o $@ $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue -lrt -lbsd
