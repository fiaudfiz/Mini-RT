/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:10:59 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/20 09:55:56 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "mlx.h"

void    render_rt(t_minirt *m)
{
    int i = 0;
    int j = 0;
    t_ray   r;

    while (i < m->world.canva->height)
    {
        j = 0;
        while (j < m->world.canva->width)
        {
            r.origin = m->camera->position;
            r.direction =; //pixel souhaite sur l'ecran
            if (intersection)
                put_color; //de la shape;
            j++;
        }
        i++;
    }
    mlx_put_image_to_window;
    return ;
}