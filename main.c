#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void errors(char *str);

int count_qq = 0;
int count_replace = 0;
int count_moveSpace = 0;
int replace = 0;

int main (int ac, char **av)
{
	int i = 0;

	while (av[1][i] == ' ')
		i++;
	errors(&av[1][i]);
	printf("\n%d\n%d\n%d\n", count_qq, count_moveSpace, count_replace);
}

void errors(char *str)
{
	if (!str || !(*str))
		return ;
	if (isalpha(*str) || (*str == ' ' &&  isalpha(*(str + 1))))
	{
		if (str[0] == 'q' && str[1] == 'q')
		{
			str[1] = 'w';
			count_qq++;
		}
		write(1, str, 1);
		errors(str + 1);
	}
	else if (*str == '.')
	{
		if (!replace)
		{
			replace = 1;
			write(1, str, 1);
			if (str[1] != ' ')
				write(1, " ", 1);
			errors(str + 1);
		}
		else
		{
			replace = 0;
			write(1, ", ", 2);
			errors(str + 1);
			count_replace++;
		}
	}
	else if ((str[0] == ';' || str[0] == ':' || str[0] == ')' || str[0] == '!' || str[0] == '?') && str[1] != ' ')
	{
		write(1, str, 1);
		write(1, " ", 1);
		errors(str + 1);
	}
	else
		errors(str + 1);

}
