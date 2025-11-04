#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Funcion para ingresar un producto
void ingresarProducto(char id[10][10], char nombre[10][20], float precio[10], int stock[10], int *cont) {
    if (*cont < 10) {
        printf("Ingrese el ID del producto %d: ", *cont);
        scanf("%s", id[*cont]);
        fflush(stdin);
        
        printf("Ingrese el nombre del producto %d: ", *cont);
        fgets(nombre[*cont], 20, stdin);
        int len = strlen(nombre[*cont]) - 1;
        nombre[*cont][len] = '\0';
        
        printf("Ingrese el precio del producto %d: ", *cont);
        scanf("%f", &precio[*cont]);
        
        printf("Ingrese el stock del producto %d: ", *cont);
        scanf("%d", &stock[*cont]);
        
        (*cont)++;
    } else {
        printf("Se ha alcanzado el limite de productos (10)\n");
    }
}

// Funcion para calcular el precio total del inventario
float calcularTotalInventario(float precio[10], int stock[10], int cont) {
    float total = 0;
    for (int i = 0; i < cont; i++) {
        total += precio[i] * stock[i];
    }
    return total;
}

// Funcion para encontrar el producto más caro
void productoMasCaro(float precio[10], char nombre[10][20], int cont) {
    float max = precio[0];
    int index = 0;
    for (int i = 1; i < cont; i++) {
        if (precio[i] > max) {
            max = precio[i];
            index = i;
        }
    }
    printf("El producto mas caro es: %s con un precio de %.2f\n", nombre[index], max);
}

// Funcion para encontrar el producto más barato
void productoMasBarato(float precio[10], char nombre[10][20], int cont) {
    float min = precio[0];
    int index = 0;
    for (int i = 1; i < cont; i++) {
        if (precio[i] < min) {
            min = precio[i];
            index = i;
        }
    }
    printf("El producto mas barato es: %s con un precio de %.2f\n", nombre[index], min);
}

// Funcion para calcular el precio promedio
float calcularPrecioPromedio(float precio[10], int cont) {
    float total = 0;
    for (int i = 0; i < cont; i++) {
        total += precio[i];
    }
    return total / cont;
}

// Funcion para buscar un producto por su nombre
void buscarProducto(char nombre[10][20], float precio[10], int cont, char nombreBuscado[20]) {
    for (int i = 0; i < cont; i++) {
        if (strcmp(nombre[i], nombreBuscado) == 0) {
            printf("Producto encontrado: %s, Precio: %.2f\n", nombre[i], precio[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
