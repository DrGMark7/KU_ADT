#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10001

void find_similar_substrings(char *text, char *pattern, int max_diff) {
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    char result[MAX_LENGTH * 2] = {0}; 
    int result_index = 0;

    for (int i = 0; i <= text_length - pattern_length ; i++) {
        int diff_count = 0;
        int match = 1;

        for (int j = 0; j < pattern_length; j++) {
            if (text[i + j] != pattern[j]) {
                diff_count++;
                if (diff_count > max_diff) {
                    match = 0;
                    break;
                }
            }
        }
        if (match) {
            result[result_index++] = '[';
            for (int j = 0; j < pattern_length; j++) {
                if (text[i + j] != pattern[j]) {
                    result[result_index++] = '?';
                } else {
                    result[result_index++] = text[i + j];
                }
            }
            result[result_index++] = ']';
            i += pattern_length - 1;
        } else {
            result[result_index++] = text[i];
        }
    }
    
    result[result_index] = '\0';
    printf("%s\n", result);
}

int main() {
    int m, p, n;
    char text[MAX_LENGTH], pattern[MAX_LENGTH];

    scanf("%d %d %d", &m, &p, &n);
    scanf("%s", text);
    scanf("%s", pattern);

    find_similar_substrings(text, pattern, n);

    return 0;
}