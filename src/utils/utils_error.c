/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/07 11:59:41 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/07 12:17:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	check_digits_only(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{ 
		j = 0; 
		while (argv[i][j]) 
		{ 
            // if (((argv[i][j] >= '0') && (argv[i][j] <= '9')) || (argv[i][j] == '-')) 
			if (((argv[i][j] >= '0') && (argv[i][j] <= '9'))) 
				j++;
			else
                return (ERROR_INPUT);
		}
		// j = 0;
		// if (check_double_minus(argv[i]) == 1)
		// {
		// 	ft_printf ("Error\n");
		// 	exit(EXIT_FAILURE);
		// }
		i++;
	}
    return (SUCCESS);
}

// int	check_double_minus(char *string)
// {
// 	int	index;

// 	index = 1;
// 	while (string[index] != '-')
// 	{
// 		if (string[index] == '\0')
// 			return (0);
// 		index++;
// 	}
// 	return (1);
// }

// void	lenght_check(long long int number)
// {
// 	if (number < INT_MIN || number > INT_MAX)
// 	{
// 		ft_printf ("Error\n");
// 		exit (EXIT_FAILURE);
// 	}
// }
