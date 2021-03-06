/*=============================================================================
#     FileName: 16-cntfreq.c
#         Desc: Fig 7.13 + 7.14 + count unique freq
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-09-03 19:34:00
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXCHAR 100
#define MAXWORD 1000

typedef char word_t[MAXCHAR+1] ;
int getword(word_t W, int limit);

int
main(int argc, char **argv) {
    word_t one_word, all_words[MAXWORD] ;
    int freq[MAXWORD];
    int unique=0, totwords=0, i, found;

    while (getword(one_word, MAXCHAR) != EOF) {
        totwords++;

        found = 0;
        for(i=0; i<unique && !found; i++) {
            /* Linear search for the word */
            found = (strcmp(one_word, all_words[i]) == 0);
        }
        if(!found && unique < MAXWORD) {
            strcpy(all_words[unique], one_word);
            freq[unique] = 1;
            unique++;
        } else {
            freq[i-1]++;
        }
    }

    printf("%d words read\n", totwords);
    for(i=0; i<unique; i++) {
        printf("%d: word #%d is '%s'\n", freq[i], i, all_words[i]);
    }

    return 0;
}


int
getword(word_t W, int limit) {
    int c, len=0;
    while((c=getchar()) != EOF && !isalpha(c)) {
        /* skip over any non alphabets */
    }

    if(c==EOF) {
        return EOF;
    }

    W[len++] = c;

    while (len<limit && (c=getchar()) != EOF && isalpha(c)) {
        /* Read word here */
        W[len++] = c;
        /* Assign then increment len by 1 */
    }
    W[len] = '\0';

    return 0;
}
