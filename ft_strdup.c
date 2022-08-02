/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:12:43 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/30 02:15:15 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		s1_l;
	char	*dst;
	int		i;

	s1_l = ft_strlen(s1);
	dst = (char *) malloc(sizeof(char) * s1_l + 1);
	if (dst == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
