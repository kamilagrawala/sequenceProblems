CC = gcc
DEBUG = -g
option = -v
CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement $(DEFINES)
PROGS = lis
testfile = latin1.txt
testfile2 = jargon.txt
testfile3 = words.txt
testfile4 = websters.txt

all: $(PROGS)

lis: lis.o 
	$(CC) $(CFLAGS) -o $@ $^

lis.o: lis.c 
	  $(CC) $(CFLAGS) -c $< 

clean: 
	rm -rf *.o
	\rm -rf *#
	\rm -rf *.#
	\rm -rf *~
	\rm -rf JUNK1 JUNK2
	\rm -rf LOGS LOGC
	\rm -rf lis.o
	\rm -rf lis	

#	Git Revision Control System (BitBucket) 
push:
	make clean 
	git add --all
	git commit -am " Automatic Makefile Backup"
	git push -u origin master  

checkout:
	git fetch
	git checkout origin/master myhostdb.c

checkout2:
	git fetch
	git checkout origin/master socket_server.c

checkout3:
	git fetch
	git checkout origin/master socket_client.c


#Checks for Memory leaks
valgrid: 
	valgrind --leak-check=yes -v ./lcs  