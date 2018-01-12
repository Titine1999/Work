/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:22:48 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/13 14:06:36 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_str_is_lowercase(char *str)
{
	int i;
	int res;

	res = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			res = 0;
		i++;
	}
	return (res);
}