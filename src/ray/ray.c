/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:33:54 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/20 10:51:33 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "point.h"
#include "vec3.h"
#include "shape.h"
#include <stdio.h>
#include "math.h"

t_point position(t_ray *r, float t)
{
    t_vec3 new_v;
    t_point new_p;

    new_v = mul_vec3_scalar(&r->direction, t);
    new_p = add_point_vec3(&r->origin, &new_v);
    return (new_p);
}

t_intersection *intersection(t_shape *s, t_ray *r)
{
    t_intersection result[2];
    float dis;
    float a;
    float b;
    float c;
    t_vec3 sphere_to_ray;
    t_point o;
    
    o.x = 0;
    o.y = 0;
    o.z = 0;
    sphere_to_ray = r->origin - o;
    a = dot(r->direction, r->direction);
    b = 2 * dot(r->direction,  sphere_to_ray);
    c = dot(sphere_to_ray, sphere_to_ray) - 1;
    dis = (b * b) - 4 * a * c; 
    if ( dis < 0)
        return;
    else
    {
        result[0].t = ((-b - sqrt(dis) / (2 * a)));
        result[0].s = s;
        result[1].t = ((-b + sqrt(dis) / (2 * a)));
        result[1].s = s;
        if ( result[0].t == result [1].t)
            result[2].t = 1;
        else
            result[2].t = 2;
    }
    return (result)
}

//intersections rassemble des minis tebleaux en un seu pour envoyer que un paramrtre a hit()

t_intersection *hit(t_intersection **i)
{
    if (i[0]->t < 0 && i[1]->t < 0)
        return (NULL);
    if (i[0]->t < 0 && i[1]->t > 0 )
        return (i[1]);
    else
        return (i[0]);
    if (i[0]->t > 0 && i[1]->t > 0 && i[0] < i[1])
        return(i[0]);
    else
        return (i[1]);
}