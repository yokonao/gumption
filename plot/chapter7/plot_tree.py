import os
import json
import glob
from graphviz import Digraph


def main():
    base_dir = os.environ["GUMPTION"]
    data_dir = os.path.join(base_dir, "results/chapter7")
    for fname in glob.glob(os.path.join(data_dir, "*.json")):
        with open(fname, "r") as f:
            json_open = json.load(f)["BinarySearchTree"]
        graph = Digraph(format="png")
        relation_ls = []
        for data in json_open:
            if len(data) == 0:
                break
            if data["isItem"]:
                graph.node(data["id"], str(data["key"]), shape="box")
            else:
                graph.node(data["id"], str(data["key"]))
                relation_ls.append((data["id"], data["left"]))
                relation_ls.append((data["id"], data["right"]))
        for relation in relation_ls:
            graph.edge(relation[0], relation[1])
        graph.render(os.path.splitext(fname)[0])


if __name__ == "__main__":
    main()
