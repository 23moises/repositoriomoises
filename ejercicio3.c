#include <stdio.h>

int main() {
    int n, factura_maxima = 0, ganadores_descuento = 0, ganadores_gif = 0, ganadores_5pct = 0, ganadores_3pct = 0;
    char etiqueta;
    float monto, descuento, descuento_adicional;
    int cedula, ultimo_digito;
    
    printf("Ingrese la cantidad de clientes a verificar: ");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("\nCliente %d:\n", i);
        
        printf("Ingrese el monto de la factura: ");
        scanf("%f", &monto);
        
        printf("Ingrese la etiqueta del producto (M o A): ");
        scanf(" %c", &etiqueta);
        
        printf("Ingrese la cantidad de productos comprados: ");
        int cantidad;
        scanf("%d", &cantidad);
        
        printf("Ingrese la cédula del cliente: ");
        scanf("%d", &cedula);
        
        if(monto >= 1000 && monto <= 5000 && (etiqueta == 'M' || etiqueta == 'A') && cantidad >= 3) {
            descuento = monto / 2.0;
            
            ultimo_digito = cedula % 10;
            if(ultimo_digito % 2 == 0) {
                descuento_adicional = descuento * 0.05;
                ganadores_5pct++;
            } else {
                descuento_adicional = descuento * 0.03;
                ganadores_3pct++;
            }
            
            descuento += descuento_adicional;
            monto -= descuento;
            
            if(monto > factura_maxima) {
                factura_maxima = monto;
                ganadores_gif = 1;
            } else if(monto == factura_maxima) {
                ganadores_gif++;
            }
            
            ganadores_descuento++;
        }
    }
    
    float porcentaje_descuento = (float)ganadores_descuento / n * 100;
    printf("\nPorcentaje de clientes ganadores del descuento: %.2f%%\n", porcentaje_descuento);
    printf("Cantidad de ganadores de la GIF: %d\n", ganadores_gif);
    printf("Cantidad de ganadores del 5%% de descuento adicional: %d\n", ganadores_5pct);
    printf("Cantidad de ganadores del 3%% de descuento adicional: %d\n", ganadores_3pct);
    
    return 0;
}
