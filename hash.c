#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// func. hash do primeiro nivel (soma dos caracteres % tam_nivel1)
int hash1(char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAM_NIVEL1;
}

// func. hash do primeiro nivel (soma ponderada dos caracteres % tam_listas)
int hash2(char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i] * (i + 1); // ponderaçao pela posiçao
    }
    return soma % TAM_LISTAS;
}
// cria a hash de dois niveis e inicializa os ponteiros
Hash1* criarHash() {
    Hash1* nova = malloc(sizeof(Hash1));
    for (int i = 0; i < TAM_NIVEL1; i++) {
        nova->tabelas[i] = NULL;
    }
    return nova;
}

// insere uma chave
void inserir(Hash1* hash, char* chave) {
    int idx1 = hash1(chave); // indice do primeiro nivel
    
    // se nao existir a tabela do segundo nivel, cria
    if (hash->tabelas[idx1] == NULL) {
        hash->tabelas[idx1] = malloc(sizeof(Hash2));
        for (int i = 0; i < TAM_LISTAS; i++) {
            hash->tabelas[idx1]->listas[i] = NULL; // inicializa as listas como vazias
        }
    }

    int idx2 = hash2(chave); // indice no segundo nivel

    Nodo* novo = malloc(sizeof(Nodo));
    strcpy(novo->chave, chave);
    novo->prox = hash->tabelas[idx1]->listas[idx2];
    hash->tabelas[idx1]->listas[idx2] = novo;
}

// busca por uma chave e retorna o ponteiro para o nodo (ou null se nao encontrar)
Nodo* buscar(Hash1* hash, char* chave) {
    int idx1 = hash1(chave);
    if (hash->tabelas[idx1] == NULL) return NULL; // nao tem nada nesse indice

    int idx2 = hash2(chave);
    Nodo* atual = hash->tabelas[idx1]->listas[idx2];

    // percorre a lista procurando a chave
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}
