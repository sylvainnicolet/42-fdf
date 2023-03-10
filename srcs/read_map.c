/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:10 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 14:14:12 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Read the file and build a matrix of t_dot
 * @param file_path
 * @return t_dot** matrix
 */
t_dot	**read_map(char *file_path)
{
	t_dot	**matrix;

	matrix = matrix_create(file_path);
	matrix_build(matrix, file_path);
	return (matrix);
}
