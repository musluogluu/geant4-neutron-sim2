#include "EventAction.hh"
#include "RunAction.hh"

EventAction::EventAction(RunAction* runAction) : fRunAction(runAction) {}

RunAction* EventAction::GetRunAction() const {
    return fRunAction;
}

