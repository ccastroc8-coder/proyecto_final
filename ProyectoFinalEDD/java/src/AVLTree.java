class AVLNode {

    Student data;

    AVLNode left;

    AVLNode right;

    int height;

    public AVLNode(Student data) {

        this.data = data;

        left = null;

        right = null;

        height = 1;
    }
}

public class AVLTree {

    AVLNode root;

    public int height(AVLNode node) {

        if(node == null) {

            return 0;
        }

        return node.height;
    }

    public int getBalance(AVLNode node) {

        if(node == null) {

            return 0;
        }

        return height(node.left)
             - height(node.right);
    }

    public AVLNode rightRotate(AVLNode y) {

        AVLNode x =
        y.left;

        AVLNode T2 =
        x.right;

        x.right = y;

        y.left = T2;

        y.height =
        Math.max(
        height(y.left),
        height(y.right)) + 1;

        x.height =
        Math.max(
        height(x.left),
        height(x.right)) + 1;

        return x;
    }

    public AVLNode leftRotate(AVLNode x) {

        AVLNode y =
        x.right;

        AVLNode T2 =
        y.left;

        y.left = x;

        x.right = T2;

        x.height =
        Math.max(
        height(x.left),
        height(x.right)) + 1;

        y.height =
        Math.max(
        height(y.left),
        height(y.right)) + 1;

        return y;
    }

    public AVLNode insert(AVLNode node,
                          Student student) {

        if(node == null) {

            return new AVLNode(student);
        }

        if(student.student_id <
           node.data.student_id) {

            node.left =
            insert(node.left,
                   student);
        }

        else if(student.student_id >
                node.data.student_id) {

            node.right =
            insert(node.right,
                   student);
        }

        else {

            return node;
        }

        node.height =
        1 + Math.max(
        height(node.left),
        height(node.right));

        int balance =
        getBalance(node);

        if(balance > 1 &&
           student.student_id <
           node.left.data.student_id) {

            return rightRotate(node);
        }

        if(balance < -1 &&
           student.student_id >
           node.right.data.student_id) {

            return leftRotate(node);
        }

        if(balance > 1 &&
           student.student_id >
           node.left.data.student_id) {

            node.left =
            leftRotate(node.left);

            return rightRotate(node);
        }

        if(balance < -1 &&
           student.student_id <
           node.right.data.student_id) {

            node.right =
            rightRotate(node.right);

            return leftRotate(node);
        }

        return node;
    }

    public void insert(Student student) {

        root =
        insert(root,
               student);
    }

    public void inorder(AVLNode node) {

        if(node != null) {

            inorder(node.left);

            System.out.println(
            node.data.student_id +
            " - " +
            node.data.full_name);

            inorder(node.right);
        }
    }

    public void display() {

        System.out.println(
        "\n===== AVL TREE =====");

        inorder(root);
    }
}