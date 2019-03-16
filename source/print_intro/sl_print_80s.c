/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_80s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:20:50 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 10:20:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_intro.h"

#define START_PICE "/____/\\___/\\__/_/\\_\\   /_/  \\___/ "
#define STUPID_42_NORMS START_PICE "  /_/ /_//_/\\__/  \\___/\\___/ /___/"

const char	g_80s[INTRO_80S_ROW_SIZE][INTRO_80S_COL_SIZE] =
{
	"   ___           __     ______       ________         ___  ___ _    ",
	"  / _ )___ _____/ /__  /_  __/__    /_  __/ /  ___   ( _ )/ _ ( )___",
	" / _  / _ `/ __/  '_/   / / / _ \\    / / / _ \\/ -_) / _  / // //(_-<",
	STUPID_42_NORMS
};

void		sl_print_80s(t_point p)
{
	uint16_t	i;
	uint16_t	j;

	i = -1;
	while (++i < INTRO_80S_COL_SIZE)
	{
		j = -1;
		while (++j < INTRO_80S_ROW_SIZE)
		{
			sl_goto(p.y + j, p.x + i);
			ft_dprintf(STDIN_FILENO, "%~c", CT_BOLD, C_MAGENTA, g_80s[j][i]);
		}
		usleep(BACK_80S_USLEEP);
	}
}
