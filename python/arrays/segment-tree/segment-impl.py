class node:
    def __init__(val):
        self.val = val
        self.left = None
        self.right = None

def generateSegmentTree(strInp, root = None):
    if root is None:
        root = node(None)
    n = len(strInp)
    if n == 1:
        root.val = strInp[0]
        return root
    root.left = generateSegmentTree(strInp[:n//2],root.left)
    root.right = generateSegmentTree(strInp[n//2:],root.right)
    root.val = root.left.val + root.right.val
    return root
    

if __name__ == '__main__':
    pass