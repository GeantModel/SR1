//Вариант 3
//
//Реализовать геометрию со следующими параметрами:
//Расположить в плоскости XZ G4Box G4Torus и G4Sphere по вершинам вписанного в окружность равностороннего треугольника
//в плоскости Y фигуры G4Box и G4Torus должны распологаться на одном уровне, а G4Sphere должна располагаться выше этих фигур

#include "DetGeometry.hh"

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

    return physWorld;
}


