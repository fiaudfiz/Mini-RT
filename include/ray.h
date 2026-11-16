/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:36:15 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/12 18:36:56 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "point.h"
#include "vec3.h"

typedef struct s_ray
{
    t_point origin;
    t_vec3 direction;
} t_ray;

#endif