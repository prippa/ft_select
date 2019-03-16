/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_song.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:41:00 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 11:41:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#define SONG_SIZE 3

#define PREF "afplay ./music/"
#define POSTF "&"
#define SONG_1 PREF "Back_To_The_80s_FM_Attack_Sleepless_Nights.mp3" POSTF
#define SONG_2 PREF "Citizen_12B_Moonscrape.mp3" POSTF
#define SONG_3 PREF "Tommy_86_Outrun.mp3" POSTF

const char	*g_song_list[SONG_SIZE] =
{
	SONG_1,
	SONG_2,
	SONG_3
};

void		sl_init_song(char ***argv)
{
	uint32_t i;

	++(*argv);
	if (!**argv || !ft_is_str_digit(**argv))
		return ;
	i = ft_atoi(**argv);
	if (i < 1 || i > SONG_SIZE)
		return ;
	sl()->music = true;
	sl()->music_cmd = g_song_list[i - 1];
}
