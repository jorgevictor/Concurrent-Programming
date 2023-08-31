1.1. 10 'Hello World' sem identificacao de qual thread as criou e 10 'Cria a thread'
com identificacao de qual thread as criou. Cada 'Hello World' so pode ser printado após
o print do 'Cria a thread' de sua respectiva thread.

1.4. Sim, estao de acordo com o esperado.

2.4. Porque o int tem 4 bytes e o tamanho de ponteiro costuma ter 8 bytes, usamos o long int
para evitar o warning de diferenca de tamanhos.
 warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]

3.4. Foi necessario criar uma estrutura de dados nova para passar mais de um argumento na funcao.

4.4. A funcao main (thread principal) so termina apos todas as threads criadas terminarem. Isso
ocorre por conta da funcao pthread_join.