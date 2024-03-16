#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototypes
char *disemvowel(const char *);
char *disemvowel_2(const char *);
char *disemvowel_3(const char *);
//run
int main(int argc, char **argv) {
    char *test_1 = "This website is for losers LOL!";
    printf("res ->\n%s\n%s\n%s\n", disemvowel(test_1), disemvowel_2(test_1), disemvowel_3(test_1));
    return 0;
}
//implementations
char *disemvowel(const char *arg) {
    char *result = calloc(strlen(arg) + 1, sizeof(char));
    int i = 0,j = 0;
    char *vowels = "aeiouAEIOU";
    while (arg[i] != '\0') {
        if (strchr(vowels, arg[i]) == NULL) {
            result[j] = arg[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';
    return result;
}
char *disemvowel_2(const char *arg) {
    char *res = calloc(strlen(arg) + 1, sizeof(char));
    int j=0;
    for (int i=0; i < strlen(arg); ++i) {
        switch (arg[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                break;
            default:
            res[j++] = arg[i];
        }
    }
    res[j] = '\0';
    return res;
}
char *disemvowel_3(const char *arg) {
    char *res = calloc(strlen(arg) + 1, sizeof(char));
    for (char *q = res; *arg; arg++){
        if (!strchr("aeiouAEIOU", *arg)) {
            *q++ = *arg;
        }
    }
    return res;
}