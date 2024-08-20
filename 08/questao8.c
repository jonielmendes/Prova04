#include <stdio.h>
#include <math.h>

int calcular_lado_terreno(int a, int b, int c) {
    if (c == 0) return 0;


    int area_casa = a * b;

  
    double area_terreno = (double)(area_casa * 100) / c;

 
    int lado_terreno = (int) sqrt(area_terreno);

    return lado_terreno;
}

int main() {
    int a, b, c;
    
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) break;
        int resultado = calcular_lado_terreno(a, b, c);
        printf("%d\n", resultado);
    }

    return 0;
}
