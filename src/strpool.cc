#include <cassert>
#include <cstring>
#include "src/strpool.h"

namespace x64asm {

StrPool::StrPool()
  : m_head( nullptr ) {
}

StrPool::~StrPool() {
  StrPoolChunk *p = m_head;
  while ( p != nullptr ) {
    StrPoolChunk *next = p->next;
    delete p;
    p = next;
  }
}

const char *StrPool::intern( const std::string &s ) {
  assert( s.length() < STRPOOL_CHUNK_SIZE-1 );

  // see if this string has already been interned
  auto i = m_interned.find( s );
  if ( i != m_interned.end() )
    return i->second;

  // allocate space for the string, intern it,
  // and return pointer to allocated string
  return alloc( s );
}

const char *StrPool::alloc( const std::string &s ) {
  if ( m_head == nullptr )
    m_head = new StrPoolChunk( nullptr );

  size_t need = s.size() + 1;
  
  for (;;) {
    if ( need <= m_head->get_bytes_available() ) {
      // can allocate in this chunk
      char *str = m_head->mem + m_head->bytes_allocated;
      m_head->bytes_allocated += need;
      ::strcpy( str, s.c_str() );
      m_interned[ s ] = str;
      return str;
    }
    // not enough room in current chunk, so allocate a new
    // chunk
    m_head = new StrPoolChunk( m_head );
  }
}

} // end namespace x64asm
