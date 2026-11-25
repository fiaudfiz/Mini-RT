/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:57:58 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 17:55:55 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"
#include "matrix.h"
#include "tuple.h"
#include "ray.h"
#include "math.h"

t_matrix4    *translation(float x, float y, float z)
{
    float new[16];

    new[0] = 1;
    new[1] = 0;
    new[2] = 0;
    new[3] = x;
    new[4] = 0;
    new[5] = 1;
    new[6] = 0;
    new[7] = y;
    new[8] = 0;
    new[9] = 0;
    new[10] = 1;
    new[11] = z;
    new[12] = 0;
    new[13] = 0;
    new[14] = 0;
    new[15] = 1;
    return (create_matrix4(new));
}

t_matrix4    *scaling(float x, float y, float z)
{
    float new[16];

    new[0] = x;
    new[1] = 0;
    new[2] = 0;
    new[3] = 0;
    new[4] = 0;
    new[5] = y;
    new[6] = 0;
    new[7] = 0;
    new[8] = 0;
    new[9] = 0;
    new[10] = z;
    new[11] = 0;
    new[12] = 0;
    new[13] = 0;
    new[14] = 0;
    new[15] = 1;
    return (create_matrix4(new));
}

t_matrix4    *rotation_x(float angle)
{
    float new[16];

    new[0] = 1;
    new[1] = 0;
    new[2] = 0;
    new[3] = 0;
    new[4] = 0;
    new[5] = cos(angle);
    new[6] = -sin(angle);
    new[7] = 0;
    new[8] = 0;
    new[9] = sin(angle);
    new[10] = cos(angle);
    new[11] = 0;
    new[12] = 0;
    new[13] = 0;
    new[14] = 0;
    new[15] = 1;
    return (create_matrix4(new));
}

t_matrix4    *rotation_y(float angle)
{
    float new[16];

    new[0] = cos(angle);
    new[1] = 0;
    new[2] = sin(angle);
    new[3] = 0;
    new[4] = 0;
    new[5] = 1;
    new[6] = 0;
    new[7] = 0;
    new[8] = -sin(angle);
    new[9] = 0;
    new[10] = cos(angle);
    new[11] = 0;
    new[12] = 0;
    new[13] = 0;
    new[14] = 0;
    new[15] = 1;
    return (create_matrix4(new));
}

t_matrix4    *rotation_z(float angle)
{
    float new[16];

    new[0] = cos(angle);
    new[1] = -sin(angle);
    new[2] = 0;
    new[3] = 0;
    new[4] = sin(angle);
    new[5] = cos(angle);
    new[6] = 0;
    new[7] = 0;
    new[8] = 0;
    new[9] = 0;
    new[10] = 1;
    new[11] = 0;
    new[12] = 0;
    new[13] = 0;
    new[14] = 0;
    new[15] = 1;
    return (create_matrix4(new));
}

t_matrix4 *shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y)
{
    float   new[16];

    new[0] = 1;
    new[1] = x_y;
    new[2] = x_z;
    new[3] = 0;
    new[4] = y_x;
    new[5] = 1;
    new[6] = y_z;
    new[7] = 0;
    new[8] = z_x;
    new[9] = z_y;
    new[10] = 1;
    new[11] = 0;
    new[12] = 0;
    new[13] = 0;
    new[14] = 0;
    new[15] = 1;
    return (create_matrix4(new));
}

t_ray   *transform(t_ray *r, t_matrix4 *t)
{
    t_ray new;

    new.direction = *mult_matrix4_vec3(t, &r->direction);
    new.origin  = mult_matrix4_point(t, &r->origin);
}

void    set_transform(t_shape *s)
{
    
}