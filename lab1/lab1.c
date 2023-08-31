#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NTHREADS 8 // Número de threads
#define EPSILON 1e-6 // Erro máximo permitido

int vector[10000]; // Vetor de entrada com 10000 elementos
int finalVector[10000]; // Vetor de saída após elevar ao quadrado

// Função que será executada pelas threads
void * elevaAoQuadrado (void * arg) {
    int ident = * (int *) arg; // Obtém o identificador da thread a partir do argumento
    
    // Loop para processar elementos do vetor em paralelo, com identificação da thread
    for (int i = ident; i < 10000; i += NTHREADS){
        finalVector[i] = vector[i] * vector[i]; // Calcula o quadrado do elemento e armazena no finalVector
    }
    
    pthread_exit(NULL); // Encerra a thread
}

int main() {
    
    // Preenche o vetor inicial com números aleatórios entre 0 e 9
    for (int c = 0; c < 10000; c++) {
        vector[c] = rand() % 10;
    }

    pthread_t tid[NTHREADS]; // Identificadores das threads no sistema
    int ident[NTHREADS]; // Array para armazenar os identificadores de thread

    // Cria as threads para processar o vetor
    for (int i = 1; i <= NTHREADS; i++) {
        ident[i - 1] = i;
        if (pthread_create(&tid[i - 1], NULL, elevaAoQuadrado, (void *)&ident[i - 1])) 
            printf("ERRO -- pthread_create\n");
    }

    // Aguarda as threads terminarem
    for (int i = 0; i < NTHREADS; i++) {
        if (pthread_join(tid[i], NULL)) 
            printf("ERRO -- pthread_join\n");
    }

    // Verifica se os resultados estão dentro da margem de erro
    for (int i = 0; i < 10000; i++) {
        if (finalVector[i] - (pow(vector[i], 2.0)) > EPSILON) {
            printf("ERRO -- elevaAoQuadrado\n");
            break;
        }
    }
    
    return 0;
}

// gcc -o lab1 lab1.c -lpthread -Wall -lm
// O parâmetro -lm deve ser passado para vincular a biblioteca matemática (libm) ao programa
// Por conta do uso da função pow
