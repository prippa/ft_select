/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:08:41 by prippa            #+#    #+#             */
/*   Updated: 2019/02/23 13:08:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_list(t_list2 *elem) // debug
{
	t_argument *arg;

	arg = (t_argument *)elem->content;
	ft_printf("%~s\n", arg->color, arg->name);
}

int		main(int argc, char **argv)
{
	sl_init(argc, argv);
	ft_lst2iter(sl()->args_start, print_list); // debug
	return (EXIT_SUCCESS);
}
