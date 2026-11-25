/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:41:09 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 18:06:51 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

#include "light.h"
#include "shape.h"

typedef struct s_world
{
    t_light **light;
    t_scene *scene;
    t_canva *canva;
    int     total_shapes;
} t_world;


#endif