/*
	loop_cmds.c
	pipex

	Created by Julia Demura on 13/11/2021.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "loop_cmds.h"

char	*check_correct_path(char *command, char *possible_path)
{
	char	*new_path;

	new_path = ft_strjoin(possible_path, command);
	if (new_path == NULL)
		return (NULL);
	if (access(new_path, R_OK) == 0)
		return (new_path);
	else
	{
		free(new_path);
		return (NULL);
	}
	return (NULL);
}

char	*find_path(char *command, char **possibl_paths)
{
	char	*correct_path;
	int		i;

	correct_path = NULL;
	command = ft_strjoin("/", command);
	if (command == NULL)
		exit_beautifully("oops, main.c:86", ERR);
	i = 0;
	while (possibl_paths[i] != NULL)
	{
		correct_path = check_correct_path(command, possibl_paths[i]);
		if (correct_path == NULL)
			i++;
		else
			break ;
	}
	free(command);
	return (correct_path);
}

void	loop_through_waitpid(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->index)
	{
		waitpid(params->child_pids[i], &params->wait_status, 0);
		params->res_wait_status = WEXITSTATUS(params->wait_status);
		i++;
	}
}

pid_t	*loop_through_commands(t_params *params, t_fd fd)
{
	int	i;

	i = 0;
	while (i < params->index)
	{
		params->cmds[i].cmd_path = find_path(params->cmds[i].cmd_arr[0],
				params->possible_pathes);
		if (i != params->index - 1)
			if (pipe(fd.pipe) < 0)
				exit_beautifully("pipe made a mistake, 42", ERR);
		params->child_pids[i] = fork();
		if (params->child_pids[i] < 0)
			exit_beautifully("fork made a mistake, 45", ERR);
		if (params->child_pids[i] == 0)
		{
			pick_fd_for_child(i, params, &fd);
			execve(params->cmds[i].cmd_path, params->cmds[i].cmd_arr,
				   params->envp);
			exit_beautifully("execve made a mistake, 45", ERR);
		}
		manage_parent_fd(i, params, &fd);
		i++;
	}
	return (params->child_pids);
}
