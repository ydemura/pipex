/*
	read_input.h
	pipex

	Created by Yuliia Demura on 10/16/21.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#ifndef READ_INPUT_H
# define READ_INPUT_H

# include "libft.h"
# include "utils.h"

typedef struct t_cmd
{
	char	*cmd_arr[3];
	char	*cmd_path;
	int		n;
}	t_cmd;

typedef struct s_params
{
	char	**envp;
	char	*envp_path_options;
	char	**possible_pathes;
	char	*path_infile;
	char	*path_outfile;
	t_cmd	*cmds;
	int		index;
	int		wait_status;
	int		res_wait_status;
	pid_t	*child_pids;
}	t_params;

void	collect_input(const char **argv, int argc, t_params *params);

#endif /* read_input_h */
