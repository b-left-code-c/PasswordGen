#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "strength.h"

int strength(char mdp[]) {
    unsigned taille = strlen(mdp);

    // Boolean
    _Bool lower = 0,
    upper = 0,
    digit = 0,
    special = 0;

    // Analyse
        for(unsigned i = 0; i < taille; ++i) {
            if(islower(mdp[i])) lower = 1;
            if(isupper(mdp[i])) upper = 1;
            if(isdigit(mdp[i])) digit = 1;
            if(ispunct(mdp[i])) special = 1;
        }

    unsigned
    // Différents score 
    score_categorie = 0,
    score_brut = 0,
    score_longueur = (taille - 8) * 4;
    if(score_longueur >= 40)
        score_longueur = 40;

        // Scoring
        score_categorie = (lower + upper + digit + special) * 15;
        score_brut = score_categorie + score_longueur;
        int score_final = score_brut;

        // Force
        return score_final;
}