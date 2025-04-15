#ifndef HASH_H
#define HASH_H

#define TAM_NIVEL1 10 // define o tam. do primeiro nivel
#define N 100 // num. total de chaves 
#define TAM_LISTAS (N / TAM_NIVEL1) // cada vetor do segundo nivel terá tam. n/tam_nivel1

// nó para armazenar as chaves
typedef struct Nodo {
    char chave[50];
    struct Nodo* prox;
} Nodo;

// tabela hash de segundo nivel 
typedef struct Hash2 {
    Nodo* listas[TAM_LISTAS]; // vetor de ponteiros p/ lista
} Hash2;

// struct da tabela hash de primeiro nivel
typedef struct {
    Hash2* tabelas[TAM_NIVEL1]; // vetor de ponteiros p/ tabela de segundo nivel
} Hash1;

// funçoes
Hash1* criarHash(); // cria e inicia a hash
void inserir(Hash1* hash, char* chave); // insere a chave
Nodo* buscar(Hash1* hash, char* chave); // busca a chave

#endif
