/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:29:39 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 10:29:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_intro.h"

#define ARG_0_1 "        :::::::::: :::::::::::           ::::::::  :"
#define ARG_0_2 "::::::::: :::        :::::::::: :::::::: ::::::::::: "
#define ARG_1_1 "       :+:            :+:              :+:    :+: :+"
#define ARG_1_2 ":        :+:        :+:       :+:    :+:    :+:      "
#define ARG_2_1 "      +:+            +:+              +:+        +:+"
#define ARG_2_2 "        +:+        +:+       +:+           +:+       "
#define ARG_3_1 "     :#::+::#       +#+              +#++:++#++ +#++"
#define ARG_3_2 ":++#   +#+        +#++:++#  +#+           +#+        "
#define ARG_4_1 "    +#+            +#+                     +#+ +#+  "
#define ARG_4_2 "      +#+        +#+       +#+           +#+         "
#define ARG_5_1 "   #+#            #+#              #+#    #+# #+#   "
#define ARG_5_2 "     #+#        #+#       #+#    #+#    #+#          "
#define ARG_6_1 "  ###            ###    ########## ########  #######"
#define ARG_6_2 "### ########## ########## ########     ###           "

#define ARG_0 ARG_0_1 ARG_0_2
#define ARG_1 ARG_1_1 ARG_1_2
#define ARG_2 ARG_2_1 ARG_2_2
#define ARG_3 ARG_3_1 ARG_3_2
#define ARG_4 ARG_4_1 ARG_4_2
#define ARG_5 ARG_5_1 ARG_5_2
#define ARG_6 ARG_6_1 ARG_6_2

const char	g_intro[INTRO_ROW_SIZE][INTRO_COL_SIZE] =
{
	ARG_0,
	ARG_1,
	ARG_2,
	ARG_3,
	ARG_4,
	ARG_5,
	ARG_6
};

static void		sl_go_and_print(uint16_t y, uint16_t x, char c, t_color_type ct)
{
	t_color color;

	sl_goto(y, x);
	if (c == '#')
		color = C_WHITE;
	else if (c == '+')
		color = C_YELLOW;
	else
		color = C_RED;
	ft_dprintf(STDIN_FILENO, "%s%~c", ITALIC, ct, color, c);
}

static t_bool	sl_check_bools(t_bool b[INTRO_COL_SIZE])
{
	uint16_t i;

	i = -1;
	while (++i < INTRO_COL_SIZE)
		if (!b[i])
			return (false);
	return (true);
}

static void		sl_print_intro_from_down_to_up(t_point p)
{
	t_bool		name[INTRO_ROW_SIZE][INTRO_COL_SIZE];
	t_point		t;
	size_t		no_room_flag;
	uint16_t	i;
	int32_t		y;

	ft_bzero(&name, sizeof(name));
	no_room_flag = INTRO_ROW_SIZE * INTRO_COL_SIZE;
	i = INTRO_ROW_SIZE - 1;
	while (no_room_flag)
	{
		t.x = (uint16_t)rand() % INTRO_COL_SIZE;
		t.y = (uint16_t)rand() % INTRO_ROW_SIZE;
		if ((y = (t.y > 1 ? i : i - 1)) < 0)
			y = 0;
		if (!name[y][t.x])
		{
			name[y][t.x] = true;
			--no_room_flag;
			sl_go_and_print(p.y + y, p.x + t.x, g_intro[y][t.x], CT_BOLD);
			if (sl_check_bools(name[i]))
				--i;
			usleep(NAME_DOWN_TO_UP_USLEEP);
		}
	}
}

static void		sl_print_intro_from_up_to_down(t_point p)
{
	uint16_t i;
	uint16_t j;

	i = -1;
	while (++i < INTRO_ROW_SIZE)
	{
		j = -1;
		while (++j < INTRO_COL_SIZE)
			sl_go_and_print(p.y + i, p.x + j, g_intro[i][j], F_NONE);
		usleep(NAME_UP_TO_DOWN_USLEEP);
	}
}

void			sl_print_name(t_point p)
{
	srand(time(NULL));
	sl_print_intro_from_up_to_down(p);
	sl_print_intro_from_down_to_up(p);
}
