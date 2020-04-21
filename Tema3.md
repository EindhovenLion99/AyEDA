# AyEDA Tema 3

#  Índice
   > * Introduccio a la Ordenacion
   > * Algoritmos Cuadraticos de Ordenacion
        Inserción, Selección, Intercambio
   > * Algoritmos Logaritmicos de Ordenacion
        HeapSort, QuickSort, MergeSort
   > * Otros Algoritmos de Ordenacion
        Incrementos decrecientes, Radicales, TimSort

# Ordenar

* **Ordenar**:
Reorganizar un conjunto de objetos en una secuencia especificada por una **clave**.
* **Objetivo** básico de la ordenación:
Facilitar la **búsqueda** de un elemento dado por su **clave**.
* La ordenación están presentes en **cualquier** contexto;
Se **aprende** antes a ordenar que a contar.
* Los métodos se describen para ordenación **ascendente**;
De menor a mayor clave.

# Clasificación de los métodos.

Según el dispositivo de almacenamiento:

* Los métodos de **ordenación externa**:
Los datos se almacenan en memoria **secundaria**.
* Los métodos de **ordenación interna**:
Los datos se almacenan en memoria **principal**.
Según la forma de abordar la tarea:
* Método de **ordenación directa**:
El método trabaja directamente con los elementos.
* Método de **ordenación por descomposición**:
El método trabaja con partes de la secuencia.

* Método **estable**: no altera el orden **previo** de los elementos de
la secuencia que tienen **igual** valor de la clave.

# Los mejores métodos de ordenación

Calidad de los métodos de ordenación:
Se mide por la **complejidad** algorítmica.

Clasificación:

* **Algoritmos Cuadráticos**: métodos **sencillos** que son **O(n^2)** en tiempo de ejecución.
* **Algoritmos Logarítimicos**: métodos **complejos** que son **O(n log2 n)** en tiempo de ejecución.
* **Otros algoritmos**: métodos mejorados que alcanzan tiempos de ejecución O(n^p) con p↓1 (n es el número de elementos de la secuencia)

# Algoritmos Cuadraticos de Ordenacion

# Inserccion

Se considera la secuencia de elementos a ordenar **dividida** en dos partes:
* Los *i* primeros elementos que **ya** están ordenados
* Los n-i últimos que **no** lo están.

![](Capturas/Cap7.png)

Se comienza desde i = 1

![](Capturas/Cap8.png)

En cada iteración:
* Se toma el elemento que ocupa la posición i y
* Se inserta en la posición (j) adecuada entre los i primeros;

![](Capturas/Cap9-.png)

Desde la secuencia

0 ---- 1 ---- j-1 ----- j ---- j+1 ---------- i-1 ------- i ----------- n-1

5 ---- 7 ---- 12 --- 42 ---- 44 -- 55 ---- 94 ------- 18 ----- 06 - 67

Se obtiene la situación:

0 ---- 1 ---- j-1 ----- j ---- j+1 ---------- i-1 ------- i ----------- n-1

5 ---- 7 ---- 12 --- 18 ---- 44 -- 55 --------------- 94 ----- 06 - 67

Ejecución, paso a paso

i = 1 | 44 55 12 42 94 18 06 67 | j = 1

i = 2 | 44 55 12 42 94 18 06 67 | j = 0

i = 3 | 12 44 55 42 94 18 06 67 | j = 1

i = 4 | 12 42 44 55 94 18 06 67 | j = 4

i = 5 | 12 42 44 55 94 18 06 67 | j = 1

i = 6 | 12 18 42 44 55 94 06 67 | j = 0

i = 7 | 06 12 18 42 44 55 94 67 | j = 6

i = 8 | 06 12 18 42 44 55 67 94

# El Codigo

El código del método de ordenación por inserción puede ser sólo:

```c++
for (int i = 1; i < n; i++)
    insertar(sec,i,x);
```

El procedimiento

```c
insertar(sec,i,x)
```

Deberá insertar en la posición adecuada de la secuencia de tamaño i el nuevo elemento x.

# La posicion de insercion 

Para determinar la posición j de inserción, se **recorre** la parte ya ordenada de la secuencia
**comparando** la clave del objeto a insertar con la clave de los elementos de la secuencia.

De forma **ascendente** desde el principio de la secuencia:

```c
j = 0 ;
while ( x > sec[j] )
     j++;
```

De forma descendente desde el índice i,

```c
j = i - 1 ;
while ( x < sec[j] )
     j--;
```

La técnica del **centinela** evita la doble condición de parada:
Se coloca como centinela una copia del elemento a insertar antes de la **primera** posición para que el recorrido se detenga al encontrarla.

```c
sec[-1] = x ;
j = i - 1 ;
while x < sec[j]
     j--;
```

