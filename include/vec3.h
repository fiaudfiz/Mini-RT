/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:27:53 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/23 20:10:09 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include "tuple.h"

typedef struct s_vec3
{
    float   x;
    float   y;
    float   z;
}   t_vec3;

float vec3_lenght(t_vec3 a);
t_vec3  normalize_vec3 (t_vec3 a);
int dot(t_vec3 *a, t_vec3 *b);
t_vec3  cross(t_vec3 a, t_vec3 b);
t_vec3 div_vec3_scalar(t_vec3 *v, float t);
t_vec3 mul_vec3_scalar(t_vec3 *v, float t);

#endif