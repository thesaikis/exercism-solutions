class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return f'TreeNode(data={self.data}, left={self.left}, right={self.right})'


class BinarySearchTree:
    def __init__(self, tree_data):
        self.root = None

        for data in tree_data:
            self.insert(data, self.root)

    def data(self):
        return self.root

    def sorted_data(self):
        stack = []
        node = self.root
        data = []

        while node is not None or stack:
            while node is not None:
                stack.append(node)
                node = node.left

            node = stack.pop()
            data.append(node.data)

            node = node.right

        return data

    def insert(self, data, cur_node):
        if self.root is None:
            self.root = TreeNode(data)
            return

        if data <= cur_node.data:
            if cur_node.left is None:
                cur_node.left = TreeNode(data)
            else:
                self.insert(data, cur_node.left)
        else:
            if cur_node.right is None:
                cur_node.right = TreeNode(data)
            else:
                self.insert(data, cur_node.right)
