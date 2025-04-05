#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "QGSP_BERT.hh"

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

int main() {
    auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new QGSP_BERT);
    runManager->SetUserInitialization(new ActionInitialization());
    runManager->Initialize();

    G4UImanager::GetUIpointer()->ApplyCommand("/run/beamOn 10000");

    delete runManager;
    return 0;
}

