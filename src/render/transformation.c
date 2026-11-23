/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:57:58 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/23 10:29:55 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"
#include "matrix.h"
#include "tuple.h"
#include "ray.h"
#include "math.h"


t_matrix translation (float x, float y, float z)
{
    float first[3];
    float second[3];
    float third[3];
    float fourth[3];
    t_matrix new;

    first[0] = 1;
    first[1] = 0;
    first[2] = 0;
    first[3] = x;
    second[0] = 0;
    second[1] = 1;
    second[2] = 0;
    second[3] = y;
    third[0] = 0;
    third[1] = 0;
    third[2] = 1;
    third[3] = z;
    fourth[0] = 0;
    fourth[1] = 0;
    fourth[2] = 0;
    fourth[3] = 1;
    create_matrix(first, second, third, fourth);
    return (new);
}

t_matrix    scaling (float x, float y, float z)
{
    float first[3];
    float second[3];
    float third[3];
    float fourth[3];
    t_matrix new;

    first[0] = x;
    first[1] = 0;
    first[2] = 0;
    first[3] = 0;
    second[0] = 0;
    second[1] = y;
    second[2] = 0;
    second[3] = 0;
    third[0] = 0;
    third[1] = 0;
    third[2] = z;
    third[3] = 0;
    fourth[0] = 0;
    fourth[1] = 0;
    fourth[2] = 0;
    fourth[3] = 1;
    create_matrix(first, second, third, fourth);
    return (new);
}

t_matrix    rotation_x(float angle)
{
    float first[3];
    float second[3];
    float third[3];
    float fourth[3];
    t_matrix new;

    first[0] = 1;
    first[1] = 0;
    first[2] = 0;
    first[3] = 0;
    second[0] = 0;
    second[1] = cos(angle);
    second[2] = -sin(angle);
    second[3] = 0;
    third[0] = 0;
    third[1] = sin(angle);
    third[2] = cos(angle);
    third[3] = 0;
    fourth[0] = 0;
    fourth[1] = 0;
    fourth[2] = 0;
    fourth[3] = 1;
    create_matrix(first, second, third, fourth);
    return (new);
}

t_matrix    rotation_y(float angle)
{
    float first[3];
    float second[3];
    float third[3];
    float fourth[3];
    t_matrix new;

    first[0] = cos(angle);
    first[1] = 0;
    first[2] = sin(angle);
    first[3] = 0;
    second[0] = 0;
    second[1] = 1;
    second[2] = 0;
    second[3] = 0;
    third[0] = -sin(angle);
    third[1] = 0;
    third[2] = cos(angle);
    third[3] = 0;
    fourth[0] = 0;
    fourth[1] = 0;
    fourth[2] = 0;
    fourth[3] = 1;
    create_matrix(first, second, third, fourth);
    return (new);
}

t_matrix    rotation_z(float angle)
{
    float first[3];
    float second[3];
    float third[3];
    float fourth[3];
    t_matrix new;

    first[0] = cos(angle);
    first[1] = -sin(angle);
    first[2] = 0;
    first[3] = 0;
    second[0] = sin(angle);
    second[1] = cos(angle);
    second[2] = 0;
    second[3] = 0;
    third[0] = 0;
    third[1] = 0;
    third[2] = 1;
    third[3] = 0;
    fourth[0] = 0;
    fourth[1] = 0;
    fourth[2] = 0;
    fourth[3] = 1;
    create_matrix(first, second, third, fourth);
    return (new);
}

t_matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y)
{
    float first[3];
    float second[3];
    float third[3];
    float fourth[3];
    t_matrix new;

    first[0] = 1;
    first[1] = x_y;
    first[2] = x_z;
    first[3] = 0;
    second[0] = y_x;
    second[1] = 1;
    second[2] = y_z;
    second[3] = 0;
    third[0] = z_x;
    third[1] = z_y;
    third[2] = 1;
    third[3] = 0;
    fourth[0] = 0;
    fourth[1] = 0;
    fourth[2] = 0;
    fourth[3] = 1;
    create_matrix(first, second, third, fourth);
    return (new);
}

t_ray   *transform(t_ray *r, t_matrix *t)
{
    t_ray new;

    new.direction = mult_matrix_vec3(t, &r->direction);
    new.origin  = mult_matrix_point(t, &r->origin);
}

void    set_transform(t_shape *s, )