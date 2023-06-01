#include "../item/item.h"
#include "utils.h"

void swap(Item *a, Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}