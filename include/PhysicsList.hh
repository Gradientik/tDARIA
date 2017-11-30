#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"
#include "G4VPhysicsConstructor.hh"

#include "G4PhotoElectricEffect.hh"
#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
//#include "G4MultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"
/*
#include "G4LowEnergyPhotoElectric.hh"
#include "G4LowEnergyCompton.hh"
#include "G4LowEnergyGammaConversion.hh"
#include "G4LowEnergyRayleigh.hh"
#include "G4LowEnergyIonisation.hh"
#include "G4LowEnergyBremsstrahlung.hh"
*/

class PhysicsList: public G4VUserPhysicsList
{
public:
	PhysicsList();
	~PhysicsList();

protected:
	void ConstructParticle();
	void ConstructProcess();
	void SetCuts();
   
protected:
	void ConstructBosons();
	void ConstructLeptons();
	void ConstructMesons();
	void ConstructBaryons();

protected:
	void ConstructGeneral();
	void ConstructEM();
	void ConstructLowEM();
  protected:
  /*   // Gamma physics
    G4PhotoElectricEffect thePhotoEffect;
    G4ComptonScattering theComptonEffect;
    G4GammaConversion thePairProduction;

   // LowEnergy Gamma physics

    G4LowEnergyPhotoElectric theLowEnPhoto;
    G4LowEnergyCompton theLowEnCompton;
    G4LowEnergyGammaConversion theLowEnPair;
    G4LowEnergyRayleigh theLowEnRayleigh;


    // Electron physics
    G4MultipleScattering theElectronMultipleScattering;
    G4eIonisation theElectronIonisation;
    G4eBremsstrahlung theElectronBremsStrahlung;

    // Low Energy e- physics

    G4LowEnergyIonisation theLowEnIon;
    G4LowEnergyBremsstrahlung theLowEnBremss;

      //Positron physics
    G4MultipleScattering thePositronMultipleScattering;
    G4eIonisation thePositronIonisation;
    G4eBremsstrahlung thePositronBremsStrahlung;
    G4eplusAnnihilation theAnnihilation;*/

};

#endif

 
