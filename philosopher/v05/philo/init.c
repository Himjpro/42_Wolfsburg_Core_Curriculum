/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:35:59 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/30 00:23:30 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	shared_init(t_shared *sh, int s)
{
	int	i;

	i = 0;
	while (i < s)
		pthread_mutex_init(&sh->fork[i++], NULL);
	pthread_mutex_init(&sh->write, NULL);
	pthread_mutex_init(&sh->update, NULL);
	pthread_mutex_init(&sh->life, NULL);
	pthread_mutex_lock(&(sh->update));
	sh->flag_ate = 0;
	sh->flag_die = 0;
	pthread_mutex_unlock(&(sh->update));
}

void	sub_init(t_philo *ph, t_shared *sh, int i)
{
		ph->id = i;
		ph->left_fork_id = i;
		ph->right_fork_id = (i + 1) % ph->nb_philos;
		ph->last_meal_time = 0;
		ph->nb_had_eat = 0;
		ph->flag_ate_enough = 0;
		ph->flag_died = 0;
		ph->shared = sh;
}

void	philos_init(t_philo *ph, t_shared *sh, char *argv[], int argc)
{
	int	i;
	int	t;

	i = 0;
	t = timestamp();
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&(ph[i].update), NULL);
		pthread_mutex_init(&(ph[i].meal), NULL);
		pthread_mutex_init(&(ph[i].life), NULL);
		pthread_mutex_init(&(ph[i].time), NULL);
		pthread_mutex_lock(&ph[i].update);
		ph[i].nb_philos = ft_atoi(argv[1]);
		ph[i].die_time = ft_atoi(argv[2]);
		ph[i].eat_time = ft_atoi(argv[3]);
		ph[i].sleep_time = ft_atoi(argv[4]);
		if (argc == 6)
			ph[i].nb_must_eat = ft_atoi(argv[5]);
		else
			ph[i].nb_must_eat = 0;
		ph[i].start_time = t;
		sub_init(&ph[i], sh, i);
		pthread_mutex_unlock(&ph[i].update);
		i++;
	}
}
