INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all:	my_ls my_cp1 my_cp2

%:	%.c
	$(CC) -o $@ $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue
