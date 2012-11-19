#pragma once
#ifndef PROPERTY_84WFI74O
#define PROPERTY_84WFI74O

namespace moost {

template <typename T>
struct dflt_set
{
    inline void set(T& val, T new_val)
    {
        val = new_val;
    }
};

template <typename T>
struct dflt_get
{
    inline T get(T& val)
    {
        return val;
    }
};

template <typename T, class setter = dflt_set<T>, class getter = dflt_get<T>>
class property : private setter, private getter
{
 public:

  property(T value = {}, setter s = setter(), getter g = getter())
      : setter(s), getter(g), val(value)
  {
  }

  void inline operator=(T val) 
  {
      this->set(this->val, val);
  }

  inline operator T()
  {
      return this->get(this->val);
  }
 private:
  T val;
};

}

#endif /* end of include guard: PROPERTY_84WFI74O */
