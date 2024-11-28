
# Operaciones de Pila

Este documento describe las operaciones disponibles para manipular dos pilas, denominadas **A** y **B**. Las pilas son estructuras de datos donde los elementos se apilan y desapilan siguiendo el principio **LIFO** (Last In, First Out).

---

## Lista de Operaciones

### 1. **Intercambio de elementos (Swap)**
- `sa`: Intercambia el primer y segundo elemento de la pila **A**.  
  _Nota_: No hace nada si la pila **A** está vacía o tiene un solo elemento.

- `sb`: Intercambia el primer y segundo elemento de la pila **B**.  
  _Nota_: No hace nada si la pila **B** está vacía o tiene un solo elemento.

- `ss`: Realiza las operaciones `sa` y `sb` al mismo tiempo.  
  _Nota_: No hace nada en las pilas que no cumplan las condiciones de `sa` o `sb`.

---

### 2. **Movimientos entre pilas (Push)**
- `pa`: Mueve el primer elemento de la pila **B** a la pila **A**.  
  _Nota_: No hace nada si la pila **B** está vacía.

- `pb`: Mueve el primer elemento de la pila **A** a la pila **B**.  
  _Nota_: No hace nada si la pila **A** está vacía.

---

### 3. **Rotación hacia arriba (Rotate)**
- `ra`: Mueve el primer elemento de la pila **A** al final de la pila.  
  _Nota_: No hace nada si la pila **A** está vacía o tiene un solo elemento.

- `rb`: Mueve el primer elemento de la pila **B** al final de la pila.  
  _Nota_: No hace nada si la pila **B** está vacía o tiene un solo elemento.

- `rr`: Realiza las operaciones `ra` y `rb` al mismo tiempo.  
  _Nota_: No hace nada en las pilas que no cumplan las condiciones de `ra` o `rb`.

---

### 4. **Rotación hacia abajo (Reverse Rotate)**
- `rra`: Mueve el último elemento de la pila **A** al principio de la pila.  
  _Nota_: No hace nada si la pila **A** está vacía o tiene un solo elemento.

- `rrb`: Mueve el último elemento de la pila **B** al principio de la pila.  
  _Nota_: No hace nada si la pila **B** está vacía o tiene un solo elemento.

- `rrr`: Realiza las operaciones `rra` y `rrb` al mismo tiempo.  
  _Nota_: No hace nada en las pilas que no cumplan las condiciones de `rra` o `rrb`.

---

## Reglas generales
- Todas las operaciones que afecten a ambas pilas (como `ss`, `rr` o `rrr`) realizan cambios simultáneamente en ambas pilas, pero no tendrán efecto en pilas que no cumplan las condiciones específicas.
- Si una operación se realiza en una pila vacía o con un solo elemento, no habrá cambios.

