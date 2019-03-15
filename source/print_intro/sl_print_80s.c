#include "print_intro.h"

const char	g_80s[INTRO_80S_ROW_SIZE][INTRO_80S_COL_SIZE] =
{
	"   ___           __     ______       ________         ___  ___ _    ",
	"  / _ )___ _____/ /__  /_  __/__    /_  __/ /  ___   ( _ )/ _ ( )___",
	" / _  / _ `/ __/  '_/   / / / _ \\    / / / _ \\/ -_) / _  / // //(_-<",
	"/____/\\_,_/\\__/_/\\_\\   /_/  \\___/   /_/ /_//_/\\__/  \\___/\\___/ /__\
_/"
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
