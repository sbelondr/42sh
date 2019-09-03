/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 09:47:57 by sbelondr          #+#    #+#             */
/*   Updated: 2019/03/20 09:48:25 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*info_display(char *buf)
{
	int		i;
	char	*tmp;
	char	*dst;

	tmp = value_line_path("HOME", 0);
	if (!tmp)
	{
		dst = ft_strdup(buf);
		return (dst);
	}
	i = -1;
	while (tmp[++i])
		if ((!buf[i]) || tmp[i] != buf[i])
		{
			dst = ft_strdup(buf);
			ft_strdel(&tmp);
			return (dst);
		}
	ft_strdel(&tmp);
	tmp = ft_strsub(buf, i, ft_strlen(buf));
	dst = ft_strjoin("~", tmp);
	ft_strdel(&tmp);
	return (dst);
}

static char	*pwd_display(void)
{
	char	*line;
	char	*path;
	char	buf[BUF_S];

	ft_bzero(buf, BUF_S);
	path = getcwd(buf, BUF_S);
	if (!path)
	{
		line = value_line_path("PWD", 0);
		if (line)
		{
			ft_cpy_str(&buf, line);
			ft_strdel(&line);
		}
	}
	path = info_display(buf);
	return (path);
}

void		display_prompt(void)
{
	char	*path;
	char	*user;

	path = pwd_display();
	user = value_line_path("USER", 0);
	ft_printf("❰\033[34;01m%s\033[00m ❙\033[33;01m%s\033[00m❱ ", user, path);
	if (check_last_command() == 0)
		ft_printf("\033[32;01m✔\033[00m > ");
	else
		ft_printf("\033[31;01m✘\033[00m > ");
	ft_strdel(&path);
	ft_strdel(&user);
}
