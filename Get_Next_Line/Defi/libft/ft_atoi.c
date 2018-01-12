/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:13:58 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/17 23:38:01 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_res(char a)
{
	return (a >= '0' && a <= '9');
}

static int			ft_resultat(const char *str, int i)
{
	long int		res;

	res = 0;
	while (str[i])
	{
		if (ft_res(str[i]) == 1)
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
		else
			break ;
	}
	return (res);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		res;

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
