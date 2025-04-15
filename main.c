#include <stdio.h>
#include "hash.h"

int main() {
    HashNivel1* hash = criarHash(); // cria a hash

    // inserçao de chaves
    inserir(hash, "João");
    inserir(hash, "Lucas");
    inserir(hash, "Kyonara");
    inserir(hash, "Marilene");
    inserir(hash, "Kyone");
    inserir(hash, "Fred");

    // busca de chave
    Nodo* resultado = buscar(hash, "Marilene");
    if (resultado) {
        printf("Encontrado: %s\n", resultado->chave);
    } else {
        printf("Não foi encontrado.\n");
    }

    return 0;
}
