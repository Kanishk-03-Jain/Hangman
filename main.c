#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "levels.h"
#include "words.h"


Category randomCategory(char** category);
Node randomNode(Category selectedCategory);
void printIntro();
void writeWord(char* word, int wrdLen);
void printWord(char* word);
void getName(char* name);
void printLevel(int level);
void printMessage(char* message, int hintFlag, char* hint);
int checkGuess(char* correctWord, int wrdLen, char* guess, char* word, int* level, char** message);
void printStats(int hint, int score, int hiscore, char** category, int wrdLen);
int gameOver(int score, int hiscore, char* name, char* word);
void printRules();
int hiScore(int score, char* name);


int main(void) {
    srand(time(NULL));
    int hint, level, score, wrdLen, hintFlag, allcorrect, hiscore;
    char* name = malloc(50 * sizeof(char));
    char* category = malloc(50 * sizeof(char));
    char* word = malloc(50 * sizeof(char));
    char* guess = malloc(50 * sizeof(char));
    char* message = 0;
    Category selectedCategory;
    Node selectedNode;

    int gameOn = 1;
    while (gameOn) {
        hint = 3, level = 1, score = 0;
        printIntro();
        printRules();
        getName(name);

        while (level < 7) {
            hiscore = hiScore(score, name);
            selectedCategory = randomCategory(&category);
            selectedNode = randomNode(selectedCategory);
            wrdLen = strlen(selectedNode.word);
            writeWord(word, wrdLen);
            printIntro();
            hintFlag = 0;
            allcorrect = 0;
            while (level < 7 && !allcorrect) {
                printIntro();
                printStats(hint, score, hiscore, &category, wrdLen);
                printLevel(level);
                printWord(word);
                printMessage(message, hintFlag, selectedNode.hint);
                message = '\0';

                printf("Enter a letter: ");
                fgets(guess, 50, stdin);
                guess[strcspn(guess, "\n")] = 0;
                if (strcasecmp(guess, "hint") == 0 && hintFlag == 0) {
                    if (hint > 0) {
                        hintFlag = 1;
                        hint--;
                        continue;
                    }
                    else {
                        message = "No hints left!";
                        continue;
                    }
                }
                else if (strlen(guess) == 1) {
                    if (tolower(guess[0]) >= 'a' && tolower(guess[0]) <= 'z' || guess[0] == ' ' || guess[0] == '-') {
                    }
                    else {
                        message = "Invalid input!";
                        continue;
                    }
                }
                else {
                    message = "Invalid input!";
                    continue;
                }

                allcorrect = checkGuess(selectedNode.word, wrdLen, guess, word, &level, &message);
                if (allcorrect) {
                    printIntro();
                    printLevel(level);
                    printWord(word);
                    printMessage("You guessed the word!", hintFlag, selectedNode.hint);
                    Sleep(2000);
                }
            }
            if (level < 7) {
                if (hintFlag == 1) {
                    score += wrdLen / 2;
                }
                else {
                    score += wrdLen;
                }
            }
        }
        gameOn = gameOver(score, hiscore, name, selectedNode.word);
    }

    free(name);
    free(category);
    free(word);
    free(guess);
}

Category randomCategory(char** category) {
    int random = rand() % numCategories;
    *category = categories[random].category;
    return categories[random];
}

Node randomNode(Category selectedCategory) {
    int random = rand() % selectedCategory.numNodes;
    return selectedCategory.nodes[random];
}

void printIntro() {
    printf("\033[H\033[J");
    for (int i = 0; i < introLen; i++) {
        printf("%s", intro[i]);
    }
    printf("\n");
    printf("\n");
    printf("\n");
}

void writeWord(char* word, int wrdLen) {
    for (int i = 0; i < wrdLen; i++) {
            word[2 * i] = '_';
            word[2 * i + 1] = ' ';
        }
        word[2 * wrdLen] = '\0';
}

void printWord(char* word) {
    printf("%s\n", word);
}

void getName(char* name) {
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
}

void printLevel(int level) {
    for (int i = 0; i < levelLen; i++) {
        printf("%s", levels[level - 1][i]);
    }
    printf("\n");
}

void printMessage(char* message, int hintFlag, char* hint) {
    if (hintFlag == 1) {
        printf("Hint: %s\n", hint);
    }
    printf("%s\n", message);
}

int checkGuess(char* correctWord, int wrdLen, char* guess, char* word, int* level, char** message) {
    int correct = 0;
    int unknowns = 0;
    int changes = 0;
    for (int i = 0; i < wrdLen; i++) {
        if (toupper(correctWord[i]) == toupper(guess[0])) {
            correct = 1;
            if (word[2 * i] == '_') {
                changes++;
            }
            word[2 * i] = tolower(guess[0]);
        }
        if (word[2 * i] == '_') {
            unknowns++;
        }
    }

    if (!correct) {
        (*level)++;
    }
    else if (changes == 0) {
        *message = "You already guessed that letter!";
    }
    if (unknowns == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void printStats(int hint, int score, int hiscore, char** category, int wrdLen) {
    printf("Hints Left : %i\n", hint);
    printf("Score      : %i\n", score);
    printf("High Score : %i\n", hiscore);
    printf("\n");
    printf("Category   : %s\n", *category);
    printf("Word Length: %i\n", wrdLen);
}

int gameOver(int score, int hiscore, char* name, char* word) {
    printIntro();
    for (int i = 0; i < gameOverLen; i++) {
        printf("%s", gameover[i]);
    }
    printf("\n");
    printLevel(7);
    printf("The word was: %s\n", word);
    printf("\n");
    printf("Don't worry %s, it's just a stickman :)\n", name);
    printf("Your score  : %i\n", score);

    if (score == hiscore) {
        printf("Congratulations! You have a new high score!\n");
    }

    int valid = 1;
    do {
        if (!valid) {
            printf("\033[H\033[J");
            printf("Invalid input!\n");
        }
        char playAgain[50];
        printf("Do you want to play again? (y/n): ");
        fgets(playAgain, 50, stdin);
        playAgain[strcspn(playAgain, "\n")] = 0;
        if (strlen(playAgain) != 1) {
            valid = 0;
        }
        else {
            if (tolower(playAgain[0]) == 'y') {
                valid = 1;
                return 1;
            }
            else if (tolower(playAgain[0]) == 'n') {
                valid = 1;
                return 0;
            }
            else {
                valid = 0;
            }
        }
    } while (!valid);
}

void printRules() {
    printf("Rules:\n");
    printf("1. You have to guess the word by entering one letter at a time.\n");
    printf("   Valid characters are alphabets, space, apostrophe and hyphen.\n");
    printf("2. You can ask for a hint by typing 'hint'. You have 3 hints in total\n");
    printf("3. You have to guess the word before the stickman is hanged.\n");
    printf("4. You get points based on the length of the word.\n");
    printf("   If you guess the word, score is increased by length of the word.\n"); 
    printf("   If hint is taken, score will increase by half the length of the word.\n");
    printf("\n");
}

int hiScore(int score, char* name) {
    FILE* fp = fopen("hiscore.txt", "r");
    char hiscore[10];
    fgets(hiscore, 10, fp);
    fclose(fp);
    if (score < atoi(hiscore)) {
        return atoi(hiscore);
    }
    else {
        FILE* fp = fopen("hiscore.txt", "w");
        fprintf(fp, "%i\n", score);
        fprintf(fp, "%s\n", name);
        fclose(fp);
        return score;
    }
}