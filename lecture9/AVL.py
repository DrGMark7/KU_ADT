class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key
        self.height = 1

class AVLTree:
    def insert(self, root, key):
        if not root:
            return TreeNode(key)
        elif key < root.value:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        
        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        
        balance = self.getBalance(root)
        
        if balance > 1 and key < root.left.value:
            return self.rightRotate(root)
        if balance < -1 and key > root.right.value:
            return self.leftRotate(root)
        if balance > 1 and key > root.left.value:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        if balance < -1 and key < root.right.value:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        
        return root
    
    def delete(self, root, key):
        if not root:
            return root
        
        elif key < root.value:
            root.left = self.delete(root.left, key)
        elif key > root.value:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            
            temp = self.getMinValueNode(root.right)
            root.value = temp.value
            root.right = self.delete(root.right, temp.value)
        
        if root is None:
            return root
        
        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        
        balance = self.getBalance(root)
        
        if balance > 1 and self.getBalance(root.left) >= 0:
            return self.rightRotate(root)
        if balance > 1 and self.getBalance(root.left) < 0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        if balance < -1 and self.getBalance(root.right) <= 0:
            return self.leftRotate(root)
        if balance < -1 and self.getBalance(root.right) > 0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        
        return root
    
    def leftRotate(self, z):
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y
    
    def rightRotate(self, z):
        y = z.left
        T3 = y.right
        y.right = z
        z.left = T3
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y
    
    def getHeight(self, root):
        if not root:
            return 0
        return root.height
    
    def getBalance(self, root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)
    
    def getMinValueNode(self, root):
        if root is None or root.left is None:
            return root
        return self.getMinValueNode(root.left)
    
    def preOrder(self, root):
        if not root:
            return
        print("{0} ".format(root.value), end="")
        self.preOrder(root.left)
        self.preOrder(root.right)

# เริ่มต้นจากต้นไม้ต้นที่มีค่าในโหนดตามรูปภาพ
myTree = AVLTree()
root = None

# สร้างต้นไม้จากค่าในรูปภาพ
nodes = [34, 21, 11, 8, 5, 3, 2, 4, 6, 7, 9, 10, 16, 12, 14, 15, 18, 17, 19, 20, 26, 23, 22, 24, 25, 31, 28, 27, 29, 30, 32, 33, 42, 37, 35, 36, 39, 38, 40, 41, 47, 45, 43, 44, 46, 49, 48, 50, 52, 51, 53, 54]

for node in nodes:
    root = myTree.insert(root, node)

# ลบโหนด 34
root = myTree.delete(root, 34)

# แสดงผลต้นไม้หลังจากการลบ
print("ต้นไม้หลังจากลบ 34:")
myTree.preOrder(root)

