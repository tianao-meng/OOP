//
// Created by 孟天奥 on 2020-10-12.
//

#ifndef Q4_ALLCAPS_H
#define Q4_ALLCAPS_H

#include "echo.h"
#include "textprocess.h"
#include "decorator.h"

class Allcaps: public Decorator {
    //std::istream *source;
public:
    Allcaps(TextProcessor * component);
    std::string getWord() override;
    void setSource(std::istream *in) override;
};

#endif //Q4_ALLCAPS_H
