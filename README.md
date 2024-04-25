# 42-2-ftprintf

```
int	main(void)
{
	const char *printable = "ahoj";
	int i = 0;
	while (*printable)
	{
		if (*printable == %)
			handle stuff
		else
			printf("%c", *printable);
		i++;
		printable++;
	}
	return(i);
}
```
