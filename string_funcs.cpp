#include "string_funcs.h"


enum numtype
{
    NEGATIVE = -1,
    POSITIVE = 1
};


/*

int main()
{
    
    char s1[10] = "abc";

    printf("sizeof %d\n", (int) sizeof(s1)); //????

    char s2[] = "ab";

    char* res = my_strcat(s1, s2);

    my_puts(res);



    char s1[] = "ABC";
    char* s2 = my_strdup(s1);

    my_puts(s2);

    free(s2);

    return 0;


}
*/



int my_puts(const char* string)
{
    assert(string != NULL);

    while(*string != '\0' && *string != '\n')
    {
        putchar(*string);
        string++;
    }

    putchar('\n');

    return 0;
}


const char* strchr(const char* string, const char symbol)
{
    assert(string != NULL);

    while (*string != '\0' && *string != symbol)
    {
        string++;
    }

    //const char* symbol_ptr = string;

    return string;
}


int my_strlen(const char* s)
{
    assert(s != NULL);

    int n = 0;
    for (n = 0; *s != '\0'; s++)
        n++;

    return n;
}


char* dynamic_strcat(char* string_1, char* string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    int len1 = my_strlen(string_1);
    int len2 = my_strlen(string_2);
    int total_len = len1 + len2 + 1; // '\0' is also should be counted

    printf("%d, %d\n", len1, len2);

    char* res_ptr = (char*) calloc((size_t) total_len, sizeof(*string_1));

    for (int i = 0; i < total_len; i++)
    {
        if (i < len1)
            *(res_ptr + i) = *(string_1 + i);
        else
            *(res_ptr + i) = *(string_2 + (i - len1));
    }

    return res_ptr;
}

char* my_strcat(char* string_1, char* string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    int len_1 = my_strlen(string_1);

    printf("len_of_str %d, sizeof %d\n", len_1, (int) sizeof(string_1)); // ????

    char c = '0';
    int i = 0;

    while ((c = *(string_2 + i)) != '\0')
    {
        *(string_1 + len_1 + i) = c;
        i++;
    }

    return string_1;
}


int my_atoi(const char* s)
{
    assert(s != NULL);

    numtype num_type = POSITIVE;
    int result_number = 0;

    if (*s == '-')
    {
        num_type = NEGATIVE;
        s++;
    }
    else if (*s == '+')
    {
        s++;
    }

    if (*s < '0' || *s > '9')
        return 0;

    for (int i = 0; *(s + i) != '\0'; i++)
    {
        result_number = result_number * 10 + *(s + i) - '0';
    }

    result_number *= num_type;

    return result_number;
}


char my_fgetc(FILE* stream)
{
    assert(stream != NULL);

    char symbol = '0';

    size_t success = fread(&symbol, sizeof(char), 1, stream);
    //printf("%d\n", (int) success);

    if (success == 1)
    {
        //printf("%c\n", symbol);

        return symbol;
    }
    else
    {
        return EOF;
    }
}


char* my_fgets(char* line, int maxline, FILE* fp)
{
    assert(line != NULL);
    assert(fp != NULL);

    char a = '\0';
    int i = 0;

    while((a = my_fgetc(fp)) != '\n' && i != maxline-1)
    {
        *(line + i) = a;
        i++;
    }

    *(line + i) = '\0';

    return line;
}


char* my_strcpy(char* location, const char* string)
{
    assert(location != NULL);
    assert(string != NULL);

    int str_ind = 0;

    while((*(location + str_ind) = *(string + str_ind)) != '\0')
        str_ind++;

    return location;
}


char* my_strdup(const char* s)
{
    assert(s != NULL);

    char* memory_ptr = (char*)calloc((size_t) my_strlen(s) + 1, sizeof(*s));

    assert(memory_ptr != NULL);

    memory_ptr = my_strcpy(memory_ptr, s);

    return memory_ptr;
}


