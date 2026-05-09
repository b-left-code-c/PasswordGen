#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

char *generator(unsigned longueur, unsigned miniscules, unsigned majuscules, unsigned chiffres, unsigned specials) {

    // Premier garde-fou
    if(longueur < 8) {
        printf("Un mot de passe standard fait minimum 8 caractères !\n");
        return NULL;
    }
    if(longueur > 64) {
        printf("Un mot de passe standard fait maximum 64 caractères !\n");
        return NULL;
    }

    // Deuxième garde-fou
    if(!miniscules && !majuscules && !chiffres && !specials) {
        printf("Veuillez entrez au moins un type de caractère pour votre mot de passe.\n");
        return NULL;
    }

    // Allocation de la taille de la chaine + 1
    char *c = malloc(longueur + 1);
    if(c == NULL) {
        printf("Oups! Quelque chose n'a pas marché !\n");
        return NULL;
    }

    char lower[] = "abcdefghijklmnopqrstuvwxyz", 
    upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 
    digit[] = "0123456789",
    special[] = "!#$&'()*+,-./:;<=>?@[]^_{|}~";
    unsigned j = 0;

    // Changer la valeur de la seed
        if(miniscules) c[j++] = lower[rand() % (sizeof(lower) - 1)];
        if(majuscules) c[j++] = upper[rand() % (sizeof(upper) - 1)];
        if(chiffres) c[j++] = digit[rand() % (sizeof(digit) - 1)];
        if(specials) c[j++] = special[rand() % (sizeof(special) - 1)];

    while(j < longueur) {
        unsigned rest = rand() % 4;
        switch (rest) {

        case 0:
            if(miniscules) c[j++] = lower[rand() % (sizeof(lower) - 1)];
            break;

            case 1:
            if(majuscules) c[j++] = upper[rand() % (sizeof(upper) - 1)]; 
            break;

            case 2:
            if(chiffres) c[j++] = digit[rand() % (sizeof(digit) - 1)]; 
            break;

            case 3:
            if(specials) c[j++] = special[rand() % (sizeof(special) - 1)]; 
            break;
        }
    }

    // Mélange aléatoire des éléments entre eux by fisher yates algo 
    for(unsigned i = longueur - 1; i > 0; --i) {
        unsigned y = rand() % (i + 1);
        char tmp = c[i];
        c[i] = c[y];
        c[y] = tmp;
    }

    // Caractère de fin de chaine
    c[longueur] = '\0';
    return c;
}