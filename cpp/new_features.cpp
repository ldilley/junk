// Demonstrate some features of new C++ standards (>=C++11)

#include <atomic>   // std::atomic_int
#include <codecvt>
#include <cstddef>  // std::byte
#include <iostream>
#include <locale>
#include <memory>   // std::shared_ptr, std::unique_ptr, std::weak_ptr
#include <mutex>
#include <regex>
#include <string>
#include <thread>
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
 * Unlike uint8_t, does not allow arithmetic operations performed on it.
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
  string example = "This is some text.";
  string pattern = "(^This)(.*)$";
  regex rx(pattern);
  cout << "Regex" << endl;
  cout << "-----" << endl;
  cout << "Example text: " << example << endl;
  cout << "Pattern: " << pattern << endl;
  if(regex_match(example, rx))
    cout << "Match found!" << endl;
  else
    cout << "No match found!" << endl;
  cout << endl;
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

// Threading (C++11)
/*
 * Based off pthreads, new atomic types
 */
// thread_print() allows for race conditions
void thread_print()
{
  for(int i = 0; i < 100; i++)
    cout << i << " ";
  cout << '\n' << endl;
  return;
}

// thread_print_safe() is thread safe due to mutex
void thread_print_safe(mutex &mtx)
{
  /*
   * std::scoped_lock lock(mtx); is recommended in C++17 or std::lock_guard lock(mtx);
   * in C++11.
   */
  mtx.lock();
  for(int i = 0; i < 100; i++)
    cout << i << " ";
  cout << '\n' << endl;
  mtx.unlock();
  return;
}

// atomic_increment() is thread safe due to atomic variable
void atomic_increment(atomic_int &ai)
{
  ai++;   // this increment occurs atomically (++ operator is overloaded for atomic type)
  return;
}

void thread_func()
{
  const int thread_count = 10;
  thread threads[thread_count];
  mutex mtx;
  atomic_int ai = 0;
  cout << "Threads" << endl;
  cout << "-------" << endl;

  // Allows for race conditions
  cout << "Thread unsafe loop counter: " << endl;
  for(int i = 0; i < thread_count; i++)
    threads[i] = thread(thread_print);
  for(int i = 0; i < thread_count; i++)
    threads[i].join();

  // Thread safe due to mutex
  cout << "Thread safe (mutex) loop counter: " << endl;
  for(int i = 0; i < thread_count; i++)
    threads[i] = thread(thread_print_safe, ref(mtx));
  for(int i = 0; i < thread_count; i++)
    threads[i].join();

  // Thread safe due to atomic variable
  cout << "Thread safe (atomic) loop counter: " << endl;
  for(int i = 0; i < thread_count; i++)
    threads[i] = thread(atomic_increment, ref(ai));
  for(int i = 0; i < thread_count; i++)
    threads[i].join();
  cout << "Atomic int value after " << thread_count << " iterations: " << ai << endl;

  cout << endl;
  return;
}

// tuple (C++11)
/*
 * Allows mixing of types. Can be used with std::tie (C++11) to return multiple values and
 * std::ignore (C++11) to omit a positional value. Use std::get (C++11) to access values.
 * Tuples start at index zero (of course!)
 */
void tuple_func()
{
  string fruit = "";
  int rda = 0;
  // Vitamin C content (fruit, % RDA, mg)
  tuple <string, int, float> tup;
  tup = make_tuple("apple", 14, 8.4);
  // Populate values and ignore mg
  tie(fruit, rda, ignore) = tup;
  cout << "Tuple" << endl;
  cout << "-----" << endl;
  cout << "Tuple contains: " << fruit << " with " << rda << "% RDA of vitamin C." << endl;
  get<0>(tup) = "brick";
  get<1>(tup) = 0;
  cout << "Tuple now contains: " << get<0>(tup) << " with " << get<1>(tup) << "% RDA of vitamin C.\n" << endl;
  return;
}

// Unicode Literals (C++11)
void unicode_func()
{
  const char a = '\x7e';             // tilde (ASCII)
  const char *b = u8"\u03A9";        // omega (UTF-8)
  const wchar_t *c = L"\x03A9";      // omega (wide character)
  const char16_t *d = u"\u03A9";     // omega (UTF-16)
  const char32_t *e = U"\U000003A9"; // omega (UTF-32)
  cout << "Unicode" << endl;
  cout << "-------" << endl;
  cout << "char: " << a << endl;
  cout << "u8: " << b << endl;
  wstring_convert<codecvt_utf8<wchar_t>> wide_to_u8_conv;
  cout << "wchar_t: " << wide_to_u8_conv.to_bytes(c) << endl;
  wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> u16_to_u8_conv;
  cout << "char16_t: " << u16_to_u8_conv.to_bytes(d) << endl;
  //wstring_convert<codecvt<char32_t, char, mbstate_t>> u32_to_u8_conv;
  //cout << u32_to_u8_conv.to_bytes(e) << endl;
  cout << endl;
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
  cout << endl;
  return;
}

// Variadic Templates (C++11)
/*
 * Accepts a variable number of args.
 */
template<typename T>
T sum(T v)
{
//#if defined(__GNUC__) || defined(__GNUG__)
//  std::cout << __PRETTY_FUNCTION__ << endl; // show the args
//#endif
  return v;
}
template<typename T, typename... Args>
T sum(T arg1, Args... args) {
//#if defined(__GNUC__) || defined(__GNUG__)
//  std::cout << __PRETTY_FUNCTION__ << endl; // show the args
//#endif
  //const int size = sizeof...(Args);
  constexpr auto size = (sizeof(Args) + ...); // C++17
  static_assert(size > 0, "There are no args!");
  //for(auto value : {args...})
  //{
  //  sum += value;
  //}
  return arg1 + sum(args...);
}

void variadic_func()
{
  cout << "Variadic Template" << endl;
  cout << "-----------------" << endl;
  cout << "Sum of 1 + 3 + 5 = " << sum(1, 3, 5) << endl;
  cout << "Sum of 10 + 20 + 30 + 40 + 50 = " << sum(10, 20, 30, 40, 50) << '\n' << endl;
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
  regex_func();
  smartptr_func();
  thread_func();
  tuple_func();
  umap_func();
  unicode_func();
  variadic_func();

  return 0;
}
