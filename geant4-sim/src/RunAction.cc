#include "RunAction.hh"
#include <cmath>
#include "G4SystemOfUnits.hh"

RunAction::RunAction() : angleBins(180, 0) {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {
    outfile.open("neutron_data.csv");
    outfile << "AngleBin,Count\n";
}

void RunAction::AddNeutron(G4double angle, G4double energy) {
    int bin = static_cast<int>(angle);
    if (bin >= 0 && bin < 180)
        angleBins[bin]++;
    energies.push_back(energy);
}

void RunAction::EndOfRunAction(const G4Run*) {
    for (size_t i = 0; i < angleBins.size(); ++i)
        outfile << i << "," << angleBins[i] << "\n";
    outfile.close();

    std::ofstream energyFile("neutron_energy.csv");
    energyFile << "Energy[MeV]\n";
    for (auto e : energies)
        energyFile << e / MeV << "\n";
    energyFile.close();

    std::ofstream totalFile("neutron_count.txt");
    totalFile << "Total Neutrons: " << energies.size() << "\n";
    totalFile.close();
}

