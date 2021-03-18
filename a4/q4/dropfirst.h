//
// Created by 孟天奥 on 2020-10-12.
//


#ifndef Q4_DROPFIRST_H
#define Q4_DROPFIRST_H
#include "echo.h"
#include "textprocess.h"
#include "decorator.h"

class Dropfirst: public Decorator {
    //std::istream *source;
    int n;

public:
    Dropfirst(TextProcessor * component, int n);
    void setSource(std::istream *in) override;
    std::string getWord() override;
};


#endif //Q4_DROPFIRST_H
