INCLUDE=/home/hmsjwzb/apue.3e/include
LIBRARY=/home/hmsjwzb/apue.3e/lib

all:	my_ls my_cp1 my_cp2 getpid execlp error getuid_gid signal

%:	%.c
	$(CC) -o $@ $@.c -I $(INCLUDE) -L $(LIBRARY) -lapue
