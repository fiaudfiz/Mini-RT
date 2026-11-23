/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:32:28 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/23 12:43:11 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include <float.h>
#include "minirt.h"
#include <stdbool.h>

typedef struct s_point
{
    float   x;
    float   y;
    float   z;
    t_color color;
} t_point;

t_point add_point (t_point a, t_point b);
t_point sub_point (t_point a, t_point b);
t_point mul_point_by_nb ( t_point a, int b);
t_point div_point_by_nb (t_point a, int b);
t_point add_point_vec3(t_point *p, t_vec3 *v);
bool    equal(float a, float b);



#endif