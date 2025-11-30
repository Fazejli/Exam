/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:29:52 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/22 17:04:11 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int ch;

	ch = fgetc(f);
	while (ch != EOF)
	{
		if (!isspace(ch))
		{
			ungetc(ch, f);
			break ;
		}
		ch = fgetc(f);
	}
    return (0);
}

int match_char(FILE *f, char c)
{
    int ch;
	ch = fgetc(f);
	if (ch == EOF)
		return (-1);
	if ((char)ch == c)
		return (1);
	ungetc(ch, f);
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
	int ch;
	char *ptr;

	ch = fgetc(f);
	ptr = va_arg(ap, char *);
	if (ch == EOF)
		return (-1);
	*ptr = (char)ch;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int ch;
	int *ptr;
	int sig;
	int nbr;

	nbr = 0;
	sig = 1;
	ptr = va_arg(ap, int *);
	ch = fgetc(f);
	if (ch == '-' || ch == '+')
	{
		if (ch == '-')
			sig = -1;
		ch = fgetc(f);
	}
	if (!isdigit(ch))
		return (-1);
	while (isdigit(ch))
	{
		nbr = nbr * 10 + ch - '0';
		if (ch == EOF)
			break ;
		ch = fgetc(f);
	}
	*ptr = nbr * sig;
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
	int ch;
	int i;
	char *ptr;

	ptr = va_arg(ap, char *);
	ch = fgetc(f);
	i = 0;
	if (ch == EOF)
		return (-1);
	if (!isalpha(ch))
	{
		ungetc(ch, f);
		return (-1);
	}
	while (isalpha(ch))
	{
		ptr[i] = (char)ch;
		ch = fgetc(f);
		if (ch == EOF)
			return (-1);
		i++;
	}
	ptr[i] = '\0';
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
