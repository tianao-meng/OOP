

#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

Subject::~Subject() = default;

void Subject::attach(Observer *o) {

    observers.push_back(o);

}

void Subject::notifyObservers(SubscriptionType t) {

    std::vector<Observer*> :: iterator it;
    if (t == SubscriptionType::All){

        for (it = observers.begin(); it != observers.end(); it++){

            if ((*it) -> subType() == t){
                (*it) -> notify(*this);
            } else {
                continue;
            }

        }

    } else {
        for (it = observers.begin(); it != observers.end(); it++){

            //observers[0] ->notify(*this);

            (*it) -> notify(*this);


        }

    }



}

