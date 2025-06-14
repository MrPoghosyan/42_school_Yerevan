/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:13:41 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 13:16:26 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		exit(1);
	}
}

int	empty_argument(const char *str)
{
	int	i;
	int	signal;

	if (!str || !*str)
		return (1);
	i = 0;
	signal = 1;
	while (str[i])
	{
		if (str[i] != ' ')
			signal = 0;
		i++;
	}
	return (signal);
}

void	free_split(char **line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

char	*get_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*result;
	char	*tmp;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	result = (char *)malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);
	tmp = result;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	while (*s3)
		*tmp++ = *s3++;
	*tmp = '\0';
	return (result);
}
