/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:39:54 by synicole          #+#    #+#             */
/*   Updated: 2023/02/01 20:39:56 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# define BUFFER_SIZE 10
//# define PRM matrix[0][0]
# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)

/**
 * Libraries
*/
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

/**
 * Get next line
*/
char	*get_next_line(int fd);
char	*gnl_get_line(char **stash);
void	gnl_read_line(int fd, char *buffer, char **stash);
size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(char *s, int c);

int		ft_wdcounter(char const *str, char c);

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
}	t_dot;

typedef struct s_param
{
	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_param;

t_dot	**read_map(char *file_path);
t_dot	**matrix_create(char *file_path);
void	matrix_display(t_dot **matrix);
void	matrix_build(t_dot **matrix, char *file_path);
void	matrix_clear(t_dot **matrix);
void	draw(t_dot **matrix, t_param *params);
void	print_menu(t_param *params);
void	set_param(t_dot *a, t_dot *b, t_param *params);
void	isometric(t_dot *dot, double angle);
int		deal_key(int key, t_dot **matrix, t_param *params);
void	new_window(int key, t_dot **matrix, t_param *params);

/**
 * Print in console
*/
void	ft_print_success(char *str);
void	ft_print_error(char *str);

#endif