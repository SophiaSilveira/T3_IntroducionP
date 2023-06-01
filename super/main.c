#include <stdio.h>
#include "super.h"

struct produto estoqueFimDia[116] = {};

void gerarEstoque(){
    for(int i = 0; i < NumProdutos; i++){
        estoqueFimDia[i] = estoque[i];

        for(int c = 0; c < NumCompras; c++){
            if(estoqueFimDia[i].codigo == registro[c].codproduto){
                estoqueFimDia[i].quantidade -= registro[c].quantidade;
            }
        }
        
        printf("\n%d %s %d %d %g", i + 1, estoqueFimDia[i].nome, estoqueFimDia[i].codigo, estoqueFimDia[i].quantidade, estoqueFimDia[i].precounidade);
    }
}

int precoMaior() {
    float aux = 0;
    int value = 0;

    for(int i = 0; i < NumProdutos; i++){
        if(estoque[i].precounidade > aux) {
            aux = estoque[i].precounidade;
            value = i;}
    }
    return value;
}

int prodMenorI() {
    int aux = 2000;
    int value = 0;

    for(int i = 0; i < NumProdutos; i++){
        if(estoque[i].quantidade < aux) {
            aux = estoque[i].quantidade;
            value = i;}
    }
    return value;
}

int precoBetween(float valueM) {
    int value = 0;
    float aux = 0;

    for(int i = 0; i < NumProdutos; i++){
         if(estoque[i].precounidade > aux && estoque[i].precounidade < valueM) {
               aux = estoque[i].precounidade;
               value = i;}
    }    
    return value;
}

int prodBetweenI(int valueM) {
    int value = 0;
    float aux = 2000;

    for(int i = 0; i < NumProdutos; i++){
         if(estoque[i].quantidade < aux && estoque[i].quantidade > valueM) {
               aux = estoque[i].quantidade;
               value = i;}
    }    
    return value;
}

void imprime(char frase[], int value, int imp){
    if(imp == 2) printf("\n%s %g:\n", frase, estoque[value].precounidade);
    else printf("\n%s %d:\n", frase, estoque[value].quantidade);

    for(int i = 0; i < NumProdutos; i++){
        if(estoque[i].precounidade == estoque[value].precounidade && imp == 2){
            printf("-%s codigo %d\n", estoque[i].nome, estoque[i].codigo);
        }

        else if(estoque[i].quantidade == estoque[value].quantidade && imp == 1){
            printf("-%s codigo %d\n", estoque[i].nome, estoque[i].codigo);
        }

    }
}

void main(){

    printf("Produtos de maior valor por unidade:");

    int primNum = precoMaior();
    int secNum = precoBetween(estoque[primNum].precounidade);
    int thiNum = precoBetween(estoque[secNum].precounidade);

    /*imprime("Primeiro maior valor", primNum, 2);
    imprime("Segundo maior valor", secNum, 2);
    imprime("Terceiro maior valor", thiNum, 2);*/

    printf("\n\nProdutos de menor estoque no inicio do dia:");

    primNum = prodMenorI();
    secNum = prodBetweenI(estoque[primNum].quantidade);
    thiNum = prodBetweenI(estoque[secNum].quantidade);

    /*imprime("Primeira menor quantidade", primNum, 1);
    imprime("Segunda menor quantidade", secNum, 1);
    imprime("Terceira menor quantidade", thiNum, 1);*/

    gerarEstoque();
 

}