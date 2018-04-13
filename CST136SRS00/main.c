#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void main() 
{
	int celcius = 0;
	char again = 'y';
	
	while (again == 'y' || again == 'Y') {
		printf("Enter Celcius: ");
		scanf("%d", &celcius);

		int kelvin = celcius + 273;
		printf("%d degree celcius is %d kelvin\n", celcius, kelvin);

		printf("Play again? (Y/N): ");
		scanf(" %c", &again);
	}
}