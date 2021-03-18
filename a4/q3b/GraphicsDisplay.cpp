//
// Created by 孟天奥 on 2020-10-10.
//

#include "GraphicsDisplay.h"
#include "window.h"
#include "info.h"

GraphicsDisplay :: GraphicsDisplay (Xwindow & a, int b) : w(a), gridsize(b){
}

void GraphicsDisplay :: notify(Subject &whoNotified){

    int gap = 500 / gridsize;
    Info notifier = whoNotified.getInfo();
    int r = notifier.row;
    int c = notifier.col;
    bool state = notifier.state;

    if (state){
        w.fillRectangle(((c * gap) + 1), ((r * gap) + 1), gap, gap, Xwindow::White);
    } else {
        w.fillRectangle(((c * gap) + 1), ((r * gap) + 1), gap, gap, Xwindow::Black);
    }

}
SubscriptionType GraphicsDisplay :: subType() const {
    return SubscriptionType::All;
}