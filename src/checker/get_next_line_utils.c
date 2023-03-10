/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:10:44 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/20 18:56:46 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_new_str_buf(char *str_buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str_buf[i] && str_buf[i] != '\n')
		i++;
	if (!str_buf[i])
	{
		free(str_buf);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_buf) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str_buf[i])
		str[j++] = str_buf[i++];
	str[j] = '\0';
	free(str_buf);
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
