# push_swap

**push_swap** est un projet de l'école 42 dont l'objectif est de trier des données sur une pile en utilisant un nombre minimal d'opérations. Ce projet met l'accent sur les algorithmes de tri efficaces et la gestion de la complexité algorithmique.

## Sommaire

- [Introduction](#introduction)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Exemples](#exemples)
- [Auteur](#auteur)

## Introduction

Le projet **push_swap** consiste à implémenter un programme capable de trier une liste d'entiers en utilisant deux piles (`a` et `b`) et un ensemble limité d'opérations :

- `sa`, `sb`, `ss` : échange des éléments en haut des piles.
- `pa`, `pb` : push d'un élément d'une pile à l'autre.
- `ra`, `rb`, `rr` : rotation des piles.
- `rra`, `rrb`, `rrr` : rotation inverse des piles.

## Fonctionnalités

- Tri d'une séquence d'entiers en utilisant un minimum d'opérations.
- Vérification des entrées pour assurer la validité des données.
- Gestion des cas particuliers pour optimiser la performance (petites et grandes séries).
- Version bonus avec un programme `checker` pour valider des séquences d'opérations.

## Installation

1. Clonez le dépôt :

   ```bash
   git clone git@github.com:Kiores23/42-Project-push_swap.git
   cd 42-Project-push_swap
   cd push_swap
   ```

2. Compilation du programme principal :

   ```bash
   make
   ```

3. Compilation de la version bonus (avec checker) :

   ```bash
   make bonus
   ```

4. Nettoyage des fichiers objets :

   ```bash
   make clean
   ```

5. Nettoyage complet :

   ```bash
   make fclean
   ```

6. Recompilation :

   ```bash
   make re
   ```

## Utilisation

### Programme principal

```bash
./push_swap 3 2 1
```

Cela affichera une séquence d'opérations pour trier les nombres.

### Checker (bonus)

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

Le programme `checker` retournera `OK` si la séquence trie correctement la pile, sinon `KO`.

## Structure du projet

```
.
├── Makefile
├── srcs
│   ├── main.c
│   ├── ps_sort.c
│   ├── ps_utils.c
│   └── push_swap.h
└── srcs_bonus
    ├── checker.c
    ├── ps_sort.c
    └── push_swap.h
```

## Exemples

```bash
./push_swap 5 2 3 1 4
```

Sortie possible :

```
pb
pb
sa
pa
pa
```

Avec le checker :

```bash
ARG="5 2 3 1 4"; ./push_swap $ARG | ./checker $ARG
```

Sortie :

```
OK
```

## Auteur
- **Nom :** Alexis Mery
- **Email :** amery@student.42nice.fr
- **GitHub :** [Kiores23](https://github.com/kiores23)

---

*Ce projet a été réalisé dans le cadre du cursus de l'école 42.*

