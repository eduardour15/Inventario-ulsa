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
    for (int j = 0; j <= i; j++)
    {
        printf("\n\t%s\n",prod[j].name);
        if (strcmp(prod[j].name, aux) == 0)
        {
            return j;
        }
    }
    return -1;
}
void update_product(product *prod, int i)
{
    product aux;
    int auxPosition = 0;
    printf("\n\n\t\tposition: %d  i: %d\n\n",auxPosition,i);
    auxPosition = find_product(prod, i);
    printf("\n\n\t\tposition: %d  i: %d\n\n",auxPosition,i);
    if (auxPosition == -1)
    {
        printf("El producto no fue encontrado (Verifica que las mayusculas esten correctas)\n");
        return;
    }
    else
    {
        printf("\nACTUALIZANDO PRODUCTOS\n");

        printf("Nombre del producto: ");
        fflush(stdin);
        scanf("%s", aux.name);
        printf("\nVentas totales del producto: ");
        fflush(stdin);
        scanf("%d", &aux._amount);
        printf("\nPrecio de compra: ");
        fflush(stdin);
        scanf("%d", &aux._price_buyed);
        printf("\nPrecio de venta: ");
        fflush(stdin);
        scanf("%d", &aux._price_selled);
        aux._earned = aux._amount * (aux._price_selled - aux._price_buyed);
        strcpy(prod[auxPosition].name, aux.name);
        prod[auxPosition]._amount = aux._amount;
        prod[auxPosition]._price_selled = aux._price_selled;
        prod[auxPosition]._price_buyed = aux._price_buyed;
        prod[auxPosition]._earned = aux._earned;
    }
}
int delete_product(product *prod, int i)
{
    int position = 0;
    printf("\n\n\t\tposition: %d  i: %d\n\n",position,i);
    position = find_product(prod, i);
    printf("\n\n\t\tposition: %d  i: %d\n\n",position,i);
    if (position == -1)
    {
        printf("El producto no fue encontrado (Verifica que las mayusculas esten correctas)\n");
        return -1;
    }
    else
    {
        for (int j = position - 1; j <= i ; j++)
        {
            strcpy(prod[j].name, prod[j + 1].name);
            prod[j]._amount = prod[j + 1]._amount;
            prod[j]._price_selled = prod[j + 1]._price_selled;
            prod[j]._price_buyed = prod[j + 1]._price_buyed;
            prod[j]._earned = prod[j + 1]._earned;
        }
        return 1;

    }
}

void delete_all(product *prod, int i)
{

    prod = (product *)realloc(prod, sizeof(product));
    printf("\n\tTODO LOS PRODUCTOS HAN SIDO BORRADOS\n");
}

void print_products(product *prod, int i)
{
    printf("\n\tTabala de productos\n");
    printf("\tDescripcion\t Ventas\t Precio de compra\t Precio de venta\t Ganancias\n");
    for (int j = 0; j < i; j++)
    {
        printf("\t%s\t%d\t%d\t%d\t%d\n", prod[j].name, prod[j]._amount, prod[j]._price_selled, prod[j]._price_buyed, prod[j]._earned);
    }
}

int menu()
{
    int opc;
    system("clear");
    printf("\n\t---------MENU---------\n");
    printf("\t1.Ingresar producto nuevo\n");
    printf("\t2.Actualizar producto existente\n");
    printf("\t3.Borrar producto\n");
    printf("\t4.Borrar todos los productos\n");
    printf("\t5.Mostrar los productos\n");
    printf("\t6.Informenes\n");
    printf("\t7.Salir\n\t");
    scanf("%d", &opc);
    return opc;
}

void most_selled_item(product *prod, int i)
{
    int may = 0, position = 0;
    for (int j = 0; j < i; j++)
    {
        if (prod[j]._amount > may)
        {
            may = prod[j]._amount;
            position = j;
        }
    }
    printf("\nEl producto con mas ventas es: ");
    printf("\tDescripcion\tVentas\tPrecio de compra\tPrecio de venta\tGanancias\n");
    printf("\t%s\t%d\t%d\t%d\t%d", prod[position].name, prod[position]._amount, prod[position]._price_selled, prod[position]._price_buyed, prod[position]._earned);
}

void profits(product *prod, int i)
{
    int adding = 0;
    for (int j = 0; j <= i; j++)
    {
        adding += prod[j]._earned;
    }
    printf("Las ganancias totales es: %d", adding);
}