#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

void ActionInitialization::Build() const {
    auto runAction = new RunAction();
    SetUserAction(runAction);
    auto eventAction = new EventAction(runAction);
    SetUserAction(eventAction);
    SetUserAction(new PrimaryGeneratorAction());
    SetUserAction(new SteppingAction(eventAction));
}

