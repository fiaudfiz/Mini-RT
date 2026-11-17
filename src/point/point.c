/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:15:24 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/16 21:37:44 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point add_point (t_point a, t_point b)
{
    t_point new;

    new.x = a.x + b.x;
    new.y = a.y + b.y;
    new.z = a.z + b.z;
    return (new);
}

t_point sub_point (t_point a , t_point b)
{
    t_point new;

    new.x = a.x - b.x;
    new.y = a.y - b.y;
    new.z = a.z - b.z;
    return (new);
}

t_point mul_point_by_nb ( t_point a, int b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return (a);
}

t_point div_point_by_nb (t_point a, int b)
{
    if ( b != 0)
    {
        a.x /= b;
        a.y /= b;
        a.z /= b;
    }
    return (a);
}