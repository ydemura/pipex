//
//  main.c
//  header_changer
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "unistd.h"
// #include "stdin.h"

int	main(int argc, char **argv)
{
	int i = 0;
	char *str = argv[1];
	char n = '\n';
	write(1, &n, 1);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			char c = str[i] - 32;
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
	}
	write(1, &n, 1);
	return (0);
}
