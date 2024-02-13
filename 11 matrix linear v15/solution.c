// Write your solution here
// 15 variant
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int32_t size;
    int32_t *matrix;
    int32_t *new_matrix;
    int32_t current_colum = 0;
    int32_t row_step = 0;
    int32_t colum_step = 0;
    int32_t array_index = 0;
    int32_t count_steps = 0;
    int32_t current_row = 0;

    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &size) != 1)
    {
        printf("Error \n");
        return 1;
    }
    matrix = (int32_t *)malloc(size * size * sizeof(int32_t));
    new_matrix = (int32_t *)malloc(size * size * sizeof(int32_t));

    count_steps = size;
    current_row = size - 1;

    // Обязательная проверка ошибки при выделении
    if (!matrix)
    {
        fprintf(stderr, "Failed to allocate memory for matrix\n");
        abort();
    }
    if (!new_matrix)
    {
        fprintf(stderr, "Failed to allocate memory for matrix\n");
        abort();
    }

    // ввод матрицы
    for (int32_t i = 0; i < size * size; ++i)
    {
        if (scanf("%d", matrix + i) != 1)
        {
            printf("Error \n");
            return 1;
        }
    }
    // вычисление новой матрицы
    while (true)
    {
        if ((row_step + colum_step) % 2 == 0)
        {
            for (int32_t i = 0; i < count_steps; ++i)
            {
                new_matrix[array_index + i] = matrix[(current_row - i) * size + (current_colum + i)];
            }
            array_index += count_steps;
            current_row -= count_steps - 1;
            current_colum += count_steps - 1;
            count_steps -= 1;
            row_step += 1;
        }
        current_row += row_step;
        current_colum += colum_step;
        if ((row_step + colum_step) % 2 != 0)
        {
            for (int32_t i = 0; i < count_steps; ++i)
            {
                new_matrix[array_index + i] = matrix[(current_row + i) * size + (current_colum - i)];
            }
            array_index += count_steps;
            current_row += count_steps - 1;
            current_colum -= count_steps - 1;
            colum_step += 1;
        }
        current_row -= row_step;
        current_colum -= colum_step;
        if (current_colum == 0 && current_row == 0)
        {
            new_matrix[size * size - 1] = matrix[0];
            break;
        }
    }

    printf("new matrix elements:\n");
    // Печать матрицы
    for (int32_t i = 0; i < size; ++i)
    {
        for (int32_t j = 0; j < size; ++j)
        {
            printf("%d ", new_matrix[i * size + j]);
        }
    }
    printf("\n");

    // Обязательное освобождение памяти!
    free(matrix);
    free(new_matrix);
}
