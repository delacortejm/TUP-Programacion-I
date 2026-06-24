#include <stdio.h>
#include <conio.h>

long int potencia(int base, int exp);

int main ()
{
	int base, exp;
	long int result;
	printf("\nIngrese base:");
	scanf("%d",&base);
	printf("\nIngrese exponente:");
	scanf("%d",&exp);

	if (exp < 0) printf("Error");
	else
	{
		result=potencia(base,exp);
		printf("\n%d elevado a %d es %ld",base,exp,result);
	}
	getch();
	return 0;
}
long int potencia(int base, int exp)
{
	long int resp;
	if(exp==0)
		return 1;
	else
		resp=base*potencia(base,exp-1);
	return (resp);
}