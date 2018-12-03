/* Ce programme trouve des valeurs de m, k, r, premiers
   pour les k dans KTABLE, pour m < 2^e  */

#include "latmrg/Primes.h"
#include "latticetester/Types.h"
#include <fstream>

using namespace std;
using namespace LatMRG;
using namespace NTL;

namespace
{
  const int KTABLE[] =
  {
    // Les premiers nombres premiers
    3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
    331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
    421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
    509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607,
    613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
    821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
    919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019,
    1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097,
    1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201,
    1213, 1217, 1223
  };
}


//===========================================================================

int main(int argc, char** argv)
{
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <I,Z> <data file>" << endl;
    cout << 1 <<endl;
    return 1;
  }
  string types(argv[1]);
  if (types != "I" && types != "Z") {
    cout << "Usage: " << argv[0] << " <I,Z> <data file>" << endl;
    cout << 2 <<endl;
    return 1;
  }
  string fname(argv[2]);
  fname += ".dat";
  ofstream fout (fname);

  Primes<std::int64_t> primesI;
  Primes<NTL::ZZ> primesZ;

  //   primes.find (3, 39, 3, true, false, fout);

  for (int i = 0; i <= 2; ++i) {
    int k = KTABLE[i];
    // trouver 3 modules m proches de 2^31 pour des MRGs d'ordre k
    if (types == "I") {
      primesI.find (k, 40, 3, true, false, fout);
    } else if (types == "Z") {
      primesZ.find (k, 40, 3, true, false, fout);
    }
  }
  return 0;
}
