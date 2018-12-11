// Demonstrate some features of new C++ standards (>=C++11)

#include <cstddef>  // byte
#include <iostream>
#include <memory>   // shared_ptr, unique_ptr, weak_ptr
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

// auto (C++11)
void auto_func()
{
  auto foo = 73; // like var num = 73 in JS (dynamically recognizes type at compile time)
  cout << "Auto Typing" << endl;
  cout << "-----------" << endl;
  cout << "int size: " << sizeof(int) << endl;
  cout << "Data size: " << sizeof(foo) << endl;
  cout << "Value: " << foo << '\n' << endl;
  return;
}

// std::byte (C++17)
/*
 * Unlike uint8_t, does not allow arithmetic operations performed on it. The data should
 * simply be treated as bits.
 */
void byte_func()
{
  byte bytes[5];
  cout << "Byte" << endl;
  cout << "----" << endl;
  cout << "Byte array contents:" << endl;
  for(int i = 0; i < 5; i++)
    bytes[i] = (byte)(33 + i);
  for(int i = 0; i < 5; i++)
    cout << (char)bytes[i] << " ";
  cout << '\n' << endl;
  return;
}

// constexpr (C++11)
/*
 * Expressions are evaluated at compile time for efficiency. This is similar to how inline
 * code is expanded at compile time for the same reason. Expressions are still evaluated
 * at run time when contained within non-constexpr/inline code.
 */
constexpr int constexpr_sum(int x, int y) { return x + y; }
void constexpr_func()
{
  auto x = 10;
  auto y = 5;
  cout << "Constant Expression (constexpr)" << endl;
  cout << "-------------------------------" << endl;
  cout << "constexpr result (" << x << " + " << y << "): " << constexpr_sum(x, y) << '\n' << endl;
  return;
}

// decltype (C++11)
void decltype_func()
{
  int a;
  decltype(a) b = 17; // b is same type as a
  cout << "Declared Type (decltype)" << endl;
  cout << "------------------------" << endl;
  cout << "decltype value: " << b << '\n' << endl;
  return;
}

// Generic Lambda (C++14)
/*
 * auto:         copy data, not referenced
 * auto&:        mutable lvalue
 * const auto&:  const_iterator
 * const auto&&: rvalue
 */
void glamb_func()
{
  auto x = 5;
  auto y = 0.5;
  auto lamb = [](auto a, auto&& b) { return a * b; };
  auto product = lamb(x, y);
  cout << "Generic Lambda" << endl;
  cout << "--------------" << endl;
  cout << "Lambda result (" << x << " * " << y << "): " << product << '\n' << endl;
  return;
}

// nullptr (C++11)
/*
 * nullptr is the literal that replaced the macro constant NULL considering C++ is strongly typed.
 * nullptr is of type std::nullptr_t.
 */
void nullptr_func()
{
  char *cptr = nullptr;
  int *iptr = nullptr;
  cout << "Null Pointers (nullptr)" << endl;
  cout << "-----------------------" << endl;
  if(NULL == nullptr)
    cout << "NULL == nullptr: true" << endl;
  else
    cout << "NULL == nullptr: false" << endl;
  if(NULL == cptr)
    cout << "NULL == ptr: true" << endl;
  else
    cout << "NULL == ptr: false" << endl;
  cout << "Value of char *ptr: " << static_cast<void*>(cptr) << endl;
  cout << "Value of int *ptr: " << iptr << endl;
  cout << boolalpha;
  // std::is_null_pointer (C++14)
  cout << "Is of type nullptr_t? " << (is_null_pointer<nullptr_t>::value ? true : false) << '\n' << endl;
}

// Regex (C++11)
void regex_func()
{
  //
  return;
}

// Smart Pointers (C++11)
/*
 * Eliminates the requirement to follow up heap allocation with delete.
 * shared_ptr: allows multiple pointers to the same data
 * unique_ptr: replaces auto_ptr, provides exclusive pointer to data, and prevents copying
 * weak_ptr:   provides a weak reference to a shared_ptr
 */
void smartptr_func()
{
  cout << "Smart Pointers" << endl;
  cout << "--------------" << endl;
  unique_ptr<string> uptr(new string("Foo"));
  cout << "unique_ptr contents: " << *uptr << endl;
  string *sptr = uptr.release(); // reassigns pointer and sets uptr to nullptr
  if(uptr == nullptr)
    cout << "uptr is now nullptr after release()." << endl;
  cout << "string pointer value after reassignment/release(): " << *sptr << endl;
  delete sptr; // need to free since we reassigned from unique_ptr
  shared_ptr<string> sptr1 (new string("Bar"));
  cout << "shared_ptr #1 contents: " << *sptr1 << endl;
  cout << "shared_ptr #1 references: " << sptr1.use_count() << endl;
  shared_ptr<string> sptr2 (sptr1);
  cout << "shared_ptr #2 contents: " << *sptr2 << endl;
  cout << "shared_ptr #2 references: " << sptr2.use_count() << endl;
  weak_ptr<string> wptr = sptr1;
  auto sptr_tmp = wptr.lock();
  cout << "weak_ptr contents: " << *sptr_tmp << endl;
  cout << "shared_ptr #1 references after weak_ptr added: " << sptr1.use_count() << '\n' << endl;
  return;
}

// Static Assertion (C++11)
void statassert_func()
{
  //
  return;
}

// Threading (C++11)
/*
 * Based off pthreads, new atomic types
 */
void thread_func()
{
  //
  return;
}

// tuple (C++11)
void tuple_func()
{
  //
  return;
}

// Unicode Literals (C++11)
void unicode_func()
{
  //
  return;
}

// Unordered Map (C++11)
void umap_func()
{
  unordered_map<string, string> umap;
  umap["CA"] = "California";
  umap["FL"] = "Florida";
  umap["NY"] = "New York";
  umap.insert(make_pair("TX", "Texas"));
  umap.insert(make_pair("WA", "Washington"));
  cout << "Unordered Map" << endl;
  cout << "-------------" << endl;
  cout << "Size of umap: " << umap.size() << endl;
  cout << "umap contents: " << endl;
  for (auto item : umap)
    cout << "Key: [" << item.first << "] Value: [" << item.second << "]" << endl;
  //cout << ((umap.find("WA") == umap.end()) ? true : false) << endl;
  cout << "Searching for Florida..." << endl;
  auto search = umap.find("FL");
  if(search != umap.end())
    cout << "Found! Key: [" << search->first << "] Value: [" << search->second << "]\n";
  else
    cout << "Not found!\n";
  return;
}

// Variadic Templates (C++11)
// <T>
void variadic_func()
{
  //
  return;
}

int main()
{
  auto_func();
  byte_func();
  constexpr_func();
  decltype_func();
  glamb_func();
  nullptr_func();
  smartptr_func();
  tuple_func();
  umap_func();

  return 0;
}
