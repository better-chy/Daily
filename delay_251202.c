#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){

    if (x < 0){
        return false;
    }

    if (x % 10 ==0 && x != 0){
        return false;
    }

    int reversed_half = 0;
    while (x > reversed_half){
        int last_digit = x % 10;
        reversed_half = reversed_half * 10 + last_digit;
        x /= 10;
    }
    return (reversed_half == x) || (reversed_half / 10 == x);

}

// 主函数:测试用例
int main() {
    // 测试案例1:121 → 预期true
    int x1 = 121;
    printf("x=%d,Is it a palindrome number?:%s\n", x1, isPalindrome(x1) ? "yes" : "no");
    
    // 测试案例2:-121 → 预期false
    int x2 = -121;
    printf("x=%d,Is it a palindrome number?:%s\n", x2, isPalindrome(x2) ? "yes" : "no");
    
    // 测试案例3:10 → 预期false
    int x3 = 10;
    printf("x=%d,Is it a palindrome number?:%s\n", x3, isPalindrome(x3) ? "yes" : "no");
    
    // 额外测试:0 → 预期true
    int x4 = 0;
    printf("x=%d,Is it a palindrome number?:%s\n", x4, isPalindrome(x4) ? "yes" : "no");
    
    // 额外测试:1221 → 预期true
    int x5 = 1221;
    printf("x=%d,Is it a palindrome number?:%s\n", x5, isPalindrome(x5) ? "yes" : "no");
    
    printf("\nPress any key to exit...");
    getchar();
    return 0;
}