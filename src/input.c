/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:53:35 by achepurn          #+#    #+#             */
/*   Updated: 2018/09/01 13:53:37 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int				read_ants(int fd, t_board *board)
{
	char	*str;
	char	*src;
	int		res;

	get_next_line(fd, &src);
	str = src;
	res = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str)
		res = 0;
	board->num = res;
	if (res)
		ft_putendl(src);
	free(src);
	return (res);
}

int				read_comment(char *str)
{
	if (ft_strequ("##start", str))
		return (R_START);
	if (ft_strequ("##end", str))
		return (R_END);
	if (ft_strnequ("#", str, 1))
		return (-1);
	return (0);
}

static char		*parse_name(char **str)
{
	int		i;
	char	*name;

	if (**str == 'L' || IS_SPACE(**str))
		return (NULL);
	i = 0;
	while ((*str)[i] && !(IS_SPACE((*str)[i])))
		i++;
	name = ft_strsub(*str, 0, i);
	*str += i;
	return (name);
}

static int		parse_coord(char **str)
{
	int	res;

	if (**str == ' ')
		(*str)++;
	else
		return (-1);
	res = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str != ' ' && **str)
		return (-1);
	return (res);
}

t_room			*parse_room(char *str, int comment)
{
	char	*name;
	int		x;
	int		y;
	t_room	*room;

	if (!(name = parse_name(&str)))
		return (NULL);
	x = parse_coord(&str);
	y = parse_coord(&str);
	if (x == -1 || y == -1 || *str)
	{
		free(name);
		return (NULL);
	}
	room = new_room(name, x, y);
	if (comment < -1 && room)
		room->status = comment;
	return (room);
}
