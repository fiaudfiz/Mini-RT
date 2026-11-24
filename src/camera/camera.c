/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:09:31 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/24 16:25:21 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"
#include "matrix.h"
#include "point.h"

t_matrix view_transform(t_point *from, t_point *to, t_vec3 *up)
{
    t_vec3 forward = normalize_vec3(to - from);
    t_vec3 upn = normalize_vec3(up);
    t_vec3 left = cross(forward, upn);
    t_vec3 true_up = cross(left, forward);
    float orientation = create_matrix_four_by_four(1, 2, 3, 4);
    return (orientation * translation(-from.x, -from.y, -from.z));
}