//
// Created by 孟天奥 on 2020-10-12.
//

#ifndef Q4_DOUBLEWORDS_H
#define Q4_DOUBLEWORDS_H
#include "echo.h"
#include "textprocess.h"
#include "decorator.h"
#include <sstream>

class DoubleWords: public Decorator {
    //std::istream *source;
    std::stringstream ss;

public:

    DoubleWords (TextProcessor * component);
    void setSource(std::istream *in) override;
    std::string getWord() override;
};

#endif //Q4_DOUBLEWORDS_H
