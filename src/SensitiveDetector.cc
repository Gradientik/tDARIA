#include<G4Step.hh>
#include <G4SystemOfUnits.hh>
#include<fstream>
#include<iostream>
#include"SensitiveDetector.hh"

using namespace std;

SensitiveDetector::SensitiveDetector(G4String name): G4VSensitiveDetector(name), max(10*MeV), min(0 *MeV)
{
  for(int i = 0; i<nobins; i++)
    histogram[i] = 0;
}

G4bool SensitiveDetector::ProcessHits(G4Step *step, G4TouchableHistory *hist)
{
  double energy = step->GetTrack()->GetDynamicParticle()->GetTotalEnergy();
  double bin_width = (max - min) / nobins;
  int index = int(floor((energy-min)/bin_width));
  if(index >= 0 && index < nobins)
    histogram[index]++;

  step->GetTrack()->SetTrackStatus(fStopAndKill);
  return true;
}


void SensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
}

SensitiveDetector::~SensitiveDetector()
{
  ofstream file("outSPECT.dat");
  
  double bin_width = (max - min) / nobins;
  for(int i = 0; i<nobins; i++)
  {
    double energy = i*bin_width + min;
    file << setw(15) << energy/MeV << " "
	 << setw(15) << histogram[i] << endl;
  }
}
