#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

bool isEmpty(Node* root) {
    return root == nullptr;
}

void createTree(Node*& root) {
    root = nullptr;
}

Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node;
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = node->right = nullptr;
    return node;
}

void insertNode(Node*& root, string nama, float berat, string tier) {
    if (root == nullptr) {
        root = newNode(nama, berat, tier);
    } else if (berat < root->beratBadan) {
        insertNode(root->left, nama, berat, tier);
    } else {
        insertNode(root->right, nama, berat, tier);
    }
}

Node* searchNode(Node* root, float berat) {
    if (root == nullptr || root->beratBadan == berat) return root;
    if (berat < root->beratBadan) return searchNode(root->left, berat);
    return searchNode(root->right, berat);
}

Node* mostLeft(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* mostRight(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

Node* findParent(Node* root, Node* child) {
    if (root == nullptr || root == child) return nullptr;
    if (root->left == child || root->right == child) return root;
    if (child->beratBadan < root->beratBadan) return findParent(root->left, child);
    return findParent(root->right, child);
}

void searchByBeratBadan(Node* root, float berat) {
    Node* target = searchNode(root, berat);
    if (target == nullptr) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    cout << "Data ditemukan didalam BST!" << endl;
    cout << "--- Data Node Yang Dicari ---" << endl;
    cout << "Nama Member : " << target->namaMember << endl;
    cout << "Berat Badan : " << target->beratBadan << endl;
    cout << "Tier Member : " << target->tierMember << endl;
    cout << "-----------------------------" << endl;

    Node* parent = findParent(root, target);
    if (parent != nullptr) {
        cout << "--- Data Parent ---" << endl;
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;
        cout << "-----------------------------" << endl;
    }

    if (parent != nullptr) {
        Node* sibling = (parent->left == target) ? parent->right : parent->left;
        if (sibling != nullptr) {
            cout << "--- Data Sibling ---" << endl;
            cout << "Nama Member : " << sibling->namaMember << endl;
            cout << "Berat Badan : " << sibling->beratBadan << endl;
            cout << "Tier Member : " << sibling->tierMember << endl;
            cout << "-----------------------------" << endl;
        } else {
            cout << "Tidak Memiliki Sibling" << endl;
            cout << "-----------------------------" << endl;
        }
    }

    if (target->left != nullptr) {
        cout << "--- Data Child Kiri ---" << endl;
        cout << "Nama Member : " << target->left->namaMember << endl;
        cout << "Berat Badan : " << target->left->beratBadan << endl;
        cout << "Tier Member : " << target->left->tierMember << endl;
        cout << "-----------------------------" << endl;
    }

    if (target->right != nullptr) {
        cout << "--- Data Child Kanan ---" << endl;
        cout << "Nama Member : " << target->right->namaMember << endl;
        cout << "Berat Badan : " << target->right->beratBadan << endl;
        cout << "Tier Member : " << target->right->tierMember << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    Node* root;
    createTree(root);

    insertNode(root, "Rizkina Azizah", 60, "Basic");
    insertNode(root, "Hakan Ismail", 50, "Bronze");
    insertNode(root, "Olivia Saevali", 65, "Silver");
    insertNode(root, "Felix Pedrosa", 47, "Gold");
    insertNode(root, "Gamel Al Ghifari", 56, "Platinum");
    insertNode(root, "Hanif Al Faiz", 70, "Basic");
    insertNode(root, "Mutiara Fauziah", 52, "Bronze");
    insertNode(root, "Davi Ilyas", 68, "Silver");
    insertNode(root, "Abdad Mubarok", 81, "Gold");

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Node MostLeft : " << mostLeft(root)->beratBadan << endl;
    cout << "Node MostRight : " << mostRight(root)->beratBadan << endl;

    cout << endl;
    searchByBeratBadan(root, 70);

    return 0;
}
