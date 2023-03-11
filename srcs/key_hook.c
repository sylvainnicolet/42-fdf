/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:20:52 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:20:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	is_key(int key)
{
	return (key == KEY_ESC || key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT
		|| key == KEY_ARROW_DOWN || key == KEY_ARROW_UP || key == KEY_A
		|| key == KEY_S || key == KEY_D || key == KEY_W
	);
}

static void	do_key(int key, t_param *params)
{
	if (key == KEY_ESC)
		fdf_close(params);
	if (key == KEY_ARROW_LEFT || key == KEY_A)
		params->shift_x -= 10;
	if (key == KEY_ARROW_RIGHT || key == KEY_D)
		params->shift_x += 10;
	if (key == KEY_ARROW_DOWN || key == KEY_S)
		params->shift_y += 10;
	if (key == KEY_ARROW_UP || key == KEY_W)
		params->shift_y -= 10;
//	if (key == 24 || key == 69)
//		params->scale += 3;
//	if (key == 27 || key == 78)
//		params->scale -= 3;
//	if (key == 91 || key == 28)
//		params->z_scale += 1;
//	if (key == 84 || key == 19)
//		params->z_scale -= 1;
//	if (key == '~')
//		params->shift_y -= 10;
//	if (key == '}')
//		params->shift_y += 10;
//	if (key == '{')
//		params->shift_x -= 10;
//	if (key == '|')
//		params->shift_x += 10;
//	if (key == 49 || key == 87 || key == 23)
//		params->is_isometric = (params->is_isometric) ? 0 : 1;
//	if (key == 86 || key == 21)
//		params->angle += 0.05;
//	if (key == 88 || key == 22)
//		params->angle -= 0.05;
}

int	key_hook(int key, t_param *params)
{
	printf("key: %d\n", key);
	if (is_key(key))
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		do_key(key, params);
		print_menu(params);
		draw(params);
	}
	return (0);
}
