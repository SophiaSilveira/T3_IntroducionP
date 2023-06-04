#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int prodF(int aux, int type) {
    int value = 0;

    for(int i = 0; i < NumProdutos; i++){
        if(estoqueFimDia[i].quantidade < aux && type == 1) {
            aux = estoqueFimDia[i].quantidade;
            value = i;}
        else if(estoqueFimDia[i].quantidade > aux && type == 2){
             aux = estoqueFimDia[i].quantidade;
            value = i;
        }
    }
    return value;
}

int prodBetweenF(int valueM, int aux, int type) {
    int value = 0;

    for(int i = 0; i < NumProdutos; i++){
         if(estoqueFimDia[i].quantidade < aux && estoqueFimDia[i].quantidade > valueM && type == 1) {
               aux = estoqueFimDia[i].quantidade;
               value = i;}

         else if(estoqueFimDia[i].quantidade > aux && estoqueFimDia[i].quantidade < valueM && type == 2) {
               aux = estoqueFimDia[i].quantidade;
               value = i;}
    }    
    return value;
}

void imprime(char frase[], int value, int imp){
    if(imp == 1) printf("\n%s %g:\n", frase, estoque[value].precounidade);
    else if(imp == 2) printf("\n%s %d:\n", frase, estoque[value].quantidade);
    else printf("\n%s %d:\n", frase, estoqueFimDia[value].quantidade);

    for(int i = 0; i < NumProdutos; i++){
        if(estoque[i].precounidade == estoque[value].precounidade && imp == 1){
            printf("-%s codigo %d\n", estoque[i].nome, estoque[i].codigo);
        }

        else if(estoque[i].quantidade == estoque[value].quantidade && imp == 2){
            printf("-%s codigo %d\n", estoque[i].nome, estoque[i].codigo);
        }

        else if(estoqueFimDia[i].quantidade == estoqueFimDia[value].quantidade && imp == 3){
            printf("-%s codigo %d\n", estoqueFimDia[i].nome, estoqueFimDia[i].codigo);
        }
    }
}

void main(){

    printf("Produtos de maior valor por unidade:");

    int primNum = precoMaior();
    int secNum = precoBetween(estoque[primNum].precounidade);
    int thiNum = precoBetween(estoque[secNum].precounidade);

    imprime("Primeiro maior valor", primNum, 1);
    imprime("Segundo maior valor", secNum, 1);
    imprime("Terceiro maior valor", thiNum, 1);

    printf("\n\nProdutos de menor estoque no inicio do dia:");

    primNum = prodMenorI();
    secNum = prodBetweenI(estoque[primNum].quantidade);
    thiNum = prodBetweenI(estoque[secNum].quantidade);

    imprime("Primeira menor quantidade", primNum, 2);
    imprime("Segunda menor quantidade", secNum, 2);
    imprime("Terceira menor quantidade", thiNum, 2);

    gerarEstoque();

    printf("\n\nProdutos de menor estoque no fim do dia:");

    primNum = prodF(2000, 1);
    secNum = prodBetweenF(estoqueFimDia[primNum].quantidade, 2000, 1);
    thiNum = prodBetweenF(estoqueFimDia[secNum].quantidade, 2000, 1);

    imprime("Primeira menor quantidade", primNum, 3);
    imprime("Segunda menor quantidade", secNum, 3);
    imprime("Terceira menor quantidade", thiNum, 3);

     printf("\n\nProdutos de maior estoque no fim do dia:");

    primNum = prodF(0, 2);
    secNum = prodBetweenF(estoqueFimDia[primNum].quantidade, 0, 2);
    thiNum = prodBetweenF(estoqueFimDia[secNum].quantidade, 0, 2);

    imprime("Primeira menor quantidade", primNum, 3);
    imprime("Segunda menor quantidade", secNum, 3);
    imprime("Terceira menor quantidade", thiNum, 3);
 
}