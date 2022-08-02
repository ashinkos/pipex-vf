/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:40:16 by aaouni            #+#    #+#             */
/*   Updated: 2022/08/02 22:58:44 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

int	len_2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		free(str[i]);
		i++;
	}
	free(str);
}

char	**get_path_env(char **env)
{
	char	**path;
	char	**path_slash;
	char	*path_str;
	t_cmpt	t;

	t.j = -1;
	t.i = 0;
	while (env[t.i])
	{
		if (ft_strncmp(env[t.i], "PATH", 4) == 0)
		{
			path_str = env[t.i] + 5;
			path = ft_split(path_str, ':');
			path_slash = malloc (sizeof(char *) * (len_2d(path) + 1));
			if (!path_slash)
				return (NULL);
			while (path[++t.j])
				path_slash[t.j] = ft_strjoin(path[t.j], "/");
			free_2d(path);
			path_slash[t.j] = NULL;
			return (path_slash);
		}
		t.i++;
	}
	return (NULL);
}

char	**get_path_cmd(char *str, char **path)
{
	int		i;
	char	**cmd;
	char	*path_cmd;

	i = 0;
	cmd = ft_split(str, ' ');
	if (access(cmd[0], X_OK) == 0)
		return (cmd);
	// else if (ft_strncmp(cmd[0], "./", 2) == 0 && str)
	// {
	// 	// (void)str;
	// 	perror("pipex");
	// 	exit(1);
	// }
	while (path[i])
	{
		path_cmd = ft_strjoin(path[i], cmd[0]);
		if (access(path_cmd, X_OK) == 0)
		{
			free (cmd [0]);
			cmd[0] = ft_strdup(path_cmd);
			free(path_cmd);
			return (cmd);
		}
		free(path_cmd);
		i++;
	}
	return (NULL);
}
