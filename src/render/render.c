/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:10:59 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/24 10:27:12 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "mlx.h"

float *intersect_world(t_world *w, t_ray *r)
{
    int i;
    float *tab;

    i = 0;

    while (i < w->shapes TOTAL)
    {
        tab += intersection(w->shapes[i], r); //should return every intersections in ascending order
        i++;
    }
    return (tab);
}
// fontion qui va nous couter le plus du projet en cycle CPU

t_ray   ray_for_pixel (t_cam *c, int px, int py)
{
    float world_x;
    float world_y;
    t_ray   new;

    int x_offset = (px + 0.5) * c.pixel_size;
    int y_offset = (py + 0.5) * c.pixel_size;
    world_x = c.half_width - x_offset;
    world_y = c.half_height - y_offset;
    t_pixel pix;
    t_point *p;
    p->x = world_x;
    p->y = world_y;
    p->z = -1.0f;
    pix  = inverse(c->transformation) * &p;
    new.origin = inverse(c->transformation) * point(0, 0, 0);
    new.direction = normalize_vec3(pixel - new.origin);
    return (new);
}


void    render_rt(t_minirt *m)
{
    int i = 0;
    int j = 0;
    t_ray   r;
    t_color c;

    while (i < m->world.canva->height)
    {
        j = 0;
        while (j < m->world.canva->width)
        {
            r = ray_for_pixel(m->camera, i, j);
            c = color_at(m->world, r);
            write_pixel(m->img, x, y, c);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window;
    return ;
}