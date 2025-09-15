#include <stdio.h>
#include <assert.h>


#define MATRIX_SIZE_X 4
#define MATRIX_SIZE_Y 4
#define TRIANGULAR_SIZE 4




int* create_matrix(int size_y, int size_x);
int* get_matrix_address(int* matrix, int size_x, int y, int x);
void print_matrix(int* matrix, int size_y, int size_x);
void read_matrix(int* matrix, int size_y, int size_x);

int* create_triangular(int size);
int* get_triangular_address(int* triangular, int y, int x);
void print_triangular(int* triangular, int size);
void read_triangular(int* triangular, int size);




int main()
{
    /*
    int* matrix = create_matrix(MATRIX_SIZE_Y, MATRIX_SIZE_X);

    read_matrix(matrix, MATRIX_SIZE_Y, MATRIX_SIZE_X);

    print_matrix(matrix, MATRIX_SIZE_Y, MATRIX_SIZE_X);

    free(matrix);
    */

    int* triangular = create_triangular(TRIANGULAR_SIZE);

    read_triangular(triangular, TRIANGULAR_SIZE);

    print_triangular(triangular, TRIANGULAR_SIZE);

    free(triangular);

    return 0;
}


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


/*---------------------------------------------------*/


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
