#include <sstream>
#include "include/x64asm.h"

int main() {
  std::string call_ins = "callq printf";
  x64asm::Instruction ins( x64asm::NOP );
  std::stringstream ss( call_ins );
  ss >> ins;
  std::cout << ins << "\n";
  return 0;
}
