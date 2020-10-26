import os
import glob
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np


def main():
    sns.set_theme()
    base_dir = os.environ["GUMPTION"]
    data_dir = os.path.join(base_dir, "results/chapter5")
    fig = plt.figure(figsize=(8, 6))
    ax1 = fig.add_subplot(1, 2, 1)
    ax2 = fig.add_subplot(1, 2, 2)
    for fname in glob.glob(os.path.join(data_dir, "*.dat")):
        with open(fname) as f:
            lines = f.readlines()
            x = [float(line.split()[0]) for line in lines]
            y = np.array([float(line.split()[1]) for line in lines])
            lny = np.log10(y)
            ax1.plot(x, y, "o-", label=os.path.basename(fname))
            ax2.plot(x, lny, "o-", label="log10-" + os.path.basename(fname))

    ax1.legend(loc="best")
    ax2.legend(loc="best")
    plt.xlabel("n")
    plt.ylabel("time/0.001s")
    fig.tight_layout()
    plt.savefig(os.path.join(data_dir, "sort.png"))


if __name__ == "__main__":
    main()
