#include "functions.h"

void error(){
    perror("Error\n");
    exit(1);
}

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
void update_prod(product *prod, int i)
{
    product aux;
    printf("\nACTUALIZANDO PRODUCTOS\n");
    printf("================================");
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", &aux.name);
    printf("\nCantidad de producto: ");
    scanf("%d", &aux._amount);
    printf("\nPrecio de venta: ");
    scanf("%d", &aux._price_selled);
    printf("\nPrecio de compra: ");
    scanf("%d", &aux._price_buyed);
    printf("\nCantidad ganada: ");
    scanf("%d", &aux._earned);
}
void delete_product(product *prod, int position, int i)
{
    if(position>=i+1){
        printf("No es posible eliminar el elemento");
    }else{
        for(int j=position-1;j<i-1;j++){
            strcpy(prod[j].name,prod[j+1].name);
            prod[j]._amount=prod[j+1]._amount;
            prod[j]._price_selled=prod[j+1]._price_selled;
            prod[j]._price_buyed=prod[j+1]._price_buyed;
            prod[j]._earned=prod[j+1]._earned;
        }
    }
    prod = (product *)realloc((product *)prod, (i - 1) * sizeof(product));
    if(!prod) error();
}