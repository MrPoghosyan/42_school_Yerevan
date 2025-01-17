/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:21:09 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/12 11:46:51 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>

int		ft_long(const char *c);
void	ft_putstr(const char *c);
int		ft_open(const char *av);
ssize_t	ft_read(int fd);

#endif
