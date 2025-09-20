# 🛵 Aplicación de Domicilios en Consola (C)

Este proyecto es una aplicación en **C** que simula un flujo básico de pedidos a domicilio usando un menú interactivo.

## 🚀 Funcionalidades
- Menú principal con opciones:
  1. Ver menú de productos
  2. Agregar producto al carrito
  3. Ver carrito y total
  4. Confirmar pedido
  5. Salir
- Catálogo con 6 productos (id, nombre y precio).
- Carrito que valida existencia del producto y cantidad > 0.
- Cálculo de subtotal + costo fijo de domicilio.

## 🛠️ Tecnologías
- Lenguaje: **C**
- Ciclos utilizados: `for`, `while`, `do…while`
- Condicionales: `if/else`, `switch`

## ▶️ Ejecución
Compilar con:

```bash
gcc main.c -o domicilios
./domicilios
