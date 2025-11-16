// Operations.hpp

#include "constants.hpp"

#ifndef Op_HPP
#define Op_HPP

namespace operations
{
  // op f(x)

  void Bascalc(biogasconstants::variables &in, biogasconstants::bascalcs &Basout);
  void purity(biogasconstants::variables &in, biogasconstants::purcalc &purout);
  void residues(biogasconstants::variables &in, biogasconstants::rescalc &resout);
  void Energy(biogasconstants::variables &in, biogasconstants::Ecalc &Eout);
  void nutrients(biogasconstants::variables &in, biogasconstants::nutcalc &nutout, biogasconstants::rescalc &r);
}

#endif