# Node class for the binary tree
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


# Function to return the postOrder
# traversal of a binary tree using
# one stack
def postOrder(root):
    # Check if the tree is empty
    if not root:
        return []

    curr = root
    st = []
    postorder = []

    # Traverse the tree until
    # current node is not None
    # or the stack is not empty
    while curr or st:
        # If current node is not None,
        # push it onto the stack
        # and move to its left child
        if curr:
            st.append(curr)
            curr = curr.left
        else:
            # If current node is None,
            # check the right child of the
            # top node in the stack
            temp = st[-1].right if st[-1] else None

            # If right child is also None
            # or already visited, it means
            # we can process the top node now
            if not temp:
                # Get the top node from stack
                temp = st.pop()
                # Add the node's data to
                # the postorder traversal list
                postorder.append(temp.data)

                # Check if there are more
                # nodes to pop whose right
                # subtree is also processed
                while st and temp == st[-1].right:
                    temp = st.pop()
                    postorder.append(temp.data)
            else:
                # If right child exists,
                # set current node to it
                curr = temp

    # Return the list containing the
    # Postorder Traversal Sequence
    return postorder


# Function to print the
# elements of a list
def printList(lst):
    # Iterate through the list
    # and print each element
    for num in lst:
        print(num, end=" ")
    print()


# Main function
if __name__ == "__main__":
    # Creating a sample binary tree
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    # Getting postorder traversal
    result = postOrder(root)

    # Printing the postorder
    # traversal result
    print("Postorder traversal: ", end="")
    printList(result)
