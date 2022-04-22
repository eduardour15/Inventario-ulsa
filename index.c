#include "functions.h"

int main(int argc, char const *argv[])
{
    product *almc = NULL;
    int contador = 0, aux_contador = 0, opc;

    for (;;)
    {
        switch (menu())
        {
        case 1:
            if (contador == 0)
            {
                almc = (product *)malloc(sizeof(product));
                if (almc == NULL)
                    error();
            }
            else
            {
                almc = (product *)realloc(almc, (contador + 1) * (sizeof(product)));
                if (almc == NULL)
                    error();
            }
            add_product(almc, contador);
            contador++;
            break;
        case 2:
            aux_contador = find_product(almc, contador);
            if (aux_contador == -1)
            {
                printf("\n\tEL PRODUCTO NO FUE ENCONTRADO\n");
                break;
            }
            else
            {
                update_product(almc, aux_contador);
            }
            printf("\n\tEL PRODUCTO HA SIDO ACTUALIZADO\n");
            break;
        case 3:
            aux_contador = -1;
            aux_contador = find_product(almc, contador);
            if (aux_contador == -1)
            {
                printf("\n\tEL PRODUCTO NO FUE ENCONTRADO\n");
                break;
            }
            else
            {
                delete_product(almc, aux_contador, contador);
                contador--;
                almc = realloc(almc, contador * (sizeof(product)));
                if (almc == NULL)
                    error();
            }
            break;
        case 4:
            delete_all(almc, contador);
            contador = 0;
            break;
        case 5:
            print_products(almc, contador);
            break;
        case 6:
            system("clear");
            printf("\t1. Producto mas vendido\n");
            printf("\t2. Ganancias generales de la empresa\n");
            printf("\t3. Salir\n\t");
            scanf("%d", &opc);
            if (opc == 1)
            {
                most_selled_item(almc, contador);
            }
            else if (opc == 2)
            {
                profits(almc, contador);
            }
            else if (opc == 3)
            {
                break;
            }
            else
            {
                printf("\n\tOPCION INCORRECTA \n");
            }
            break;
        case 7:
            printf("\t\nADIOOOS!!!\n");
            exit(-1);
            break;
        default:
            printf("\n\tOPCION INCORRECTA\n");
            break;
        }
        printf("\n\tPULSE UNA TECLA PARA CONTINUAR\n");
        fflush(stdin);
        getchar();
        getchar();
    }

    return 0;
}
