/*
	manage_fd.h
	pipex

	Created by Yuliia Demura on 11/16/21.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#ifndef MANAGE_FD_H
# define MANAGE_FD_H

# include "read_input.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>

void	pick_fd_for_child(int i, t_params *params, t_fd *fd);
void	manage_parent_fd(int i, t_params *params, t_fd *fd);
void	check_for_leaks(t_params *params);

#endif /* manage_fd_h */
