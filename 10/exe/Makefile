INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all:	e10.1 e10.2	e10.5 e10-11

%:	%.c
	$(CC) -O -o $@ $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue
