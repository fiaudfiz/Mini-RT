/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:25:24 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/16 20:46:26 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include "vec3.h"
#include "tuple.h"
#include "point.h"

typedef enum e_shape_type
{
    SPHERE,
    CUBE,
    CYLINDER,
    PYRAMID,
    PLANE,
    CONE,
    TRIANGLE
} t_shape_type;

typedef struct s_meterial
{
    float   ambiant;
    float   diffuse;
    float   specular;
    float   shininess;
    float   transparency;
    float   refractive_index;

} t_material;

typedef struct  s_shape
{
    t_point center;
    t_shape_type    type;
    t_vec3  normal_vector;
    t_material  material;

} t_shape;

typedef struct s_sphere
{
    //transform;
    //
} t_sphere;

/*typedef struct s_xs
{
    //count
} t_xs;*/





#endif