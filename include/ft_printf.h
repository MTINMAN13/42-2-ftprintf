/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:44:05 by apple             #+#    #+#             */
/*   Updated: 2023/10/27 23:06:05 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include "libft.h"

int			ft_putcharo(int c);
int			ft_hex_len(unsigned	int num);
int			ft_printfhandler(va_list input, const char type);
void		ft_handle_x(unsigned int num, const char format);
int			ft_print_hex(unsigned int num, const char format);
int			ft_numlen(int n, int base);
char		ft_handle_u(unsigned int n);
int			ft_handle_di(int i);
int			ft_print_pointer(void *hi);
int			ft_print_percent(void);
int			ft_handle_s(char *string);
int			ft_handle_c(int whatever);
int			ft_printf(const char *to_be_printed, ... );
#endif
