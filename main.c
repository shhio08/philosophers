/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:52:09 by stakimot          #+#    #+#             */
/*   Updated: 2023/04/26 19:44:24 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*my_fanc(void *arg)
{
	printf("my_fanc\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, my_fanc, NULL);
	pthread_join(tid, NULL);
	printf("main\n");
	return (0);
}