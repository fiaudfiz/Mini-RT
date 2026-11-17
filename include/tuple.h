/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:25:43 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/16 21:35:34 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

#include "float.h"
#include "point.h"

typedef struct  s_tuple
{
    t_point   x;
    t_point   y;
    t_point   z;
} t_tuple;

t_tuple     create_tuple(float new_x, float new_y, float new_z);
t_tuple add_tupple (t_tuple a, t_tuple b);
t_tuple sub_tuple (t_tuple a, t_tuple b);
t_tuple mul_tuple_by_nb (t_tuple a, int b);
t_tuple div_tuple_by_nb (t_tuple a, int b);

#endif