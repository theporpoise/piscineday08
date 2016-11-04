/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:29:45 by mgould            #+#    #+#             */
/*   Updated: 2016/11/03 22:10:40 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int i;
	int	*strints;

	if (max <= min)
		return (NULL);
	i = 0;
	strints = (int*)malloc(sizeof(int) * (max - min));
	while ((i + min) < max)
	{
		strints[i] = min + i;
		i++;
	}
	return (strints);
}

int *words_in_string(char *str, int *ip)
{
	int i;
	int j;
	int f;
	int *strints;
	
	i = 0;
	j = 0;
	f = 0;
	while(str[i])
	{
		if (f == 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		{
		} else if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))	
		{
			f = 1;
		} else if (f == 1 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		{
			f = 0;
			j++;
		}
		i++;
	}
	strints = ft_range(0, j);
	*ip = j; 
	return (strints);
}

void	 letters_per_word(char *str, int *strints)
{
	int i;
	int j;
	int f;
	
	i = 0;
	j = 0;
	f = 0;
	while(str[i])
	{
		if (f == 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		{
		} else if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))	
		{
			f = 1;
			strints[j]++;
		} else if (f == 1 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		{
			f = 0;
			j++;
		}
		i++;
	}
}

char **ft_split_whitespaces(char *str)
{
	char **words;
	int *strints;
	int i;

	i = 0;
	strints = words_in_string(str, &i);
	words = (char**)malloc(sizeof(char*) * (i + 1));
	//letters_per_word(str, strints);
	printf("i is:%d\n", i);	
	i = 0; 
	while(strints[i])
	{
		printf("strints is:%d\n", strints[i]);
		//words[i] = (char*)malloc(sizeof(char) * strints[i]);
		i++;
	}

	return words;
}

int main()
{
	char *string ="1 22 th2 four";

	ft_split_whitespaces(string);


}


/*
int		get_count(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++
	}
	return (i)
}



*/
