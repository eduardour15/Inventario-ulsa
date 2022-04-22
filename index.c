#include "functions.h"

char nomb[] = "Empresa";

int main(int argc, char const *argv[])
{
    printf("Bienvenido ");
    printf("%s\n\n\n\n\n", nomb);
    int j = 0;

    int i = 0;
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
            delete_product(f, j);
            j--;
            f = (product *)realloc(f, j * sizeof(product));
            if (!f)
                error();
            break;

        case 4:
            delete_all(f, j);
            break;

        case 5:
            print_products(f, j);
            break;
            
        }
    }

    return 0;
}
