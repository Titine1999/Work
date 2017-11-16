/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:09:28 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/13 14:03:54 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 90 && str[i] >= 65)
			str[i] = str[i] + 32;
		i++;
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	ft_strlowcase(str);
	if (str[0] <= 122 & str[0] >= 97)
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
		{
			while (str[i] && !((str[i] <= 'z' && str[i] >= 'a')
						|| (str[i] <= 'Z' && str[i] >= 'A')
						|| (str[i] <= '9' && str[i] >= '0')))
			{
				str[i + 1] = str[i + 1] - 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}
