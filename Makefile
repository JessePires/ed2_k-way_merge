all:
	gcc -g -c main.c
	gcc -g -c buffer/entrada.c
	gcc -g -c buffer/saida.c
	gcc -g -c particao/particao.c
	gcc -g -c big_file.c 
	gcc main.o entrada.o saida.o particao.o big_file.o  -o main
	