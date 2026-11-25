/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:11:05 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 18:46:40 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "render.h"
#include "minirt.h"
#include <math.h>

t_light lightning(t_material *m, t_light *l, t_point *p ,t_vec3 *eyev, t_vec3 *normal_v, bool shadowed)
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
    bool shadowed;
    shadowed = is_shadowed(w, comps.over_point);
    return (lightning(&comps->obj->material, w->light, comps->point, comps->eyev, comps->normal_v, shadowed));
}


bool is_shadowed(t_world *w, t_point *p)
{
    t_vec3 v;
    t_intersection *h;

    v = sub_point(w->light.position, *p);
    float distance = vec3_lenght(v);
    t_vec3 direction = normalize_vec3(v);
    t_ray *r;
    r->origin = *p;
    r->direction = direction;
    t_intersection *i = intersect_world(w, r);
    h = hit(i); //fonction a revoir
    if (h && (h->t < distance))
        return (true);
    return (false);
}

t_vec3  reflect(t_vec3 *in, t_vec3 *normal)
{
    return (in - normal * 2 * dot(in, normal)); //fonction sub_vec3 a faire
}