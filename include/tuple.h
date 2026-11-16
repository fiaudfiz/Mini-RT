/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:25:43 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/12 12:33:14 by fiaudfiz         ###   ########.fr       */
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

#endif