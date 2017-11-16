/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:51:56 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/15 19:54:05 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	if (to_find[0] == '\0')
		return (0);
	while (str[i])
	{
		x = i;
		y = 0;
		while (str[x] == to_find[y])
		{
			x++;
			y++;
			if (to_find[y] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
