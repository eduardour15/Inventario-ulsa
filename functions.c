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
void update_prod(product *prod, int i)
{
    product aux;
    int auxPosition = 0;
    auxPosition = find_product(prod, i);
    if (auxPosition == -1)
    {
        printf("El producto no fue encontrado (Verifica que las mayusculas esten correctas\n");
        return;
    }
    else
    {
        printf("\nACTUALIZANDO PRODUCTOS\n");
        printf("================================");
        printf("Nombre: ");
        fflush(stdin);
        scanf("%s", &aux.name);
        printf("\nVentas totales de producto: ");
        scanf("%d", &aux._amount);
        printf("\nPrecio de venta: ");
        scanf("%d", &aux._price_selled);
        printf("\nPrecio de compra: ");
        scanf("%d", &aux._price_buyed);
        printf("\nCantidad ganada: ");
        scanf("%d", &aux._earned);
        strcpy(prod[auxPosition].name,aux.name);
        prod[auxPosition]._amount=aux._amount;
        prod[auxPosition]._price_selled=aux._price_selled;
        prod[auxPosition]._price_buyed=aux._price_buyed;
        prod[auxPosition]._earned=aux._earned;
    }
}
void delete_product(product *prod, int position, int i)
{
    if (position >= i + 1)
    {
        printf("No es posible eliminar el elemento");
    }
    else
    {
        for (int j = position - 1; j < i - 1; j++)
        {
            strcpy(prod[j].name, prod[j + 1].name);
            prod[j]._amount = prod[j + 1]._amount;
            prod[j]._price_selled = prod[j + 1]._price_selled;
            prod[j]._price_buyed = prod[j + 1]._price_buyed;
            prod[j]._earned = prod[j + 1]._earned;
        }
    }
    prod = (product *)realloc((product *)prod, (i - 1) * sizeof(product));
    if (!prod)
        error();
}

void delele_all(product *prod, int i)
{
}

void print_products(product *prod, int i)
{
    printf("\tTabala de productos\n");
    printf("\tDescripcion\tVentas\tPrecio de compra\tPrecio de venta\tGanancias\n");
    for (int j = 0; j < i; j++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d", prod[j].name, prod[j]._amount, prod[j]._price_selled, prod[j]._price_buyed, prod[j]._earned);
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
    printf("\t6.Salir\n");
    scanf("%d", &opc);
    return opc;
}

void most_selled_item(product *prod, int i)
{
    int may = 0;
    for (int j = 0; j < i; j++)
    {
        if (prod[j]._amount > may)
            may = prod[j]._amount;
    }
}