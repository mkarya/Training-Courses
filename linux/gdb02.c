#include <stdio.h>
#include <stdlib.h>

int add (int number) {
	if (number > 1) return number+add(number - 1);
	return (1);
}


int main(int argc, char ** argv) {
 int i = 0, sum = 0;
 for (; i <= 2000; i++ )
	sum = sum + i;


	
 printf("concurrent addition of number 2000 using conventional method = %d\n", sum);
 printf("concurrent addition of number 2000 using recurssion = %d\n", add(2000));
 exit(0);
}
