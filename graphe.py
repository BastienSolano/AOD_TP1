import matplotlib.pyplot as plt

N = [i for i in range(100, 1001, 100)]
IJK = [14, 45, 166, 319, 474, 971, 1616, 2491, 4079, 5099]
IKJ = [6, 27, 84, 187, 352, 608, 946, 1426, 1992, 2704]

N3 = [i**3 for i in N]
X = [i/j for (i, j) in zip(IKJ, N3)]

plt.plot(N, X)
plt.xlabel("n")
plt.ylabel("time(ikj)/n^3")
plt.show()
