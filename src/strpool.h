#ifndef X64ASM_STRPOOL_H
#define X64ASM_STRPOOL_H

#include <cstddef>
#include <string>
#include <unordered_set>

namespace x64asm {

/** String pool for interning labels.
 * The string pointers in Operand objects, if set,
 * point to strings interned this way. This means
 * that the Operands don't have responsibility for
 * managing the label strings.
 */
class StrPool {
private:
  std::unordered_set<std::string> m_strings;

  // no value semantics
  StrPool( const StrPool & ) = delete;
  StrPool &operator=( const StrPool & ) = delete;

public:
  StrPool();
  ~StrPool();

  const char *intern( const std::string &s );
};

} // end x64asm namespace

#endif // X64ASM_STRPOOL_H
