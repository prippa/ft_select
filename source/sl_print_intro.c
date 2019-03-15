#include "ft_select.h"
#include <signal.h>
#include <math.h>

#define INFO_ROWS_SIZE 5
#define FRAME_SIZE 3
#define INTRO_ROW_SIZE 7
#define INTRO_COL_SIZE 104

const char	g_intro[INTRO_ROW_SIZE][INTRO_COL_SIZE] =
{
	"      :::::::::: :::::::::::           ::::::::  :\
::::::::: :::        :::::::::: :::::::: ::::::::::: ",
	"     :+:            :+:              :+:    :+: :+\
:        :+:        :+:       :+:    :+:    :+:      ",
	"    +:+            +:+              +:+        +:+\
        +:+        +:+       +:+           +:+       ",
	"   :#::+::#       +#+              +#++:++#++ +#++\
:++#   +#+        +#++:++#  +#+           +#+        ",
	"  +#+            +#+                     +#+ +#+  \
      +#+        +#+       +#+           +#+         ",
	" #+#            #+#              #+#    #+# #+#   \
     #+#        #+#       #+#    #+#    #+#          ",
	"###            ###    ########## ########  #######\
### ########## ########## ########     ###           ",
};

static t_bool	sl_is_valid_window(size_t *col, size_t *row)
{
	*col = INTRO_COL_SIZE + (FRAME_SIZE * 2) + 1;
	*row = INTRO_ROW_SIZE + (FRAME_SIZE * 2) + INFO_ROWS_SIZE + 1;
	if (sl_ws_col() < *col)
		return (false);
	else if (sl_ws_row() < *row)
		return (false);
	return (true);
}

static void		sl_print_intro_naem(t_point p)
{

}

static void		sl_print_intro_info(t_point p)
{

}

static void		sl_print_intro_frame(t_point p)
{
	uint16_t	row;
	uint16_t	col;

	row = INTRO_ROW_SIZE + (FRAME_SIZE * 2);
	while (row--)
	{
		sl_goto(p.y, p.x);
		col = INTRO_COL_SIZE + (FRAME_SIZE * 2);
		while (col--)
			ft_dprintf(STDIN_FILENO, "%~c", CT_BOLD, C_MAGENTA, '*');
		++p.y;
	}
}

void			sl_print_intro(void)
{
	t_point		p;
	size_t		col;
	size_t		row;

	tputs(tgetstr("cl", NULL), 1, sl_print_key);
	if (sl_is_valid_window(&col, &row))
	{
		p.x = (uint16_t)ceil((double)sl_ws_col() / col);
		p.y = (uint16_t)ceil((double)sl_ws_row() / row);
		sl_print_intro_frame(p);
		sl_print_intro_naem(p);
		sl_print_intro_info(p);
		read(STDIN_FILENO, NULL, 1);
	}
	signal(SIGWINCH, sl_sig_hendler);
}


**********