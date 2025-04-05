#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

G4VPhysicalVolume* DetectorConstruction::Construct() {
    auto nist = G4NistManager::Instance();
    auto worldMat = nist->FindOrBuildMaterial("G4_AIR");
    auto targetMat = nist->FindOrBuildMaterial("G4_W");

    auto solidWorld = new G4Box("World", 1*m, 1*m, 1*m);
    auto logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
    auto physWorld = new G4PVPlacement(nullptr, {}, logicWorld, "World", nullptr, false, 0);

    auto solidTarget = new G4Tubs("Target", 0., 7.5*cm, 15*cm, 0., 360.*deg);
    auto logicTarget = new G4LogicalVolume(solidTarget, targetMat, "Target");
    new G4PVPlacement(nullptr, {}, logicTarget, "Target", logicWorld, false, 0);

    return physWorld;
}

