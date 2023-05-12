// NOTA - Si i > 30, usar 1LL
// Siendo S un numero y {i, j} indices 0-indexados:

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // retorna S % N, siendo N una potencia de 2
#define isOdd(S) (s & 1)
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) (1 << lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffInRange(S, i, j) s &= (((~0) << (j + 1)) | ((1 << i) - 1));
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
/*
Si en un problema tenemos un conjunto de menos de 30 elementos y tenemos que probar cual es el "bueno"
Podemos usar una mascara de bits e intentar cada combinacion.
int limit = 1 << (n + 1);
for (int i = 1; i < limit; i++) {
  ....
} 
*/

// Funciones integradas por el compilador GNU (GCC)
// IMPORTANTE ---> Si x cabe en un int quitar el ll de cada metodo :D
    
// Numero de bits encendidos de x
__builtin_popcountll(x);
        
// Indice del primer (de derecha a izquierda) bit encendido de x
// Por ejemplo __builtin_ffs(0b0001'0010'1100) = 3
__builtin_ffsll(x);
    
// Cuenta de ceros a la izquierda del primer bit encendido de x    
// Utilizado para calcular piso(log2(x)) -> 63 - __builtin_clzll(x)
// Si x es int, utilizar 31 en lugar de 63
// Por ejemplo __builtin_clz(0b0001'0010'1100) = 23 (YA QUE X SE TOMA COMO ENTERO)
__builtin_clzll(x);
     
// Cuenta de ceros a la derecha del primer uno (de derecha a izquierda
// Por ejemplo __builtin_ctzll(0b0001'0010'1100) = 2
__builtin_ctzll(x);
