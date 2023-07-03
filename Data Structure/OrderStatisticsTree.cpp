#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;
/*
Funciona igual que un set, con 2 operaciones extra en O(log n):
obj.find_by_order(k) - Retorna un iterador apuntando al elemento k-esimo mas grande
obj.order_of_key(x) - Retorna un entero que indica la cantidad de elementos menores a x

Modificar primer y tercer parametro, correspondientes al tipo de dato del ost
y a la funcion comparadora (less<T>, greater<T>, less_equal<T> o incluso una propia)

Si queremos elementos repetidos y no necesitamos eliminacion de valores, usar less_equal<T>.

Si queremos elementos repetidos y necesitamos la eliminacion, utilizar una
tecnica con pares, donde el second es un numero unico para cada valor.
*/

// Implementacion
int n = 9;
int A[] = {2, 4, 7, 10, 15, 23, 50, 65, 71};  // as in Chapter 2
ost tree;
for (int i = 0; i < n; ++i)  // O(n log n)
    tree.insert(A[i]);
// O(log n) select
cout << *tree.find_by_order(0) << "\n";      // 1-smallest = 2
cout << *tree.find_by_order(n - 1) << "\n";  // 9-smallest/largest = 71
cout << *tree.find_by_order(4) << "\n";      // 5-smallest = 15
// O(log n) rank
cout << tree.order_of_key(2) << "\n";   // index 0 (rank 1)
cout << tree.order_of_key(71) << "\n";  // index 8 (rank 9)
cout << tree.order_of_key(15) << "\n";  // index 4 (rank 5)
