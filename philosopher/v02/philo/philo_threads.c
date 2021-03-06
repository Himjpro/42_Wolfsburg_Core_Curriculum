/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:40:24 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/29 17:43:25 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *ph, int s)
{
	int		i;

	i = 0;
	while (i < s)
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
	while (i < s)
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


// void	sim_end_init(t_philo *ph, pthread_t *sim_end)
// {
// 	pthread_create(sim_end, NULL, &end_thread, ph);
// 	pthread_join(*sim_end, NULL);
// }
void philo_detach(t_philo *ph)
{
	pthread_detach(ph->p);
}

void exit_free(t_philo *ph)
{
	int i;
	pthread_mutex_lock(&ph->shared->write);
	i = 0;
	// pthread_mutex_lock(&r->write);
	// usleep((r->time_eat) * 1000);
	// mutex_des(r);
	while (i < ph->nb_philos)
	{
		philo_detach(&ph[i]);
		i++;
	}
	
	free(ph);
	// pthread_mutex_unlock(&r->write);
	pthread_mutex_unlock(&ph->shared->write);
	free(ph->shared->fork);

}