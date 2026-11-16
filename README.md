*this project has been created as part of 42 curriculum by miouali and yyuskiv.

# Minirt

## Table of contents

---

1. [Architecture Globale de Minishell](#1-architecture-globale-minishell)
2. [REPL](#2-repl-interface-utilisateur)
3. [Lexer](#3-lexer)
4. [Parser](#4-parser)
5. [Expender](#5-expender)
6. [Executor](#6-executor)
7. [Ressources](#7-ressources)

---


## 1. What is a ray tracer ?

---

## 2. How to implement a ray tracer ?

---

## 3. Architecture of this project

---

## 4. How use it

---

## 5. How import scenes from blender for exemple ?

---

## 6. Ressources






































































Voici les 3 principales formules pour calculer le produit scalaire de deux vecteurs \(\vec{u}\) et \(\vec{v}\) :
1. Formule avec le cosinus (géométrique) :
\(\vec{u}\cdot \vec{v}=\|{}\vec{u}\|{}\times \|{}\vec{v}\|{}\times \cos (\vec{u},\vec{v})\)
(Utilisée lorsque l'on connaît les longueurs des vecteurs et l'angle entre eux).
2. Formule avec les coordonnées (analytique dans un repère orthonormé) :
	• Pour \(\vec{u}(x ; y)\) et \(\vec{v}(x' ; y')\) en 2D :
\(\vec{u}\cdot \vec{v}=xx^{\prime }+yy^{\prime }\)
(Utilisée lorsque l'on connaît les coordonnées des vecteurs).
3. Formule avec le projeté orthogonal :
\(\vec{AB}\cdot \vec{AC}=\vec{AB}\cdot \vec{AH}\)
où H est le projeté orthogonal du point C sur la droite (AB). Le produit est égal à ± AB × AH selon la position de H.