class Record:
    def __init__(self, record_id, parent_id):
        self.record_id = record_id
        self.parent_id = parent_id


class Node:
    def __init__(self, node_id):
        self.node_id = node_id
        self.children = []


def BuildTree(records):
    items = {r.record_id: Node(r.record_id) for r in records}
    root = items.get(0, None)

    if any(n not in items for n in range(len(records))):
        raise ValueError("Record id is invalid or out of order.")

    for r in sorted(records, key=lambda r: r.record_id):
        if r.parent_id > r.record_id:
            raise ValueError("Node parent_id should be smaller than it's record_id.")

        if r.record_id != 0:
            if r.record_id == r.parent_id:
                raise ValueError("Only root should have equal record and parent id.")

            items[r.parent_id].children.append(items[r.record_id])

    return root
