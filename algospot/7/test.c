#include<stdio.h>
#include<string.h>

int main(void) {
    char str[3][1000] = {
        {"hello"},
        {"world"},
        {"hihi"}
    };

    printf("%s\n", str[1]);
}