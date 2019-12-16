/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:53:56 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 19:39:26 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_key_pointers(t_pointers *point, int key)
{
	int			d;

	if (key == PLUS || key == LEFT || key == UP)
		d = -1;
	else
		d = 1;
	if ((key == LEFT || key == RIGHT) && point->mod.iso)
	{
		point->base.start_x += 10 * d;
		point->base.start_y -= 10 * d;
	}
	else if ((key == LEFT || key == RIGHT) && !point->mod.iso)
		point->base.start_x += 10 * d;
	if ((key == DOWN || key == UP) && point->mod.iso)
	{
		point->base.start_x += 10 * d;
		point->base.start_y += 10 * d;
	}
	else if ((key == DOWN || key == UP) && !point->mod.iso)
		point->base.start_y += 20 * d;
}

void				ft_key_change(t_pointers *point, int key)
{
	if (key == PLUS)
	{
		point->base.start_x += 1;
		point->base.start_y += 1;
		point->base.size -= 1;
	}
	if (key == MINUS)
	{
		point->base.start_x -= 1;
		point->base.start_y -= 1;
		point->base.size += 1;
	}
	if (key == C && !point->mod.iso)
	{
		point->base.start_x = WIDTH / 3;
		point->base.start_y = HEIGHT / 3;
	}
	else if (key == C)
	{
		point->base.start_x = WIDTH / 2;
		point->base.start_y = -HEIGHT / 3;
	}
	if (key == RISE)
		point->base.z_p += 2;
	if (key == FALL)
		point->base.z_p -= 2;
}

void				ft_change_color(t_pointers *point)
{
	if (!point->mod.flag_color)
	{
		if (point->color.custom_color == WHITE_F)
			point->color.custom_color = RED_F;
		else if (point->color.custom_color == RED_F)
			point->color.custom_color = BLUE_F;
		else if (point->color.custom_color == BLUE_F)
			point->color.custom_color = TURQUOISE_F;
		else if (point->color.custom_color == TURQUOISE_F)
			point->color.custom_color = GREEN_F;
		else if (point->color.custom_color == GREEN_F)
			point->color.custom_color = YELLOW_F;
		else if (point->color.custom_color == YELLOW_F)
			point->color.custom_color = ORANGE_F;
		else if (point->color.custom_color == ORANGE_F)
			point->color.custom_color = PURPLE_F;
		else if (point->color.custom_color == PURPLE_F)
			point->color.custom_color = WHITE_F;
		ft_set_custom_color(point);
	}
}

void				ft_check_key(t_pointers *point, int key)
{
	if (key == ESC)
		exit(0);
	if (key == SPACE)
		ft_set_dot(point);
	if (key == K)
		ft_change_color(point);
	if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		ft_key_pointers(point, key);
	if (key == PLUS || key == MINUS || key == C || key == RISE ||
			key == FALL)
		ft_key_change(point, key);
	if (key == Y_LEFT || key == Y_RIGHT || key == X_DOWN || key == X_UP ||
		key == Z_DOWN || key == Z_UP)
		ft_change_angle(point, key);
	if (key == O)
		point->mod.iso = FALSE;
	if (key == I)
		point->mod.iso = TRUE;
	if (key == G)
		point->mod.grad = !point->mod.grad;
	if (key == SHIFT)
		point->mod.shift = TRUE;
}