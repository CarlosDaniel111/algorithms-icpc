#include <bits/stdc++.h>
using namespace std;

int main() {
    // Imprimir una cantidad especifica de digitos despues del punto decimal
    // en este caso 5
    cout.setf(ios::fixed); cout << setprecision(5);
    cout << 100.0/7.0 << '\n';
    cout.unsetf(ios::fixed);

    // Imprimir el numero con su decimal y el cero a su derecha
    // Salida -> 100.50
    // Si fuese 100.0, la salida seria -> 100.00
    cout.setf(ios::showpoint);
    cout << 100.5 << '\n';
    cout.unsetf(ios::showpoint);

    // Imprime un '+' antes de un valor positivo
    cout.setf(ios::showpos);
    cout << 100 << ' ' << -100 << '\n';
    cout.unsetf(ios::showpos);

    // Imprime valores decimales en hexadecimales
    cout << hex << 100 << " " << 1000 << " " << 10000 << dec << endl;

    // Redondea el valor dado al entero mas cercano
    round(5.5);

    // Se realiza la operacion y redondea, siempre que se pueda, hacia abajo el numero
    cout << a / b;

    // Se realiza la operacion y redondea, siempre que se pueda, hacia arriba el numero
    cout << (a + b - 1) / b;

    // Llena el arreglo/vector x, con value en cada posicion.
    fill(begin(x), end(x), value);

    // True si encuentra el valor, false si no
    binary_search(begin(x), end(x), value);

    // Retorna un iterador que apunta a un elemento mayor o igual a value
    lower_bound(begin(x), end(x), value);

    // Retorna un iterador que apunta a un elemento MAYOR a value
    upper_bound(begin(x), end(x), value);

    // Retorna un pair de iteradores, donde first es el lower_bound y second el upper_bound
    equal_range(begin(x), end(x), value);

    // Llena la estructura con el valor (unicamente puede ser -1 o 0)
    memset(estructura, valor, sizeof estrutura);

    // True si esta ordenado x, false si no.
    is_sorted(begin(x), end(x));

    // Ordena de forma que si hay 2 cincos, el primer cinco estara acomodado antes del segundo, tras ser ordenado
    stable_sort(begin(x), end(x));
}