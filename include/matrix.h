/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:35:11 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/19 16:36:05 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include <stdbool.h>

typedef struct s_matrix
{
    int x_size;
    int y_size;
    float **matrix;
}  t_matrix;

t_point mult_matrix_point(t_matrix *a, t_point *b);
t_matrix create_matrix_four_by_four (float *first_line, float *second_line, float *third_line, float *fourth_line);
bool if_eq_matrix(t_matrix *a, t_matrix *b);
t_matrix mult_matrix(t_matrix *a, t_matrix *b);
t_point mult_matrix_point(t_matrix *a, t_point *b);
t_vec3  mult_matrix_vec3(t_matrix *a, t_vec3 *vec);
t_matrix transpose_matrix(t_matrix *a);
float   determinant(t_matrix *a);
t_matrix    submatrix(t_matrix *a, int row, int col);
float   minor(t_matrix *a, int row, int col);
float   cofactor(t_matrix *a, int row, int col);
t_matrix inverse(t_matrix *a);

#endif