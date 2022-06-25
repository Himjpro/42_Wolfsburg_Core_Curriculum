/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:40:24 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/25 19:02:52 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *ph)
{
	int		i;

	i = 0;
	while (i < ph[0].nb_philos)
	{
		if (pthread_create(&(ph[i].p), NULL, &philo_thread, &(ph[i])) != 0)
		{
			printf("could not create thread for philosopher %d", i);
			// exit_free(ph);
			exit(1);
		}
		i += 1;
	}
	i = 0;
	while (i < ph[0].nb_philos)
	{
		if (pthread_join(ph[i].p, NULL) != 0)
		{
			printf("could not join the thread for philosopher %d", i);
			// exit_free(ph);
			exit(1);
		}
		i += 1;
	}
}

void philo_detach(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].nb_philos)
	{
		if (pthread_detach(ph[i].p) != 0)
		{
			printf("could not detach the thread for philosopher %d", i);
			// exit_free(ph);
			exit(1);
		}
		i += 1;
	}
	free(ph);
}

// void exit_free(t_philo *ph)
// {
// 	pthread_mutex_lock(&r->ex);
// 	// pthread_mutex_lock(&r->write);
// 	// usleep((r->time_eat) * 1000);
// 	// mutex_des(r);
// 	philo_detach(r);
// 	// pthread_mutex_unlock(&r->write);
// 	pthread_mutex_unlock(&r->ex);
	
// }