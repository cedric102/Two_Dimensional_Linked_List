#include <stdio.h>

#include <struct.h>
#include <print_functions.h>

void printListAddress( list *head ) {

    while( head != NULL ) {
        printf( "%p , %p\n" , (list *)head , (list *)head->next );
        head = head->next;
    }
    printf( "\n" );
}

void printListContent( list *head ) {

    while (head != NULL) {
        printf("%d,%d\n" , head->a, head->b.b);
        head = (list *)head->next;
    }
    printf( "\n" );
}

