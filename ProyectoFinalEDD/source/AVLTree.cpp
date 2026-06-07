#include "../headers/AVLTree.h"

AVLTree::AVLTree() {

    root = NULL;
}

int AVLTree::getHeight(AVLNode* node) {

    if(node == NULL) {

        return 0;
    }

    return node->height;
}

int AVLTree::getBalance(AVLNode* node) {

    if(node == NULL) {

        return 0;
    }

    return getHeight(node->left)
           - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {

    AVLNode* x = y->left;

    AVLNode* T2 = x->right;

    x->right = y;

    y->left = T2;

    y->height =
    max(getHeight(y->left),
        getHeight(y->right)) + 1;

    x->height =
    max(getHeight(x->left),
        getHeight(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {

    AVLNode* y = x->right;

    AVLNode* T2 = y->left;

    y->left = x;

    x->right = T2;

    x->height =
    max(getHeight(x->left),
        getHeight(x->right)) + 1;

    y->height =
    max(getHeight(y->left),
        getHeight(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insertNode(AVLNode* node,
                             Student student) {

    if(node == NULL) {

        AVLNode* newNode = new AVLNode();

        newNode->data = student;

        newNode->left = NULL;

        newNode->right = NULL;

        newNode->height = 1;

        return newNode;
    }

    if(student.skill_score
       < node->data.skill_score) {

        node->left =
        insertNode(node->left,
                   student);
    }

    else if(student.skill_score
            > node->data.skill_score) {

        node->right =
        insertNode(node->right,
                   student);
    }

    else {

        return node;
    }

    node->height =
    1 + max(getHeight(node->left),
            getHeight(node->right));

    int balance =
    getBalance(node);

    if(balance > 1
       && student.skill_score
       < node->left->data.skill_score) {

        return rotateRight(node);
    }

    if(balance < -1
       && student.skill_score
       > node->right->data.skill_score) {

        return rotateLeft(node);
    }

    if(balance > 1
       && student.skill_score
       > node->left->data.skill_score) {

        node->left =
        rotateLeft(node->left);

        return rotateRight(node);
    }

    if(balance < -1
       && student.skill_score
       < node->right->data.skill_score) {

        node->right =
        rotateRight(node->right);

        return rotateLeft(node);
    }

    return node;
}

void AVLTree::inorderTraversal(AVLNode* node) {

    if(node != NULL) {

        inorderTraversal(node->left);

        cout
        << node->data.skill_score
        << " - "
        << node->data.full_name
        << endl;

        inorderTraversal(node->right);
    }
}

void AVLTree::insert(Student student) {

    root = insertNode(root,
                      student);
}

void AVLTree::inorder() {

    cout << "\n===== AVL TREE =====\n";

    inorderTraversal(root);
}

AVLNode* AVLTree::searchNode(AVLNode* node,
                             int skill) {

    if(node == NULL
       || node->data.skill_score == skill) {

        return node;
    }

    if(skill < node->data.skill_score) {

        return searchNode(node->left,
                          skill);
    }

    return searchNode(node->right,
                      skill);
}

void AVLTree::search(int skill) {

    AVLNode* result =
    searchNode(root, skill);

    if(result == NULL) {

        cout << "\nEstudiante no encontrado\n";

        return;
    }

    cout << "\n===== ESTUDIANTE AVL =====\n";

    cout << "ID: "
         << result->data.student_id
         << endl;

    cout << "Nombre: "
         << result->data.full_name
         << endl;

    cout << "Carrera: "
         << result->data.career
         << endl;

    cout << "Skill Score: "
         << result->data.skill_score
         << endl;
}