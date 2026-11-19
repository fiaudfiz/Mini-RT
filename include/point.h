/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:32:28 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/19 10:10:10 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include <float.h>
#include "minirt.h"

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

#endif