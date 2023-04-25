// NOTA - Si i > 30, usar 1LL
// Tomando en cuenta un número x e índices i, j (0-indexados); podemos hacer muchas cosas:

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) (1 << lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

/*Tomando en cuenta el i-esimo bit, retorna:
0                       Si está apagado
Cualquier otro valor    Si está encendido*/
x & (1 << i);

// Apagar (si está encendido) el i-esimo bit
x &= ~(1 << i);

// Prender (si está apagado) el i-esimo bit
x |= (1 << i);

// Invierte el i-esimo bit
x ^ (1 << i);

// Apaga los primeros i bits
x &= (-1 << i);

// Apaga los bits en el rango [i, j]
x &= (((~0) << (j + 1)) | ((1 << i) - 1));

/*Retorna:
1 si x es impar
0 si x es par*/
x & 1;

// Recorre a x k bits a la derecha, lo podemos ver como (x >> k) = piso(x / (2^k))
x >> k;

// Recorre a x k bits a la izquierda, lo podemos ver como (x << k) = x * (2^k)
x << k;
