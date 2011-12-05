#ifndef BASIC_THREAD_HYZ878KM

#define BASIC_THREAD_HYZ878KM

#include <tuple>
#include <functional>
#include "moost/threads/ThreadTraits.h"
#include "moost/utils.hpp"

namespace moost {
namespace thread {
namespace ti_ {

template <size_t ... indexes>
struct indices_holder {
};

template <size_t index, size_t stop, typename holder>
struct _tuple_indices {};

template <size_t index, size_t stop, size_t ...indexes>
struct _tuple_indices<index, stop, indices_holder<indexes...>>
{
  typedef typename _tuple_indices<index + 1, stop, indices_holder<indexes..., index>>::type type;
};

template <size_t index, size_t ...indexes>
struct _tuple_indices<index, index, indices_holder<indexes...>>
{
  typedef indices_holder<indexes...> type;
};

template <typename ...args_types>
struct tuple_indices
{
  typedef typename _tuple_indices<1, sizeof...(args_types), indices_holder<>>::type type;
};

template <>
struct tuple_indices<>
{
  typedef indices_holder<> type;
};

template <class call_tuple, size_t ...indx>
void __call(call_tuple *t, indices_holder<indx...>)
{
  std::get<0>(*t)(std::get<indx>(*t)...);
}

template <class Call, typename ...ARGS>
thread::ThreadTraits::ReturnType _call(void *value)
{
  typedef typename ti_::tuple_indices<Call, ARGS...>::type indices;
  indices i;
  std::tuple<Call, ARGS...> *t = reinterpret_cast<std::tuple<Call, ARGS...>*>(value);
  __call(t, i);
  return THREAD_RETURN;
}

}

template <class Implem>
class basic_thread
{
 public:
  template <typename Call, typename ...ARGS>
  basic_thread(Call c, ARGS... args)
  {
    std::tuple<Call, ARGS...> *t = new std::tuple<Call, ARGS...>(c, args...);
    _implem.begin(ti_::_call<Call, ARGS...>, t);
  }

  template <typename Call>
  basic_thread(Call c, moost::Error &err)
  {
    std::tuple<Call> *t = new std::tuple<Call>(c);
    _implem.begin(ti_::_call<Call>, t, err);
  }

  inline bool operator==(basic_thread<Implem> const & other)
  {
    return this->_implem == other._implem;
  }

  inline void join()
  {
    _implem.join();
  }
 private:
  Implem _implem;
};

}
typedef thread::basic_thread<thread::ThreadTraits::ThreadImplementation> Thread;
}
#endif /* end of include guard: BASIC_THREAD_HYZ878KM */
