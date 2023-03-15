#include <stdio.h>
#include <stdlib.h>

void main(){
    unsigned int n, m, i, j;
    int**p;

    printf("Informe a quantidade de linhas e colunas da matriz: ");
    scanf("%u %u", &n, &m);

    p = (int**) malloc (n*sizeof(int**));
    for(i = 0; i < n; i++){
        p[i] = (int*) malloc (m*sizeof(int*));
    }

    printf("Informe os elementos:");
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            scanf("%u", &p[i][j]);
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            printf("%u ", p[i][j]);
            //printf("\n");
        }
    }
    free(p);
}