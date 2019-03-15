#include "print_intro.h"
#include <time.h>

// const char	g_intro[INTRO_ROW_SIZE][INTRO_COL_SIZE] =
// {
// 	"      :::::::::: :::::::::::           ::::::::  :\
// ::::::::: :::        :::::::::: :::::::: ::::::::::: ",
// 	"     :+:            :+:              :+:    :+: :+\
// :        :+:        :+:       :+:    :+:    :+:      ",
// 	"    +:+            +:+              +:+        +:+\
//         +:+        +:+       +:+           +:+       ",
// 	"   :#::+::#       +#+              +#++:++#++ +#++\
// :++#   +#+        +#++:++#  +#+           +#+        ",
// 	"  +#+            +#+                     +#+ +#+  \
//       +#+        +#+       +#+           +#+         ",
// 	" #+#            #+#              #+#    #+# #+#   \
//      #+#        #+#       #+#    #+#    #+#          ",
// 	"###            ###    ########## ########  #######\
// ### ########## ########## ########     ###           ",
// };

const char	g_intro[INTRO_ROW_SIZE][INTRO_COL_SIZE] =
{
	"  :::::::::: :::::::::::           ::::::::  ::::::::\
:: :::        :::::::::: :::::::: ::::::::::: ",
	"  :+:            :+:              :+:    :+: :+:     \
   :+:        :+:       :+:    :+:    :+:     ",
	"  +:+            +:+              +:+        +:+     \
   +:+        +:+       +:+           +:+     ",
	"  :#::+::#       +#+              +#++:++#++ +#++:++#\
   +#+        +#++:++#  +#+           +#+     ",
	"  +#+            +#+                     +#+ +#+     \
   +#+        +#+       +#+           +#+     ",
	"  #+#            #+#              #+#    #+# #+#     \
   #+#        #+#       #+#    #+#    #+#     ",
	"  ###            ###    ########## ########  ########\
## ########## ########## ########     ###     "
};


static void	sl_go_and_print(uint16_t y, uint16_t x, char c, t_color_type ct, uint16_t u)
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
	usleep(u);
}

static void sl_print_intro_from_up_to_down(t_point p)
{
	uint16_t i;
	uint16_t j;

	i = -1;
	while (++i < INTRO_ROW_SIZE)
	{
		j = -1;
		while (++j < INTRO_COL_SIZE)
			sl_go_and_print(p.y + i, p.x + j, g_intro[i][j],
				F_NONE, NAME_UP_TO_DOWN_USLEEP);
	}
}

// static void sl_print_intro_from_down_to_up(t_point p)
// {
// 	t_bool	name[INTRO_ROW_SIZE][INTRO_COL_SIZE];
// 	t_point	t;
// 	size_t	no_room_flag;

// 	ft_bzero(&name, sizeof(name));
// 	no_room_flag = INTRO_ROW_SIZE * INTRO_COL_SIZE;
// 	while (no_room_flag)
// 	{
// 		t.y = (uint16_t)rand() % INTRO_ROW_SIZE;
// 		t.x = (uint16_t)rand() % INTRO_COL_SIZE;
// 		if (!name[t.y][t.x])
// 		{
// 			name[t.y][t.x] = true;
// 			--no_room_flag;
// 			sl_go_and_print(p.y + t.y, p.x + t.x, g_intro[t.y][t.x], CT_BOLD);
// 			usleep(NAME_DOWN_TO_UP_USLEEP);
// 		}
// 	}
// }

static t_bool	sl_check_bools(t_bool b[INTRO_COL_SIZE])
{
	uint16_t i;

	i = -1;
	while (++i < INTRO_COL_SIZE)
		if (!b[i])
			return (false);
	return (true);
}

static void sl_print_intro_from_down_to_up(t_point p)
{
	t_bool		name[INTRO_ROW_SIZE][INTRO_COL_SIZE];
	t_point		t;
	size_t		no_room_flag;
	uint16_t	i;

	ft_bzero(&name, sizeof(name));
	no_room_flag = INTRO_ROW_SIZE * INTRO_COL_SIZE;
	i = INTRO_ROW_SIZE - 1;
	while (no_room_flag)
	{
		t.x = (uint16_t)rand() % INTRO_COL_SIZE;
		t.y = (uint16_t)rand() % INTRO_ROW_SIZE;
		if (t.y > 1)
		{
			if (sl_check_bools(name[i]))
				--i;
			else if (!name[i][t.x])
			{
				name[i][t.x] = true;
				--no_room_flag;
				sl_go_and_print(p.y + i, p.x + t.x, g_intro[i][t.x],
					CT_BOLD, NAME_DOWN_TO_UP_USLEEP);
			}
		}
		else if (i - 1 >= 0 && !name[i - 1][t.x])
		{
			name[i - 1][t.x] = true;
			--no_room_flag;
			sl_go_and_print(p.y + i - 1, p.x + t.x, g_intro[i - 1][t.x],
				CT_BOLD, NAME_DOWN_TO_UP_USLEEP);
		}
	}
}

void		sl_print_name(t_point p)
{
	srand(time(NULL));
	sl_print_intro_from_up_to_down(p);
	sl_print_intro_from_down_to_up(p);
}
