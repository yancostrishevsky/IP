#include <stdio.h>
#include <stdlib.h>
struct bst
{
    int val;
    struct bst *left, *right;
};


struct bst* newNode(int key)
{
    struct bst* leaf = (struct bst*)malloc(sizeof (struct bst));
    leaf->val = key;
    leaf->left = leaf->right = NULL;
    return leaf;
}


void copyrec(struct bst* root, struct bst* copyRoot)
{
    if(root->left !=NULL )
    {
        copyRoot->left = newNode(root->left->val);
        copyrec(root->left,copyRoot->left);
    }
    if(root->right !=NULL)
    {
        copyRoot->right = newNode(root->right->val);
        copyrec(root->right,copyRoot->right);
    }
}


struct bst* copyTree(struct bst* root)
{
    struct bst* copyRoot = newNode(root->val);
    copyrec(root, copyRoot);
    return copyRoot;

}


void insert(struct bst* root, int key)
{
    struct bst* leaf = newNode(key);
    while(1)
    {
        if(root->val==leaf->val)
            break;
        if(root->val > leaf->val)
        {
            if(root->left != NULL)
            {
                root = root->left;
            }
            else
            {
                root->left = leaf;
                break;
            }
        }
        else
        {
            if(root->right != NULL)
                root = root->right;

            else
            {
                root->right = leaf;
                break;
            }
        }
    }
}


void display(struct bst* root)
{
    if(root!= NULL){

        display(root->left);
        printf("%d\n",root->val);
        display(root->right);

    }
}

void deleteTree(struct bst* root)
{
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);

    printf("\n usuwam: %d", root->val);
    free(root);
}



int main() {

    struct bst* root = newNode(100);
    insert(root,50);
    insert(root,20);
    insert(root,75);
    insert(root,10);
    insert(root,1);
    insert(root,12);
    insert(root,24);
    insert(root,22);
    insert(root,25);
    insert(root,60);
    insert(root,85);
    insert(root,55);
    insert(root,66);
    insert(root,80);
    insert(root,90);
    insert(root,150);
    insert(root,130);
    insert(root,120);
    insert(root,110);
    insert(root,121);
    insert(root,135);
    insert(root,131);
    insert(root,140);
    insert(root,200);
    insert(root,160);
    insert(root,159);
    insert(root,161);
    insert(root,300);
    insert(root,250);
    insert(root,301);
    deleteTree(root);


    return 0;
}
