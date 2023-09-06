/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 12:44:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/06 14:33:05 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ph_strcmp(const char *str1, const char *str2)
{
	size_t	index;

	index = 0;

	while (str1[index] != '\0' && str2[index] != '\0' && str1[index] == str2[index])
        index++;
	if (str1[index] == '\0' && str2[index] == '\0')
		return (0);
	else
		return (1);
}

static uint32_t	ph_strlen(const char *str)
{
	int	len;
	if (!str)
		return (0);
	len = 0;
	while(str[len])
		len++;
	return(len);
}

void	ph_putstr_fd(const int fd, const char *message)
{
	if (!message)
	{
		ph_putstr_fd(fd, "(null)");
		return ;
	}
	write (fd, message, ph_strlen(message));
}
