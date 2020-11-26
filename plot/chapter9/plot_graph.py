import os
import json
import glob
from graphviz import Digraph


def main():
    base_dir = os.environ["GUMPTION"]
    data_dir = os.path.join(base_dir, "results/chapter9")
    for fname in glob.glob(os.path.join(data_dir, "*.json")):
        with open(fname, "r") as f:
            json_open = json.load(f)
        graph = Digraph(format="png")

        print(json_open)
        for i in range(int(json_open["size"])):
            graph.node(str(i), str(i))
        for idx in json_open["content"]:
            for item in json_open["content"][idx]:
                graph.edge(idx, str(item))
        graph.render(os.path.splitext(fname)[0])


if __name__ == "__main__":
    main()
