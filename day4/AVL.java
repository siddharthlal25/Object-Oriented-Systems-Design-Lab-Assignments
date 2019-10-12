import java.util.*;
 

public class AVL 
{ 

    static class Node 
    { 
	    int key, height; 
    	Node left, right;   

	    Node(int d) 
	    { 
		    key = d; 
	    	height = 1; 
	    } 
    }

	Node root; 

	static int height(Node n) 
	{ 
		if (n == null) 
			return 0; 

		return n.height; 
	} 


	static int max(int a, int b) 
	{ 
		return (a > b) ? a : b; 
	} 

	static Node rightRotate(Node y) 
	{ 
		Node x = y.left; 
		Node T2 = x.right; 

		x.right = y; 
		y.left = T2; 

		y.height = max(height(y.left), height(y.right)) + 1; 
		x.height = max(height(x.left), height(x.right)) + 1; 

		return x; 
	} 

	static Node leftRotate(Node x) 
	{ 
		Node y = x.right; 
		Node T2 = y.left; 

		y.left = x; 
		x.right = T2; 

		x.height = max(height(x.left), height(x.right)) + 1; 
		y.height = max(height(y.left), height(y.right)) + 1; 

		return y; 
	} 

	static int getBalance(Node N) 
	{ 
		if (N == null) 
			return 0; 

		return height(N.left) - height(N.right); 
	} 

	static Node insert(Node node, int key)
	{ 

		if (node == null) 
			return (new Node(key)); 

		if (key < node.key) 
			node.left = insert(node.left, key); 
		else if (key > node.key) 
			node.right = insert(node.right, key); 
		else 
			return node; 

		node.height = 1 + max(height(node.left), 
							height(node.right)); 

		
		int balance = getBalance(node); 

		
		if (balance > 1 && key < node.left.key) 
			return rightRotate(node); 

		if (balance < -1 && key > node.right.key) 
			return leftRotate(node); 


		if (balance > 1 && key > node.left.key)
		{ 
			node.left = leftRotate(node.left); 
			return rightRotate(node); 
		} 
 
		if (balance < -1 && key < node.right.key)
		{ 
			node.right = rightRotate(node.right); 
			return leftRotate(node); 
		} 

		return node; 
	} 
    
    static void inOrder(Node n)
    {
        if(n == null)
            return;
        
        inOrder(n.left);
        System.out.println(n.key);
        inOrder(n.right);
    }
        
    
	public static void main(String[] args)
	{ 
		Node root = null; 

		root = insert(root, 40); 
		root = insert(root, 30); 
		root = insert(root, 20); 
		root = insert(root, 10); 
		root = insert(root, 26); 
		root = insert(root, 50); 
        
        inOrder(root);
	} 
} 

