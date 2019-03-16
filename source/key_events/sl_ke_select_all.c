/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_select_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:20:35 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 10:20:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sl_select_all_args(t_list2 *start)
{
	while (start)
	{
		((t_argument *)start->content)->selected = true;
		start = start->next;
	}
}

void		sl_ke_select_all(t_list2 *co)
{
	(void)co;
	sl_select_all_args(sl()->args_start);
	sl_print_all();
}
