/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/14 15:48:09 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_sig(int signum, siginfo_t *info, void *ptr)
{
	(void)signum;
	(void)info;
	(void)ptr;
	ft_printf("ET NON TU VA FAIRE QUOI C'EST PAS BIEN D'EXIT COMME CA");
}

