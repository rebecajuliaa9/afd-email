#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

//cria uma lista de adjacencia para armazenar os emails
typedef struct Node{
    char letra;
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

//inserir item ao final da lista
void inserirItemNaLista (Lista *lista, char letra){
    Node *novo = (Node *)malloc(sizeof(Node)); //cria um novo espaço para o email
    novo->letra = letra; //o novo espaço recebe o email
    novo->proximo = NULL; 

    if(lista->inicio == NULL){ //se a lista estiver vazia
        lista->inicio = novo;//a lista recebe o novo espaço
        lista->fim = novo;
    }else{ //se a lista não estiver vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
        lista->fim->proximo = NULL;
    }
    
    return;
}

void ler_arquivo(Lista **listaAdjacencia){
    int i = 0;
    listaAdjacencia[i] = criarLista();
    FILE *file = fopen("emails.csv", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char caracter;
    caracter = fgetc(file); //recebe o arquivo

    while (caracter != EOF) { 
        if (caracter == '\n'){
            i++;
            listaAdjacencia[i] = criarLista();
        }
        inserirItemNaLista(listaAdjacencia[i], caracter);
        caracter = fgetc(file);
    }

    fclose(file);

    return;
}

//faca um print da lista 
void imprimirLista(Lista *lista){
    Node *aux = lista->inicio;
    while(aux != NULL){
        printf("%c -> ", aux->letra);
        aux = aux->proximo;
    }
    printf("\n");
    return;
}

int main(){
    Lista **listaAdjacencia = (Lista **)malloc(4 * sizeof(Lista *));

    ler_arquivo(listaAdjacencia);

    for (int i=0; i<4; i++){
        imprimirLista(listaAdjacencia[i]);
    }
    
    return 0;
}
