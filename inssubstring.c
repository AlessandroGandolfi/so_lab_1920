#include <stdio.h>
#include <stdlib.h>

char *ins_substring(char *, char, char *);

int main(int argc, char **argv) {
    printf("risultato: %s\n", ins_substring(argv[1], argv[2][0], argv[3]));
    return 0;
}

char *ins_substring(char *s, char sel, char *ins) {
    int i = 0, j = 0;
    char *result = (char *) malloc(sizeof(char));

    while(s[i] != '\0') {

        if(s[i] != sel) {
            result[j] = s[i];
            j++;

        } else {
            int tmp = 0;

            while(ins[tmp] != '\0') {
                result[j] = ins[tmp];
                tmp++;
                j++;
            }
        }
        i++;
    }

    return result;
}