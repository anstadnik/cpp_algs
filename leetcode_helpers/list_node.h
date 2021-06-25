#include <stdexcept>
#include <sstream>
#include <vector>

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode* next;
  /* ListNode() : val(0), next(nullptr) {} */
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  ListNode(const std::initializer_list<int>& l) {
    if (!l.size())
      throw std::runtime_error("You can't create an empty List, use nullptr");
    ListNode* cur = this;
    bool first = true;
    for (const auto i : l) {
      if (first) {
        cur->val = i;
        first = false;
      } else
        cur = cur->next = new ListNode(i);
    }
  }
  operator std::string() const {
    using std::string_literals::operator""s;
    static bool first = true;
    bool f = first;
    std::stringstream s;
    s << val;
    if (first) first = false;
    if (next) s << " " << static_cast<std::string>(*next);
    if (f) {
      first = true;
      return "{"s + s.str() + "}"s;
    }
    return s.str();
  }
  std::size_t size() const { return 1 + (this->next ? this->next->size() : 0); }
  static ListNode* C(const std::initializer_list<int>& l) {
    return l.size() ? new ListNode(l) : nullptr;
  }

  friend std::ostream& operator<<(std::ostream& os, const ListNode& v);
  friend bool operator==(const ListNode& a, const ListNode& b);
};
std::ostream& operator<<(std::ostream& os, const ListNode& v);
bool operator==(const ListNode& a, const ListNode& b);
