#include "ft_select.h"
#include <signal.h>
#include <sys/ioctl.h>

#define INTRO_ROW_SIZE 7
#define INTRO_COL_SIZE 104

t_bool		ok_w_size;
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

void		sl_print_window_rwh(int32_t sig)
{

	(void)sig;

}

static void	sl_set_ok_w_size(void)
{
	struct winsize	w;
	
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
}

void		sl_print_intro(void)
{
	t_bool	msc[INTRO_ROW_SIZE][INTRO_COL_SIZE];

	tputs(tgetstr("cl", NULL), 1, sl_print_key);
	ft_bzero(&msc, sizeof(msc));
	signal(SIGWINCH, sl_sig_hendler);
}

