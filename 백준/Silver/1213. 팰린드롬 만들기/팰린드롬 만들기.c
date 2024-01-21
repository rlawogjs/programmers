#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main() {
	char arr[51];
	int* alpha = (int*)calloc(26, sizeof(int));
	scanf("%s", &arr);
	int len = strlen(arr);
 
	int i, j, check = 0, n;	
	for (i = 0; i < len; i++)
		alpha[arr[i] - 'A']++;
 
	if (len % 2 == 0) {	
		for (i = 0; i < 26; i++) {
			if (alpha[i] % 2 != 0) {
				check = 1;
				break;
			}
		}
		if (!check) {
			for (i = 0; i < 26; i++) {
				n = alpha[i];
				for (j = 0; j < n / 2; j++)
					printf("%c", i + 'A');
				alpha[i] /= 2;
			}
			
			for (i = 25; i >= 0; i--) {
				n = alpha[i];
				for (j = 0; j < n; j++)
					printf("%c", i + 'A');
			}
		}
		else
			printf("I'm Sorry Hansoo");
	}
	else {	
		int loc;	
		for (i = 0; i < 26; i++) {
			if (alpha[i] % 2 != 0) {
				loc = i;
				check++;
				continue;
			}
		}
		
		if (check == 1) {
			for (i = 0; i < 26; i++) {
				n = alpha[i];
				for (j = 0; j < n / 2; j++)
					printf("%c", i + 'A');
				alpha[i] /= 2;
				if (i == loc)	
					alpha[i]++;
			}
            
			printf("%c", loc + 'A');
			alpha[loc]--;
			for (i = 25; i >= 0; i--) {
				n = alpha[i];
				for (j = 0; j < n; j++)
					printf("%c", i + 'A');
			}
		}

		else
			printf("I'm Sorry Hansoo");
	}
	free(alpha);
	return 0;
}
