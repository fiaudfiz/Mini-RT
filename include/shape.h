/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:25:24 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 15:41:18 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include "vec3.h"
#include "tuple.h"
#include "point.h"
#include "matrix.h"
#include <stdint.h>

typedef enum e_shape_type
{
    SHAPE_SPHERE,
    SHAPE_PLANE,
    SHAPE_CYLINDER,
    SHAPE_PYRAMID,
    SHAPE_TRIANGLE,
    SHAPE_TYPE_COUNT
}   t_shape_type;

typedef struct s_shape //tableau qui dit quel sphere a quel endroit
{
    t_shape_type  type; //type of shape
    uint32_t      index; //index dans le sous tableau
    uint32_t      material_id; //id du tableau material*
}   t_shape;

typedef struct s_shape_pool //case du tableau pour un seul type ex sphere
{
    void        *data; //tableau de type de shape ex sphere
    uint32_t    count; //combien de shape de ce type
    uint32_t    capacity; //capacity total of the tab 
}   t_shape_pool;

typedef struct s_material
{
    t_color color;
    float   ambient;
    float   diffuse;
    float   specular;
    float   shininess;
    float   transparency;
    float   refractive_index;
}   t_material;

typedef struct s_sphere
{
    t_vec3      position;
    double      radius;
    t_vec3      normal;
    t_point     center;
    t_matrix4    transform;
}   t_sphere;

typedef struct s_plane
{
    t_vec3      position;
    t_vec3      normal;
    t_matrix4    transform;
}   t_plane;

typedef struct s_cylinder
{
    t_vec3      position;
    t_vec3      axis;
    t_vec3      normal;
    double      radius;
    double      height;
    t_matrix4    transform;
}   t_cylinder;

/*typedef struct s_xs
{
    //count
} t_xs;*/

typedef struct s_scene
{
    t_shape_pool    pools[SHAPE_TYPE_COUNT]; //tableau de type de shape
    t_shape         *shapes; //tableau de shape pour recuperer l'index
    uint32_t        shape_count; //nombre total de shape
    uint32_t        shape_capacity; //????
    t_material     *materials; //tableau de materials avec un id
    uint32_t        material_count; //nombre total de material differents
}   t_scene;

/*
bool    intersect_sphere(const t_sphere *sphere, t_ray *ray);
bool    intersect_plane(const t_plane *plane, t_ray *ray);
bool    intersect_cylinder(const t_cylinder *cylinder, t_ray *ray);
bool    intersect_pyramid(const t_pyramid *pyramid, t_ray *ray);

t_vec3  normal_at_shape(t_scene *scene, const t_shape *shape,
            t_vec3 point);

t_aabb  bounds_of_shape(t_scene *scene, const t_shape *shape);

bool    intersect_shape(t_scene *scene, const t_shape *shape,
            t_ray *ray);

*/


#endif