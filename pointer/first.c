
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	long int longNumber, *lPtr = &longNumber;
	unsigned char * bytePtr = NULL;
	printf("Please input an integer with %lu bytes:\n", sizeof(long int));
	scanf("%ld", lPtr );
	printf("Your input is %lX, located in %p\n\n", *lPtr, lPtr );

	printf("Print the memory from high address to low address:\n" );
	bytePtr = (unsigned char *) (lPtr + 1) - 1;
	// start of your code
    for(;bytePtr>=(unsigned char *)lPtr;bytePtr--)
    {
        printf("%p  %X\n",bytePtr, *bytePtr);
    
    }
	// end of your code

	printf("Print the hex value from high address to low address:\n" );
	// start of your code
    bytePtr = (unsigned char *) (lPtr + 1) - 1;
    for(;bytePtr>=(unsigned char *)lPtr;bytePtr--)
    {
       printf("%s",(*bytePtr<0xF)?"0":"");
       printf("%X ", *bytePtr);
       printf(",");

    }
    printf("\b  \n\n");
	// end of your code
	
	return 0;
}
