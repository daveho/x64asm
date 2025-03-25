#include <sstream>
#include "include/x64asm.h"

int main() {
  std::string call_ins = "callq printf";
  x64asm::Instruction ins( x64asm::NOP );
  std::stringstream ss( call_ins );
  ss >> ins;
  // Using the x64asm::symbolic I/O manipulator should result
  // in seeing "printf" as the operand to callq rather than
  // some meaningless address.
  std::cout << x64asm::symbolic << ins << "\n";
  return 0;
}