# La insercion

Una vez determinada la posición j de inserción, es necesario **desplazar** la parte de la secuencia entre los índices i y j para dejar **hueco** al objeto a insertar.

```c
for (int k = i-1; k >= j; k--)
     sec[k+1] = sec[k];
     sec[j] = x;
```

Las operaciones de búsqueda descendente de la posición de inserción y la propia inserción **se pueden realizar a la vez**.

# Procedimiento Conjunto

```c
void inserta(Tvector &sec, int i, Tdef x){
     sec[-1] = x;
     j = i - 1;
     while ( x < sec[j] ){
     sec[j+1] = sec[j];
     j--;
     }
     sec[j+1] = x;
}
```

# Inserción con centinela

```c
for (int i = 1; i < n; i++ ){
     j = i;
     x = sec[i];
     sec[-1] = x;
     while ( x < sec[j-1] ){
          sec[j] = sec[j-1];
          j--;
     }
     sec[j] = x;
}
```

# Análisis de la complejidad


Se trata de un algoritmo de complejidad O(n^2).

Hay que realizar n veces la búsqueda de la posición de inserción, que es O(n).

Una **mejora** significativa se obtendría al realizar una **búsqueda binaria** de la posición de inserción.

* Se compara la clave del elemento a insertar con la del elemento **medio** de la secuencia de búsqueda.
* Según que la clave del elemento a insertar sea mayor o menor que la del elemento medio, la secuencia de búsqueda pasa a ser la mitad superior o la inferior de la anterior.

Al procedimiento resultante se le llama **BinSort**

# Procedimiento de BinSort

```c
for (int i = 1; i < n; i++ ) {
     j = i;
     x = sec[i];
     ini = 0; 
     fin = i-1;
     while(ini <= fin) {
          med = (ini+fin)/2;
          if (v[med] < x)
             ini = med+1;
          else
             fin = med-1;
     }
     for (int j = i-1; j >= ini; j--)
          sec[j+1] = sec[j];
     sec[ini] = x;
}
```

## EJEMPLO 

Partiendo de la situación intermedia del ejemplo anterior con el estado de la secuencia parcialmente ordenada siguiente.

12 42 44 55 94 18 06 67

La secuencia de los pasos que sigue el método es la siguiente:

Espacio de búsqueda --------- x ---- ini fin med

12 42 44 55 94 ---------------- **18** -- 0 -- 4 -- 2

12 42 -------------------------- **18** -- 0 -- 1 -- 0

--- 42 -------------------------- **18** -- 1 -- 1 -- 1


12 18 42 44 55 94 ------------- **06** -- 0 -- 5 -- 2

12 18 -------------------------- **06** -- 0 -- 1 -- 0

12 ------------------------------ **06** -- 0 -- 0 -- 0

06 12 18 42 44 55 94 ---------- **67** -- 0 -- 6 -- 3

------------- 44 55 94 ---------- **67** -- 4 -- 6 -- 5

-------------------- 94 ---------- **67** -- 6 -- 6 -- 6

# Compeljidad de BinSort

Si la **búsqueda binaria** en la secuencia de tamaño n emplea un tiempo **O(log n)** y se realiza una búsqueda binaria
en la parte de la secuencia ordenada, el algoritmo BinSort es **O(n log n)**.

* Sin embargo, un análisis cuidadoso de la implementación anterior muestra que este algoritmo es **O(n^2)**.
* Observando el procedimiento de la ordenación **BinSort** anterior se deduce que, aunque la **búsqueda binaria** es **O(log n)**, se aplica un procedimiento **O(n)** para **dejar hueco** al elemento a insertar.

# El analisis detallado

En particular, un análisis detallado del bucle **while** interno muestra que el número de divisiones (y comparaciones) máximo en la iteración i es log i = O(log n).

A continuación se ejecuta un bucle **for** en el que el número de asignaciones máximo en la iteración i es i = O(n).

Por tanto el número máximo total de divisiones y comparaciones es: n O(log n) = O(n log n),

pero el número máximo total de asignaciones realizadas es: **O(n^2).**

# Implementación óptima de BinSort

* Con la secuencia representada por una lista enlazada, como la descrita anteriormente, se evita el bucle **for** y el número de asignaciones también sería O(n log n).

* Sin embargo, la búsqueda binaria tal como se ha expuesto aquí, está implementada para una secuencia representada por **array** lo que permite acceder en tiempo O(1) al elemento medio, lo que no puede realizarse con la lista.

* Para obtener una implementación del algoritmo de ordenación por inserción de complejidad O(n log n) debe hacerse uso de un *árbol binario de búsqueda* para mantener la parte ordenada de la secuencia.







