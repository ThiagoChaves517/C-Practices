#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

    int n = 50, m = 10;
    int* p;
    
    p = &n;
    printf("%d\n", *p);
    printf("%p\n", &n);
    printf("%p\n", p);
    
    p = &m;
    printf("%d\n", *p);
    printf("%p\n", &m);
    printf("%p\n", p);

    */

    /*

    printf("------------------------------------------------------\n");

    int n = 0;
    int* p;

    p = &n;
    scanf("%d", p);
    printf("valor de n: %d\n", n);
    printf("valor de *p: %d\n", *p);

    printf("\n");

    scanf("%d", p);
    printf("valor de n: %d\n", n);
    printf("valor de *p: %d\n", *p);

    */
    /*

    printf("------------------------------------------------------\n");

    int n[5] = {1,2,3,10,5};
    int* p;

    p = &n[2];

    printf("p: %d\n", *p);
    printf("p+1: %d\n", *(p+1));

    *(p-1) = 0;
    printf("n[1]: %d\n", n[1]);

    */
    /*

    printf("------------------------------------------------------\n");

    int x = 5;
    int* p;

    p = &x;
    *p = 15;

    printf("Valor de x: %d\n", x);
    printf("Endereço de p (com &): %p\n", &p);
    printf("Endereço de p: %p\n", p);
    printf("Endereço de x: %p\n", &x);
    printf("Valor de p: %d\n", *p);

    */
    /*

    printf("------------------------------------------------------\n");

    unsigned int n, sum = 0;
    int* p;

    printf("Informe a quantidade de elementos: \n");
    scanf("%u", &n);
    p = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", (p+i));
        sum += *(p+i);
    }
    printf("Soma: %u\n", sum);

    free(p);

    printf("------------------------------------------------------\n");

    */
    /*
    
    //Infinite Array:

    unsigned int n = 10, i = 0;
    int* p;

    p = (int*) malloc(n*sizeof(int));

    do{
        scanf("%d", (p+i));
        if(n-i < 2){
            n += 10;
            p = realloc(p, n*sizeof(int));
        }
    } while (*(p + i++));

    free(p);

    */

    printf("------------------------------------------------------\n");

    int array[10];
    int* pares;
    int* impares;

    pares = (int*) malloc (10*sizeof(int));
    impares = (int*) malloc (10*sizeof(int));

    int j = 0, k = 0;
    int counter1 = 0, counter2 = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d", &array[i]);
        if(array[i]%2==0){
            *(pares+j) = array[i];
            j++;
            counter1++;
        }
        else{
            *(impares+k) = array[i];
            k++;
            counter2++;
        }

    }

    printf("Pares: ");
    for(int i = 0; i < counter1; i++){
        printf("%d ", *(pares+i));
    }

    printf("\n");

    printf("Impares: ");
    for(int i = 0; i < counter2; i++){
        printf("%d ", *(impares+i));
    }

    printf("\n");

    printf("------------------------------------------------------\n");


    return 0;
}