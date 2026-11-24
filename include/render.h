/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:17:04 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/24 13:45:32 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "minirt.h"
#include "shape.h"
#include "vec3.h"
#include "ray.h"
#include <stdbool.h>

typedef struct s_comps
{
    t_intersection *t;
    t_shape         *obj;
    t_point         *point;
    t_vec3          *eyev;
    t_vec3          *normal_v;
    bool            inside;
    t_point         over_point;
} t_comps;


#endif