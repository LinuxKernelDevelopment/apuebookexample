INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all: 15-5 15-6 15-11 15-17 15-18 15-19 15-31 15-33

%:	%.c
	$(CC) -o $@ $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue -lrt -lbsd
