#include "print_intro.h"
#include <signal.h>
#include <math.h>
#include <time.h>

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

static void		sl_print_background(void)
{
	t_point	w;
	t_point	i;
	int32_t	rand_number;

	w.x = sl_ws_col();
	w.y = sl_ws_row();
	i.y = -1;
	while (++i.y < w.y)
	{
		i.x = -1;
		while (++i.x < w.x)
			if ((rand_number = rand() % 30) == 0)
			{
				sl_goto(i.y, i.x);
				ft_dprintf(STDIN_FILENO, "%~c", F_NONE, C_WHITE, '*');
			}
	}
}

void			sl_print_intro(void)
{
	t_point		p;
	int64_t		tmp;

	tputs(tgetstr("cl", NULL), 1, sl_print_key);
	if (sl_is_valid_window())
	{
		srand(time(NULL));
		sl_print_background();
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
		p.x = (uint16_t)ceil((double)(sl_ws_col() - INFO_COL_SIZE) / 2);
		p.y += INTRO_ROW_SIZE + FRAME_SIZE  + 1;
		sl_print_info(p);
		read(STDIN_FILENO, &tmp, 8);
	}
	signal(SIGWINCH, sl_sig_hendler);
}
