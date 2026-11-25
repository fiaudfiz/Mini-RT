/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:39:13 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 18:05:51 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

float vec3_lenght(t_vec3 a)
{
    return (sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

t_vec3  normalize_vec3 (t_vec3 a)
{
    t_vec3 new;

    new.x  = a.x / vec3_lenght(a);
    new.y = a.y / vec3_lenght(a);
    new.z = a.z / vec3_lenght(a);
    return (new); 
}

int dot(t_vec3 *a, t_vec3 *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3  cross(t_vec3 a, t_vec3 b)
{
    t_vec3 new;

    new.x = a.y * b.z - a.z * b.y;
    new.y = a.z * b.x - a.x * b.z;
    new.z = a.x * b.y - a.y * b.x;
    return (new);
}

t_vec3 mul_vec3_scalar(t_vec3 *v, float t)
{
    t_vec3 new;

    new.x = t * v->x;
    new.y = t * v->y;
    new.z = t * v->z;
    return (new);
}

t_vec3 div_vec3_scalar(t_vec3 *v, float t)
{
    t_vec3 new;

    if (t != 0.0f)
    {
        new.x = v->x / t;
        new.y = v->y / t;
        new.z = v->z / t;
        return (new);
    }
    return (*v);
}

t_vec3 normal_at(t_shape *s, t_point *p)
{
    t_point local_point;
    t_vec3 local_normal;
    t_vec3 normal_world;

    local_point = mult_matrix4_point(inverse(s->transform), p);
    local_normal = local_normal_at(s, local_point);
    normal_world = transpose(invserse(s->transform)) * local_normal;
    return (normalize_vec3(normal_world));
}