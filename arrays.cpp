#include "string_funcs.h"
#include "sys/stat.h"
#include <stdlib.h>


//TODO: assert files, calloc????


enum sizes {MATRIX_SIZE_X = 4,
            MATRIX_SIZE_Y = 4,
            TRIANGULAR_SIZE = 4,
            POINTER_ARR_SIZE = 4,
            DIAMOND_ARR_SIZE = 4};


int* create_matrix(int size_y, int size_x);
int* get_matrix_address(int* matrix, int size_x, int y, int x);
void print_matrix(int* matrix, int size_y, int size_x);
void read_matrix(int* matrix, int size_y, int size_x);

int* create_triangular(int size);
int* get_triangular_address(int* triangular, int y, int x);
void print_triangular(int* triangular, int size);
void read_triangular(int* triangular, int size);

/*
int* create_diamond_arr(int size);
void print_diamond_arr(int* diamond_arr, int size);
int* get_diamond_arr_address(int* diamond_arr, int y, int x, int size);
*/

char** create_pointer_arr(int size);
void read_pointer_arr(char** arr, int size);
void print_pointer_arr(char**, int size);
void terminate_pointer_arr(char** arr);
size_t get_file_size(FILE* fp);


int main()
{
    /*
    int* matrix = create_matrix(MATRIX_SIZE_Y, MATRIX_SIZE_X);

    read_matrix(matrix, MATRIX_SIZE_Y, MATRIX_SIZE_X);

    print_matrix(matrix, MATRIX_SIZE_Y, MATRIX_SIZE_X);

    free(matrix);
    */

    /*
    int* triangular = create_triangular(TRIANGULAR_SIZE);

    read_triangular(triangular, TRIANGULAR_SIZE);

    print_triangular(triangular, TRIANGULAR_SIZE);

    free(triangular);
    */

    char** pointer_arr = create_pointer_arr(POINTER_ARR_SIZE);

    read_pointer_arr(pointer_arr, POINTER_ARR_SIZE);

    print_pointer_arr(pointer_arr, POINTER_ARR_SIZE);

    terminate_pointer_arr(pointer_arr);


    return 0;
}


/*-----------------------------------------------*/
//matrix funcs


int* create_matrix(int size_y, int size_x)
{
    int* matrix = (int *) calloc((size_t) (size_y * size_x), sizeof(int));
    return matrix;
}


void print_matrix(int* matrix, int size_y, int size_x)
{
    assert(matrix != NULL);

    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            int el = *get_matrix_address(matrix, size_x, y, x);
            printf("%d ", el);
        }

        printf("\n");
    }
}


int* get_matrix_address(int* matrix, int size_x, int y, int x)
{
    assert(matrix != NULL);

    return matrix + size_x * y + x;
}


void read_matrix(int* matrix, int size_y, int size_x)
{
    assert(matrix != NULL);

    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            int el = 0;
            scanf("%d", &el);

            //printf("\nread el: %d\n", el);

            *(get_matrix_address(matrix, size_x, y, x)) = el;
        }

        printf("\n");
    }
}


/*-----------------------------------------------*/
// triangular funcs


int* create_triangular(int size)
{
    int number_of_els = 0;

    for(int i = 0; i < size; i++)
    {
        number_of_els += i;
    }

    int* triangular = (int *) calloc((size_t)(number_of_els), sizeof(int));

    return triangular;
}


int* get_triangular_address(int* triangular, int y, int x)
{
    assert(triangular != NULL);

    return triangular + y * (y + 1) / 2 + x; // because y0 = 0
}


void print_triangular(int* triangular, int size)
{
    assert(triangular != NULL);

    int row_size = 1;

    for (int y = 0; y < size; y++)
    {
        for(int x = 0; x < row_size; x++)
        {
            int el = *get_triangular_address(triangular, y, x);
            printf("%d ", el);
        }

        printf("\n");
        row_size++;
    }
}


void read_triangular(int* triangular, int size)
{
    assert(triangular != NULL);
    int row_size = 1;

    for (int y = 0; y < size; y++)
    {
        for(int x = 0; x < row_size; x++)
        {
            int el = 0;
            scanf("%d", &el);

            //printf("\nread el: %d\n", el);

            *(get_triangular_address(triangular, y, x)) = el;
        }

        printf("\n");
        row_size++;
    }
}


/*-----------------------------------------------*/
/*
//diamond_arr funcs


// size argument of diamond_arr represents the number of rows in this array
int* create_diamond_arr(int size)
{
    int max_row_len = size - (1 - size % 2);
    size_t total_len = 2 * (size / 2 + size % 2) *
                        (size / 2 + size % 2) -
                        max_row_len * (size % 2);

    int* diamond_arr = (int*) calloc(total_len, sizeof(int));

    return diamond_arr;
}

*/
/*-----------------------------------------------*/
//pointer_arr funcs


char** create_pointer_arr(int size)
{
    char** arr = (char**) calloc((size_t) size, sizeof(arr[0]));

    return arr;
}


size_t get_file_size(FILE* fp)
{
    assert(fp != NULL);

    struct stat buf = {};
    fstat(fileno(fp), &buf);
    size_t sym_num = buf.st_size / sizeof(char);

    return sym_num;
}


void read_pointer_arr(char** arr, int size)
{
    assert(arr != NULL);

    FILE* fp = fopen("text.txt", "r");

    assert(fp != NULL);

    size_t sym_num = get_file_size(fp);
    char* str = (char*) calloc(sym_num + 1, sizeof(char));

    assert(str != NULL);

    //printf("sym_num before: %d\n", sym_num);

    sym_num = fread(str, sizeof(char), sym_num, fp);

    //printf("sym_num after: %d\n", sym_num);
    //puts(str);

    *arr = str;
    int str_ind = 0;

    for (int i = 1; i < size; i++)
    {
        while(*(str + str_ind) != '\n')
            str_ind++;

        str_ind++;
        *(arr + i) = str + str_ind;

        //printf("i = %d str_ind = %d\n", i, str_ind);
    }

    fclose(fp);
}


void print_pointer_arr(char** arr, int size)
{
    assert(arr != NULL);

    for (int i = 0; i < size; i++)
    {
        my_puts(*(arr + i));
    }
}


void terminate_pointer_arr(char** arr)
{
    assert(arr != NULL);

    free(*arr);
    free(arr);
}


