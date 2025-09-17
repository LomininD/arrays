#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H


#include <stdio.h>
#include <assert.h>


int my_puts(const char* string);
const char* strchr(const char* string, const char symbol);
int my_strlen(const char* s);
char* dynamic_strcat(char* string_1, char* string_2);
int my_atoi(const char* s);
char* my_strdup(const char* s);
char my_fgetc(FILE* stream);
char* my_fgets(char* line, int maxline, FILE* fp);
char* my_strcpy(char* location, const char* string);

char* my_strcat(char* string_1, char* string_2);

#endif
