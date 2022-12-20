/*
	loop_cmds.h
	pipex

	Created by Julia Demura on 13/11/2021.
	Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#ifndef LOOP_CMDS_H
# define LOOP_CMDS_H

# include "manage_fd.h"

pid_t	*loop_through_commands(t_params *params, t_fd fd);
void	loop_through_waitpid(t_params *params);

#endif /* new_attempt_h */
