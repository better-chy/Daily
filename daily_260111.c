#include <stdio.h>
#include <string.h>

int romanCharToInt(char c) {
    switch (c){
        case 'I': return 1;
        case 'V': return 5; 
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int romanToInt(char * s) {
    int total = 0;
    int str_len = strlen(s);

    for (int i = 0; i < str_len; i++) {
        int current_val = romanCharToInt(s[i]);
        int next_val = (i < str_len - 1) ? romanCharToInt(s[i+1]) : 0;

        if (current_val < next_val) {
            total -= current_val;
        }
        else {
            total += current_val;
        }
    }
    return total;
}
int main() {
    char *test_cases[] = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
    int case_count = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_count; i++) {
        int result = romanToInt(test_cases[i]);
        printf("Roman numeral: %s => Integer: %d\n", test_cases[i], result);
    }
}