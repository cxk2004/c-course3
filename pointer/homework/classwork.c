#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void  setRandomIPAddr(unsigned char *ip);
void  displayBinaryIPAddr(unsigned char *ip);
void  displayDecimalIPAddr(unsigned char *ip);


int main(void)
{
   unsigned char ip[4];
   setRandomIPAddr(ip);
   displayBinaryIPAddr(ip);
    displayDecimalIPAddr(ip);
    return 0;
}
void  setRandomIPAddr(unsigned char *ip)
{
    srand(time(NULL));
    int i;
    do
    {
        
    for(i = 0;i<4;i++)
    {
        ip[i] = rand()%256;
    }
    }
    while (ip[0]==0||ip[0]==255||(ip[0]==192 && ip[0]==168)||(ip[0]==0
     && ip[1]==0 &&ip[2]==0 && ip[3]==0)||(ip[0]==1 && ip[1]==1 &&ip[2]==1 && ip[3]==1));
    
}
void  displayBinaryIPAddr(unsigned char *ip)
{
    for(int i =0;i<4;i++)
    {
        for(int j =7;j>=0;j--)
        {
            printf("%d",ip[i]>>j&1);
        }
        if(i!=3)
        {
            printf(" ");
        }
    }
    printf("\n");
}
void  displayDecimalIPAddr(unsigned char *ip)
{
    for(int i =0;i<4;i++)
    {
        printf("%d",ip[i]);
        if(i!=3)
        {
            printf(".");
        }
    }
    printf("\n");
}