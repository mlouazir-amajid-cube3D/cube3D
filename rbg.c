#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// int mai(int argc, char const *argv[])
// {
// 	int r = 95;
// 	int b = 85;
// 	int c = 75;
// 	int res = 0;

// 	res = r << 16;
// 	res = res | b << 8;
// 	res = res | c;
// 	printf("res = %d\n", res);
// 	return 0;
// }

void	**new_array(void **array, int lenght, void *add)
{
	void **new = malloc(lenght + 1);
	int i = 0;

	while (array && array[i])
	{
		new[i] = array[i];
		i++;
	}
	new[i++] = add;
	new[i] = 0;
	free(array);
	return(new);
}

void	*gc(int size, int pass)
{
	static void **array;
	static int length = 1;
	void	*add;
	
	printf("%p\n", array);
	if (!pass)
	{
		add = malloc(size);
		array = new_array(array, length, add);
		length++;
		return add;
	}
	return add;
}

int main()
{
	char *this = gc(122, 0);
	printf("=---->%p\n", this);
	this = "this is me";

	while (1)
	{
		usleep(5000);
	}
	return 0;
}
