/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 10:35:47 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/23 10:42:02 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "world.h"
#include "ray.h"
#include "shape.h"


t_world create_world()
{
    t_world new;
    return (new);
}


//light source -10 -10 -10


t_point point_light(t_point *p, t_color *c)
{
    
}

t_computation   prepare_computation(t_intersect *i, t_ray *r)
{
    t_computation *comps;

    comps.t = i.t;
    comps.obj = i.s;
    comps.point = position(r, comps.t);
    comps.eyev = -r->direction;
    comps.normalv = normal_at(comps.object, comps.point);
    return (comps);
}