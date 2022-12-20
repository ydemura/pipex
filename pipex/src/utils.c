/*
	utils.c
	pipex

	Created by Yuliia Demura on 10/16/21.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "utils.h"

void	write_str_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	exit_beautifully(const char *message, t_error err)
{
	if (err == ERR)
	{
		write_str_fd(message, 2);
		write_str_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		exit(0);
}

int	check_word(char *word, int word_len, char *str)
{
	int	i;

	i = 0;
	while (i < word_len && (word[i] != '\0' || str[i] != '\0'))
	{
		if (word[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int	strlen_till_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*strdup_till_char(char *str, char c)
{
	int		i;
	char	*s2;
	int		len;

	len = strlen_till_char(str, c);
	i = 0;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
