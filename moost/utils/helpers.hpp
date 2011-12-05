#pragma once
#ifndef HELPERS_Y6FBR5RA
#define HELPERS_Y6FBR5RA

namespace mooost {
namespace helpers {
  
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
  typedef typename _tuple_indices<0, sizeof...(args_types), indices_holder<>>::type type;
};

} /* helpers */
} /*moost */

#endif /* end of include guard: HELPERS_Y6FBR5RA */
