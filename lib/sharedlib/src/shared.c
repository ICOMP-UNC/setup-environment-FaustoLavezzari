#include "shared.h"
#include <stdio.h>
#include <string.h>

int shared_lib_function(char* msg)
{
    printf("I am a shared lib that receives '%s', and return its length!", msg);
    return strlen(msg);
}