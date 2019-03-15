#include "print_intro.h"

static void	sl_go_and_print(uint16_t y, uint16_t x, char c)
{
	sl_goto(y, x);
	ft_dprintf(STDIN_FILENO, "%~c", CT_BOLD, C_MAGENTA, c);
	usleep(FRAME_USLEEP);
}

static void	sl_print_one_frame(t_point p, uint16_t col, uint16_t row)
{
	t_point t;

	ft_bzero(&t, sizeof(t_point));
	while (t.x++ < col)
		sl_go_and_print(p.y, p.x++, '-');
	--p.x;
	++p.y;
	while (t.y++ < row)
		sl_go_and_print(p.y++, p.x, '|');
	while (col--)
		sl_go_and_print(p.y, p.x--, '-');
	++p.x;
	while (row--)
		sl_go_and_print(--p.y, p.x, '|');
}

void		sl_print_frame(t_point p)
{
	uint16_t	i;

	i = -1;
	while (++i < FRAME_SIZE)
	{
		sl_print_one_frame(p,
			INTRO_COL_SIZE + (FRAME_SIZE * 2) - (i * 2),
			INTRO_ROW_SIZE + (FRAME_SIZE * 2) - (i * 2) - 2);
		++p.x;
		++p.y;
	}
}
