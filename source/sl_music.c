#include "ft_select.h"

void		sl_music_on(void)
{
	system("afplay ./../song/Dynatron_Intergalactic_Highway.mp3&");
	// system("ls /dev/");
	// sleep(3);
}

void		sl_music_off(void)
{
	system("pkill afplay 2>&-");
}
