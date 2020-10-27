all:
	gcc -c main.c -O2
	gcc -c sorting/quick_sort.c -O2
	gcc -c buffer/buffer.c -O2
	gcc -c buffer/buffer_entrada.c -O2
	gcc -c buffer/buffer_saida.c -O2
	gcc -c particao/particao.c -O2
	gcc -c big_file/big_file.c -O2
	gcc -c ordenacao_externa/ordenacao_externa.c -O2
	gcc -o main *.o -lm -O2
	