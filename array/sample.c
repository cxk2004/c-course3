#include<stdio.h>
int main(void)
{
  int sum=0,i, array[5];
  printf("input 5 integer numbers\n");
  for(i=0;i<5;i++)
  {
    scanf("%d",&array[i]);
    sum+=array[i];

  }
  int max=array[0];
  int seq;
  for(i=0;i<5;i++)
  {
    {
    if(array[i]>=max)
    {
      max = array[i];
      seq = i+1;
    }
  
  }
  printf("The max value array[%d] = %d\n ",seq,max);
  printf("The sum is %d\n",sum);
  printf("The average is %.2f",(float)sum/5);
  return 0;
}
