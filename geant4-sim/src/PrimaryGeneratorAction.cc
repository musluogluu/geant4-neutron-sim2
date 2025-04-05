#include "PrimaryGeneratorAction.hh"
#include "G4Proton.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = new G4ParticleGun(1);
    fParticleGun->SetParticleDefinition(G4Proton::ProtonDefinition());
    fParticleGun->SetParticleEnergy(1*GeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -20*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    fParticleGun->GeneratePrimaryVertex(event);
}

