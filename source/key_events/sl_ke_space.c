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

void		sl_ke_space(t_list2 *co)
{
	t_argument	*arg;

	arg = (t_argument *)co->content;
	arg->selected = SWITCH_LOGIC(arg->selected);
	sl_print_elem((t_list *)co);
	sl_ke_down(co);
}
