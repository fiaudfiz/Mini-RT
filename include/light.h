/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:48:46 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/12 18:40:36 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "vec3.h"
#include "minirt.h"

typedef struct s_light
{
    //t_vec3 lv;
    t_color color;
    int intensity;
    t_point position;
}t_light;


#endif