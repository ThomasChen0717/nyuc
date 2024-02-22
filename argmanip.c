#include <stdio.h>
#include <stdlib.h>
#include "argmanip.h"
#include <string.h>
#include <stdarg.h>


//References used: https://en.cppreference.com/w/c/variadic; https://en.cppreference.com/w/cpp/string/byte/memset; https://en.cppreference.com/w/c/string/byte/strcpy

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int)){
    char **list_manip = malloc(argc * (sizeof(char *) + 5)); 
    memset(list_manip, 0, argc * (sizeof(char *) + 5));
    char **list_manipHead = list_manip; 
    for(; *argv; argv++, list_manip++){
        *list_manip = malloc(strlen(*argv) * sizeof(char) + 5);
        *list_manip = strcpy(*list_manip, *argv);
        for(char *word = *list_manip; *word; word++) {
            *word = (*manip)(*word);
        }
    }
    return list_manipHead;
}

void free_copied_args(char **args, ...){
    va_list  valist;
    va_start(valist, args);
    va_list  first;
    va_copy(first, valist);
    char** argsHead =  args;
    for(; *args; args++){
        free(*args);
    }
    free(argsHead);
    while(va_arg(valist, char**) != NULL){
        char **word = va_arg(first, char**);
        char **wordHead = word;
        for(;*word; word++){
            free(*word);    
        }
        free(wordHead);
    }
    va_end(valist);
}