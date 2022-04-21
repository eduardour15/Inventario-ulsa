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
            case 1: 
                add_product(*f,j); 
                j++;
                j = (product *)realloc((product *)j, (i + 1) * sizeof(product));
                if (j == NULL){
                    error();
                }
                break;
            case 2: 
                update_prod(*f,j);
            case 3: 
                int obj = 0;
                obj = find_product();
                if(obj == NULL){
                    printf("Producto no encontrado");
                };
                delete_product(*f,obj,j);
            case 4:
                delete_product(*f,j);
            case 5:
            
        }
    }

    return 0;
}
