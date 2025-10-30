/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:46:03 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/28 16:20:24 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strchr(const char *s);
int		ft_slen(char *str);
char	*ft_joinedcpy(char *str, char *buf);
char	*ft_strjoin(char *str, char *buf);
char	*get_next_line(int fd);
void	ft_freeall(char **str, char *buf);
#endif
