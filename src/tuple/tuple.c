/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:12:43 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/16 21:38:58 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "point.h"

t_tuple add_tupple(t_tuple a, t_tuple b)
{
    t_tuple new;

    new.x = add_point(a.x, b.x);
    new.y = add_point(a.y, b.y);
    new.z = add_point(a.z, b.z);
    return (new);
}

t_tuple sub_tuple(t_tuple a, t_tuple b)
{
    t_tuple new;

    new.x = sub_point(a.x, b.x);
    new.y = sub_point(a.y, b.y);
    new.z = sub_point(a.z, b.z);
    return (new);
}

t_tuple mul_tuple_by_nb (t_tuple a, int b)
{
    a.x = mul_point_by_nb (a.x, b);
    a.y = mul_point_by_nb (a.y, b);
    a.z = mul_point_by_nb (a.z, b);
    return (a);
}

t_tuple div_tuple_by_nb (t_tuple a, int b)
{
    a.x = div_point_by_nb(a.x, b);
    a.y = div_point_by_nb(a.y, b);
    a.z = div_point_by_nb(a.z, b);
    return (a);
}