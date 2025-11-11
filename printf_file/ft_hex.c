#include "libftprintf.h"
#include "libft_files/libft.h"

void	ft_percentage_p(va_list args, int *totalchars)
{
	unsigned long	num;
	unsigned long	compare;
	char			digit;
	char			base[17];

	ft_memcpy(base, "0123456789ABCDEF", 17);
	compare = 1152921504606846976;
	num = (unsigned long) va_arg(args, void *);
	if (!num)
	{
		write (1, "(nil)", 5);
		*totalchars += 5;
		return ;
	}
	write (1, "0x", 2);
	*totalchars += 2;
	while (compare && num / compare == 0)
		compare = compare / 16;
	while (compare > 0)
	{
		digit = (char)ft_tolower(base[num / compare]);
		write (1, &digit, 1);
		num = num % compare;
		*totalchars += 1;
		compare = compare / 16;
	}
}

void	ft_percentage_x(va_list args, const char str, int *totalchars)
{
	unsigned int	num;
	unsigned int	compare;
	char			base[17];

	ft_memcpy(base, "0123456789ABCDEF", 17);
	compare = 268435456;
	num = (unsigned long) va_arg(args, unsigned int);
	if (num == 0)
	{
		write (1, "0", 1);
		*totalchars += 1;
		return ;
	}
	while (compare && num / compare == 0)
		compare = compare / 16;
	while (compare > 0)
	{
		if (str == 'x')
			write(1, &(char){ft_tolower(base[num / compare])}, 1);
		else
			write(1, &base[num / compare], 1);
		num = num % compare;
		*totalchars += 1;
		compare = compare / 16;
	}
}
