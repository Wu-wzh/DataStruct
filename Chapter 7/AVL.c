#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    int balance; // ƽ������
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

typedef AVLNode* AVLTree;

// ����ڵ�ĸ߶�
int Height(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = Height(node->left);
    int rightHeight = Height(node->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// ����ڵ��ƽ������
int BalanceFactor(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return Height(node->left) - Height(node->right);
}

// ��������
AVLNode* LeftRotate(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    // ����ƽ������
    node->balance = BalanceFactor(node);
    newRoot->balance = BalanceFactor(newRoot);
    return newRoot;
}

// ��������
AVLNode* RightRotate(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    // ����ƽ������
    node->balance = BalanceFactor(node);
    newRoot->balance = BalanceFactor(newRoot);
    return newRoot;
}

// �������
AVLNode* Insert(AVLNode* root, int key) {
    if (root == NULL) {
        AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
        newNode->data = key;
        newNode->balance = 0;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->data) {
        root->left = Insert(root->left, key);
    } else if (key > root->data) {
        root->right = Insert(root->right, key);
    } else {
        // ���Ѵ�����ͬ�ڵ㣬�򲻽��в������
        return root;
    }

    // ����ƽ������
    root->balance = BalanceFactor(root);

    // ƽ��ά��
    if (root->balance > 1) {
        if (key < root->left->data) {
            // LL�ͣ�������������
            root = RightRotate(root);
        } else if (key > root->left->data) {
            // LR�ͣ�������������
            root->left = LeftRotate(root->left);
            root = RightRotate(root);
        }
    } else if (root->balance < -1) {
        if (key > root->right->data) {
            // RR�ͣ�������������
            root = LeftRotate(root);
        } else if (key < root->right->data) {
            // RL�ͣ�������������
            root->right = RightRotate(root->right);
            root = LeftRotate(root);
        }
    }

    return root;
}

// �������
void InOrder(AVLNode* root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%d\n", root->data);
        InOrder(root->right);
    }
}

int main() {
    AVLNode* root = NULL;
    int keys[] = {50, 66, 60, 26, 21, 30, 70, 68};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        root = Insert(root, keys[i]);
    }

    InOrder(root);

    system("pause");
    return 0;
}
