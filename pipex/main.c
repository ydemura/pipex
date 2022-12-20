/*
	main.c
	pipex

	Created by Yuliia Demura on 11/16/21.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "loop_cmds.h"

void	initiate_fd_struct(t_fd *fd)
{
	fd->infile = -1;
	fd->outfile = -1;
	fd->temp_file = -1;
	fd->pipe[0] = -1;
	fd->pipe[1] = -1;
}

void	initiate_pids_arr(t_params *params)
{
	params->child_pids = malloc(sizeof(pid_t) * params->index);
	if (params->child_pids == NULL)
		exit_beautifully("malloc failed in loop_cmds:15", ERR);
}

void	free_double_array(char **array)
{
	int	n;

	n = 0;
	if (array == NULL)
		return ;
	while (array[n] != NULL)
	{
		free(array[n]);
		n++;
	}
}

void	check_for_leaks(t_params *params)
{
	int	i;

	i = 0;
	if (params->cmds != NULL)
	{
		while (i < params->index)
		{
			if (params->cmds[i].cmd_path != NULL)
				free(params->cmds[i].cmd_path);
			free_double_array(params->cmds[i].cmd_arr);
			i++;
		}
	}
	if (params->cmds != NULL)
		free(params->cmds);
}

int	main(int argc, const char *argv[], const char *envp[])
{
	t_params	params;
	t_fd		fd;

	initiate_fd_struct(&fd);
	params.envp = (char **)envp;
	collect_input(argv, argc, &params);
	initiate_pids_arr(&params);
	params.child_pids = loop_through_commands(&params, fd);
	loop_through_waitpid(&params);
	check_for_leaks(&params);
	return (params.res_wait_status);
}
