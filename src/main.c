#include <greetings.h>
#include <stdio.h>

#include "shared.h"
#include "static.h"

int main(int argc , char *argv[])
{
    printf("Hello World from main!\n");
    greetings();
    printf("'%d'\n", shared_lib_function("Hola hola shared"));
    printf("'%d'\n", static_lib_function("Hola hola static"));
    return 0;
}