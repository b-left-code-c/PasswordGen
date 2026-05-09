# 🔐 PasswordGen

Un générateur de mots de passe en C, simple, rapide et efficace — avec un système de scoring intégré pour évaluer la robustesse du mot de passe généré.

---

## Fonctionnalités

- Génération aléatoire sécurisée via l'algorithme **Fisher-Yates**
- Choix des types de caractères inclus dans le mot de passe
- Longueur personnalisable (entre 8 et 64 caractères)
- Scoring automatique de la robustesse du mot de passe

---

## Types de caractères supportés

| Type | Exemple |
|---|---|
| Minuscules | `abcdefghijklmnopqrstuvwxyz` |
| Majuscules | `ABCDEFGHIJKLMNOPQRSTUVWXYZ` |
| Chiffres | `0123456789` |
| Caractères spéciaux | `!#$&'()*+,-./:;<=>?@[]^_{|}~` |

---

## Système de scoring

Le mot de passe généré est évalué sur **100 points**, répartis comme suit :

| Critère | Points |
|---|---|
| Diversité des types de caractères | jusqu'à **60 pts** (15 pts par type) |
| Longueur du mot de passe | jusqu'à **40 pts** (4 pts par caractère au-delà de 8) |

### Niveaux de robustesse

| Score | Niveau |
|---|---|
| ≤ 30 | ❌ Faible |
| 31 – 50 | 🟡 Moyen |
| 51 – 75 | 🟢 Bon |
| 76 – 90 | 🔵 Très bon |
| 91 – 100 | 🏆 Excellent |

---

## Compilation

```bash
gcc main.c generator.c strength.c -o passwordgen
```

## Utilisation

```bash
./passwordgen
```

Le programme vous guidera à travers les options via des prompts interactifs.

---

## Structure du projet

```
passwordgen/
├── main.c          # Point d'entrée
├── generator.c     # Logique de génération
├── generator.h
├── strength.c      # Logique de scoring
├── strength.h
└── README.md
```

---

## Exemple de sortie

```
Entrez un longueur pour votre mot de passe : 16
Voulez-vous des miniscules là dedans (y / n) ? y
Voulez-vous des majuscules là dedans (y / n) ? y
Voulez vous des chiffres là dedans (y / n) ? y
Voulez vous des caractères spéciaux là dedans (y / n) ? y

Mot de passe généré : aB3!Kz9#mQ2@Xw7&
Votre mot de passe est excellent !
```

---

## Roadmap

Améliorations prévues pour le scoring :

- [ ] Détection de répétitions consécutives (ex: `aaa`, `111`)
- [ ] Analyse de fréquence des caractères
- [ ] Détection de patterns (ex: `abc`, `123`, `qwerty`)

## Langage

Écrit en **C** (standard C11), compilable avec GCC.