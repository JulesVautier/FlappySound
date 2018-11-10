import numpy as np
import os
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

fig, ax = plt.subplots()
xdata, ydata = [1], [1]
ln, = plt.plot([], [], 'ro', animated=True)


def init():
    ax.set_xlim(0, 20)
    ax.set_ylim(10, 40)
    return ln,


arr = [0, 0]


def update(frame, arr):
    inByteFile = arr[0]
    x = arr[1]
    print(inByteFile)

    file_data = open("../data.txt", "r")
    if inByteFile != 0:
        file_data.seek(inByteFile)
    while True:
        line = file_data.readline()
        if not line:
            break
        xdata.append(int(xdata[-1:][0]) + 1)
        x = xdata[-1:][0]
        ax.set_xlim(x - 40, x)
        ydata.append(int(line))
    inByteFile = file_data.tell()
    file_data.close()
    ln.set_data(xdata, ydata)
    arr[0] = inByteFile
    arr[1] = x
    return ln,


ani = FuncAnimation(fig, update,
                    init_func=init, blit=True,
                    fargs=(arr, ))
plt.show()
