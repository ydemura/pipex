/*
	read_input.c
	pipex

	Created by Yuliia Demura on 10/16/21.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "read_input.h"

char	**find_possible_pathes(char *env_path_options)
{
	char	**possible_pathes;
	int		i;

	possible_pathes = ft_split(env_path_options, ':');
	if (possible_pathes == NULL)
		exit_beautifully("oops, main.c:86", ERR);
	i = 0;
	return (possible_pathes);
}

char	*find_path_options(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (check_word("PATH=/", 6, env[i]) == 1)
		{
			while (*env[i] != ':' && *env[i] != '\0')
				env[i]++;
			break ;
		}
		i++;
	}
	if (env[i] == NULL)
		return (NULL);
	return (env[i]);
}

char	*trim_extra_quotes(char *str)
{
	char	*trimmed_str;

	if (*str == '\"')
	{
		trimmed_str = ft_strtrim(str, "\"");
		if (trimmed_str == NULL)
			return (NULL);
		else
			return (trimmed_str);
	}
	else if (*str == '\'')
	{
		trimmed_str = ft_strtrim(str, "\'");
		if (trimmed_str == NULL)
			return (NULL);
		else
			return (trimmed_str);
	}
	trimmed_str = ft_strdup(str);
	return (trimmed_str);
}

void	handle_one_command(char *str, t_cmd *cmds, int i)
{
	int		n;
	char	*second_str;

	n = 0;
	second_str = NULL;
	cmds[i].cmd_arr[n] = strdup_till_char(str, ' ');
	if (cmds[i].cmd_arr[n] == NULL)
		exit_beautifully("malloc faied\nread_input.c:110", ERR);
	n++;
	while (*str != ' ' && *str != '\0')
		str++;
	if (*str == '\0')
		cmds[i].cmd_arr[n] = NULL;
	else
	{
		str++;
		cmds[i].cmd_arr[n] = trim_extra_quotes(str);
		if (cmds[i].cmd_arr[n] == NULL)
			exit_beautifully("malloc faied\nread_input.c:86", ERR);
		cmds[i].cmd_arr[n + 1] = NULL;
	}
}

void	collect_input(const char **argv, int argc, t_params *params)
{
	int	j;

	if (argc < 5)
		exit_beautifully("infile cmd1 cmd2 ... cmd_n outfile\nread_input.c:32",
			ERR);
	params->path_infile = (char *)argv[1];
	params->path_outfile = (char *)argv[argc - 1];
	params->envp_path_options = find_path_options(params->envp);
	params->possible_pathes = find_possible_pathes(params->envp_path_options);
	j = 2;
	params->index = 0;
	params->cmds = malloc(argc * sizeof(t_cmd));
	if (params->cmds == NULL)
		exit_beautifully("malloc faied\nread_input.c:44", ERR);
	while (j < argc - 1)
	{
		handle_one_command((char *)argv[j], params->cmds, params->index);
		params->index++;
		j++;
	}
}
