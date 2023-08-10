# Solucion para un rango chico ---> k <= 510
# Si k es mayor, puedes utilizar la clase BigInteger de Java
# Si solo necesitamos almacenar catalan[i] % m, usa c++
catalan = [0 for i in range(510)]

def precalculate():
    catalan[0] = 1
    for i in range(509):
        catalan[i + 1] = ((2*(2*i+1) * catalan[i])/(i+2))

precalculate()

print(int(catalan[505]))
