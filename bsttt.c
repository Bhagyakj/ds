#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node in the Binary Search Tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in the right subtree
    }

    return root;
}

// Inorder Traversal: Left, Root, Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Visit root node
        inorder(root->right);  // Visit right subtree
    }
}

// Preorder Traversal: Root, Left, Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit root node
        preorder(root->left);  // Visit left subtree
        preorder(root->right);  // Visit right subtree
    }
}

// Postorder Traversal: Left, Right, Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);  // Visit left subtree
        postorder(root->right);  // Visit right subtree
        printf("%d ", root->data);  // Visit root node
    }
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int key) {
    // Base case: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's data, search in the right subtree
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's data, search in the left subtree
    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;  // Start with an empty tree
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal of the BST: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal of the BST: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = search(root, value);
                if (result != NULL) {
                    printf("Node %d found in the tree.\n", value);
                } else {
                    printf("Node %d not found in the tree.\n", value);
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
