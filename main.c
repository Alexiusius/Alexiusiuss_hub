#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
}

void errors(char *str)
{
	if (!str || !(*str))
		return ;
	if (isalpha(*str) || (*str == ' ' &&  isalpha(str + 1)))
	{
		write(1, str, 1);
		errors(str + 1);
	}
	else if (*str == '.')
	{
		if (replace)
		{
			replace = 0;
			write(1, str, 1);
			errors(str +1);
		}
		else
		{
			replace = 1;
			write(1, ",", 1);
			errors(str + 1);
		}
	}
}
