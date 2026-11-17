/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 22:08:12 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/11/16 23:13:43 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

int create_canva( t_minirt *minirt )
{
    minirt->mlx = mlx_init();
    minirt->win = mlx_new_window (minirt->mlx, WIN_WIDTH, WIN_HEIGHT, "Mini-RT");
    if (!minirt->win)
        return (1);
    minirt->img = mlx_new_image (minirt->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!minirt->img)
        return (1);
    minirt->addr = mlx_get_data_addr (minirt->img, &minirt->bits_per_pixel, minirt->line_lenght, &minirt->endian);
}