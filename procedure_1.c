#include <struct.h>
#include <procedure_1.h>
#include <print_functions.h>
#include <remove_functions.h>

list* populateList_Proc_1() {

    list *list1;
    list1 = (struct list *)malloc(sizeof(list));
    list *head = list1;
    list1->a = 0;
    list1->b.b=10;
    printf("0\n");
    for( int i=1; i<10; i++ ) {
        list1->next = (struct list *) malloc(sizeof(list));
        list1 = (list *)list1->next;
        list1->a = i%4;
        list1->b.b=i+10;
    }
    list1->next = NULL;

    list1 = head;

    return list1;

}

void deleteTheWholeList( listOfList * head ) {

    listOfList * prev = head;
    while (head != NULL) {
        prev=head;
        head = (list *)head->next;
        free(prev);
        prev=NULL;
    }
    free(head);

}

void procOne() {

    printf("\n => Populate the List : \n\n");
    list *list1 = populateList_Proc_1();
    list *head = list1;

    head=list1;
    printf("\n => Print List Address : \n\n");
    printListAddress( head );

    printf("\n => Print List Content : \n\n");
    head=list1;
    printListContent( head );

    int removeContent = 2;
    printf("\n => Remove element that contains a '%d' : \n\n" , removeContent);
    remove_list(head , 2);
    remove_list2(&head , 2);

    printf("\n => Print List Address After the Removal of content  '%d' : \n\n" , removeContent );
    head=list1;
    printListAddress( head );

    printf("\n => Print List Content After the Removal of content  '%d' : \n\n" , removeContent );
    head=list1;
    printListContent( head );

    printf("\n => Delete the Whole List : \n\n");
    deleteTheWholeList(head);

}
