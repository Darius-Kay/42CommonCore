/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 05:30:27 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 15:12:02 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_nbrsize(long long int n);
int		ft_nbrsize_hexa(unsigned long long int nbr);
int		ft_putp(void *ptr);
int		ft_putchar_len(char c, int fd);
int		ft_putnbr_hexa(unsigned long long nbr, int choice);
int		ft_putnbr_len(int n, int fd);
int		ft_putstr_len(char *s, int fd);
int		ft_putunbr(unsigned long int unbr);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_truestrlen(const char *s);
#endif
