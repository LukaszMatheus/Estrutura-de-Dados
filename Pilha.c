#include <stdio.h>
#include <stdlib.h>

struct Elemento {
    int num;        //struct elemento que vai conter o numero e um ponteiro do tipo elemento
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Pilha{
    Elemento *topo;
};

Elemento *aux;
typedef struct Pilha Pilha;

Pilha* criaPilha(){

    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL){
        pi->topo = NULL;
    }
    return pi;
}
void insereElemento(Pilha* pi){
    
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    printf("Digite o numero a ser inserido\n");
    scanf("%d", &novo->num);
    novo->prox = pi->topo;
    pi->topo = novo;
    printf("Numero inserido na pilha\n");
    getch();
    
};

void removeElemento(Pilha *pi){
    if(pi->topo == NULL){
        printf("Pilha vazia\n");
    }
    else{
        aux = pi->topo;
        printf("Numero removido da Pilha %d\n", pi->topo->num);
        pi->topo = pi->topo->prox;
        free(aux);
    }
    getch();
};

void verificaPilha(Pilha *pi){
    
    if(pi == NULL || pi->topo == NULL){
        printf("Pilha vazia\n");
        return;
    } 

    Elemento *atual = pi->topo;
    while(atual != NULL){
        
    printf("%d\n", atual->num);
    atual = atual->prox;
    };
    getch();
}



int main()
{
   Pilha *pi = criaPilha();
   int opcao;
   do {
       printf("\nDigite uma opção\n");
       printf("1 para inserir um item na pilha\n");
       printf("2 para remover um item na pilha\n");
       printf("3 para exibir a pilha completa\n");
       printf("0 para fechar o programa\n");
       scanf("%d", &opcao);
       
       switch(opcao){
           case 1:
           insereElemento(pi);
           break;
           
           case 2:
           removeElemento(pi);
           break;
           
           case 3:
           verificaPilha(pi);
           break;
           
           case 0:
           printf("fechando o programa\n");
           break;
       };
   } while (opcao != 0);
   
   

    return 0;
}
