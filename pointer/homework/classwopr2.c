#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void setRandomIPAddr(unsigned char *ip1, unsigned char *ip2, unsigned char *ip3, unsigned char *ip4);
void displayBinaryIPAddr(unsigned char ip1, unsigned char ip2, unsigned char ip3, unsigned char ip4);
void displayDecimalIPAddr(unsigned char ip1, unsigned char ip2, unsigned char ip3, unsigned char ip4);

int main(void)
{
    unsigned char ip1, ip2, ip3, ip4;
    setRandomIPAddr(&ip1, &ip2, &ip3, &ip4);
    displayBinaryIPAddr(ip1, ip2, ip3, ip4);
    displayDecimalIPAddr(ip1, ip2, ip3, ip4);
    return 0;
}

void setRandomIPAddr(unsigned char *ip1, unsigned char *ip2, unsigned char *ip3, unsigned char *ip4)
{
    srand(time(NULL));
    do
    {
        *ip1 = rand() % 256;
        *ip2 = rand() % 256;
        *ip3 = rand() % 256;
        *ip4 = rand() % 256;
    } while(*ip1 == 0 || *ip1 == 255 || (*ip1 == 192 && *ip2 == 168)||
    (*ip1 == 0 && *ip2 == 0 && *ip3 == 0 && *ip4 == 0)||(*ip1 == 1 && *ip2 == 1 && *ip3 == 1 && *ip4 == 1));
}

void displayBinaryIPAddr(unsigned char ip1, unsigned char ip2, unsigned char ip3, unsigned char ip4)
{
   unsigned char* ip = &ip1;
   for(int i =0;i<4;i++)
    {
        for(int j =7;j>=0;j--)
        {
            printf("%d",*ip>>j&1);
        }
        ip++;
        if(i!=3)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void displayDecimalIPAddr(unsigned char ip1, unsigned char ip2, unsigned char ip3, unsigned char ip4)
{
    printf("%d.%d.%d.%d\n", ip1, ip2, ip3, ip4);
}