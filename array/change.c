#include <stdio.h>

void convertCase(char* str) {
    int i = 0;
    while (str[i] != '\0') 
    {
        if (str[i] >= 'a' && str[i] <= 'z')
         {
            str[i] = str[i] - 'a' + 'A';  // 转换为大写字母
        }
         else if (str[i] >= 'A' && str[i] <= 'Z')
          {
            str[i] = str[i] - 'A' + 'a';  // 转换为小写字母
          }
        i++;
    }
}

int main()
 {
    char str[51];  // 50 characters + '\0' null terminator
    
    printf("Enter a string (up to 50 characters): ");
    scanf("%50s", str);
    
    convertCase(str);
    
    printf("Converted string: %s\n", str);
    
    return 0;
}
