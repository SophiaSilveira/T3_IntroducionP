#include <stdio.h>
#include "super.h"

int precoMaior(int compa, float aux) {
    int i = 0;
    int value = 0;

    while(i < NumProdutos ){
        if(compa == 2){
            if(estoque[i].precounidade > aux) {
                aux = estoque[i].precounidade;
                value = i;}
        }
        else{
            if(estoque[i].precounidade < aux) {
                aux = estoque[i].precounidade;
                value = i;}
        }
        i++;
    }
    return value;
}

int precoBetween(float valueM, int compa, float aux) {
    int i = 0;
    int value = 0;

    while(i < NumProdutos){
        if(compa == 2){
            if(estoque[i].precounidade > aux && estoque[i].precounidade < valueM) {
               aux = estoque[i].precounidade;
               value = i;}
        }
        else{
            if(estoque[i].precounidade < aux && estoque[i].precounidade > valueM) {
               aux = estoque[i].precounidade;
               value = i;}
        }
        i++;
    }
    return value;
}

void imprimePreco(char frase[], float value){
    printf("\n%s %g:\n", frase, value);
    
    int i = 0;

    while(i < NumProdutos){
        if(estoque[i].precounidade == value){
            printf("-%s\n", estoque[i].nome);
        }
        i++;
    }
}

void main(){

    printf("Produtos de maior valor por unidade:");

    int primNum = precoMaior(2, 0);

    int secNum = precoBetween(estoque[primNum].precounidade, 2, 0);

    int thiNum = precoBetween(estoque[secNum].precounidade, 2, 0);

    imprimePreco("Primeiro maior valor", estoque[primNum].precounidade);
    imprimePreco("Segundo maior valor", estoque[secNum].precounidade);
    imprimePreco("Terceiro maior valor", estoque[thiNum].precounidade);

    
    printf("\n\nProdutos de menor valor por unidade:");

    primNum = precoMaior(1, 1000.5);

    secNum = precoBetween(estoque[primNum].precounidade, 1, 1000.5);

    thiNum = precoBetween(estoque[secNum].precounidade, 1, 1000.5);

    imprimePreco("Primeiro menor valor", estoque[primNum].precounidade);
    imprimePreco("Segundo menor valor", estoque[secNum].precounidade);
    imprimePreco("Terceiro menor valor", estoque[thiNum].precounidade);


}