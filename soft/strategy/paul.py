import numpy as np

def paul2(X, Y, Z):
    mysin = Z / np.sqrt(X**2 + Y**2)
    if mysin < -1 or 1 < mysin:
        return []
    delta = np.arcsin(mysin)
    main = np.arctan2(Y, X)
    return [delta - main, np.pi - delta - main]

def paul8(X, Y, Z1, Z2):
    Zp = Y**2 - Z1**2 - Z2**2 - X**2
    Xp = -2 * X * Z2
    Yp = -2 * X * Z1
    Ai = paul2(Xp, Yp, Zp)
    I = lambda ai: Z2 - X * np.sin(ai)
    R = lambda ai: Z1 - X * np.cos(ai)
    S = []
    for ai in Ai:
        ak = np.arctan2(I(ai) * np.sign(Y), R(ai) * np.sign(Y)) 
        S.append([ai, ak])
    return S

def paul6(X, Y, Z1, Z2, W):
    Zp = W**2 - Z1**2 - Z2**2 - X**2 - Y**2
    Xp = 2 * (X * Z2 + Y * Z1)
    Yp = 2 * (X * Z1 - Y * Z2)
    Ai = paul2(Xp, Yp, Zp)
    I = lambda ai: X * np.cos(ai) + Y * np.sin(ai) + Z1
    R = lambda ai: X * np.sin(ai) - Y * np.cos(ai) + Z2
    S = []
    for ai in Ai:
        ak = np.arctan2(I(ai) * np.sign(W), R(ai) * np.sign(W))
        S.append([ai, ak])
    return S
