#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;
/*(Posiciones indexadas en 0).
Funciona igual que un set, con 2 operaciones extra:
obj.find_by_order(k) - Retorna un iterador apuntando al elemento k-esimo mas grande
obj.order_of_key(x) - Retorna un entero que indica la cantidad de elementos menores a x

Modificar únicamente primer y tercer parámetro, que corresponden a el tipo de dato
del ost y a la función de comparación de valores (less<T>, greater<T>, less_equal<T>
o incluso una implementada por nosotros)

Si queremos elementos repetidos, usar less_equal<T> (sin embargo, ya no servirá la
función de eliminación).

Si queremos elementos repetidos y necesitamos la eliminación, utilizar una
técnica con pares, donde el second es un número único para cada valor.
*/