//
// Created by 孟天奥 on 2020-09-18.
//

#ifndef _TREE_H_
#define _TREE_H_

#include <stack>

class Tree;
class TreeNode;

//enum Types {left, right, root};

class TreeNode{

public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
    TreeNode(int value);

};

class Tree {
    //friend class TreeNode;
    TreeNode *root;
    TreeNode *start;
    TreeNode *ending;
    TreeNode *cur;


public:

    class iterator {
        friend class Tree;

        iterator(TreeNode * ptr);

    public:
        TreeNode * pointer;


        //get next smallest value of BST

        bool operator== (Tree:: iterator  rpointer);
        bool operator!= (Tree:: iterator  rpointer);
        iterator operator++ ();
        //TreeNode* operator*();
        iterator  operator*();
    };


    iterator begin();
    iterator end();
//    TreeNode* operator*(iterator & is);

    Tree();
    ~Tree();

    TreeNode * left_next(TreeNode * node);
    TreeNode * right_next (TreeNode * node);
    void insert (int data);

};

TreeNode * get_smallest(TreeNode * root);
void push(TreeNode * node);
TreeNode * get_largest(TreeNode * root);
std::ostream& operator<<(std::ostream& out, Tree :: iterator & is);
void deleteTree(TreeNode * node);
#endif
