# Solution for small range ---> k <= 510
# if k is greater, use Java's BigInteger class
catalan = [0 for i in range(510)]


def precalculate():
    catalan[0] = 1
    for i in range(509):
        catalan[i + 1] = (((2*(2*i+1))/(i+2)) * catalan[i])


precalculate()

print(int(catalan[505]))
