/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 12:44:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/07 16:48:59 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long int	ph_atoi(const char *str)
{
	int	index;
	long long int	result;

	index = 0;
	result = 0;
	while ((str[index] > '0' && str[index] <= '9') && str[index])
	{	
		result = result * 10;
		result = (result + (str[index] - '0'));
		index++;
	}
	if (str[index] != '\0' || result < INT_MIN || result > INT_MAX)
	{
		error_message(ERROR_INPUT);
		exit(ERROR_INPUT);
	}
	return (result);
}

int32_t	ph_strcmp(const char *str1, const char *str2)
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

static int32_t ph_strlen(const char *str)
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


void	ph_bzero(void *s, size_t amount)
{
	char	*zeroed_string;
	size_t	index;

	zeroed_string = (char *)s;
	index = 0;
	while (index < amount)
	{
		zeroed_string[index] = '\0';
		index++;
	}
}
