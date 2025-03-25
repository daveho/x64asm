#include <cassert>
#include <cstring>
#include "src/strpool.h"

namespace x64asm {

StrPool::StrPool() {
}

StrPool::~StrPool() {
}

const char *StrPool::intern( const std::string &s ) {
  auto i = m_strings.find( s );
  if ( i == m_strings.end() ) {
    auto pair = m_strings.insert( s );
    i = pair.first;
  }
  return i->c_str();
}

}
