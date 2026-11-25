/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:35:11 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 17:22:53 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include <stdbool.h>

typedef struct s_matrix4
{
    int x_size;
    int y_size;
    float matrix[16];
}  t_matrix4;

typedef struct s_matrix3
{
    float   matrix[9];
    int     x_size;
    int     y_size;
} t_matrix3;

typedef struct matrix2
{
    float   matrix[4];
    int     x_size;
    int     y_size;
} t_matrix2;


t_point *mult_matrix_point(t_matrix4 *a, t_point *b);
t_matrix4 *create_matrix4(float *matrix);
t_matrix3 *create_matrix3(float *matrix);
t_matrix2 *create_matrix2(float *matrix);
bool if_eq_matrix4(t_matrix4 *a, t_matrix4 *b);
t_matrix4 *mult_matrix4(t_matrix4 *a, t_matrix4 *b);
t_point mult_matrix4_point(t_matrix4 *a, t_point *b);
t_vec3 *mult_matrix4_vec3(t_matrix4 *a, t_vec3 *vec);
t_matrix4 *transpose_matrix(t_matrix4 *a);
float determinant4(t_matrix4 *a);
t_matrix3 *submatrix4(t_matrix4 *a, int row, int col);
float minor(t_matrix4 *a, int row, int col);
float cofactor(t_matrix4 *a, int row, int col);
t_matrix4 *inverse(t_matrix4 *a);
t_matrix4   *identity_matrix4(void);

#endif