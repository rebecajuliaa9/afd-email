#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//cria uma lista de adjacencia para armazenar os emails
typedef struct Node{
    char email[50];
    struct Node *proximo;
} Node;

//cria a estrutura da lista
typedef struct Lista{
    Node *inicio;
    Node *fim;
} Lista;

//cria a lista
Lista *criarLista(){
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

//adiciona um email na lista
void adicionarEmail(Lista *lista, char email[]){
    Node *novo = (Node *)malloc(sizeof(Node));
    strcpy(novo->email, email);
    novo->proximo = NULL;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
}

//imprima a lista
void imprimirLista(Lista *lista){
    Node *atual = lista->inicio;
    while(atual != NULL){
        printf("%s\n", atual->email);
        atual = atual->proximo;
    }
}


int main(){
    //abra um arquivo csv
    FILE *file = fopen("emails.csv", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //cria a lista de emails
    Lista *lista = criarLista();

    //leia o arquivo
    char linha[100];
    while(fgets(linha, 100, file)){
        char *email = strtok(linha, ",");
        adicionarEmail(lista, email);
    }

    //imprima a lista
    imprimirLista(lista);

    //feche o arquivo
    fclose(file);

    return 0;
}

