/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:27:39 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/07 21:37:22 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
			f(s + i++);
	}
}
