#include<stdio.h>
#include<stdlib.h>
/*
1. root노드는 첫 노드로 한다. 첫 노드에서 binary search tree를 만들면서 insert한다.
2. search_node() current가 NULL이 될 때 까지 (자식노드가 없을 때 까지) 반복하며 찾는다.
3. insert_node() 일단 삽입하려는 노드의 부모를 찾고, 부모의 왼쪽/오른쪽에 해당 노드를 삽입한다.
*/
typedef struct _treenode {
    int data;
    struct _treenode *left;
    struct _treenode *right;
} TREENODE;

TREENODE *root = NULL; // 어떻게 정하지? -> 첫번째 노드!
int search_node(TREENODE *current, int data) {
    if (current == NULL) {
        return 0;
    }
/*
    if (data == current->data) {
        return 1;
    } else if (data < current->data) {
        printf("%d smaller than %d\n", data, current->data);
        search_node(current->left, data);
    } else if (data > current->data) {
        printf("%d is bigger than %d\n", data, current->data);
        search_node(current->right, data);
    }  
*/
    while(current != NULL) {
        if (data == current->data) {
            return 1;
        } else if (data < current->data) {
            // current의 왼쪽 노드 탐색
            current = current->left;
        } else {
            // current의 오른쪽 노드 탐색 
            current = current->right;
        }
    }
    return 0;
}

TREENODE *make_node(int data) {
    TREENODE *node = (TREENODE *)malloc(sizeof(TREENODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(TREENODE *node) {
    if (root == NULL) {
        printf("Insert %d \n", node->data);
        root = node;
        return;
    }

    if (search_node(root, node->data) != 1) {  // 중복 없음
        TREENODE *parent = NULL;
        TREENODE *current = root;  // 어떻게 정하지? -> 첫 노드
        // node의 부모를 정한다
        while(current != NULL) {
            parent = current;
            if (node->data < parent->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // 노드 삽입
        if (node->data < parent->data) {
            parent->left = node;
        } else {
            parent->right = node;
        }

        printf("Insert %d \n", node->data);
        return;
    }
    printf("%d is already exist!\n", node->data);
}



void build_tree() {
    // 10, 14, 2, 5, 11, 16
    insert_node(make_node(10));
    insert_node(make_node(14));
    insert_node(make_node(2));
    insert_node(make_node(5));
    insert_node(make_node(11));
    insert_node(make_node(16));
}

void visit(TREENODE *node) {
    if (node != NULL) {
        printf("%d ", node->data);
    }
}

void preorder(TREENODE *node) {
    if (node != NULL) {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

int main(void) {
    int snum, num;
    build_tree();
    printf("Preorder : \n");
    preorder(root);
    printf("\n\n");

    printf("Search Number : ");
    scanf("%d", &snum);
    printf("result(0=not exist / 1=exist) : %d\n\n", search_node(root, snum));

    printf("Enter Number : ");
    scanf("%d", &num);
    insert_node(make_node(num));
    printf("New Bin Search Tree : \n");
    preorder(root);
    printf("\n");


}