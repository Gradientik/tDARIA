#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include<globals.hh>
#include<G4VUserDetectorConstruction.hh>
#include<G4VSolid.hh>
#include<G4LogicalVolume.hh>
#include<G4VPhysicalVolume.hh>
#include<G4Material.hh>

class World {
protected:
  G4VSolid              *solid;
  G4LogicalVolume       *logic;
  G4VPhysicalVolume     *physic;
  G4Material            *mater;
  double sizex, sizey, sizez;
public:
  World(double size_x, double size_y, double size_z, G4Material *mater_=NULL);
  operator G4LogicalVolume*() {return logic;}
  G4LogicalVolume *getLogic() {return logic;}
  G4VSolid *getSolid() {return solid;}
  G4VPhysicalVolume *getPhysic() {return physic;}
};

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  ~DetectorConstruction();
  
  G4VPhysicalVolume* Construct();
  
protected:
  World *world;
};

#endif
