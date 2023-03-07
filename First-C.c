#include <stdio.h>

int main() {

    char a, b;

    printf("Digite um caractere: ");
    scanf("%c", &a);
    printf("Digite outro caractere: ");
    scanf("\n%c", &b);
    printf("\n");

    printf("- Caracteres digitados: '%c' e '%c'\n", a, b);
    printf("- Código ASCII: %d e %d\n", a, b);
    printf("- Endereços de Memórias: %p e %p \n", &a, &b);

    return 0;
}