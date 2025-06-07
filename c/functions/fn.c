void print(char *s)
{//str print
	printf("%s\n",s);
}
void my_strcpy(const char *s,char *d)
{
	int i;
	while(*s)
	{
		*d=*s;
		s++;
		d++;
	}
	*d=*s;
}

int my_strlen(const char *p)
{//string length
	int i ;
	for(i=0;p[i];i++);
	return i;
}
void my_strupr(char *p)
{
	while(*p)
	{
		if(*p>='a' && *p<='z')
			*p=*p-32;
		p++;
	}
}
