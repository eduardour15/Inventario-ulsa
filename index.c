#include "functions.h"

char nomb[] = "Empresa";

int main(int argc, char const *argv[])
{   
   printf("Bienvenido ");
   printf("%s\n\n\n\n\n", nomb);
    int j = 0;
    int obj;
    product *f;
    f = (product*)malloc(sizeof(product));
    if (f == NULL){
        error();
    }
    while(1){
        int i = 0;
        fflush(stdin);
        i = menu();
        switch(i){
            case 1: 
                add_product(f,j); 
                j++;
                f = (product *)realloc((product *)f, (j + 1) * sizeof(product));
                if (f == NULL){
                    error();
                }
                break;
            case 2: 
                update_product(f,j);
                break;
            case 3: 
                obj = 0;
                obj = find_product(f,j);
                if(obj == -1){
                    printf("Producto no encontrado");
                };
                delete_product(f,obj,j);
                break;
            case 4:
                delete_all(f,j);
                break;
            case 5:
                break;
                
            
        }
    }

    return 0;
}
