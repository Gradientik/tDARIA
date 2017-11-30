#ifndef SENSITIVEDETECTOR
#define SENSITIVEDETECTOR

#include<G4VSensitiveDetector.hh>

class G4Step;
class G4TouchableHistory;


class SensitiveDetector: public G4VSensitiveDetector
{
private:
  static const int nobins = 1000;
  const double max;
  const double min;
  int histogram[nobins];
public:
  SensitiveDetector(G4String name);
  ~SensitiveDetector();
  G4bool ProcessHits(G4Step *step, G4TouchableHistory *hist);
  void EndOfEvent(G4HCofThisEvent*);
};

#endif /* SENSITIVEDETECTOR */
