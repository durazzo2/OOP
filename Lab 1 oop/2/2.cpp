#include <stdio.h>
#include <math.h>

typedef struct Tocka {
    int x;
    int y;
} Tocka;

typedef struct Krug {
    Tocka centar;
    int radius;
} Krug;

double plostina(Krug k) {
    return 3.14 * k.radius * k.radius;
}


Krug najgolem_krug(Krug krugovi[], int n) {
    Krug najgolem = krugovi[0];
    double najgolem_plostina = plostina(krugovi[0]);

    for (int i = 1; i < n; i++) {
        double p = plostina(krugovi[i]);
        if (p > najgolem_plostina) {
            najgolem_plostina = p;
            najgolem = krugovi[i];
        }
    }

    return najgolem;
}

int main() {
    int n;
    scanf("%d", &n);

    Krug krugovi[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &krugovi[i].centar.x, &krugovi[i].centar.y, &krugovi[i].radius);
    }

    Krug najgolem = najgolem_krug(krugovi, n);
    printf("Largest circle has area of: %.2lf with centre: (%d,%d)", plostina(najgolem), najgolem.centar.x, najgolem.centar.y);

    return 0;
}