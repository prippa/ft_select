#include "print_intro.h"
#include <math.h>

const char		*g_info_list[INFO_ROWS_SIZE] = 
{
	"Program Usage:",
	"Arrows: (↑ ↓ ← →) To list items",
	"SPACE: to select item",
	"DEL or BACKSPACE: to remove item",
	"RETURN: to exit with print all selected items",
	"ESC: to exit",
	"Ctrl + A: to select all items",
	"Ctrl + A: to unselect all items",
	"Press any key to continue..."
};

static void	sl_go_and_print(uint16_t y, uint16_t x, const char *s, t_color c)
{
	sl_goto(y, x);
	ft_dprintf(STDIN_FILENO, "%~s", CT_BOLD, c, s);
	usleep(INFO_SLEEP);
}

void			sl_print_info(t_point p)
{
	uint16_t	i;

	i = 0;
	sl_go_and_print(p.y + i, p.x, g_info_list[i], C_MAGENTA);
	++p.y;
	while (++i < INFO_ROWS_SIZE - 1)
		sl_go_and_print(p.y + i, p.x, g_info_list[i], C_MAGENTA);
	++p.y;
	sl_go_and_print(p.y + i, p.x, g_info_list[i], C_GREEN);
}
