#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no* elo_anterior;
    struct no* elo_proximo;
};

typedef struct no No;

struct fila{
  No* inicio;
  No* fim;
};

typedef struct fila Fila;

Fila* cria(){
  Fila* fila = (Fila*) malloc(sizeof(Fila));
  fila->inicio = NULL;
  fila->fim = NULL;

  printf("\nA fila foi criada!\n");

  return fila;
}

No* insere_fim(No* inicio, No* fim , int info){
    No* no = (No*) malloc(sizeof(No));
    no->info = info;
    no->elo_proximo = NULL;
    no->elo_anterior = fim;

    if (fim != NULL){
        fim->elo_proximo = no;
    }
    
    printf("\nO valor foi INSERIDO no FIM da fila com sucesso!\n");
    return no;
}

void enqueue_fim(Fila* fila , int info){
  fila->fim = insere_fim(fila->inicio, fila->fim , info);

  if(fila->inicio == NULL){
    fila->inicio = fila->fim;
  }
}

No* retira_fim(No* inicio, No* fim){
  No* no = fim->elo_anterior;

  no->elo_proximo = NULL;

  printf("\nO valor foi REMOVIDO do FIM da fila com sucesso!\n");
  return no;
}

void dequeue_fim(Fila* fila){
  if(fila->inicio != NULL || fila->fim != NULL){
    fila->fim = retira_fim(fila->inicio, fila->fim);
  }else{
    printf("Fila vazia!");
  }

  if (fila->fim == NULL){
    fila->inicio = NULL;
  }
}

No* insere_inicio(No* inicio, No* fim , int info){
    No* no = (No*) malloc(sizeof(No));
    no->info = info;
    no->elo_proximo = inicio;
    no->elo_anterior = NULL;

    if(inicio != NULL){
      inicio->elo_anterior = no;
    }
    
    printf("\nO valor foi INSERIDO no INICIO da fila com sucesso!\n");
    return no;
}

void enqueue_inicio(Fila* fila , int info){
    fila->inicio = insere_inicio(fila->inicio, fila->fim , info);
    
    if(fila->fim == NULL){
        fila->fim = fila->inicio;
    }
}

No* retira_inicio(No* inicio, No* fim){
    No* no = inicio->elo_proximo;

    no->elo_anterior = NULL;

    printf("\nO valor foi REMOVIDO do INICIO da fila com sucesso!\n");
    return no;
}

void dequeue_inicio(Fila* fila){
    if(fila->inicio != NULL || fila->fim != NULL){
      fila->inicio = retira_inicio(fila->inicio, fila->fim);
    }else{
      printf("Fila vazia!");
    }

    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
}

void imprime(Fila* fila){
  No* no;

  printf("\n\nImprimindo valores da fila!\n\n");

  if(fila->fim == NULL && fila->inicio == NULL){
    printf("\nFila vazia!");
  }else{
    for(no = fila->inicio; no != NULL; no = no->elo_proximo){
      printf("\nInformacao da fila: %d", no->info);
    }
  }

  printf("\n");
}

void libera(Fila* fila){
  No* no;
  No* no_anterior;
  
  for(no = fila->inicio; no != NULL; no = no_anterior){
    no_anterior = no->elo_proximo;
    free(no);
  }

  free(fila);

  printf("\nA memoria foi liberada!\n");
}

int main(){
	
	Fila* f1;
	
	f1 = cria();
	
	enqueue_fim(f1, 1);
	enqueue_fim(f1, 2);
	enqueue_fim(f1, 3);
	enqueue_fim(f1, 4);
	enqueue_fim(f1, 5);
	imprime(f1);
	
	enqueue_inicio(f1, 10);
	imprime(f1);
	
	enqueue_inicio(f1, 12);
	imprime(f1);
	
	dequeue_fim(f1);
	imprime(f1);
	
	dequeue_inicio(f1);
	imprime(f1);
	
	libera(f1);
	cria();
	imprime(f1);
}

/*int main(){
  int opcao=0, valor;

    Fila* fila = cria();
    
    do {
        printf("\n\n\n1 - Inserir valor no inicio");
        printf("\n2 - Retirar valor no inicio");
        printf("\n3 - Inserir valor no fim");
        printf("\n4 - Retirar valor no fim");
        printf("\n5 - Imprimir valores");
        printf("\n6 - Liberar memoria");
        printf("\n\n0 - Sair\n\n");
        printf("Digite sua opcao > ");
        scanf("%d",&opcao);

        switch (opcao) {
          case 1:
            printf("\nDigite o valor que deseja inserir no inicio\n");
            scanf("%d", &valor);
            enqueue_inicio(fila, valor);
            
            break;

          case 2:
            dequeue_inicio(fila);
            
            break;

          case 3:
            printf("\nDigite o valor que deseja inserir no fim\n");
            scanf("%d", &valor);

            enqueue_fim(fila, valor);

            break;

          case 4:
            dequeue_fim(fila);
            
            break;

          case 5:
            imprime(fila);
            break;

          case 6:
            break;

          case 7:
            libera(fila);
            cria();
            break;

          case 0:
            libera(fila);
            printf("\n\nFinalizando Sistema\n\n");
            break;

          default:
            printf("\n\nOpÃ§Ã£o invalida!\n\n");
        }
    } while(opcao != 0);
}*/