CC = gcc
CFLAGS = -ansi -Wall -g

projeto: main.o menu.o prints.o deletes.o listas.o inputs.o triagem.o prot.o cura.o datas.o ficheiros.o header.h
	$(CC) $(CFLAGS) -o projeto main.o menu.o prints.o deletes.o listas.o inputs.o prot.o cura.o triagem.o datas.o ficheiros.o
main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c
menu.o: menu.c header.h
	$(CC) $(CFLAGS) -c menu.c
prints.o: prints.c header.h
	$(CC) $(CFLAGS) -c prints.c
deletes.o: deletes.c header.h
	$(CC) $(CFLAGS) -c deletes.c
listas.o: listas.c header.h
	$(CC) $(CFLAGS) -c listas.c
inputs.o: inputs.c header.h
	$(CC) $(CFLAGS) -c inputs.c
triagem.o: triagem.c header.h
	$(CC) $(CFLAGS) -c triagem.c
prot.o: prot.c header.h
	$(CC) $(CFLAGS) -c prot.c
cura.o: cura.c header.h
	$(CC) $(CFLAGS) -c cura.c
datas.o: datas.c header.h
	$(CC) $(CFLAGS) -c datas.c
ficheiros.o: ficheiros.c header.h
	$(CC) $(CFLAGS) -c ficheiros.c
