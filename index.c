#include "functions.h"

char nomb[] = "Empresa";

int main(int argc, char const *argv[])
{
    printf("Bienvenido ");
    printf("%s\n\n\n\n\n", nomb);
    int j = 0;
    char wait;
    int i = 0, opc = 0, dele = -5;
    product *f;
    f = (product *)malloc(sizeof(product));
    if (f == NULL)
    {
        error();
    }
    while (1)
    {
        fflush(stdin);
        i = menu();
        switch (i)
        {
        case 1:
            add_product(f, j);
            j++;
            f = (product *)realloc((product *)f, (j + 1) * sizeof(product));
            if (f == NULL)
            {
                error();
            }
            break;

        case 2:
            update_product(f, j);
            break;

        case 3:

            dele = delete_product(f, j);
            if (dele == 1)
            {
                j--;
                f = (product *)realloc(f, j * sizeof(product));
                printf("\n\tPRODUCTO ELIMINADO\n");
                if (!f)
                    error();
                break;
            }else{
                break;
            }

        case 4:
            delete_all(f, j);
            j = 0;
            free(f);
            break;

        case 5:
            print_products(f, j);
            break;
        case 6:
            system("clear");
            printf("\t1. Producto mas vendido\n");
            printf("\t2. Ganancias generales de la empresa\n");
            printf("\t3. Salir\n\t");
            scanf("%d", &opc);
            if (opc == 1)
            {
                most_selled_item(f, j);
            }
            else if (opc == 2)
            {
                profits(f, j);
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
        }
        printf("\n\tPULSE UNA TECLA PARA CONTINUAR\n");
        fflush(stdin);
        getchar();
        getchar();
    }

    return 0;
}
