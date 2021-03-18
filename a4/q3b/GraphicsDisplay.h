//
// Created by 孟天奥 on 2020-10-10.
//

#ifndef Q3B_GRAPHICSDISPLAY_H
#define Q3B_GRAPHICSDISPLAY_H
#include "observer.h"
#include "subscriptions.h"
#include "window.h"
#include "subject.h"
#include "window.h"
class Info;

class GraphicsDisplay : public Observer {
    Xwindow & w;
    const int gridsize;

public:
    GraphicsDisplay (Xwindow & a, int b);
    void notify(Subject &whoNotified) override;
    SubscriptionType subType() const override;

};

#endif //Q3B_GRAPHICSDISPLAY_H
