#include "functions.h"

char nomb[] = "Empresa";

int main(int argc, char const *argv[])
{   
   printf("Bienvenido ");
   printf("%s\n\n\n\n\n", nomb);
    j = 0;
    product *f;
    f = malloc(sizeof(product));
    if (f == NULL){
        error();
    }
    while(1){
        int i = 0;
        fflush(stdin);
        i = menu();
        switch(i){
            case 1: add_product(*f,); 
                    break;
        }
    }

    return 0;
}
