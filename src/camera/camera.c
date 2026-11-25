/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:09:31 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/25 17:58:22 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"
#include "matrix.h"
#include "point.h"
#include <math.h>
#include "render.h"

t_cam *new_camera(int h_size_new, int v_size_new, float new_angle)
{
    t_cam *new;

    new->h_size = h_size_new;
    new->v_size = v_size_new;
    new->view_angle = new_angle;
    new->transformation = identity_matrix4(); //fonction a faire
    new->half_view = tan(new->view_angle / 2);
    new->aspect = new->h_size / new->v_size;
    if (new->aspect >= 1)
    {
        new->half_height = new->half_view / new->aspect;
        new->half_width = new->half_view;
    }
    else
    {
        new->half_width = new->half_view * new->aspect;
        new->half_height = new->half_view;
    }
    new->pixel_size = (new->half_width * 2) / new->h_size;
}

t_matrix4 *view_transform(t_point from, t_point to, t_vec3 up)
{
    t_vec3 forward = normalize_vec3(sub_point(to, from));
    t_vec3 upn = normalize_vec3(up);
    t_vec3 left = cross(forward, upn);
    t_vec3 true_up = cross(left, forward);
    float   matrix[16] = {left.x, left.y, left.z, 0, true_up.x, true_up.y, true_up.z, 0, -forward.x, -forward.y, -forward.z, 0, 0, 0, 0, 1};
    t_matrix4 *orientation = create_matrix4(matrix);
    return (mult_matrix4(orientation, translation(-from.x, -from.y, -from.z)));
}