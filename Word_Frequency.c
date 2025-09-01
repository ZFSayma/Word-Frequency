#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_alphanumeric(char c) {
    return (isalnum(c));
}





int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open input.txt\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int wordCount = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(inputFile, "%s", buffer) != EOF) {
        char cleanedWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; buffer[i]; i++) {
            if (is_alphanumeric(buffer[i])) {
                cleanedWord[j++] = buffer[i];
            }
        }
        cleanedWord[j] = '\0';
        to_lowercase(cleanedWord);

        if (strlen(cleanedWord) > 0) {
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(words[i].word, cleanedWord) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found && wordCount < MAX_WORDS) {
                strcpy(words[wordCount].word, cleanedWord);
                words[wordCount].count = 1;
                wordCount++;
            }
        }
    }
    fclose(inputFile);


 char mostFrequentWord[MAX_WORD_LENGTH] = "";
    int maxCount = 0;

    for (int i = 0; i < wordCount; i++) {
        if (words[i].count > maxCount ||
            (words[i].count == maxCount && strcmp(words[i].word, mostFrequentWord) < 0)) {
            maxCount = words[i].count;
            strcpy(mostFrequentWord, words[i].word);     }  }

    FILE *outputFile = fopen("output.txt", "w");
        printf("output.txt file created. open to see result.\n");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not open output.txt\n");
        return 1; }

    fprintf(outputFile, "%s %d\n", mostFrequentWord, maxCount);
    fclose(outputFile);

    return 0;
}

