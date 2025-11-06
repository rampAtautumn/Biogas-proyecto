// Operations.hpp

#include "constants.hpp"

#ifndef Op_HPP
#define Op_HPP

namespace op
{
  // op f(x)

  void Bascalc(bc::variables &in, bc::bascalcs &Basout);
  void purity(bc::variables &in, bc::purcalc &purout);
  void residues(bc::variables &in, bc::rescalc &resout);
  void Energy(bc::variables &in, bc::Ecalc &Eout);
  void nutrients(bc::variables &in, bc::nutcalc &nutout, bc::rescalc &r);
}

#endif