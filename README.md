# 42sh
Création d'un shell à 4 avec pour objectif:
 - Lecture et édition de ligne avancée avec Termcaps  
- Analyse lexicale ("Lexing")  
- Analyse syntaxique ("Parsing")  
- Analyse sémantique  
- Génération d'un Arbre de Syntaxe Abstraite (Abstract Syntax Tree, AST)  
- Evaluation d'un AST
- Gestion de l'environnement  
- Gestion du PATH
- Gestion des processus et de leurs interactions
- Gestion de la ligne de commande et du terminal
- Gestion des fichiers

## Features

- Exécution de commande
 - Gestion du job control (`jobs`, `fg`, `bg` et `&`)
 - Édition de ligne en utilisant les termcaps (voir Raccourcis)
 - Gestion des redirections: `>`, `>>`, `<`, `<<`, `>&` et `<&`.
 - Séparateur de commandes (`;`).
 - Opérateurs logiques (`|`, `||` et `&&`)
 - Builtins à la norme POSIX:
	 - `cd`
	 - `echo`
	 - `type`
	 - `exit`
	 - `alias`
	 - `hash`
	 - `fc`
- Builtin non POSIX:
	- test avec les options suivantes: `-b`, `-c`, `-d`, `-e`, `-f`, `-g`, `-L`, `-p`, `-r`, `-S`, `-s`, `-u`, `-w`, `-x`, `-z`, `=`, `!=`, `-eq`, `-ne`, `-ge`, `-lt`, `-le` et `!`.
 - Gestion des variables internes au shell avec les builtins suivants:
	 - `set`
	 - `export`
	 - `<clef>=<valeur>`
	 - `unset`
- Gestions de tous les signaux
- Les inhibiteurs: `'`, `"`, `\`
- Expansion des variables, du tilde et des [paramètres](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_02)
- Gestion de l'historique

## Raccourcis
|Touches                         |Effet                        |
|--------------------------------|-----------------------------:|
|`Left/Right`                    |**Déplacement du curseur**               |
|`PgUp/PgDown`                   |**Déplacement du curseur sur le mot suivant ou précédent**|
|`Home/End`                      |**Déplacement du curseur au début ou à la fin de la saisie**|
|`Up/Down`                       |**Parcourir l'historique**|
|`Shift+Left/Right`              |**Sélection**|
|`Alt+X`                         |**Couper la sélection**|
|`Alt+C`                         |**Copier la sélection**|
|`Alt+V`                         |**Coller la sélection**|
|`Ctrl+R`                        |**Recherche dans l'historique**|
|`Ctrl+C`                        |**Annuler la saisie**|
|`Ctrl+D`                        |**Quitter**|

