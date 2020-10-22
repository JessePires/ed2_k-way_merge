all:
	gcc -g -c main.c
	gcc -g -c sorting/quick_sort.c
	gcc -g -c buffer/buffer.c
	gcc -g -c buffer/buffer_entrada.c
	gcc -g -c buffer/buffer_saida.c
	gcc -g -c particao/particao.c
	gcc -g -c big_file.c
	gcc -g -c ordenacao_externa/ordenacao_externa.c
	gcc main.o quick_sort.o buffer.o buffer_entrada.o buffer_saida.o particao.o big_file.o ordenacao_externa.o -o main -lm
	