all:
	gcc -g -c main.c
	gcc -g -c sorting/quick_sort.c
	gcc -g -c buffer/entrada.c
	gcc -g -c buffer/saida.c
	gcc -g -c particao/particao.c
	gcc -g -c big_file.c
	gcc -g -c ordenacao/ordenacao_externa.c
	gcc main.o quick_sort.o	entrada.o saida.o particao.o big_file.o ordenacao_externa.o -o main -lm
	