#include"DetectorConstruction.hh"
#include"SensitiveDetector.hh" 
#include<G4NistManager.hh>
#include<G4Box.hh>
#include<G4Tubs.hh>
#include<G4LogicalVolume.hh>
#include<G4PVPlacement.hh>
#include<G4SDManager.hh>
#include<G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

using namespace std;

#define Mat(x) (G4NistManager::Instance()->FindOrBuildMaterial(x))


World::World(double size_x, double size_y, double size_z,  G4Material *mater_): mater(mater_), sizex(size_x), sizey(size_y), sizez(size_z)
{
	//double size05 = size/2;
	solid = new G4Box("world", sizex/2, sizey/2, sizez/2);
	logic = new G4LogicalVolume( solid, mater, "World", 0, 0, 0);
	physic = new G4PVPlacement(0, G4ThreeVector(), logic, "World",
				   0, false, 0);             
}

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{

  world = new World(30*cm, 30*cm, 30*cm, Mat("G4_Galactic"));
  
  G4Box *solidTgt = new G4Box("solidTgt", 5*cm, 5*cm, 1.2*mm);
  G4LogicalVolume *logiclTgt = new G4LogicalVolume(solidTgt, Mat("G4_Be"), "logiclTgt");
  G4PVPlacement *physilTgt = new G4PVPlacement(0, G4ThreeVector(0,0,-5*cm), logiclTgt,
					       "physilTgt", world->getLogic(), false, 0);
  
  G4Box *solidDet = new G4Box("solidDet", 5*cm, 5*cm, 0.5*mm);
  G4LogicalVolume *logicDet = new G4LogicalVolume(solidDet, Mat("G4_WATER"), "logicDet");
  G4PVPlacement *physiDet = new G4PVPlacement(0, G4ThreeVector(0,0,5*cm), logicDet,
					      "physiDet", world->getLogic(), false, 0);

  
  SensitiveDetector *detector = new SensitiveDetector("1");
  
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  SDman->AddNewDetector(detector);
  logicDet->SetSensitiveDetector(detector);
  
  world->getLogic()->SetVisAttributes (G4VisAttributes::Invisible);
  
  return world->getPhysic();
}
