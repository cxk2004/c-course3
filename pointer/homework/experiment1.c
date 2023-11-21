#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
  char message[100];
  printf("Please imput a message (without empty space):");
  scanf("%200s", message);

  char *p = message ;
    int length = 0;
    while(*p++ != '\0')
    {
        length++;
        
    }
    printf("length = %d\n", length);

    for(p=message;*p++ != '\0';p++)
    {
        length++;
    }
    printf("length = %d\n", length);
    do
    {   
        
        length++;
        p++;
    } while (*p ++!= '\0');   
    printf("length = %d\n", length-3);
    


}