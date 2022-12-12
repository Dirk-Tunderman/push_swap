#include "pushlib.h"
#include <limits.h>


int push_swap(int argc, char **argv)
{
    t_list *list_a;
    t_list *list_b;

    list_a = passing_list(&list_a, argc, argv);
    list_b = order_list(&list_a, &list_b);

    return (0);
}


int main(int argc, char **argv)
{
    push_swap(argc, argv);
    


}