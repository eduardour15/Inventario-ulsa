#include "functions.h"

void add_product(product *prod, int i)
{
    printf("Nombre del producto: ");
    fflush(stdin);
    scanf("%s", prod[i].name);
    printf("\nCantidad de producto: ");
    fflush(stdin);
    scanf("%d", prod[i]._amount);
    printf("\nPrecio de compra: ");
    fflush(stdin);
    scanf("%d", prod[i]._price_buyed);
    printf("\nPrecio de venta: ");
    fflush(stdin);
    scanf("%d", prod[i]._price_selled);
    printf("\nGanancias de producto: ");
    fflush(stdin);
    scanf("%d", prod[i]._earned);
}

int find_product(product *prod, int i)
{
    int pos = 0;
    char aux[256];

    printf("Escriba el nombre del producot a actualizar");
    fflush(stdin);
    scanf("%s", aux);
    for (int j = 0; i < i; j++)
    {
        if (strcmp(prod[j].name, aux) == 0)
        {
            return j;
        }
        return -1;
    }
}