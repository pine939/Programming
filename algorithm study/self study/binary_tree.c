#include<stdio.h>
#include<stdlib.h>
/*
1. root노드는 첫 노드로 한다. 첫 노드에서 binary search tree를 만들면서 insert한다.
2. search_node() current가 NULL이 될 때 까지 (자식노드가 없을 때 까지) 반복하며 찾는다.
3. insert_node() 일단 삽입하려는 노드의 부모를 찾고, 부모의 왼쪽/오른쪽에 해당 노드를 삽입한다.
*/
typedef struct  _treenode{
    int data;
    struct _treenode *left;
    struct _treenode *right;
} TREENODE;

TREENODE *root = NULL;

int search_node(TREENODE *node, int data) {
    if (node == NULL) return 0;

    while(node) {
        if (data == node->data) {
            return 1;
        } else if (data < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return 0;
}

void insert_node(TREENODE *node) {
    if (root == NULL) {
        root = node;
        printf("Insert : %d (root)\n", node->data);
        return;
    }

    if (search_node(root, node->data) != 1) {  // 중복X
        TREENODE *parent;
        TREENODE *current;

        current = root;

        while(current) {
            parent = current;
            if (node->data < parent->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (node->data < parent->data) {
            parent->left = node;            
        } else {
            parent->right = node;
        }
        
        printf("Insert : %d\n", node->data);
        return;
    }

    printf("%d is already exist in tree\n", node->data);
}

TREENODE * make_node(int data) {
    TREENODE *node = (TREENODE *)malloc(sizeof(TREENODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void visit(TREENODE *node) {
    printf("%d ", node->data);
}

void preorder(TREENODE *node) {
    if (node != NULL) {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

void midorder(TREENODE *node) {
    if (node != NULL) {
        midorder(node->left);
        visit(node);
        midorder(node->right);
    }
}

void postorder(TREENODE *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
}

void build_tree() {
    insert_node(make_node(10));
    insert_node(make_node(14));
    insert_node(make_node(7));
    insert_node(make_node(16));
    insert_node(make_node(11));
    insert_node(make_node(1));
    insert_node(make_node(2));
    insert_node(make_node(20));
    insert_node(make_node(3));
    insert_node(make_node(15));
    insert_node(make_node(12));
}

int main(void) {
    int num, snum, ret;
    printf("build tree\n");
    build_tree();
    printf("\n");
    
    printf("pre order\n");
    preorder(root);
    printf("\n");

    printf("mid order\n");
    midorder(root);
    printf("\n");

    printf("post order\n");
    postorder(root);
    printf("\n");

    printf("Insert number :");
    scanf("%d", &num);
    insert_node(make_node(num));
    printf("New binary tree(preorder) : ");
    preorder(root);
    printf("\n");

    printf("Search number :");
    scanf("%d", &snum);
    ret = search_node(root, snum);
    if (ret == 1) {
        printf ("%d is exist!\n", snum);
    } else {
        printf("%d is not exist!\n", snum);
    }

}