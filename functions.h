#ifndef _LIBRERIA
#define _LIBRERIA
#define SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    char name[SIZE];
    int _amount;
    int _price_buyed;
    int _price_selled;
    int _earned;
} product;

void add_product(product *prod, int i);
int find_product(product *prod, int i);
void update_product(product *prod, int i);
void delete_product(product *prod, int position, int i);

#endif
