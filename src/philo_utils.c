/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:37:05 by stakimot          #+#    #+#             */
/*   Updated: 2023/05/30 20:38:59 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	have_fork(t_philo *philo)
{
	if (philo->philo_number % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_move(philo, TAKEN_FORK);
		pthread_mutex_lock(philo->r_fork);
		print_move(philo, TAKEN_FORK);
	}
	else
	{
		usleep(10);
		pthread_mutex_lock(philo->r_fork);
		print_move(philo, TAKEN_FORK);
		usleep(50);
		pthread_mutex_lock(philo->l_fork);
		print_move(philo, TAKEN_FORK);
	}
}

void	happy_eat(t_philo *philo)
{
	print_move(philo, EAT);
	my_usleep(philo->info->eat);
	if (philo->philo_number % 2 == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	pthread_mutex_lock(&philo->info->check_die);
	philo->last_eat = get_now_time();
	pthread_mutex_unlock(&philo->info->check_die);
	philo->eat_cnt++;
}

void	happy_think(t_philo *philo)
{
	print_move(philo, THINK);
}

void	happy_sleep(t_philo *philo)
{
	print_move(philo, SLEEP);
	my_usleep(philo->info->sleep);
}
