import numpy as np

x0 =[
    [1, 2],
    [2, 1], ]

x1 = [
    [4, 4],
    [1, 2],
    [2, 3],
    [3, 4],
    [4, 1], ]

x2 = [
    [3, 3],
    [1, 2],
    [1, 3],
    [2, 3], ]


def read_input(x):
    a = np.zeros((20, 20))
    max_nb = 0
    for link in x:
        max_nb = link[0] if link[0] > max_nb else max_nb
        max_nb = link[1] if link[1] > max_nb else max_nb

        if link[0] == link[1]:
            pass
        else:
            a[link[0] - 1, link[1] - 1] = 1

    a = a[:max_nb, :max_nb]
    return a, max_nb


a, n = read_input(x2)
print(a)

color = np.zeros((n,))
color[0] = 1

for i in range(n):
    if color[i] == 0:
        color[i] = 1

    for j in range(n):
        if a[i, j] == 1:
            if color[j] == 0:
                color[j] = 3 - color[i]
            else:
                if color[j] != 3 - color[i]:
                    print(color, j)
                    raise ValueError("Not biparty graph")

print("biparty graph!")

# print()
