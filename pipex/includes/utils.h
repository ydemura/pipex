/*
	utils.h
	pipex

	Created by Yuliia Demura on 10/16/21.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_error
{
	OK = 0,
	ERR = -404
}	t_error;

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	temp_file;
	int	pipe[2];
}	t_fd;

void	exit_beautifully(const char *message, t_error err);
void	write_str_fd(const char *str, int fd);
int		check_word(char *word, int word_len, char *str);
char	*strdup_till_char(char *str, char c);
void	free_double_array(char **array);

#endif /* utils_h */
