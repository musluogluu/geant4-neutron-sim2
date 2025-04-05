#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4Track.hh"
#include "G4Neutron.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction(EventAction* eventAction) : fEventAction(eventAction) {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    auto track = step->GetTrack();
    if (track->GetDefinition() == G4Neutron::NeutronDefinition()) {
        auto postVol = step->GetPostStepPoint()->GetTouchableHandle()->GetVolume();
        if (postVol && postVol->GetName() == "World") {
            auto momDir = track->GetMomentumDirection();
            auto angle = std::acos(momDir.z()) * 180. / CLHEP::pi;
            auto energy = track->GetKineticEnergy();
            fEventAction->GetRunAction()->AddNeutron(angle, energy);
            track->SetTrackStatus(fStopAndKill); // Takip etmeye devam etme
        }
    }
}

