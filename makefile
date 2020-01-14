CC=gcc
CFLAGS=-WallI.
PATHSERV=serveur/
PATHCLIENT=client/

all: client serv 

serv:
	@echo creation executable serveur
	$(CC) -o serv.exe $(PATHSERV)main.c $(PATHSERV)serv.c

client:
	@echo creation executable client
	$(CC) -o client.exe $(PATHCLIENT)main.c

clean:
	rm -f serv.exe client.exe