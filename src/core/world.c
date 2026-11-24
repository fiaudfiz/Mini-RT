/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 10:35:47 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/24 13:46:08 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "world.h"
#include "ray.h"
#include "shape.h"
#include "render.h"


t_world create_world()
{
    t_world new;
    return (new);
}


//light source -10 -10 -10


t_point point_light(t_point *p, t_color *c)
{
    
}

t_comps   *prepare_computation(t_intersection *i, t_ray *r)
{
    t_comps *comps;

    comps->t = i->t;
    comps->obj = i->s;
    comps->point = position(r, comps->t);
    comps->eyev = mul_vec3_scalar(&r->direction, comps->t);
    comps->normal_v = normal_at(comps->obj, comps->point);
    comps->over_point = comps->point + comps->normalv * EPSILON;
    if (dot(&comps->normal_v, &comps->eyev) < 0)
    {
        comps->inside = true;
        comps->normal_v = mul_vec3_scalar(comps->normal_v, -1.0f);
    }
    
    return (comps);
}

