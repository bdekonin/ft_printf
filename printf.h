/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 08:07:31 by bdekonin      #+#    #+#                 */
/*   Updated: 2020/04/26 22:00:32 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flag
{
	char			zero;
	char			space;
	char			minus;
	char			*zero_x;
	int				width_count;
	int				width_amount;
	int				data_type;
	int				flag_type;
	int				flag_bool;
	int				precision;
	int				prec_bool;
	int				index_i;
	int				index_j;
	int				total_print;
	int				space_count;
	int				putnbr_neg;
	int				plus_flag;
	int				hash_flag;
	int				flag_continue;
	int				error;
	int				prec_point;
	int				star_point;
	int				arg_count;
}					t_flag;

/*
** Printing functions that return a value.
** also checks if write hasn't failed.
*/

int					ft_putchar_fd_return(char c, int fd, t_flag *flags);
int					ft_putstr_fd_return(char *s, int fd, t_flag *flags);
int					ft_putnbr_fd_return(int n, int fd, t_flag *flags);
int					ft_putnbr_fd_return_unsigned(unsigned int n, int fd, \
t_flag *flags);

/*
** Used for setting everything up before printing a pointer value.
*/

int					ft_hex_convert_pointer(unsigned long long ans, unsigned \
long long addition, t_flag *flags);
void				ft_putnbr_print_pointer(char *s, int fd, t_flag *flags);

/*
** Used for setting everything up before printing a hex value.
*/

int					ft_hex_convert(unsigned int ans, unsigned int addition, \
int bool, t_flag *flags);
int					ft_putnbr_flags_hex(long n, int fd, t_flag *flags);
void				ft_putnbr_flags_print_hex(char *s, int fd, t_flag *flags);

/*
** Uses this function to convert from decimal to hex.
*/

char				*ft_hex_converting(char *hex, unsigned long long ans, \
unsigned long long addition);

/*
** Used to count how long a pointer or hexidecimal numer should be.
** and convert a number to char
*/
int					ft_intlen_unsigned(unsigned long long n, int base);
char				*ft_itoa_long(long long n, t_flag *flags);

/*
** All used to print out numbers.
*/
int					ft_putnbr_flags(long long n, int fd, t_flag *flags);
void				ft_putnbr_flags_print(char *s, int fd, t_flag *flags);
void				ft_putnbr_flags_print_negative(char *s, int fd, \
t_flag *flags);

/*
** This is the beginnning of printf, This is all used to setup everything,
** before looking for flags.
*/
int					ft_printf(const char *format, ...);
t_flag				*ft_structset(t_flag *flags);
void				ft_checkformat(const char *format, t_flag *flags, int i, \
va_list argp);

/*
** These function makes sure it will take the right path before printing.
** also resets all flags when done printing.
*/
int					ft_printing_noflags(t_flag *flags, va_list argp);
int					ft_printing_with_flags(t_flag *flags, va_list argp);

/*
** Used to look for flags. read the input of it, and store it in a struct.
*/
int					check_minus_zero(int i, const char *format, \
t_flag *flags, va_list argp);
int					check_minwidth_wildcard(int i, const char *format, \
t_flag *flags, va_list argp);
int					check_for_prec(int i, const char *format, \
t_flag *flags, va_list argp);
int					check_spaces(int i, int bool, const char *format, \
t_flag *flags);

/*
** Used to check if the given argument has failed.
*/
int					checkerror(char *str, char *hex, t_flag *flags, int bool);

/*
** Used for printing strings and chars with flags.
*/
int					ft_putchar_flags(char c, int fd, t_flag *flags);
void				ft_putstr_flags(char *s, int fd, t_flag *flags);

#endif
