#include <math.h>
#include "trigo.hpp"
#include <base/integer.hpp>
#include <base/array.hpp>
#include "devices.hpp"

namespace FlashTrigo {

  namespace Private {
    template<template<int ...A> class List, array_t N, int ...ARGS>
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

  template<s32 SUBDIV>
  class CosTable {
    template<int ...VAL>
    struct Helper {
      double table[SUBDIV] = {
        cos(((double)VAL/(double)SUBDIV)*(PI/2.0))...
      };
    };

  public:
    using Type = typename Private::ListBuilder<Helper, SUBDIV>::Value;
  };


}


namespace MyCos {
  constexpr FlashTrigo::CosTable<1024>::Type test;

  double cos(double val) {
    int index = (int)(fmod(val*2048/PI));
    //cout << val << " :: " << fmod(val, PI) << " :: " << index << endl;

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

  double sin(double val) {
    return cos(val-(PI/2));
  }
}
