/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:17:31 by aaouni            #+#    #+#             */
/*   Updated: 2022/08/02 15:22:37 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_varint
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	infile;
	int	outfile;	
}					t_varint;

typedef struct s_varstr2
{
	char	**path;
	char	**cmd1;
	char	**cmd2;	
}					t_varstr2;

typedef struct s_cmpt
{
	int	i;
	int	j;	
}					t_cmpt;

char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**get_path_env(char **env);
char	**get_path_cmd(char *str, char **path);
int		len_2d(char **str);
void	free_2d(char **str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

#endif