// проверка кососимметриности матрицы.
// сгенерировать матрицу расхождений, где нули записаны на местах кососимметричных элементов.
// условие a[j][k] = -a[k][j]

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t **Matrix;

Matrix CreatingMatrix(int32_t size)
{
    Matrix matrix = (Matrix)malloc(sizeof(int32_t *) * size);
    for (int32_t i = 0; i < size; ++i)
    {
        matrix[i] = (int32_t *)malloc(sizeof(int32_t *) * size);
    }
    return matrix;
}

void FreeingMemory(Matrix matrix, int32_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int args, char *argv[])
{
    FILE *file;
    int32_t matrix_size;

    // open file
    if ((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Не удалось открыть файл \n");
        return 0;
    }

    // find line size
    fscanf(file, "%d", &matrix_size);

    Matrix matrix = CreatingMatrix(matrix_size);

    // memory allocation error
    if (!matrix)
    {
        fprintf(stderr, "Failed to allocate memory for matrix\n");
        abort();
    }

    for (int32_t i = 0; i < matrix_size; ++i)
    {
        for (int32_t j = 0; j < matrix_size; ++j)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
            {
                printf("Error!");
                return 0;
            }
        }
    }

    for (int32_t i = 0; i < matrix_size; ++i)
    {
        for (int32_t j = 0; j < matrix_size; ++j)
        {
            if (matrix[i][j] == -matrix[j][i])
            {
                printf("0 ");
            }
            else
            {
                printf("1 ");
            }
        }
        putchar('\n');
    }

    FreeingMemory(matrix, matrix_size);

    fclose(file);
    return 0;
}
