#include <stdio.h>
#include "super.h"

int precoMaior(int numP, struct produto est[] ) {
    int i = 0;
    float aux = 0;
    int value = 0;

    while(i < numP){
        if(est[i].precounidade > aux) {
            aux = est[i].precounidade;
            value = i;
        }
        i++;
    }
    return value;
}

int precoBetween(float valueM, int numP, struct produto est[] ) {
    int i = 0;
    float aux = 0;
    int value = 0;

    while(i < numP){
        if(est[i].precounidade > aux && est[i].precounidade < valueM) {
           aux = est[i].precounidade;
           value = i;
        }
        i++;
    }
    return value;
}

void imprimePreco(char frase[], float value, int numP, struct produto est[] ){
    printf("\n%s ", frase);
    
    int i = 0;

    while(i < numP){
        if(est[i].precounidade == value){
            printf("produto %s que vale %g\n", est[i].nome, est[i].precounidade);
        }
        i++;
    }
}

void main(){
   // printf("%s", estoque[0].nome);

    int primNum = precoMaior( NumProdutos, estoque );
  //  printf("Mais caro %g\n",  estoque[primNum].precounidade);

    int secNum = precoBetween(estoque[primNum].precounidade, NumProdutos, estoque);
  //  printf("Segundo mais caro %g\n",  estoque[secNum].precounidade);

    int thiNum = precoBetween(estoque[secNum].precounidade, NumProdutos, estoque);
   // printf("Terceiro mais caro %g",  estoque[thiNum].precounidade);

    imprimePreco("Mais caro", estoque[primNum].precounidade, NumProdutos, estoque);
    imprimePreco("Segundo mais caro", estoque[secNum].precounidade, NumProdutos, estoque);
    imprimePreco("Terceiro mais caro", estoque[thiNum].precounidade, NumProdutos, estoque);



}