#include <stdio.h>

#include <struct.h>
#include <remove_functions.h>

void remove_list(list *head , int entry ) {
    list **indirect = &head;
    list *prev = head;

    while((*indirect) != NULL ) {
        if((*indirect)->a == entry) {
            list *rem = *indirect;
            list *next = (list *)(*indirect)->next;
            list **nextAddr = (list **)&(*indirect)->next;
            *indirect = (*indirect)->next;
            printf("%d\n", rem->a);
            free(rem);
            printf("%d\n", rem->a);
            rem->next = NULL;
            rem = NULL;
        }
        prev = *indirect;
        indirect = (list **)&(*indirect)->next;
    }
}

void remove_list2(list **indirect , int entry ) {
    list *prev = *indirect;

    while((*indirect) != NULL ) {

        if((*indirect)->a == entry) {
            list *rem = *indirect;
            list *next = (list *)(*indirect)->next;
            list **nextAddr = (list **)&(*indirect)->next;
            printf("Remove Middle => %p,%p,%p\n", prev, *indirect, &(*(list *)(*indirect)->next ) );

            printf("Remove Middle => %p,%p,%p,%p\n", prev , prev->next , *indirect, (list *)(*indirect)->next );

            //  head = head->next
            *indirect = (list *)(*indirect)->next;

            printf("Remove Middle => %p,%p,%p,%p\n", prev , prev->next , *indirect, (list *)(*indirect)->next );

            printf("%d\n", rem->a);
            free(rem);
            printf("%d\n", rem->a);
            rem->next = NULL;
            rem = NULL;

        }
        prev = *indirect;
        indirect = (list **)&(*indirect)->next;
    }
}

