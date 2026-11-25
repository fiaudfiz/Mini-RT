/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:17:04 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 17:57:11 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "minirt.h"
#include "shape.h"
#include "vec3.h"
#include "ray.h"
#include <stdbool.h>

typedef struct s_comps
{
    t_intersection *t;
    void            *obj;
    t_point         *point;
    t_vec3          *eyev;
    t_vec3          *normal_v;
    bool            inside;
    t_point         over_point;
} t_comps;


t_matrix4    *translation(float x, float y, float z);
t_matrix4    *scaling(float x, float y, float z);
t_matrix4    *rotation_x(float angle);
t_matrix4    *rotation_y(float angle);
t_matrix4    *rotation_z(float angle);
t_matrix4 *shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);
t_ray   *transform(t_ray *r, t_matrix4 *t);

#endif