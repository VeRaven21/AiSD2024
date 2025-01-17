// ��������� �����, ���-233202. �������� ������� �������� � �������� ������, �������� 99 ������� 3.10
#include "L310_099.hpp"

Tree* create_tree(Tree* parent, int item) { // �������� ��������� ������
    Tree* node = new Tree;
    node->parent = parent;
    node->data = item;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Tree* insert(Tree* root, int item) { // ������� ������� �������� � �������� ������
    if (root == nullptr) {
        return create_tree(nullptr, item);
    }

    if (item < root->data) {
        if (root->left == nullptr) {
            root->left = create_tree(root, item);
        }
        else {
            root->left = insert(root->left, item);
        }
    }
    else {
        if (root->right == nullptr) {
            root->right = create_tree(root, item);
        }
        else {
            root->right = insert(root->right, item);
        }
    }

    return root;
}

void delete_tree(Tree* root) { //�������� ������
    if (root == nullptr) return;
    delete_tree(root->right);
    delete_tree(root->left);
    delete root;
}
