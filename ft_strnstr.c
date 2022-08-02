/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:45:07 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/28 19:21:29 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;
	char	*ret;

	if (!haystack && len == 0 && needle)
		return (NULL);
	ret = (char *)haystack;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return (ret);
	i = 0;
	while (ret[i] && i < len)
	{
		if ((ft_strncmp(ret + i, needle, len_needle)) == 0
			&& (i + len_needle) <= len)
			return (ret + i);
		i++;
	}
	return (NULL);
}
