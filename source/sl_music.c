/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_music.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:21:29 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 10:21:32 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		sl_music_on(void)
{
	system(sl()->music_cmd);
}

void		sl_music_off(void)
{
	system("pkill afplay 2>&-");
}
