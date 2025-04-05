#ifndef EVENT_ACTION_HH
#define EVENT_ACTION_HH

#include "G4UserEventAction.hh"
class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAction);
    RunAction* GetRunAction() const;

private:
    RunAction* fRunAction;
};

#endif

