# push_swap

`push_swap` est un projet de l’École 42 qui consiste à trier une pile d'entiers avec un nombre minimal d'opérations, en utilisant deux piles (A et B) et un ensemble restreint d'instructions.  
Ce projet met à l’épreuve la capacité à concevoir un algorithme efficace, à manipuler des structures de données, et à respecter de fortes contraintes techniques.

## Objectifs pédagogiques

- Implémenter un algorithme de tri optimisé sous contraintes
- Manipuler des piles et des structures chaînées en C
- Optimiser les performances en temps et en nombre d'instructions
- Respecter les règles strictes du projet 42 (pas de tri classique autorisé)

##  Algorithme utilisé

Pour les grandes piles (≥ 100 éléments), j’ai utilisé **l’algorithme de tri par base (Radix Sort)**, adapté pour fonctionner avec des entiers indexés, afin de garantir une complexité en O(n log n).

Pour les petits jeux de données (≤ 5), des algorithmes de tri brut avec conditions précises sont utilisés pour atteindre un nombre optimal d'opérations.

## Instructions autorisées

| Instruction | Description                        |
|------------|------------------------------------|
| `sa`, `sb`, `ss` | Swap (pile A, pile B, les deux)     |
| `pa`, `pb`       | Push (de B vers A, de A vers B)     |
| `ra`, `rb`, `rr` | Rotate (vers le haut)              |
| `rra`, `rrb`, `rrr` | Reverse rotate (vers le bas)     |

## 🧪 Compilation & Exécution

### Compiler le programme
```bash
make
