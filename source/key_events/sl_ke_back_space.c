/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_back_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:51:05 by prippa            #+#    #+#             */
/*   Updated: 2019/03/14 14:51:06 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

void		sl_ke_back_space(t_list2 *co)
{
	sl_ke_up(co);
	ft_lst2del_by_obj(&sl()->args_start, &sl()->args_end, co, sl_del_arg);
	if (!sl()->args_start)
		sl_exit(EXIT_SUCCESS);
	sl_print_all();
}
