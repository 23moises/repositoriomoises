#include <stdio.h>

int main() {
    int n, num, digit, reversed, count3 = 0, count5 = 0;
    
    printf("Ingrese la cantidad de números que desea verificar: ");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("Ingrese el número %d: ", i);
        scanf("%d", &num);
        
        if(num >= 1000) { // Si el número tiene más de 3 dígitos, invertimos el número
            reversed = 0;
            while(num != 0) {
                digit = num % 10;
                reversed = reversed * 10 + digit;
                num /= 10;
            }
            printf("El número invertido de %d es %d\n", num, reversed);
        }
        
        // Contamos la cantidad de veces que aparece el 3 y el 5 en el número ingresado
        while(num != 0) {
            digit = num % 10;
            if(digit == 3) {
                count3++;
            } else if(digit == 5) {
                count5++;
            }
            num /= 10;
        }
    }
    
    printf("El número 3 apareció %d veces\n", count3);
    printf("El número 5 apareció %d veces\n", count5);
    
    return 0;
}
