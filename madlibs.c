//Vincent Lira
//Mason Chacon
//Group Final
#define FILE_NAME "madlib2.txt"
#define STR_CAP 1000
#include <stdio.h>

void stringAppend(char source[], char dest[], int *index);
void Adj(char final[], int *index);
void Noun(char final[], int *index);
void Verb(char final[], int *index);
void pointer(char line[], char finalSentence[], int *index);
void printFinal(char final[], int *index);

int main() {
    FILE *fp;
    char line_number[STR_CAP];
    char finalSen[STR_CAP];
    int index = 0;
    char madlib[STR_CAP][STR_CAP];
    
    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fgets(line_number, STR_CAP, fp)) {
        pointer(line_number, finalSen, &index);
    }

    fclose(fp);

    printf("\nMadlib: \n");
    printFinal(finalSen, &index);
    printf("\n");
    
    return 0;
}

void stringAppend(char source[], char dest[], int *index) {
    int i = 0;
    while (source[i] != '\0' && *index < STR_CAP) {
        dest[*index] = source[i];
        i++;
        (*index)++;
    }
    dest[*index] = '\0';
}

void question(char buff, char word[]) {
    int i = 0;
    switch (buff) {
        case 'A':
            printf("Please enter an adjective: ");
            break;
        case 'N':
            printf("Please enter a noun: ");
            break;
        case 'V':
            printf("Please enter a verb: ");
            break;
        default:
            word[0] = '\0';
            return;
    }
    char k;
    while ((k = getchar()) != '\n' && k != EOF) {
        word[i++] = k;
    }
    word[i] = '\0';
}

void pointer(char line[], char finalSentence[], int *index) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == 'A') {
            Adj(finalSentence, index);
        } else if (line[i] == 'N') {
            Noun(finalSentence, index);
        } else if (line[i] == 'V') {
            Verb(finalSentence, index);
        } else {
            finalSentence[*index] = line[i];
            (*index)++;
        }
    }
}

void Adj(char final[], int *index) {
    char word[STR_CAP];
    question('A', word);
    stringAppend(word, final, index);
}

void Noun(char final[], int *index) {
    char word[STR_CAP];
    question('N', word);
    stringAppend(word, final, index);
}

void Verb(char final[], int *index) {
    char word[STR_CAP];
    question('V', word);
    stringAppend(word, final, index);
}

void printFinal(char final[], int *index){
	char madlib[STR_CAP][STR_CAP];
	int count = 0;
	for(int i = 0; i < 17; i++){
		for(int j = 0; j < STR_CAP; j++){
			if(final[j] == '\n'){
				madlib[count][j] = ' ';
			}else{
			madlib[count][j] = final[j];
			}
		}
		count++;
	}
	
	
	
	int count3 = 0;
	for(int j = 0; madlib[count3][j] != '\0'; j++){
			printf("%c", madlib[count3][j]);
	}


}
