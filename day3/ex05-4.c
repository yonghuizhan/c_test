/*4. BUG BUSTER: What’s wrong with the following listing?
#include <stdio.h>
void print_msg( void );
int main( void )
{
	print_msg( “This is a message to print” );
	return 0;
}
void print_msg( void )
{
	puts( “This is a message to print” );
	return 0;
}
*/
#include <stdio.h>
void print_msg();
int main( void )
{
        print_msg( "This is a message to print");
        return 0;
}
void print_msg()
{
        puts( "This is a message to print" );
        
}

