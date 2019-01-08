import numpy as np

n = 4
x1 = np.arange(2, 18).reshape((4, 4))
x1 = np.array([[1, 2, 5], [7, 3, 4], [-1, 3, 2]])
x2 = np.array([[1, 2], [3, 4]])
x3 = np.array([[1, 2], [3, 4]])


def adj(x, i):
    n = x.shape[0]

    # print(x[1:,:i])
    # print(x[1:,i:])
    y = np.concatenate((x[1:, :i], x[1:, i + 1:]), axis=1)

    return y


def det(x):
    buf = 0
    if x.shape[0] == 1:
        return x[0, 0]
    else:
        for i in range(x.shape[0]):
            sign = (-1) ** (i)
            a = x[0, i]
            # print(sign, x[0, i], adj(x, i))
            buf += sign * a * det(adj(x, i))
            # print(buf)
        return buf


# print(x1)
print(det(x1))
print(np.linalg.det(x1))
