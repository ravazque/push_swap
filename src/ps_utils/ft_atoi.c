/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:56:38 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:13:01 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static float	check_limits(long num, int sign)
{
	if (sign == 1 && num > INT_MAX)
		return (-1);
	if (sign == -1 && (num * sign) < INT_MIN)
		return (-1);
	return (num);
}

static int	parse_sign(const char *nptr, int *index, int *res)
{
	int	sign;

	sign = 1;
	while (nptr[*index] == ' ')
		*index = *index + 1;
	if (nptr[*index] == '-')
	{
		if (nptr[*index + 1] == '-' || nptr[*index + 1] == '+')
			return (*res = 0, 0);
		sign = -1;
		*index = *index + 1;
	}
	if (nptr[*index] == '+')
	{
		if (nptr[*index + 1] == '-' || nptr[*index + 1] == '+')
			return (*res = 0, 0);
		*index = *index + 1;
	}
	return (sign);
}

static int	parse_number(const char *nptr, int *index, long *num, int sign)
{
	while (nptr[*index] >= '0' && nptr[*index] <= '9')
	{
		*num = *num * 10 + nptr[*index] - '0';
		if (check_limits(*num, sign) < 0)
			return (0);
		*index = *index + 1;
	}
	return (1);
}

int	*ft_atoi(const char *nptr, int *res, int *index)
{
	long	num;
	int		sign;

	num = 0;
	sign = parse_sign(nptr, index, res);
	if (sign == 0)
		return (NULL);
	if (nptr[*index] < '0' || nptr[*index] > '9')
		return (*res = 0, NULL);
	if (!parse_number(nptr, index, &num, sign))
		return (*res = 0, NULL);
	if ((nptr[*index] < '0' || nptr[*index] > '9') && nptr[*index] != '\0'
		&& nptr[*index] != ' ')
	{
		return (*res = 0, NULL);
	}
	while (nptr[*index] == ' ')
		*index = *index + 1;
	if ((nptr[*index] < '0' || nptr[*index] > '9') && nptr[*index] != '\0'
		&& nptr[*index] != '+' && nptr[*index] != '-')
	{
		return (*res = 0, NULL);
	}
	*res = num * sign;
	return (res);
}
