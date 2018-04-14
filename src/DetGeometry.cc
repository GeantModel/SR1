//Вариант 3
//
//Реализовать геометрию со следующими параметрами:
//Расположить в плоскости XZ G4Box G4Torus и G4Sphere по вершинам вписанного в окружность равностороннего треугольника
//в плоскости Y фигуры G4Box и G4Torus должны распологаться на одном уровне, а G4Sphere должна располагаться выше этих фигур

#include "DetGeometry.hh"
#include "G4Torus.hh"
#include "G4Sphere.hh"
#include <G4RunManager.hh>
#include <G4GeometryManager.hh>
#include <G4VisAttributes.hh>


DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4Material* b_material = nist->FindOrBuildMaterial("G4_Fe");
    G4Material* t_material = nist->FindOrBuildMaterial("G4_ALANINE");
    G4Material* s_material = nist->FindOrBuildMaterial("G4_ANTHRACENE");

    auto box = new G4Box("box", 100, 100, 100);
    auto box_log = new G4LogicalVolume(box, G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "logicWorld");
    box_log->SetVisAttributes(G4Colour::Green());
    auto box_PV = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), box_log, "box_log", logicWorld, false, 0);

    auto torus = new G4Torus("torus", 40, 60, 200, 0, 90);
    auto torus_log = new G4LogicalVolume(torus, G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "logicWorld");
    torus_log->SetVisAttributes(G4Colour::Green());
    auto torus_PV = new G4PVPlacement(0, G4ThreeVector(5*m, 0, 0), torus_log, "torus_log", logicWorld, false, 0);

    auto sphere = new G4Sphere("sphere", 10, 100, 0, 2*3.14, 0, 3.14);
    auto shpere_log = new G4LogicalVolume(sphere, G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "logicWorld");
    shpere_log->SetVisAttributes(G4Colour::Green());
    auto sphere_PV = new G4PVPlacement(0, G4ThreeVector(2.5*m, 1*m, 4.3*m), shpere_log, "torus_log", logicWorld, false, 0);

    return physWorld;
}


