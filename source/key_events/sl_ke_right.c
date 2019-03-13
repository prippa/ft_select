/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:02:58 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 18:02:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

void		sl_ke_right(void)
{
	t_list2	*co;

	co = sl_ke_get_chosen_one(sl()->args_start);
	((t_argument *)co->content)->chosen_one = false;
	if (co->next)
		((t_argument *)co->next->content)->chosen_one = true;
	else
		((t_argument *)sl()->args_start->content)->chosen_one = true;
}
