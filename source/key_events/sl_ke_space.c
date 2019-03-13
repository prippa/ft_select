/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:16:36 by prippa            #+#    #+#             */
/*   Updated: 2019/03/13 14:16:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

void		sl_ke_space(void)
{
	t_list2		*co;
	t_argument	*arg;

	co = sl_ke_get_chosen_one(sl()->args_start);
	arg = (t_argument *)co->content;
	arg->selected = SWITCH_LOGIC(arg->selected);
	sl_ke_right();
}
