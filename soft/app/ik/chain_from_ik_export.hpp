#ifndef CHAIN_FROM_IK_EXPORT_HPP
#define CHAIN_FROM_IK_EXPORT_HPP

#include <cas/function.hpp>
#include <ik/chain.hpp>

template<typename Node>
class ChainFromIKExport : protected ChainFromIKExport<typename Node::parent> {
protected:
  using PreviousChainBuilder = typename ChainFromIKExport<typename Node::parent>::ChainBuilder;

  template<bool VARIABLE, DummyType DUMMY = DUMMY_VALUE>
  struct Helper {
    using ChainBuilder = typename PreviousChainBuilder::template BuildConstant<typename Node::matrix>;
  };

  template<DummyType DUMMY>
  struct Helper<true, DUMMY> {
    using ChainBuilder = typename PreviousChainBuilder::template BuildVariable<typename Node::matrix>;
  };

public:
  using ChainBuilder = typename Helper<Node::VARIABLE>::ChainBuilder;
};

template<>
class ChainFromIKExport<void> {
public:
  using ChainBuilder = IK::ChainBuilder<CAS::General<double, double>::Space3D::Identity>;
};

#endif//CHAIN_FROM_IK_EXPORT_HPP
