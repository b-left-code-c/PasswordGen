#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "strength.h"


int main(void) {

    // Variables
    unsigned longueur = 0, i = 0;
    int force = 0;
    char maj = 0, min = 0, digit = 0, special = 0;

    // La seed
    srand(time(NULL));

    // Entrée utilisateur
    printf("Entrez un longueur pour votre mot de passe : ");
    scanf("%u", &longueur);
    printf("Voulez-vous des miniscules là dedans (y / n) ? y = yes, n = no : ");
    scanf(" %c", &min);
    printf("Voulez-vous des majuscules là dedans (y / n) ? ");
    scanf(" %c", &maj);
    printf("Voulez vous des chiffres là dedans (y / n) ? ");
    scanf(" %c", &digit);
    printf("Voulez vous des caractères spéciaux là dedans (y / n) ? ");
    scanf(" %c", &special);

    // Conversion, calcul et affichage du mdp
    min = (min == 'y') ? 1 : 0;
    maj = (maj == 'y') ? 1 : 0;
    digit = (digit == 'y') ? 1 : 0;
    special = (special == 'y') ? 1 : 0;
    char *pwd = generator(longueur, min, maj, digit, special);
    printf("Mot de passe généré : %s\n", (pwd == NULL) ? "Aucun." : pwd);

    // Force du mdp 
    force = strength(pwd);
    if(force <= 30) 
            printf("Votre mot de passe est faible !\n");
        else if(force > 30 && force <= 50)
            printf("Votre mot de passe est moyen !\n"); 
        else if(force > 50 && force <= 75)
            printf("Votre mot de passe est bon !\n");
        else if(force > 75 && force <= 90)
            printf("Votre mot de passe est très bon !\n");
        else if(force > 90 && force <= 100)
        printf("Votre mot de passe est excellent !\n");

    // Libération de la mémoire et fin du programme
    free(pwd);
    return 0;
}