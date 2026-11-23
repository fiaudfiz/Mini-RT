*this project has been created as part of 42 curriculum by miouali and yyuskiv.*

# Minirt

## Table of contents

---

1. [What is a ray tracer ?](#1-what-is-a-ray-tracer)
2. [How to implement a ray tracer ?](#2-how-to-implement-a-ray-tracer)
3. [Architecture of this project](#3-architecture-of-this-project)
4. [How use it](#4-how-use-it)
5. [How import scenes from blender for exemple ?](#5-how-import-scenes-from-blender-for-exemmple)
6. [Ressources](#6-ressources)

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


# miniRT — math TODO

## 1. Tuples / vectors
- [ ] add(a, b)
- [ ] sub(a, b)
- [ ] negate(v)
- [ ] mul_scalar(v, k)          — float k
- [ ] div_scalar(v, k)          — fabsf(k) < EPSILON → return v
- [ ] magnitude(v)              — sqrtf
- [ ] normalize(v)              — compute len once, check < EPSILON
- [ +] dot(a, b)                 — returns float!
- [x] cross(a, b)               — fixed
- [ ] reflect(in, normal)       — in - normal * 2 * dot(in, normal)

## 2. Matrices (fix + test before moving on)
- [ ] t_matrix { int size; float m[4][4]; }
- [ ] identity()
- [ ] matrix_equal(a, b)        — true if equal, fabsf < EPSILON
- [ ] mult_matrix(a, b)
- [ ] mult_matrix_tuple(m, t)   — uses w
- [ ] transpose(m)              — loop m[i][j] = a[j][i]
- [ ] determinant(m)            — 2×2: m00*m11 - m01*m10; N×N: m[0][i] * cofactor
- [ ] submatrix(m, row, col)
- [ ] minor(m, row, col)
- [ ] cofactor(m, row, col)     — negate when (row + col) is odd
- [ ] inverse(m, &out)          — det once, return 0 if det ≈ 0

## 3. Transformations
- [ ] translation(x, y, z)
- [ ] scaling(x, y, z)
- [ ] rotation_x(rad)
- [ ] rotation_y(rad)
- [ ] rotation_z(rad)

## 4. Rays
- [ ] position(ray, t)          — origin + direction * t
- [ ] transform_ray(ray, m)

## 5. Shape
- [ ] intersect_sphere(s, ray, xs)   — quadratic formula, 0 or 2 hits
- [ ] hit(xs, count)                 — smallest t >= 0
- [ ] normal_at_sphere(s, point)
- [ ] ★ first render: red circle on black

## 6. Colors + lighting
- [ ] add_color(a, b)
- [ ] mul_color_scalar(c, k)
- [ ] hadamard(a, b)            — component-wise multiply
- [ ] lighting(material, light, point, eye, normal)   — ambient + diffuse + specular
- [ ] ★ render: shaded sphere

## 7. Camera
- [ ] view_transform(from, to, up)
- [ ] ray_for_pixel(cam, px, py)
- [ ] render(cam, world)

## 8. miniRT-specific
- [ ] orientation_to_matrix(dir)    — rotate y axis onto .rt orientation vector
- [ ] intersect_plane + normal_at_plane
- [ ] intersect_cylinder + caps + normal_at_cylinder
- [ ] is_shadowed(world, point)
- [ ] ★ render a full .rt scene

## Tests (book values)
- [ ] cross((1,2,3), (2,3,4)) == (-1, 2, -1)
- [ ] dot((1,2,3), (2,3,4)) == 20
- [ ] determinant of book's 4×4 == -4071
- [ ] A * B * inverse(B) == A
- [ ] transpose(identity) == identity