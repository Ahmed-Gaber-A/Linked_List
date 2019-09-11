#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"


int main()
{
    st_node ** LL_head;
    LL_head = create_list();
    printf("created\n");
    Insert_node( LL_head ,1);
   printf("1 Added\n");
    Insert_node( LL_head ,6);
    printf("2 Added\n");
    Insert_node( LL_head ,5);
    printf("3 Added\n");
    Insert_to_list(LL_head ,4,3);

    print_linkedlist( LL_head);
    printf("\n%d \n",calc_LstLength (LL_head));

    find_element(LL_head  , 6);
    return 0;
}
