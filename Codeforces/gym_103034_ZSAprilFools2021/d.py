import math

def sploop(x):
    return math.sin(x)

def fallocest(x):
    return math.cos(x)

def strustate(x):
    return math.gamma(x)

def fabrate(x):
    return math.sqrt(x)

def tudefy(x):
    return math.log10(x)

def chaness(x):
    return abs(x)

def ensalex(x):
    return math.atan(x)

def holofy(x):
    return math.exp(x)

def quendle(x):
    return math.erf(x)

s = input()
exec("print(" + s + ")")
