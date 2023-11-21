// 整数观察

// 【问题描述】
// 对于用户输入的long int，打印其每个字节的16进制表达，
// 对每个字节所代表的非零的16进制数字排序后，输出

// 【编写要求】
// 1. 要求尽可能char *指针完成相关功能
// 2. 输出结果
// Please input a long int number:213412341234
// Your input is: 0x31B05DE5F2
// Obtain bytes : F2,E5,5D,B0,31,0,0,0
// Sorted bytes : 31,5D,B0,E5,F2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned long int x;
    printf("Please input a long int number:");
    scanf("%lu", &x);

    const int size = sizeof(unsigned long int);
    printf("Your input is: 0x%lX\n", x);

    unsigned char hex[size];
    unsigned char *p = (unsigned char *)&x;
    
    // -----------------------------
    // start of your source code
    //
    printf("Obtain bytes : ");
    int j = 0;
    for(int i =0;i<size;i++)
    {
       
        
        if (*(p+i) != 0)
        {
           printf("%X",*(p+i));
            hex[j++] = *(p+i);      
        }
        else
        {
            printf("0");
        }
        if(i!=size)
        {
            printf(",");
        }
        
        
    }
    printf("\n");
    for(int i =0;i<j;i++)
    {
        for(int k=0;k<j-i-1;k++)
        {
            if(hex[k]>hex[k+1])
            {
                unsigned char temp = hex[k];
                hex[k] = hex[k+1];
                hex[k+1] = temp;
            }
        }
    }
    printf("Sorted bytes : ");
    for(int i =0;i<j;i++)
    {
        printf("%X",hex[i]);
        if(i!=j)
        {
            printf(",");
        }
    }
    //
    // end of your source code
    // -----------------------------

    return 0;
}
