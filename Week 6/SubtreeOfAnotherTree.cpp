#include <iostream>

using namespace std;

// Auxiliary Structure

struct NodeTree {
    int val;
    NodeTree *left;
    NodeTree *right;
    NodeTree(int x) : val(x), left(NULL), right(NULL) {}
};

// Code from Homework

// Fucntion to see is they s and t are the same
bool isEqual(NodeTree *s, NodeTree *t) {
    // IF the have reach null at the same time, they are equa
    if (s == NULL && t == NULL) {
        return true;
    }
    // If only one has reach null, it means the other has more s
    if (s == NULL || t == NULL) {
        return false;
    }
    // Recursively check for the rest of the s
    return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
}

// Function to traverse tree s in preorder
bool traversePreorder(NodeTree *s, NodeTree *t) {
    return  s != NULL && (isEqual(s, t) || traversePreorder(s->left,t) || traversePreorder(s->right,t));
}

// Main function
bool isSubtree(NodeTree *s, NodeTree *t) {
    return traversePreorder(s, t);
}


int main() {
    
    // Exaple A -> Simple Success
    NodeTree testS1a(10);
    NodeTree testS2a(2);
    NodeTree testS3a(1);
    NodeTree testS4a(3);
    NodeTree testS5a(13);
    
    testS1a.left = &testS2a;
    testS1a.right = &testS5a;
    testS2a.left = &testS3a;
    testS2a.right = &testS4a;
    
    NodeTree testT1a(2);
    NodeTree testT2a(1);
    NodeTree testT3a(3);
    
    testT1a.left = &testT2a;
    testT1a.right = &testT3a;
    
    cout << "EXAMPLE A" << endl;
    cout << "PREORDER TREE S: [10, 2, 1, 3, 13]" << endl;
    cout << "PREORDER TREE T: [2, 1, 3]" << endl;
    cout << endl;
    if (isSubtree(&testS1a, &testT1a)){
        cout << "T is subtree of S" << endl;
    }
    else{
        cout << "T is NOT subtree of S" << endl;
    }
    
    cout << endl;
    
    // Exaple B -> Simple Failure
    NodeTree testS1b(10);
    NodeTree testS2b(2);
    NodeTree testS3b(5);
    NodeTree testS4b(3);
    NodeTree testS5b(13);
    
    testS1b.left = &testS2b;
    testS1b.right = &testS5b;
    testS2b.left = &testS3b;
    testS2b.right = &testS4b;
    
    NodeTree testT1b(2);
    NodeTree testT2b(1);
    NodeTree testT3b(3);
    
    testT1b.left = &testT2b;
    testT1b.right = &testT3b;
    
    
    cout << "EXAMPLE B" << endl;
    cout << "PREORDER TREE S: [10, 2, 5, 3, 13]" << endl;
    cout << "PREORDER TREE T: [2, 1, 3]" << endl;
    cout << endl;
    if (isSubtree(&testS1b, &testT1b)){
        cout << "T is subtree of S" << endl;
    }
    else{
        cout << "T is NOT subtree of S" << endl;
    }
    
    return 0;
}
