/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:16:23 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/24 10:18:34 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"

t_color *color_at(t_world *w, t_ray *r)
{
    t_color *c;
    
    intersect_world(w, r);
    hit();
    if (no intersection)
        return (black);
    prepare_computations();
    shade_hit();
    return (c);
}