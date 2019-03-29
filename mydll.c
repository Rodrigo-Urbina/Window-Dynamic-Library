#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char myString[20];
    do {
        printf("Introduzca un número en hexadecimal\n");
        scanf("%s", myString);
        int toPrint = myHexToInt(myString);
        if (toPrint > 0) {
            printf("%d\n", toPrint);
        } else {
            printf("Error: número inválido\n");
            return 0;
        }
    } while (1);
    
    return 0;
}