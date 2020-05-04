# AyEDA Tema 3

#  Índice
   > * Introduccio a los Arboles
   > * Arboles Binarios
   > * Arboles de Busqueda
   > * Arboles AVL

# Introduccion
# Concepto de árbol basado nodos

* Un **árbol** es un TDA formado por nodos cada uno de los cuales es
apuntado por un sólo nodo de su mismo tipo excepto el nodo raíz,
que no es apuntado por ninguno y desde el que se accede a todos los
demás por una serie de enlaces.
* Un árbol de **grado** n está formado por nodos con n apuntadores.
* Las listas simples se pueden interpretar como árboles de grado 1.
* Los **árboles binarios** son árboles de grado 2.

![](https://www.monografias.com/trabajos92/arboles-binario/image006.gif)

# Definición recursiva de árbol

El concepto abstracto de árbol se define *recursivamente*.
Un **árbol** T es una estructura compuesta por:
* una raíz y
* una serie finita de estructuras disjuntas de su mismo tipo.

Formalmente T = T(r; T1, T2, ..., Tk), con T1, T2, ... Tk *disjuntos*

Las estructurase T1, T2, ... y Tk son los *subárboles* de T.

Si se asume que los subárboles de un árbol están dados en un orden concreto se habla de árbol *ordenado*.

Por lo general los árboles son ordenados aunque no se diga.

# Definicion recursiva del nodo

Los nodos de un árbol también se definen **recursivamente**:

“**los nodos de un árbol son: su raíz y los nodos de sus subárboles**”

Relaciones entre nodos

El nodo raíz del árbol T se dice que:
* Es **padre** de los nodos raíz de los árboles T1, T2, ...y Tk.

Si el nodo i es padre del nodo j se dice que:
* El nodo j es **hijo** del nodo i.

Se pueden considerar definidas otras **relaciones** entre nodos:
**hermano, abuelo, nieto, ascendiente, descendiente, ....**

# Enlace

El número de hijos de un nodo se llama **grado** del nodo;
* El **grado de un árbol** es el máximo grado de sus nodos.
* Entre los nodos de un árbol se puede distinguir:
* * la **raíz**,
* * las **hojas** (o nodos terminales) que no tienen hijos, y
* * los **nodos interiores** que sí los tienen.
* La relación entre padres e hijos se representa por **enlaces** que van de cada nodo **hacia** cada uno de sus hijos.

* Un **camino** es una secuencia de enlaces de forma que cada enlace parte del nodo al que llega el enlace anterior.
* La **longitud** de un camino es el número de enlaces que lo componen.
* Una **rama** de un árbol es un árbol que tiene uno de sus nodos
como raíz; y está compuesto por todos los descendientes de
esta raíz y todos los enlaces de los caminos que parten de ella.

# Niveles

Los nodos de un árbol están organizados por niveles.
Las raíces de los subárboles de un árbol cualquiera se dice que tienen un **nivel** más que la raíz de dicho árbol.

El **nivel** de un nodo es:
* uno más que el nivel de su padre y
* uno menos que el nivel de cualquiera de sus hijos.

Los niveles se cuentan a partir de la **raíz** empezando por **0** (aunque a veces se empieza por **1**).

La **altura** de un árbol es el nivel máximo de sus nodos. (**profundidad** es un sinónimo de nivel o altura)

El **tamaño** de un árbol es el número de nodos que tiene.


![](Capturas/Cap28.png)

* La raíz del árbol T es A.
* El nodo A es padre de B, C y D.
* Los hijos de E son K y L.
* E, F y H son nietos de A.
* El nodo C es abuelo de P.
* Los nodos I y J son hermanos.
* El árbol T tiene tres subárboles de raíces B, C y D (en este orden).
* El nodo B tiene grado 2, H tiene grado 1 y G tiene grado 3.
* Los nodos K, L, F, P e I son nodos hoja.
* Los nodos B, D, G y J son interiores.
*  Existe un arco de C a G y una arista entre J y R.
* Los nodos A,C,G y N, con los arcos que los unen, constituyen un camino.
* La longitud del camino anterior es 3 (tiene tres arcos y 4 nodos).
* El árbol con nodos G, M, N y O es una rama de T pero no un subárbol.
* Si el nodo A es de nivel 0, los nodos de nivel 1 son B, C y D.
* Hay 6 nodos de nivel 2 y 8 de nivel 3.
* El grado del árbol es al menos 3.
* La profundidad del árbol es 3.
* El tamaño de árbol es 18.

# Arboles Binarios

Los árboles de grado 2 se llaman árboles binarios.

Son los árboles en los que ningún nodo tiene más de dos hijos.

En un árbol binario todos los nodos tienen grado 0, 1 ó 2.

Un árbol es binario si ningún nodo tiene grado superior a 2.

Los árboles:
* con sólo dos nodos (padre e hijo),
* con un solo nodo (la raíz) son árboles también **binarios**.

Además, un árbol binario puede ser **vacío**.

Esto motiva una definición recursiva distinta a la de árbol.

# Subárboles izquierdo y derecho

Los dos subárboles de un árbol binario se denominan: subárbol **izquierdo** y subárbol **derecho**.

Los dos hijos de cada nodo de un árbol binario se denominan hijo **izquierdo** e hijo **derecho**.

Puesto que estos dos árboles se consideran ordenados, si se intercambian, el árbol **no** es el mismo árbol.

Además, si un nodo tiene un sólo hijo **no** es indiferente que sea el hijo derecho a que sea el izquierdo.

En general, el orden entre los hijos es de izquierda a derecha.

Se puede definir un árbol binario como un árbol donde:
* **Todas sus ramas tienen exactamente dos subárboles** (que pueden ser vacíos).

# Resultados Formales

**Definición**. Un **árbol binario** B se define recursivamente como
un árbol vacío o un árbol constituido por:

Un nodo raíz y un par de subárboles binarios BI y BD

*Formalmente*: B = 0 o B = B (r ; BI, BD).

*Teorema*. Sea 0 el nivel de la raíz de un árbol binario. Entonces:
* El número máximo de nodos de nivel i es 2^i
* El número máximo de nodos de un árbol profundidad p es 2^p+1 - 1
* El número de nodos terminales de un árbol es 1 más el número
de nodos de grado 2.
* La profundidad mínima de un árbol de n nodos es p = [log2 n]
* La profundidad máxima de un árbol de n nodos es p = n

*Demostración*

Todos los apartados se demuestran fácilmente por inducción en el número n de nodos.