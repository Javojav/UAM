#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include "list.h"

int main(){
	List *lista1, *lista2, *lista3;
    int i, *aux;
    fprintf(stdout, "Creating list 1... ");
	if(!(lista1=list_new(int_free, int_copy, int_print))){
        return 1;
    }
    printf("%d\n", list_size(lista1));
    fprintf(stdout, "Inserting elements into list...\n");
    for(i=0; i!=11; i++){
        if(i%2==0){
            if(list_pushBack(lista1, &i)==ERROR){
                list_free(lista1);
                return 1;
            }
        }
    }
    fprintf(stdout, "Printing list 1:\n");
    list_print(stdout, lista1);
    fprintf(stdout, "\nCreating list 2... ");
	if(!(lista2=list_new(int_free, int_copy, int_print))){
        list_free(lista1);
        return 1;
    }
    printf("%d", list_size(lista2));
    fprintf(stdout, "Inserting elements into list...\n");
    for(i=1; i!=10; i++){
        if(i%2!=0){
            if(list_pushBack(lista2, &i)==ERROR){
                list_free(lista1);
                list_free(lista2);
                return 1;
            }           
        }
    }
    fprintf(stdout, "Printing list 2:\n");
    list_print(stdout, lista2);
    fprintf(stdout, "\nCreating list 3... ");
	if(!(lista3=list_new(int_free, int_copy, int_print))){
        list_free(lista1);
        list_free(lista2);
        return 1;
    }
    printf("%d\n", list_size(lista3));
    fprintf(stdout, "Combining elements from list 1 and list 2 into list 3...\n");
    for(i=0; i!=11; i++){
        if(i%2==0){
            aux=list_popFront(lista1);
            fprintf(stdout, "Extracted element from list 1: %d\n", aux);
        }
        else{
            aux=list_popFront(lista2);
            fprintf(stdout, "Extracted element from list 2: %d\n", aux);
        }
        if(list_pushBack(lista3, aux)==ERROR){
            list_free(lista1);
            list_free(lista2);
            list_free(lista3);
            return 1;
        }
        free(aux);        
    }
    fprintf(stdout, "Printing list 1:\n");
    list_print(stdout, lista1);
    fprintf(stdout, "Printing list 2:\n");
    list_print(stdout, lista2);
    fprintf(stdout, "Printing list 3:\n"); 
    list_print(stdout, lista3);
    fprintf(stdout, "\nFreeing memory..."); 
    list_free(lista1);
    list_free(lista2);
    list_free(lista3);
    return 0;     

}