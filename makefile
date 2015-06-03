projeto: main.o menu.o prints.o deletes.o listas.o inputs.o triagem.o prot.o cura.o datas.o ficheiros.o header.h
	gcc  -o projeto main.o menu.o prints.o deletes.o listas.o inputs.o prot.o cura.o triagem.o datas.o ficheiros.o  
main.o: main.c header.h
	gcc -c main.c
menu.o: menu.c header.h
	gcc -c menu.c
prints.o: prints.c header.h
	gcc -c prints.c
deletes.o: deletes.c header.h
	gcc -c deletes.c
listas.o: listas.c header.h
	gcc -c listas.c
inputs.o: inputs.c header.h
	gcc -c inputs.c
triagem.o: triagem.c header.h
	gcc -c triagem.c
prot.o: prot.c header.h
	gcc -c prot.c
cura.o: cura.c header.h
	gcc -c cura.c
datas.o: datas.c header.h
	gcc -c datas.c
ficheiros.o: ficheiros.c header.h
	gcc -c ficheiros.c


