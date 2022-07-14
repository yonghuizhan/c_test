 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*猜一个100以内的数字游戏*/
#define NO 0
#define YES 1


int main( void )
{
	int guess_value = -1;
	int number;
	int nbr_of_guesses;
	int done = NO;
	
	printf("\n\nGetting a Random number\n");
	
	/* use the time to seed the random number generator */
	srand( (unsigned) time( NULL ) );
	number = rand();
	number = number % 100; 
	nbr_of_guesses = 0;
	while ( done == NO )
	{
	printf("\nPick a number between 0 and %d> ", RAND_MAX);
	scanf( "%d", &guess_value ); /* Get a number */
	
	nbr_of_guesses++;
	
	if ( number == guess_value )
	 {
	 done = YES;
	 }
	 else
	 if ( number < guess_value )
	 {
	 printf("\nYou guessed high!");
	 }
	 else
	 {
	 printf("\nYou guessed low!");
	 }
	 }
	
	 printf("\n\nCongratulations! You guessed right in %d Guesses!",
	 nbr_of_guesses);
	 printf("\n\nThe number was %d\n\n", number);
	 
	 return 0;
}
