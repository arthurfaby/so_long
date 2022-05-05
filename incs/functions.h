/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:06:05 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 17:25:48 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

t_tile	*create_tile(t_map *, char, int, int);
int		create_board(t_map *, char *);
t_map	*create_map(char *);
t_tile	***malloc_board(int	, int);

#endif
