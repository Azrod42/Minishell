/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:47:25 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/17 18:30:08 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	size_t	ret;

	va_start(arg, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strrchr_ptf("cspdiuxX", (int)str[i + 1]) != 0)
			ft_printf_redirect(str[i + 1], va_arg(arg, CINT), &ret, &i);
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_printf_redirect(str[i + 1], 1, &ret, &i);
		else
		{
			ft_putchar_fd_ptf(str[i++], 1);
			ret++;
		}
	}
	va_end(arg);
	return (ret--);
}
