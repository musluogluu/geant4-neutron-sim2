#ifndef RUN_ACTION_HH
#define RUN_ACTION_HH

#include "G4UserRunAction.hh"
#include <fstream>
#include <vector>

class RunAction : public G4UserRunAction {
public:
    RunAction();
    ~RunAction() override;

    void BeginOfRunAction(const G4Run*) override;
    void EndOfRunAction(const G4Run*) override;

    void AddNeutron(G4double angle, G4double energy);

private:
    std::ofstream outfile;
    std::vector<int> angleBins;
    std::vector<G4double> energies;
};

#endif

