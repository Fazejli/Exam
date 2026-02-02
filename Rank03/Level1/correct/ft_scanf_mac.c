#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int ch;
    ch = fgetc(f);
    while (ch != EOF && isspace(ch))
        ch = fgetc(f);
    if (ch != EOF)
        ungetc(ch, f);
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

int scan_char(FILE *f, va_list *ap)
{
    int ch;
    char *ptr;
    ptr = va_arg(*ap, char *);
    ch = fgetc(f);
    if (ch == EOF)
        return (-1);
    *ptr = ch;
    return (1);
}

int scan_int(FILE *f, va_list *ap)
{
    int ch;
    int res;
    int sig;
    int *ptr;

    ptr = va_arg(*ap, int *);
    res = 0;
    sig = 1;
    ch = fgetc(f);
    if (ch == '-' || ch == '+')
    {
        if (ch == '-')
            sig = -1;
        ch = fgetc(f);
    }
    if (!isdigit(ch) || ch == EOF)
    {
        if (ch != EOF)
            ungetc(ch, f);
        return (-1);
    }
    while (isdigit(ch))
    {
        res = res * 10 + ch - '0';
        ch = fgetc(f);
        if (ch == EOF)
            break ;
    }
    if (ch != EOF)
        ungetc(ch, f);
    *ptr = res * sig;
    return (1);
}

int scan_string(FILE *f, va_list *ap)
{
    int ch;
    int i;
    char *ptr;
    i = 0;
    ptr = va_arg(*ap, char *);
    ch = fgetc(f);
    if (isspace(ch) || ch == EOF)
    {
        if (ch != EOF)
            ungetc(ch, f);
        return (-1);
    }
    while (!isspace(ch))
    {
        ptr[i] = ch;
        i++;
        ch = fgetc(f);
        if (ch == EOF)
            break ;
    }
    if (ch != EOF)
        ungetc(ch, f);
    ptr[i] = '\0';
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list *ap)
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
			if (match_conv(f, &format, &ap) != 1)
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
    int ret;
	va_start(ap, format);
    ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
