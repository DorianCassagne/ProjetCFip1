CC=gcc
CFLAGS=-WallI.
PATHSERV=serveur/
PATHCLIENT=client/

all: client serv 

serv: $(PATHSERV)main.c $(PATHSERV)serv.c $(PATHSERV)servSecondaire.c $(PATHSERV)general.c 
	@echo creation executable serveur
	$(CC) -o serv.exe $(PATHSERV)main.c $(PATHSERV)serv.c $(PATHSERV)servSecondaire.c $(PATHSERV)traitementRequete.c $(PATHSERV)general.c -lpthread

client: $(PATHCLIENT)main.c $(PATHCLIENT)client.c $(PATHCLIENT)general.c
	@echo creation executable client
	$(CC) -o client.exe $(PATHCLIENT)main.c $(PATHCLIENT)client.c $(PATHCLIENT)general.c

clean:
	@echo supretion des executable
	rm -f serv.exe client.exe$(PATHCLIENT)main.c $(PATHCLIENT)main.c 