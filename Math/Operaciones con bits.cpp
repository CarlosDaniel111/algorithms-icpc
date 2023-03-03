//Tomando en cuenta un número x e índices i, j (0-indexados); podemos hacer muchas cosas:

/*Tomando en cuenta el i-esimo bit, retorna:
0                       Si está apagado
Cualquier otro valor    Si está encendido*/
x & (1 << i);

//Apagar (si está encendido) el i-esimo bit
x &= ~(1 << i);

//Prender (si está apagado) el i-esimo bit
x |= (1 << i);

//Invierte el i-esimo bit
x ^ (1 << i);

//Apaga los primeros i bits
x &= (-1 << i);

//Apaga los bits en el rango [i, j]
x &= (((~0) << (j + 1)) | ((1 << i) - 1));

/*Retorna:
1 si x es impar
0 si x es par*/
x & 1
