import os
import json
from graphviz import Digraph


def main():
    base_dir = os.environ["GUMPTION"]
    data_dir = os.path.join(base_dir, "results/chapter7")
    with open(os.path.join(data_dir, "out.json"), "r") as f:
        json_open = json.load(f)
    graph = Digraph(format="png")
    relation_ls = []
    data_ls = json_open["BinarySearchTree"]
    for data in data_ls:
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

    graph.render(os.path.join(data_dir, "tree"))


if __name__ == "__main__":
    main()
