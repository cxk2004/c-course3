// 字符串处理

// 【问题描述】
// 对于给定的长字符串，查找其中是否存在连续三个字母字符的情况，
// 如果找到了，则打印找到的每个串

// 【编写要求】
// 1. 对于字符串的处理，要求用指针作为循环控制变量
// 2. 输出结果的格式化要求为"[%d] %c%c%c\n"
// 例如用户输入“12386-ABCDz09**”后，程序输出
// [1] ABC
// [2] BCD

#include <stdio.h>
#include <string.h>

int main()
{
    char message[200] = {0};

    printf("Please input your messge\n");
    scanf("%200s", message );

    char *p = message;
    int length = strlen(message);
    int count = 0;

    // -----------------------------
    // start of your source code
    //
     for(int i = 0; i < length - 2; i++)
    {
        if
        ((*(p+i) >= 'A' && *(p+i) <= 'Z') &&
           (*(p+i+1) == *(p+i)+1 && *(p+i+1) <= 'Z' ) &&
           (*(p+i+2) >= *(p+i)+2 && *(p+i+2) <= 'Z' ))
        {
            printf("[%d] %c%c%c\n", ++count, *(p+i), *(p+i+1), *(p+i+2));
        }
          else if 
          ((*(p+i) >= 'a' && *(p+i) <= 'z') &&
           (*(p+i+1) == *(p+i)+1 && *(p+i+1) <= 'z' ) &&
           (*(p+i+2) >= *(p+i)+2 && *(p+i+2) <= 'z' ))
        {
            printf("[%d] %c%c%c\n", ++count, *(p+i), *(p+i+1), *(p+i+2));
        }
    }

    
    //
    // end of your source code
    // -----------------------------

    return 0;
}