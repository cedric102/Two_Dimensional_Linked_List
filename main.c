#include <stdio.h>
#include <string.h>

#include <struct.h>
#include <remove_functions.h>
#include <print_functions.h>
#include <procedure_1.h>
#include <procedure_2.h>


int main()
{

    printf("\n ==> START PROCEDURE 1 : \n");
    procOne();
    printf(" ==> END PROCEDURE 1 : \n");

    printf("\n\n ||||||||||||||||||||||| \n\n");

    printf("\n ==> START PROCEDURE 2 : \n");
    procThree();
    printf(" ==> END PROCEDURE 2 : \n\n");

    return 0;

}
