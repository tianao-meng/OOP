//
// Created by 孟天奥 on 2020-10-01.
//
#ifndef Q2_EXPRESSION_H
#define Q2_EXPRESSION_H

#include <iostream>
#include <vector>
//#include <string>
class integers;

class expression{

public:
    std :: string toPrint;
    virtual integers  evaluate() = 0;
    virtual void prettyprint() = 0;
    virtual ~expression()= default;
//    virtual ~expression(){
//        std :: cout <<" in expression" << std :: endl;
//    }
};

class integers : public expression{

public:
    int val;
    integers(int i);
    ~integers() = default;
//    ~integers(){
//        std :: cout <<" in integers" << std :: endl;
//    }
    integers evaluate();

    int getInt();
    void prettyprint() ;

};

class unary : public expression {

public:
    std :: string type;
    expression * operand;
    unary(std :: string t, expression * i);
    ~unary() = default;
//    ~unary(){
//        std :: cout <<" in unary" << std :: endl;
//    }
    integers  evaluate();
    void prettyprint();



};

class binary : public expression{

public:
    std :: string type;
    expression * operand_1;
    expression * operand_2;

    binary(std :: string t, expression * i, expression * j);
    ~binary()= default;
//    ~binary(){
//        std :: cout <<" in binary" << std :: endl;
//    }
    void prettyprint();
    integers  evaluate();



};

class stack {

public:
    int size = 0;
    std :: vector<expression * > data;
    std :: vector<expression * > :: iterator it = data.begin();
    void push (expression * i);
    expression * pop ();


};


#endif //Q2_EXPRESSION_H
