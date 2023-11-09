#define N 10
#include<stdlib.h>
#include<time.h>
#include<stdio.h>


int isPrimeNumber(int x);
void printPrimeFactors(int x);


int main (void)
{
    srand (time(NULL));
    int number[N],i;
    for(int i=0;i<10;i++)
    {
      number[i]=100+rand()%101;
    }

 int counter = 0;
  for (int i=0;i<N;i++)
 {
  counter++;
  if(isPrimeNumber(number[i])==1)
  {
    printf("(%d)%d is not a prime number.\n",counter,number[i]);
  } 
  else
  {
    printf("(%d)%d is a prime number. ",counter,number[i]);
    printPrimeFactors(number[i]);
    
  }
 }
}
int isPrimeNumber(int x)
{
    int i;
    for(int i =2;i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

}
void printPrimeFactors(int x)
{
    int i;
    printf("%d=" ,x);

    while (x % 2==0)
    {
        printf ("2*");
        x=x/2;
    }
    for(int i =3;i<=x;i=i+2)
    {
        while (x%i==0)
        {
         printf("%d*",i);
         x=x/i;
        }
        
    }
    
    printf("\b  ");
    printf("\n");
}
