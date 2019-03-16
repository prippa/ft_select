/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_unselect_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:20:45 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 10:20:46 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sl_unselect_all_args(t_list2 *start)
{
	while (start)
	{
		((t_argument *)start->content)->selected = false;
		start = start->next;
	}
}

void		sl_ke_unselect_all(t_list2 *co)
{
	(void)co;
	sl_unselect_all_args(sl()->args_start);
	sl_print_all();
}
