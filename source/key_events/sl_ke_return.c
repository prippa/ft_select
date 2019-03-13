/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:08:08 by prippa            #+#    #+#             */
/*   Updated: 2019/03/13 14:08:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sl_print_selected_args(t_list2 *start)
{
	t_argument	*arg;
	t_bool		first_elem_flag;

	first_elem_flag = true;
	while (start)
	{
		arg = (t_argument *)start->content;
		if (arg->selected)
		{
			if (!first_elem_flag)
				ft_putchar_fd(' ', STDOUT_FILENO);
			else
				first_elem_flag = false;
			ft_putstr_fd(arg->name, STDOUT_FILENO);
		}
		start = start->next;
	}
}

void		sl_ke_return(void)
{
	sl_set_base_settings();
	sl_print_selected_args(sl()->args_start);
	exit(EXIT_SUCCESS);
}
