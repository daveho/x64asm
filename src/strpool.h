#ifndef X64ASM_STRPOOL_H
#define X64ASM_STRPOOL_H

#include <cstddef>
#include <string>
#include <unordered_map>

namespace x64asm {

constexpr size_t STRPOOL_CHUNK_SIZE = 8000;

struct StrPoolChunk {
  char mem[STRPOOL_CHUNK_SIZE];
  size_t bytes_allocated;
  StrPoolChunk *next;

  StrPoolChunk( StrPoolChunk *next ) : bytes_allocated( 0 ), next( next ) { }

  size_t get_bytes_available() const { return STRPOOL_CHUNK_SIZE - bytes_allocated; }

private:
  // no value semantics
  StrPoolChunk( const StrPoolChunk & ) = delete;
  StrPoolChunk &operator=( const StrPoolChunk & ) = delete;
};

/** String pool for interning labels.
 * The string pointers in Operand objects, if set,
 * point to strings interned this way. This means
 * that the Operands don't have responsibility for
 * managing the label strings.
 */
class StrPool {
private:
  StrPoolChunk *m_head; // head of list of chunks
  std::unordered_map<std::string, const char *> m_interned;

  // no value semantics
  StrPool( const StrPool & ) = delete;
  StrPool &operator=( const StrPool & ) = delete;

public:
  StrPool();
  ~StrPool();

  const char *intern( const std::string &s );

private:
  const char *alloc( const std::string &s );
};

} // end x64asm namespace

#endif // X64ASM_STRPOOL_H
