#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 6
#define MAX_CARRITO 20

typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

typedef struct {
    Producto producto;
    int cantidad;
} ItemCarrito;

Producto catalogo[MAX_PRODUCTOS] = {
    {1, "Pizza", 25000},
    {2, "Hamburguesa", 18000},
    {3, "Perro Caliente", 15000},
    {4, "Empanada", 3000},
    {5, "Gaseosa", 5000},
    {6, "Jugo Natural", 7000}
};

ItemCarrito carrito[MAX_CARRITO];
int numItems = 0;

void verMenuProductos() {
    printf("\n--- MENU DE PRODUCTOS ---\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("%d. %s - $%.2f\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
    }
}

void agregarAlCarrito() {
    int id, cantidad;
    verMenuProductos();
    printf("\nIngrese el ID del producto que desea agregar: ");
    scanf("%d", &id);

    int encontrado = -1;
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (catalogo[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese la cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("Cantidad inválida.\n");
    } else {
        carrito[numItems].producto = catalogo[encontrado];
        carrito[numItems].cantidad = cantidad;
        numItems++;
        printf("Producto agregado correctamente.\n");
    }
}

void verCarrito() {
    if (numItems == 0) {
        printf("\nEl carrito está vacío.\n");
        return;
    }

    printf("\n--- CARRITO ---\n");
    float subtotal = 0;
    int i = 0;
    while (i < numItems) {
        printf("%d x %s - $%.2f\n",
               carrito[i].cantidad,
               carrito[i].producto.nombre,
               carrito[i].producto.precio * carrito[i].cantidad);
        subtotal += carrito[i].producto.precio * carrito[i].cantidad;
        i++;
    }
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Domicilio: $5000.00\n");
    printf("TOTAL: $%.2f\n", subtotal + 5000.0);
}

void confirmarPedido() {
    if (numItems == 0) {
        printf("\nNo hay productos en el carrito.\n");
        return;
    }
    verCarrito();
    printf("\nPedido confirmado. ¡Gracias por su compra!\n");
    numItems = 0;
}

int main() {
    int opcion;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ver menú de productos\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: verMenuProductos(); break;
            case 2: agregarAlCarrito(); break;
            case 3: verCarrito(); break;
            case 4: confirmarPedido(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}
