#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[1000];
    int busca;
    
    printf("Qual elemento do vetor pesquisar? ");
    scanf("%i", &busca);

    for (int i = 0; i < 1000; i++)
    {
        vetor [i] = i;
    }

    int maior = 999;
    int menor = 0;
    buscaLinear(vetor, busca);
    buscaBinaria(vetor,busca);
    buscaTabela(vetor, busca);
    return 0;
}

int buscaBinaria(int vet[], int busca)
{
    int menor = 0;
    int maior = 999;
    int comp = 0;
   
    while (menor <= maior) {  
        comp++;
        int meio = (menor + maior) / 2;  
        
        if (vet[meio] == busca) {  
            return printf("\nBusca binaria: %i comparacoes.", comp);
        }
        if (vet[meio] < busca) {  
            menor = meio + 1;
        } else {  
            maior = meio;
        }
    }

    return -1;
}

int buscaLinear(int vet[],int busca){
    int comparacoes = 0;
    
    for (int i = 0; i < 1000; i++)
    {
        if (vet[i] == busca)
        {   
            comparacoes++;
            return printf("\nBusca linear: %i comparacoes.", comparacoes);
        } else if(vet[i] != busca){
            comparacoes++;
        }else 
            return printf("\nElemento nao encontrado, %i comparacoes", comparacoes);
        
    }
}

int buscaTabela(int vet[],int busca){
    int freq[1000];
    int comparacoes = 0;

    for (int i = 0; i < 1000; i++){
        freq[vet[i]]++;
    }
    if(freq[busca] > 0)
        comparacoes++;
        return printf("\nBusca por tabela de frequencia: %i comparacoes.",comparacoes);
    if(freq[busca] <= 0)
        comparacoes++;
        return printf("\nElemento nao encontrado, %i comparacoes.", comparacoes);
}