#include "list_node.h"

std::ostream& operator<<(std::ostream& os, const ListNode& v) {
  return os << static_cast<std::string>(v);
}

bool operator==(const ListNode& a, const ListNode& b) {
  if (!a.next && !b.next)
    return a.val == b.val;
  if (!a.next || !b.next)
    return false;
  return a.val == b.val && *a.next == *b.next;
}
