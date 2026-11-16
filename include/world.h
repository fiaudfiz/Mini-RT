/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:41:09 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/12 18:43:39 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

#include "light.h"
#include "shape.h"

typedef struct s_world
{
    t_light **light;
    t_shape **shapes;
    t_canva *canva;
} t_world;


#endif