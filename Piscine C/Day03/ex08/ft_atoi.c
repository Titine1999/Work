/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:48:50 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/10 17:41:39 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_res(char a)
{
	return (a > 48 && a < 57);
}

int		ft_resultat(char *str, int i)
{
	int res;
	int b;

	b = 0;
	res = 0;
	while (str[i] && b == 0)
	{
		if (ft_res(str[i]) == 1)
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
		else
			b = 1;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	res = ft_resultat(str, i);
	return (sign * res);
}
