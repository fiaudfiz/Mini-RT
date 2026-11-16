/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:39:58 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/12 18:46:16 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON 0.0001f

#include "shape.h"
#include "world.h"

typedef struct s_color
{
    float   r;
    float   g;
    float   b;
} t_color;

typedef struct  s_pixel
{
    int x;
    int y;
    t_color color;
} t_pixel;

typedef struct s_canva
{
    int width;
    int height;
    t_pixel **tab_of_pixel;
} t_canva;

typedef struct  s_cam
{
    t_point position;
    t_vec3 transformation;
    t_color color;
    int h_size;
    int v_size;
    float view_angle;
} t_cam;

typedef struct s_minirt
{
    t_cam   *camera;
    t_world world;
} t_minirt;

#endif