// contare occorrenze di ciascuna lettera dell'alfabeto in un file testuale di cui passo il path come parametro

#include <stdio.h>

#define NUM_LETTERE ('z' - 'a' + 1)
// macro
#define is_uppercase(c) (c >= 65 && c <= 90) // A = 65, Z = 90
#define is_lowercase(c) (c >= 97 && c <= 122) // a = 97, z = 122
#define is_whitespace(c) (c == ' ' || c == '\n' || c == '\t') // da usare per occorrenze spazi bianchi

int main(int argc, char **argv) {
    if(argc == 2) {
        FILE *fs = fopen(argv[1], "r");
        int letterCount[NUM_LETTERE] = { 0 };
        int totChars = 0;
        
        if(fs) { // fs != NULL
            int c;

            while((c = getc(fs)) != EOF) {
                totChars++;
                if(is_lowercase(c))
                    letterCount[c - 'a']++;
                else if(is_uppercase(c))
                    letterCount[c - 'A']++;
            }

        } else
            perror(argv[1]); 

        printf("caratteri contati: %d\n", totChars);

        for(int i = 0; i < 27; i++)
            if(letterCount[i])
                printf("numero di %c trovate: %d\nfrequenza di %c trovate: %.2f%%\n", (i + 65), letterCount[i], (i + 65),  (((float) letterCount[i] / totChars) * 100));

    } else
        printf("Usage: es10fsoccurrencies <pathname>\n");

    return 0;
}