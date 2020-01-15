CC=gcc
CFLAGS=-WallI.
PATHSERV=serveur/
PATHCLIENT=client/

all: client serv 

serv: $(PATHSERV)main.c $(PATHSERV)serv.c $(PATHSERV)servSecondaire.c $(PATHSERV)traitementRequete.c 
	@echo creation executable serveur
	$(CC) -o serv.exe $(PATHSERV)main.c $(PATHSERV)serv.c $(PATHSERV)servSecondaire.c $(PATHSERV)traitementRequete.c -lpthread

client: $(PATHCLIENT)main.c 
	@echo creation executable client
	$(CC) -o client.exe $(PATHCLIENT)main.c

clean:
	@echo supretion des executable
	rm -f serv.exe client.exe