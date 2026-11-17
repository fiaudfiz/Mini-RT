/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:39:13 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/16 22:06:47 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "math.h"

float vec3_lenght(t_vec3 a)
{
    return ((float)sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

t_vec3  normalize_vec3 (t_vec3 a)
{
    t_vec3 new;

    new.x  = a.x / vec3_lenght(a);
    new.y = a.y / vec3_lenght(a);
    new.z = a.z / vec3_lenght(a);
    return (new); 
}

int dot(t_vec3 a, t_vec3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3  cross(t_vec3 a, t_vec3 b)
{
    t_vec3 new;

    new.x = a.y * b.z - a.z - b.y;
    new.y = a.z * b.x - a.x * b.z;
    new.z = a.x * b.y - a.y * b.x;
    return (new);
}