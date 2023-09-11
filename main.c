// Premier programme en C
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void rootFunction(double a, double b, double c, double* x, double *y){
    double delta = (b*b)-(4*a*c);
    *x = (-b-delta)/(2*a);
    *y = (-b+delta)/(2*a);
}

int lowerCaseChar(char a){
    return a + 32;
}

double factorielF(int i){
    double result = 1;
    for(int y = 1; y <= i; y++){
        result = result*y;
    }
    return result;
}

double factorielW(int i){
    double result = 1;
    int y = 1;
    while( y <= i){
        result = result * y;
        y++;
    }
    return result;
}

double factorielR(int i){
    double result = i;
    if(result == 1){
        return result;
    }
    return result * factorielR(i-1);
}

void printPendu(char* tab, int try, int size){
    printf("\n\n\n\n");
    for(int i = 0; i<size; i++){
        printf("%c", tab[i]);
    }
    printf("\n\nEssaie restant : %i", try);
}

void penduGame(const char * word){
    int try = 10;
    int found = 0;
    const int size = (int)strlen(word);
    char * tab = malloc(size);
    for(int i = 0; i < size; i++){
        tab[i] = '_';
    }
    while(try != 0 && !found){
            printPendu(tab, try, size);
            char letter = (char) getchar();
            if(letter == '\n') {
                letter = (char) getchar();
            }
            for (int i = 0; i < size; i++) {
                if (word[i] == letter) {
                    tab[i] = letter;
                }
            }
            int verif = 0;
            for (int i = 0; i < size; i++) {
                if (word[i] == tab[i]) {
                    verif++;
                }
            }
            if (verif == size) {
                found = 1;
                printf("WIN");
                return;
            }
            try--;

    }
    printf("LOOSE");
}


int main() {
    printf("Hello, World!\n");
    double x,y = 0;
    rootFunction(1,4,2,&x,&y);
    printf("Les racines sont: %2.f et%2.f\n", x, y);
    printf("'A' ecrit en minuscule : %c\n", lowerCaseChar('A'));
    printf("3 factoriel : %2.f %2.f %2.f\n", factorielF(3), factorielW(3), factorielR(3));

    printf("Jeu du pendu ! ////////////// \n \n ");
    printf("Donne un mot!!");
    char word[500];
    scanf("%s", word);
    penduGame(word);

    return 0;
}