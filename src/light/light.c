/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:11:05 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/23 20:37:57 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "render.h"
#include "minirt.h"
#include <math.h>

t_light lightning(t_material *m, t_light *l, t_point *p ,t_vec3 *eyev, t_vec3 *normal_v)
{
    effective_color = m->color * l->intensity;
    t_vec3 lightv;
    lightv = normalize_vec3(l->position - point);
    ambiant = effective_color * m->ambiant;
    int dot_normal = dot(lightv, normal_v);
    if (dot_normal < 0)
    {
        diffuse = black;
        specular = black;
    }
    else
    {
        diffuse = effective_color * m->diffuse * dot_normal;
        t_vec3 reflectv;
        reflectv = reflect( -lightv, normal_v);
        int reflect_dot_eye = dot(reflectv, eyev);
        if(reflect_dot_eye <= 0)
            specular = black;
        else
        {
            int factor = pow(reflect_dot_eye, m->shininess);
            specular = l->intensity * m->specular * factor; 
        }
    }
    return (ambiant + diffuse + specular);
}

t_color *shade_hit(t_world *w, t_comps *comps)
{
    return (lightning(&comps->obj->material, w->light, comps->point, comps->eyev, comps->normal_v));
}
