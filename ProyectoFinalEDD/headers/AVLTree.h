#pragma once

#include <iostream>

#include "Student.h"

using namespace std;

struct AVLNode {

    Student data;

    AVLNode* left;
    AVLNode* right;

    int height;
};

class AVLTree {

private:

    AVLNode* root;

    int getHeight(AVLNode* node);

    int getBalance(AVLNode* node);

    AVLNode* rotateRight(AVLNode* y);

    AVLNode* rotateLeft(AVLNode* x);

    AVLNode* insertNode(AVLNode* node,
                        Student student);

    void inorderTraversal(AVLNode* node);

    AVLNode* searchNode(AVLNode* node,
                        int skill);

public:

    AVLTree();

    void insert(Student student);

    void inorder();

    void search(int skill);
};