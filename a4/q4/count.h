//
// Created by 孟天奥 on 2020-10-12.
//

#ifndef Q4_COUNT_H
#define Q4_COUNT_H

#include "echo.h"
#include "textprocess.h"
#include "decorator.h"

class Count: public Decorator {
    //std::istream *source;
    char c;
    int n = 0;

public:
    Count(TextProcessor * component, char c);
    void setSource(std::istream *in) override;
    std::string getWord() override;
};

#endif //Q4_COUNT_H
