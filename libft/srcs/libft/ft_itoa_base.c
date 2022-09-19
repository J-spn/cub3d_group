/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:32:42 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/09/17 20:00:37 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_len(int *len, unsigned long tmp_nbr, int base)
{
	if (tmp_nbr == 0)
		*len += 1;
	while (tmp_nbr > 0)
	{
		tmp_nbr /= base;
		*len += 1;
	}
}

char	*ft_itoa_base(unsigned long nbr, int base, char l_case)
{
	int				len;
	unsigned long	tmp_nbr;
	char			*str;

	tmp_nbr = nbr;
	len = 0;
	ft_itoa_len(&len, tmp_nbr, base);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
		{
			if (l_case == 'u')
				str[len - 1] += 'A' - 10;
			else if (l_case == 'l')
				str[len - 1] += 'a' - 10;
		}
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}
