#include "functions.h"

void error()
{
    perror("Error\n");
    exit(1);
}

void add_product(product *prod, int i)
{
    printf("Nombre del producto: ");
    fflush(stdin);
    scanf("%s", prod[i].name);
    printf("\nVentas totales del producto: ");
    fflush(stdin);
    scanf("%d", &prod[i]._amount);
    printf("\nPrecio de compra: ");
    fflush(stdin);
    scanf("%d", &prod[i]._price_buyed);
    printf("\nPrecio de venta: ");
    fflush(stdin);
    scanf("%d", &prod[i]._price_selled);
    prod[i]._earned = prod[i]._amount * (prod[i]._price_selled - prod[i]._price_buyed);
}

int find_product(product *prod, int i)
{
    int pos = 0;
    char aux[256];
    print_products(prod, i);
    printf("Escriba el nombre del producto a actualizar: ");
    fflush(stdin);
    scanf("%s", aux);
    for (int j = 0; i <= i; j++)
    {
        if (strcmp(prod[j].name, aux) == 0)
        {
            return j;
        }
        return -1;
    }
}
void update_product(product *prod, int i)
{
    product aux;
    int auxPosition = 0;
    auxPosition = find_product(prod, i);
    if (auxPosition == -1)
    {
        printf("El producto no fue encontrado (Verifica que las mayusculas esten correctas)\n");
        return;
    }
    else
    {
        printf("\nACTUALIZANDO PRODUCTOS\n");

        printf("Nombre: ");
        fflush(stdin);
        scanf("%s", aux.name);
        printf("\nVentas totales de producto: ");
        scanf("%d", &aux._amount);
        printf("\nPrecio de venta: ");
        scanf("%d", &aux._price_selled);
        printf("\nPrecio de compra: ");
        scanf("%d", &aux._price_buyed);
        printf("\nCantidad ganada: ");
        scanf("%d", &aux._earned);
        strcpy(prod[auxPosition].name, aux.name);
        prod[auxPosition]._amount = aux._amount;
        prod[auxPosition]._price_selled = aux._price_selled;
        prod[auxPosition]._price_buyed = aux._price_buyed;
        prod[auxPosition]._earned = aux._earned;
    }
}
void delete_product(product *prod, int i)
{
    int position = 0;
    position = find_product(prod, i);
    if (position == -1)
    {
        printf("El producto no fue encontrado (Verifica que las mayusculas esten correctas)\n");
        return;
    }
    else
    {
        for (int j = position - 1; j <= i - 1; j++)
        {
            strcpy(prod[j].name, prod[j + 1].name);
            prod[j]._amount = prod[j + 1]._amount;
            prod[j]._price_selled = prod[j + 1]._price_selled;
            prod[j]._price_buyed = prod[j + 1]._price_buyed;
            prod[j]._earned = prod[j + 1]._earned;
        }
    }
}

void delete_all(product *prod, int i)
{
}

void print_products(product *prod, int i)
{
    printf("\tTabala de productos\n");
    printf("\tDescripcion\t Ventas\t Precio de compra\t Precio de venta\t Ganancias\n");
    for (int j = 0; j < i; j++)
    {
        printf("\t%s\t%d\t%d\t%d\t%d\n", prod[j].name, prod[j]._amount, prod[j]._price_selled, prod[j]._price_buyed, prod[j]._earned);
    }
}

int menu()
{
    int opc;
    printf("\t---------MENU---------\n");
    printf("\t1.Ingresar producto nuevo\n");
    printf("\t2.Actualizar producto existente\n");
    printf("\t3.Borrar producto\n");
    printf("\t4.Borrar todos los productos\n");
    printf("\t5.Mostrar los productos\n");
    printf("\t6.Salir\n\t");
    scanf("%d", &opc);
    return opc;
}

void most_selled_item(product *prod, int i)
{
    int may = 0;
    for (int j = 0; j < i; j++)
    {
        if (prod[j]._amount > may)
            may = j;
    }
    printf("\nEl producto con mas ventas es: ");
    printf("\tDescripcion\tVentas\tPrecio de compra\tPrecio de venta\tGanancias\n");
    printf("\t%s\t%d\t%d\t%d\t%d", prod[may].name, prod[may]._amount, prod[may]._price_selled, prod[may]._price_buyed, prod[may]._earned);
}