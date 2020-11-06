#include<stdio.h>
#include<string.h>

int main(void) {
    int C;
    char fan[200000];
    char member[200000];
    scanf("%d", &C);
    if (C > 20 || C < 1) {
        return 0;
    }   

    while (C > 0) {
        C--;
        scanf("%s", member);
        scanf("%s", fan);
        if (strlen(member) > strlen(fan)) {
            return 0;
        }

        
    }
    
    
}