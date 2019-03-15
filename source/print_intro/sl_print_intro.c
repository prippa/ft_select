#include "print_intro.h"
#include <signal.h>
#include <math.h>

static t_bool	sl_is_valid_window(void)
{
	size_t	col;
	size_t	row;

	col = MAX(INTRO_COL_SIZE, INTRO_80S_COL_SIZE) + (FRAME_SIZE * 2);
	row = MAX(INTRO_ROW_SIZE, INTRO_80S_ROW_SIZE) + (FRAME_SIZE * 2)
		+ INFO_ROWS_SIZE + INTRO_80S_ROW_SIZE + SEPARATORS;
	if (sl_ws_col() < col + 1)
		return (false);
	else if (sl_ws_row() < row + 1)
		return (false);
	return (true);
}

static uint16_t	sl_get_80s_y(void)
{
	return ((uint16_t)ceil(
			(double)(sl_ws_row() - (
			INFO_ROWS_SIZE + SEPARATORS +
			INTRO_80S_ROW_SIZE + INTRO_ROW_SIZE + (FRAME_SIZE * 2))) / 2));
}

void			sl_print_intro(void)
{
	t_point		p;

	tputs(tgetstr("cl", NULL), 1, sl_print_key);
	if (sl_is_valid_window())
	{
		p.x = (uint16_t)ceil((double)(sl_ws_col() - INTRO_80S_COL_SIZE) / 2);
		p.y = sl_get_80s_y();
		sl_print_80s(p);
		p.x = (uint16_t)ceil(
			(double)(sl_ws_col() - (INTRO_COL_SIZE + (FRAME_SIZE * 2))) / 2);
		p.y += INTRO_80S_ROW_SIZE + 1;
		sl_print_frame(p);
		p.x += FRAME_SIZE;
		p.y += FRAME_SIZE;
		sl_print_name(p);
		read(STDIN_FILENO, NULL, 1);
	}
	signal(SIGWINCH, sl_sig_hendler);
}
