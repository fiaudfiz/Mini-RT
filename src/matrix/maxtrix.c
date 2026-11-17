/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxtrix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 23:16:28 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/17 20:24:04 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdbool.h>
#include "tuple.h"
#include "vec3.h"


t_matrix create_matrix_four_by_four (int *first_line, int *second_line, int *third_line, int *fourth_line)
{
    t_matrix    new;
        
    new.matrix[0] = first_line;
    new.matrix[1] = second_line;
    new.matrix[2] = third_line;
    new.matrix[3] = fourth_line;
    new.x_size = 4;
    new.y_size = 4;
    return (new);
}

t_matrix create_matrix_two_by_two (int *first_line, int *second_line)
{
    t_matrix    new;
        
    new.matrix[0] = first_line;
    new.matrix[1] = second_line;
    new.x_size = 2;
    new.y_size = 2;
    return (new);
}

bool if_eq_matrix(t_matrix *a, t_matrix *b)
{
    int i = 0;
    int j;
    
    if (a->x_size != b->x_size || a->y_size != b->y_size)
        return (1);
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (a->matrix[i][j] != b->matrix[i][j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

t_matrix mult_matrix(t_matrix *a, t_matrix *b)
{
    t_matrix new;
    int i = 0;
    int j = 0;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            new.matrix[i][j] = a->matrix[i][0] * b->matrix[0][j] + a->matrix[i][1] * b->matrix[1][j] + a->matrix[i][2] * b->matrix[2][j] + a->matrix[i][3] * b->matrix[3][j];
            j++;
        }
        i++;
    }
    return (new);
}

t_point mult_matrix_point(t_matrix *a, t_point *b)
{
    t_point new;
    
    new.x = a->matrix[0][0] * b->x + a->matrix[0][1] * b->y + a->matrix[0][2] * b->z + a->matrix[0][3];
    new.y = a->matrix[1][0] * b->x + a->matrix[1][1] * b->y + a->matrix[1][2] * b->z + a->matrix[1][3];
    new.z = a->matrix[2][0] * b->x + a->matrix[2][1] * b->y + a->matrix[2][2] * b->z + a->matrix[2][3];
    return (new);
}

t_vec3  mult_matrix_vec3(t_matrix *a, t_vec3 *vec)
{
    t_vec3 new;

    new.x = a->matrix[0][0] * vec->x + a->matrix[0][1] * vec->y + a->matrix[0][2] * vec->z;
    new.y = a->matrix[1][0] * vec->x + a->matrix[1][1] * vec->y + a->matrix[1][2] * vec->z;
    new.z = a->matrix[2][0] * vec->x + a->matrix[2][1] * vec->y + a->matrix[2][2] * vec->z;
    return (new);
}

t_matrix transpose_matrix(t_matrix *a)
{
    t_matrix new;

    new.matrix[0][0] = a->matrix[0][0];
    new.matrix[0][1] = a->matrix[1][0];
    new.matrix[0][2] = a->matrix[2][0];
    new.matrix[0][3] = a->matrix[3][2];
    new.matrix[1][0] = a->matrix[0][1];
    new.matrix[1][1] = a->matrix[1][1];
    new.matrix[1][2] = a->matrix[2][1];
    new.matrix[1][3] = a->matrix[3][1];
    new.matrix[2][0] = a->matrix[0][2];
    new.matrix[2][1] = a->matrix[1][2];
    new.matrix[2][2] = a->matrix[2][2];
    new.matrix[2][3] = a->matrix[3][2];
    new.matrix[3][0] = a->matrix[0][3];
    new.matrix[3][1] = a->matrix[1][3];
    new.matrix[3][2] = a->matrix[2][3];
    new.matrix[3][3] = a->matrix[3][3];
    return (new);
}

float   determinant(t_matrix *a)
{
    int det = 0;
    int i = 0;
    
    if (a->x_size == 2 && a->y_size == 2)
        return (a->matrix[0][0] * a->matrix[1][1] - a->matrix[1][0] * a->matrix[1][0]);
    else
    {
        while (i < a->y_size)
        {
            det = det + a->matrix[0][i] - cofactor(a, 0, i);
            i++;
        }
    }
    return (det);
}

t_matrix    submatrix(t_matrix *a, int row, int col)
{
    t_matrix new;
    int matrix[a->x_size - 1][a->y_size - 1];
    int i = 0;
    int j;

    while (i < a->x_size - 1)
    {
        j = 0;
        while (j < a->y_size - 1)
        {
            if (i == row || j == col)
                j++;
            else
            {
                matrix[i][j] = a->matrix[i][j];
                j++;
            }
        }
        i++;
    }
    return (new);
}

float   minor(t_matrix *a, int row, int col)
{
    t_matrix new;
    float   det;

    new = submatrix(a, row, col);
    det = determinant(&new);
    return (det);
}

float   cofactor(t_matrix *a, int row, int col)
{
    int i = 0;
    i = minor(a, row, col);
    if (row + col % 2 == 0)
        i *= -1;
    return (i);
}

t_matrix inverse(t_matrix *a)
{
    t_matrix new;
    int i = 0;
    int j = 0;
    int c = 0;

    while (i < a->x_size)
    {
        j = 0;
        while (j < a->y_size)
        {
            c = cofactor (a, i, j);
            new.matrix[j][i] = c/det(a);
            j++;
        }
        i++;
    }
    return (new);
}