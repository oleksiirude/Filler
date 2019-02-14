/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:39:37 by olrudenk          #+#    #+#             */
/*   Updated: 2018/12/05 15:39:41 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		clean_elem(int fd, t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*head;

	head = *lst;
	while (head)
	{
		if (head->fd == fd)
			if (*lst == head)
			{
				free((*lst)->buf);
				free(*lst);
				*lst = head->next;
				return (0);
			}
		if (head->next->fd == fd)
		{
			tmp = head->next;
			head->next = head->next->next;
			free(tmp->buf);
			free(tmp);
			break ;
		}
		head = head->next;
	}
	return (0);
}

static	int		check_sn(t_lst *lst, char **line)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	tmp1 = *line;
	while (lst->buf[++i])
	{
		if (lst->buf[i] == '\n')
		{
			tmp2 = ft_strsub(lst->buf, 0, i);
			*line = ft_strjoin(*line, tmp2);
			free(tmp2);
			free(tmp1);
			tmp1 = lst->buf;
			lst->buf = ft_strsub(lst->buf, i + 1, BUFF_SIZE);
			free(tmp1);
			return (1);
		}
	}
	*line = ft_strjoin(*line, lst->buf);
	free(tmp1);
	if (lst->rb == 0 && (ft_strlen(*line) > 0))
		return (1);
	return (0);
}

static	t_lst	*cr_elem(int fd, t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(tmp->buf = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	ft_bzero(tmp->buf, BUFF_SIZE + 1);
	tmp->fd = fd;
	tmp->rb = -1;
	tmp->next = NULL;
	lst->next = tmp;
	return (tmp);
}

static	t_lst	*cr_head(int fd, t_lst *lst)
{
	if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(lst->buf = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	ft_bzero(lst->buf, BUFF_SIZE + 1);
	lst->fd = fd;
	lst->rb = -1;
	lst->next = NULL;
	return (lst);
}

int				get_next_line(const	int fd, char **line)
{
	static t_lst	*lst = NULL;
	t_lst			*tmp;

	if (!line || fd < 0 || BUFF_SIZE < 1 || (read(fd, 0, 0)) < 0)
		return (-1);
	*line = ft_strdup("");
	if (!lst)
		if (!(lst = cr_head(fd, lst)))
			return (-1);
	if (!(tmp = cr_elem(fd, lst)))
		return (-1);
	if (ft_strlen(tmp->buf) > 0)
		if (check_sn(tmp, line) == 1)
			return (1);
	if (!tmp->rb)
		return (clean_elem(fd, &lst));
	while ((tmp->rb = read(tmp->fd, tmp->buf, BUFF_SIZE)) >= 0)
	{
		tmp->buf[tmp->rb] = 0;
		if (check_sn(tmp, line) > 0 || (!tmp->rb && ft_strlen(*line)))
			return (1);
		if (!ft_strlen(tmp->buf))
			return (clean_elem(fd, &lst));
	}
	return (0);
}
