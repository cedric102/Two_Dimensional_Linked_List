#include <struct.h>
#include <procedure_2.h>

listOfList* populateListOfList( int ii , int jj ) {

    listOfList * bulk = (listOfList *)malloc(sizeof(listOfList));
    listOfList * bulkHead = bulk;

    for( int i=0 ; i<ii ; i++ ) {
        printf("Bulk = %p\n" , (void *) bulk);
        bulk->innerList = (list2 *) malloc(sizeof(list2));
        list2 * inner = bulk->innerList;
        for( int j=0; j<jj; j++ ) {
            printf("%p , " , (void *)inner);
            int mod = ( i + j ) % jj;
            inner->next = (struct list2 *) malloc(sizeof(list2));
            inner->a = mod;
            char* txt = (char *) malloc(sizeof(char)*8);
            inner->text = (char *) malloc(sizeof(char)*8);
            txt = "TEXT : ";
            strcpy( inner->text , "TEXT : " );
            char s[2];
            sprintf(s, "%d", mod);
            strcat( inner->text , s );
            printf( "%s\n" , inner->text );
            inner = (list2 *)inner->next;
        }
        printf( "\n" );
        free(inner->next);
        inner->next=NULL;
        bulk->next = (struct listOfList *)malloc(sizeof(listOfList));
        bulk = (listOfList *)bulk->next;
    }
    free(bulk->next);
    bulk->next = NULL;


    bulk = bulkHead;

    return bulk;

}

void printListOfList( listOfList * bulk ) {

    while( bulk->next != NULL && bulk != NULL ) {
        list2 * inner = ( list2 * )bulk->innerList;
        while( inner->next != NULL && inner != NULL ) {
            printf("%p , %d , %s\n" , ( void * )inner , inner->a , inner->text );
            inner = ( list2 * )inner->next;
        }

        bulk = (listOfList *)bulk->next;

        printf( "\n" );

    }

}

void deleteListOfList( listOfList * bulk ) {

    listOfList * nextLol = bulk;
    while( nextLol != NULL ) {
        nextLol = (listOfList *)bulk->next;
        list * inner = (list *)bulk->innerList;
        list * nextInner = inner;
        while( nextInner != NULL ) {
            nextInner = (list *)inner->next;
            printf("Prev / Next Inner = %d , " , inner->a);
            inner->next = NULL;
            free(inner);
            printf("%d\n" , inner->a);
            inner = nextInner;
        }
        printf("Prev / Next Bulk = %d , " , bulk->a);
        bulk->next = NULL;
        bulk->innerList = NULL;
        free(bulk);
        printf("%d\n" , bulk->a);
        bulk = nextLol;
        printf( "\n" );
    }

}

void procThree() {

    printf("\n => Populate the List Of List : \n\n");
    listOfList * bulk = populateListOfList( 10 , 10 );

    printf("\n => Print the List Of List : \n\n");
    printListOfList(bulk);

    printf("\n => Delete the List Of List : \n\n");
    deleteListOfList( bulk );

}
