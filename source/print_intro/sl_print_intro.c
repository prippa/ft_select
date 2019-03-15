#include "print_intro.h"
#include <signal.h>
#include <math.h>

static t_bool	sl_is_valid_window(size_t *col, size_t *row)
{
	*col = INTRO_COL_SIZE + (FRAME_SIZE * 2);
	*row = INTRO_ROW_SIZE + (FRAME_SIZE * 2) + INFO_ROWS_SIZE;
	if (sl_ws_col() < *col + 1)
		return (false);
	else if (sl_ws_row() < *row + 1)
		return (false);
	return (true);
}

void			sl_print_intro(void)
{
	t_point		p;
	size_t		col;
	size_t		row;

	tputs(tgetstr("cl", NULL), 1, sl_print_key);
	if (sl_is_valid_window(&col, &row))
	{
		p.x = (uint16_t)ceil((double)(sl_ws_col() - col) / 2);
		p.y = (uint16_t)ceil((double)(sl_ws_row() - row) / 2) - INFO_ROWS_SIZE;
		sl_print_frame(p);
		p.x += FRAME_SIZE;
		p.y += FRAME_SIZE;
		sl_print_name(p);
		read(STDIN_FILENO, NULL, 1);
	}
	signal(SIGWINCH, sl_sig_hendler);
}
