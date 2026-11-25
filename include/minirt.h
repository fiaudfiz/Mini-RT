/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:39:58 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/24 16:46:34 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1000
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif


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
    float   half_view;
    int     aspect;
    float   half_width;
    float   half_height;
    float   pixel_size;
} t_cam;

typedef struct s_minirt
{
    t_cam   *camera;
    t_world world;
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
} t_minirt;

#endif