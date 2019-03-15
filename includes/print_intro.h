#ifndef PRINT_INTRO_H
# define PRINT_INTRO_H

# include "ft_select.h"

# define INFO_ROWS_SIZE 5
# define FRAME_SIZE 5
# define INTRO_ROW_SIZE 7
// # define INTRO_COL_SIZE 104
# define INTRO_COL_SIZE 100

# define FRAME_USLEEP	1000
# define NAME_UP_TO_DOWN_USLEEP	3000
# define NAME_DOWN_TO_UP_USLEEP	500

void			sl_print_frame(t_point p);
void			sl_print_name(t_point p);

#endif
