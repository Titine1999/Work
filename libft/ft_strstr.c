/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:26:01 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/10 01:55:16 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (*haystack)
	{
		if (!(ft_strcmp(haystack, needle)
			return (needle);
		haystack++;
	}
return (0);
}
