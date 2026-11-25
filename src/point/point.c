/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:15:24 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 18:01:42 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include <stdbool.h>
#include "minirt.h"
#include <math.h>
#include "vec3.h"

t_point add_point (t_point a, t_point b)
{
    t_point new;

    new.x = a.x + b.x;
    new.y = a.y + b.y;
    new.z = a.z + b.z;
    return (new);
}

t_vec3 sub_point (t_point a , t_point b)
{
    t_vec3 new;

    new.x = a.x - b.x;
    new.y = a.y - b.y;
    new.z = a.z - b.z;
    return (new);
}

t_point mul_point_by_nb ( t_point a, int b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return (a);
}

t_point div_point_by_nb (t_point a, int b)
{
    if ( b != 0)
    {
        a.x /= b;
        a.y /= b;
        a.z /= b;
    }
    return (a);
}

bool    equal(float a, float b)
{
    if (abs(a - b) < EPSILON)
        return (true);
    return (false);
}

t_point add_point_vec3(t_point *p, t_vec3 *v)
{
    t_point new;

    new.x = p->x + v->x;
    new.y = p->y + v->y;
    new.z = p->z + v->z;
    //color
    return (new);
}