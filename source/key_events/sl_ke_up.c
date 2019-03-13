/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:02:37 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 18:02:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

void		sl_ke_up(void)
{
	t_list2	*co;

	co = sl_ke_get_chosen_one(sl()->args_start);
	((t_argument *)co->content)->chosen_one = false;
	if (co->prev)
		((t_argument *)co->prev->content)->chosen_one = true;
	else
		((t_argument *)sl()->args_end->content)->chosen_one = true;
}