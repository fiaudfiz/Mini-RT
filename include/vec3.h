/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:27:53 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/12 15:15:01 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include "tuple.h"

typedef struct s_vec3
{
    t_tuple coor;
    t_point start;
    t_point target;
    float   lenght;
} t_vec3;


#endif