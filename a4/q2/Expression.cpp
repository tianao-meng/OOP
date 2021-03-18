//
// Created by 孟天奥 on 2020-10-01.
//

//#include <iostream>
//#include <vector>
#include "Expression.h"
#include <sstream>
using namespace std;

integers :: integers(int i){
    val = i;
    //char m = '0' + (i - 0);
    //string (1, m);
    stringstream ss;
    ss.exceptions(ios::failbit);
    ss << i;
    string m = ss.str();
    toPrint = m;
}

//integers :: ~integers(){
//
//}



integers  integers :: evaluate(){

    return *this;

}

int integers ::getInt() {

    return val;

}

void integers ::prettyprint() {

    cout << toPrint << endl;

}


unary :: unary(std :: string t, expression * i){

    type = t;
    operand = i;
    if (type == "NEG"){

        toPrint = "-" + operand -> toPrint;



    }

    if (type == "ABS"){

        toPrint = "|" + operand -> toPrint + "|";



    }


}
//unary :: ~unary(){
//
//}

integers  unary :: evaluate(){

    if (type == "NEG"){

        integers res = operand -> evaluate();
        integers output = integers(-(res.val));
        return output;

    }

    if (type == "ABS"){

        integers res = operand -> evaluate();
        integers output = integers(abs(res.val));
        return output;
    }

}

void unary :: prettyprint() {

    cout << toPrint << endl;

}

binary :: binary( string t, expression * i, expression * j){

    type = t;
    operand_1 = i;
    operand_2 = j;

    if (type == "+"){
        //cout << "in" << endl;
        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        toPrint = "(" + operand_1 -> toPrint + "+" + operand_2 -> toPrint + ")";

    }

    if (type == "-"){

        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        toPrint = "(" + operand_2 -> toPrint + "-" +operand_1 -> toPrint + ")";

    }

    if (type == "*"){
        //cout << "in" << endl;
        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        toPrint = "(" + operand_1 -> toPrint + "*" + operand_2 -> toPrint + ")";

    }

    if (type == "/"){

        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        toPrint = "(" + operand_2 -> toPrint + "/" + operand_1 -> toPrint + ")";

    }

}
//binary :: ~binary(){
//
//}

integers binary :: evaluate(){

    if (type == "+"){

        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        integers output = integers (res_1.val + res_2.val);
        return output;

    }

    if (type == "-"){

        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        integers output = integers (res_2.val - res_1.val);
        return output;

    }

    if (type == "*"){

        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        integers output = integers (res_1.val * res_2.val);
        return output;

    }

    if (type == "/"){

        integers res_1 = operand_1 -> evaluate();
        integers res_2 = operand_2 -> evaluate();
        integers output = integers (res_2.val / res_1.val);
        return output;

    }

}

void binary :: prettyprint(){

    cout << toPrint << endl;

}



void stack :: push(expression * i){
    //cout << i << endl;
    data.insert(it, i);
    size ++;
    it = data.begin();


}

expression * stack :: pop() {

    expression * output = data[0];

    data.erase(it);
    it = data.begin();
    size --;
    //cout << size << endl;
    return output;

}


