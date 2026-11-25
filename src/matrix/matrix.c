/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 23:16:28 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 17:22:26 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdbool.h>
#include "tuple.h"
#include "vec3.h"

t_matrix4 *create_matrix4(float *matrix)
{
    t_matrix4 *new;

    new = malloc(sizeof(t_matrix4));
    if (!new)
        return (NULL);
    new->matrix = matrix;
    new->x_size = 4;
    new->y_size = 4;
    return (new);
}

t_matrix4   *identity_matrix4(void)
{
    t_matrix4 *new;

    new = malloc(sizeof(t_matrix4));
    if (!new)
        rerurn (NULL);
    new->matrix = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    new->x_size = 4;
    new->y_size = 4;
    return (new);
}

t_matrix2 *create_matrix2(float *matrix)
{
    t_matrix2 *new;

    new = malloc(sizeof(t_matrix2));
    if (!new)
        return (NULL);
    new->matrix = matrix;
    new->x_size = 2;
    new->y_size = 2;
    return (new);
}

t_matrix3 *create_matrix3(float *matrix)
{
    t_matrix3 *new;

    new = malloc(sizeof(t_matrix3));
    if (!new)
        return (NULL);
    new->matrix = matrix;
    new->x_size = 3;
    new->y_size = 3;
    return (new);
}

bool if_eq_matrix4(t_matrix4 *a, t_matrix4 *b)
{
    int i;
    
    i = 0;
    while (i < a->x_size)
    {
        if (fabsf(a->matrix[i] - b->matrix[i]) > EPSILON)
            return (1);
        i++;
    }
    return (0);
}

t_matrix4 *mult_matrix4(t_matrix4 *a, t_matrix4 *b)
{
    t_matrix4 *new;
    int i;

    new = malloc(sizeof(t_matrix4));
    if (!new)
        return (NULL);
    i = 0;
    while (i < 16)
    {
        new->matrix[i] =
            a->matrix[(i / 4) * 4] * b->matrix[i % 4] +
            a->matrix[(i / 4) * 4 + 1] * b->matrix[4 + i % 4] +
            a->matrix[(i / 4) * 4 + 2] * b->matrix[8 + i % 4] +
            a->matrix[(i / 4) * 4 + 3] * b->matrix[12 + i % 4];
        i++;
    }
    return (new);
}

t_point *mult_matrix_point(t_matrix4 *a, t_point *b)
{
    t_point *new;

    new = malloc(sizeof(t_point));
    if (!new)
        return (NULL);
    new->x = a->matrix[0] * b->x
        + a->matrix[1] * b->y
        + a->matrix[2] * b->z
        + a->matrix[3];
    new->y = a->matrix[4] * b->x
        + a->matrix[5] * b->y
        + a->matrix[6] * b->z
        + a->matrix[7];
    new->z = a->matrix[8] * b->x
        + a->matrix[9] * b->y
        + a->matrix[10] * b->z
        + a->matrix[11];
    return (new);
}

t_vec3 *mult_matrix4_vec3(t_matrix4 *a, t_vec3 *vec)
{
    t_vec3 *new;

    new = malloc(sizeof(t_vec3));
    if (!new)
        return (NULL);
    new->x = a->matrix[0] * vec->x
        + a->matrix[1] * vec->y
        + a->matrix[2] * vec->z;
    new->y = a->matrix[4] * vec->x
        + a->matrix[5] * vec->y
        + a->matrix[6] * vec->z;
    new->z = a->matrix[8] * vec->x
        + a->matrix[9] * vec->y
        + a->matrix[10] * vec->z;
    return (new);
}

t_matrix4 *transpose_matrix(t_matrix4 *a)
{
    t_matrix4 *new;
    int i;

    new = malloc(sizeof(t_matrix4));
    if (!new)
        return (NULL);
    i = 0;
    while (i < 16)
    {
        new->matrix[i] = a->matrix[(i % 4) * 4 + (i / 4)];
        i++;
    }
    return (new);
}

float determinant4(t_matrix4 *a)
{
    float det;
    int i;

    det = 0;
    i = 0;
    while (i < 4)
    {
        det += a->matrix[i] * cofactor(a, 0, i);
        i++;
    }
    return (det);
}

t_matrix3 *submatrix4(t_matrix4 *a, int row, int col)
{
    t_matrix3 *new;
    int i;
    int dst;

    new = malloc(sizeof(t_matrix3));
    if (!new)
        return (NULL);
    i = 0;
    dst = 0;
    while (i < 16)
    {
        if (i / 4 != row && i % 4 != col)
        {
            new->matrix[dst] = a->matrix[i];
            dst++;
        }
        i++;
    }
    return (new);
}

float minor(t_matrix4 *a, int row, int col)
{
    t_matrix3 *new;
    float det;

    new = submatrix4(a, row, col);
    if (!new)
        return (0);
    det = determinant3(new);
    free(new);
    return (det);
}

float cofactor(t_matrix4 *a, int row, int col)
{
    float det;

    det = minor(a, row, col);
    if ((row + col) % 2 != 0)
        det *= -1;
    return (det);
}

t_matrix4 *inverse(t_matrix4 *a)
{
    t_matrix4 *new;
    float det;
    int i;
    int j;

    det = determinant4(a);
    if (det == 0)
        return (NULL);
    new = malloc(sizeof(t_matrix4));
    if (!new)
        return (NULL);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            new->matrix[j * 4 + i] = cofactor(a, i, j) / det;
            j++;
        }
        i++;
    }
    return (new);
}