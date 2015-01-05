/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:05:23 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/17 14:04:01 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_len_c_stop(const char *str, int start, char c_stop)
{
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && (str[start] != c_stop))
	{
		start++;
		counter++;
	}
	return (counter);
}

static int		ft_retln(char *str, char **line, t_data *data)
{
	int		len_str;
	char	*tmp;
	char	*tmp_l;

	len_str = 0;
	if (ft_strchr(str, '\n') == 0)
	{
		tmp_l = *line;
		*line = ft_strjoin(tmp_l, str);
		free(tmp_l);
	}
	else
	{
		len_str = ft_len_c_stop(str, 0, '\n');
		tmp = ft_strsub(str, 0, len_str);
		tmp_l = *line;
		*line = ft_strjoin(tmp_l, tmp);
		free(tmp_l);
		free(tmp);
		tmp = ft_strsub(str, len_str + 1, ft_strlen(str) - len_str);
		free(data->save_buf);
		data->save_buf = tmp;
		return (1);
	}
	return (0);
}

static int		ft_read_line(int fd, char *buf, char **line, t_data *data)
{
	int	ret;

	ret = 0;
	if (!(data->save_buf))
		data->save_buf = ft_strdup("");
	if (ft_retln(data->save_buf, line, data) == 1)
		return (data->is_read = 1);
	free(data->save_buf);
	data->save_buf = ft_strdup("");
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		if (ft_retln(buf, line, data) == 1)
			return (1);
		data->is_read = 1;
	}
	if (ret == -1)
		return (-1);
	if (data->is_read == 1)
	{
		data->is_read = 0;
		if (ft_strcmp("", *line) != 0)
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	char			*buf;
	int				result;
	static t_data	*data;

	if (!line)
		return (-1);
	if (!data)
		if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
			return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	buf[0] = 0;
	*line = ft_strdup("");
	result = ft_read_line(fd, buf, line, data);
	if ((result == 0) || (result == -1))
	{
		free(data->save_buf);
		free(data);
	}
	free(buf);
	return (result);
}
