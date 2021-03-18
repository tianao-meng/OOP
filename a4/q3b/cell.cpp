
#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}


bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {

    Info output;
    output.col = c;
    output.row = r;
    output.state = isOn;
    return output;
}

void Cell::setOn() {

    isOn = true;

}

void Cell::toggle() {

    isOn = !isOn;

}

void Cell::setCoords(int r, int c) {
    this->r = r; this->c = c;
}

void Cell::notify(Subject &whoNotified) {

    toggle();
    notifyObservers(SubscriptionType :: All);

}

SubscriptionType Cell::subType() const {
    return SubscriptionType::SwitchOnly;
}

