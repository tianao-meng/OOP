//
// Created by 孟天奥 on 2020-09-18.
//

#include <iostream>
#include <string>
#include "tree.h"
#include <stack>
using namespace std;

std :: stack <TreeNode *> stack_iterator;

Tree:: iterator :: iterator(TreeNode * ptr){
    pointer = ptr;
}

TreeNode * get_largest(TreeNode * root){

    TreeNode * parent = nullptr;
    TreeNode * root_1 = root;
    while (root_1){

        parent = root_1;
        root_1 = root_1 -> right;

    }


    if (parent == nullptr){

        return nullptr;
    }

    return parent;
}

void push(TreeNode * node){

    for (; node != nullptr; node = node -> left){

        //cout << "in"<< endl;
        //cout << node -> val << endl;
        stack_iterator.push(node);

    }


}

Tree:: iterator Tree:: begin(){

    push(root);
    if (!stack_iterator.empty()){
        start = stack_iterator.top();
        //cout << start << endl;

        stack_iterator.pop();
        push(start -> right);
        if (stack_iterator.empty()){
            cout << start -> val << endl;
            push(start -> right);
            return {start};
        }
        cout << start -> val;



        return {start};

    } else {
        return {nullptr};
    }

}

Tree:: iterator Tree:: end(){
    //cout << "in" << endl;
    ending = get_largest(root);
    //cout << ending ->val << endl;
    return {ending};
}



Tree:: iterator Tree:: iterator :: operator++ (){


    pointer = stack_iterator.top();

    stack_iterator.pop();
    push(pointer->right);
    //cout << pointer << endl;

    if (stack_iterator.empty()){
        cout << pointer -> val << endl;
        return {pointer};
    }
    cout << pointer -> val;

    return {pointer};

}

bool Tree:: iterator :: operator == (Tree:: iterator  rpointer){

    return rpointer.pointer == pointer;

}

bool Tree:: iterator :: operator != (Tree:: iterator  rpointer){

//    cout << rpointer.pointer << endl;
//    cout << pointer << endl;
    if (rpointer.pointer != pointer){
        //cout << "in" << endl;
        return true;
    } else {

        //cout << pointer -> val << endl;

        //stack_iterator.pop();

        return false;

    }
    //return rpointer.pointer != pointer;

}

//TreeNode* Tree:: iterator :: operator * (){
Tree:: iterator Tree:: iterator :: operator * (){
    //cout <<"in" << endl;

    return pointer;

}

//TreeNode* Tree:: operator*(Tree :: iterator & is){
//
//    cout << "in" << endl;
//    return is.pointer;
//}



TreeNode::TreeNode(int value){

    val = value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;

}


Tree::Tree(){

    root = nullptr;
    //start = get_smallest(TreeNode * root);

}

TreeNode * Tree :: left_next(TreeNode * node){

    if (!node) {
        return nullptr;
    }
    if (node -> left){
        return node -> left;
    } else {
        return nullptr;
    }

}

TreeNode * Tree :: right_next (TreeNode * node){

    if (! node){
        return nullptr;
    }

    if (node -> right){

        return node -> right;

    } else {

        return nullptr;

    }
}

void Tree::insert(int data) {

    //cout << "in" << endl;

    TreeNode * node = root;
    TreeNode * parent = nullptr;

    while (node){

        if (node -> val == data){
            return;
        }

        if (node -> val > data){
            parent = node;
            node = left_next(node);
            continue;
        }

        if (node -> val < data){
            parent = node;
            node = right_next(node);
            continue;
        }

    }

    if (parent == nullptr){
        //cout << "in" << endl;
        node = new TreeNode(data);
        root = node;

    } else {

        if (data > parent->val){

            node = new TreeNode(data);
            node -> parent = parent;
            parent -> right = node;
            //cout << parent ->val << endl;
        }

        if (data < parent->val){

            node = new TreeNode(data);
            node -> parent = parent;
            parent -> left = node;

        }

    }




}

std::ostream& operator<<(std::ostream& out, Tree :: iterator & is){

    //cout << "in "<< endl;
    //cout << is.pointer ->val;

    return cout;
}

void deleteTree(TreeNode * node){

    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

Tree::~Tree(){

    deleteTree(root);
}
