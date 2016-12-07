#include <math.h>
#include "trigo.hpp"
#include <base/integer.hpp>
#include <base/array.hpp>

static constexpr double PI = 3.1415;

namespace FlashTrigo {

  namespace Private {
    template<template<int ...A> class List, int N, int ...ARGS>
    struct ListBuilder {
      using Value = typename ListBuilder<List, N-2, N-2, N-1, ARGS...>::Value;
    };

    template<template<int ...A> class List, int ...ARGS>
    struct ListBuilder<List, 1, ARGS...> {
      using Value = typename ListBuilder<List, 0, 1, ARGS...>::Value;
    };

    template<template<int ...A> class List, int ...ARGS>
    struct ListBuilder<List, 0, ARGS...> {
      using Value = List<ARGS...>;
    };
  }

  template<int SUBDIV>
  class CosTable {
    template<int ...VAL>
    struct Helper {
      real table[SUBDIV] = {
        __builtin_cosf(((float)VAL/(float)SUBDIV)*(PI/2.0))...
      };
    };

  public:
    using Type = typename Private::ListBuilder<Helper, SUBDIV>::Value;
  };


}


namespace MyCos {
  constexpr FlashTrigo::CosTable<1024>::Type test;

  real cos(real val) {
    int index = (int)(val*2048/PI);

    if(0 <= index) {
      if(index < 1024) {
	return test.table[index];
      }
      else {
	return -test.table[2048-index-1];
      }
    }
    else {
      if(index > -1024) {
	return test.table[-index];
      }
      else {
	return -test.table[2048+index-1];
      }
    }
    
    return -1;
  }

  real sin(real val) {
    return cos(val-(PI/2));
  }
}
