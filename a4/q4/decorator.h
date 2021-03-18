//
// Created by 孟天奥 on 2020-10-12.
//

#include "echo.h"
#include "textprocess.h"

#ifndef Q4_DECORATOR_H
#define Q4_DECORATOR_H

class Decorator: public Echo {
    TextProcessor * component;
    //std::istream *source;
public:

    Decorator(TextProcessor * component);
    ~Decorator();
    void setSource(std::istream *in) override;
    TextProcessor * get_component();

};

#endif //Q4_DECORATOR_H
