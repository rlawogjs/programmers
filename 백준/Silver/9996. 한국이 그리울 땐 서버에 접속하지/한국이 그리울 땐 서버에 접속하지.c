#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char pattern[101], front[101], back[101];
    scanf("%d", &n);
    scanf("%s", pattern);

    
    int starPos = strchr(pattern, '*') - pattern;

    
    strncpy(front, pattern, starPos);
    front[starPos] = '\0';
    strcpy(back, pattern + starPos + 1);

    
    for(int i = 0; i < n; i++) {
        char str[101];
        scanf("%s", str);
        int len = strlen(str);
        int frontLen = strlen(front);
        int backLen = strlen(back);

       
        if(len >= frontLen + backLen && 
           strncmp(str, front, frontLen) == 0 && 
           strcmp(str + len - backLen, back) == 0) {
            printf("DA\n");
        } else {
            printf("NE\n");
        }
    }

    return 0;
}
