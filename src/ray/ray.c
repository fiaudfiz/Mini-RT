/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:33:54 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/17 20:41:27 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "point.h"
#include "vec3.h"

t_point position(t_ray r, t_vec3 v)
{
    return (r.origin + r.direction * t);
}