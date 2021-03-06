/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:17:43 by prippa            #+#    #+#             */
/*   Updated: 2019/03/13 14:17:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

void		sl_ke_del(t_list2 *co)
{
	sl_ke_down(co);
	ft_lst2del_by_obj(&sl()->args_start, &sl()->args_end, co, sl_del_arg);
	if (!sl()->args_start)
		sl_exit(EXIT_SUCCESS);
	sl_print_all();
}
