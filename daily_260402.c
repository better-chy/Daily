#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[100];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        //左括号
        if (c == '(' || c == '{' || c == '[') {
            //入栈
            stack[++top] = c;
        }
        //右括号
        else {
            if (top == -1) return false;
            //出栈
            char t = stack[top--];

            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                    return false;
                }
        }
    }

    return top == -1;
}

// 测试代码
int main() {
    char str1[] = "([])";   // 正确
    char str2[] = "([)]";   // 错误
    
    printf("%d\n", isValid(str1)); // 输出 1 (true)
    printf("%d\n", isValid(str2)); // 输出 0 (false)
    printf("\nPress any key to exit...");
    getchar();
    return 0;
}