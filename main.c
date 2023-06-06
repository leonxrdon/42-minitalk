#include <stdio.h>

void convertirABinario(char c) {
    printf("Carácter: %c\n", c);
    printf("Representación binaria: \n");

    int bit;

    for (bit = 7; bit >= 0; --bit) {
        if (c & (0x01 << bit))
            printf("1");
        else
            printf("0");
    }

    printf("\n\n");
}

int main() {
    char linea[] = "leo";
    int i;

    for (i = 0; linea[i] != '\0'; ++i) {
        convertirABinario(linea[i]);
    }

    return 0;
}
