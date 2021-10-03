//define node of the BST
class Node { 
    int key; 
    Node left, right; 
   
    public Node(int data){ 
        key = data; 
        left = right = null; 
    } 
} 
//BST class
class BST_class { 
    // BST root node 
    Node root; 
   
    BST_class(){ 
        root = null; 
    } 
   
    //PostOrder Traversal - Left:Right:rootNode (LRn)
    void postOrder(Node node)  { 
        if (node == null) 
            return; 
   
        // first traverse left subtree recursively 
        postOrder(node.left); 
   
        // then traverse right subtree recursively 
        postOrder(node.right); 
   
        // now process root node 
        System.out.print(node.key + " "); 
    } 
  // InOrder Traversal - Left:rootNode:Right (LnR) 
    void inOrder(Node node)  { 
        if (node == null) 
            return; 
        //first traverse left subtree recursively
        inOrder(node.left); 
   
        //then go for root node
        System.out.print(node.key + " "); 
   
        //next traverse right subtree recursively
        inOrder(node.right); 
    } 
   
//PreOrder Traversal - rootNode:Left:Right (nLR)
    void preOrder(Node node)  { 
        if (node == null) 
            return; 
   
        //first print root node first
        System.out.print(node.key + " "); 
        // then traverse left subtree recursively
        preOrder(node.left); 
        // next traverse right subtree recursively
        preOrder(node.right); 
    } 
   // Wrappers for recursive functions 
    void postOrder_traversal()  {    
        postOrder(root);  } 
    void inOrder_traversal() { 
        inOrder(root);   } 
    void preOrder_traversal() {
        preOrder(root);  } 
}
class Main{
    public static void main(String[] args) { 
        //construct a BST
        BST_class tree = new BST_class(); 
        /*        45
                //  \\
                10   90  
               // \\
               7   12      */
        tree.root = new Node(45); 
        tree.root.left = new Node(10); 
        tree.root.right = new Node(90); 
        tree.root.left.left = new Node(7); 
        tree.root.left.right = new Node(12); 
        //PreOrder Traversal
        System.out.println("BST => PreOrder Traversal:"); 
        tree.preOrder_traversal(); 
        //InOrder Traversal
        System.out.println("\nBST => InOrder Traversal:"); 
        tree.inOrder_traversal(); 
        //PostOrder Traversal
        System.out.println("\nBST => PostOrder Traversal:"); 
        tree.postOrder_traversal(); 
    } 
}
