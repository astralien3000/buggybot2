#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/archives/json.hpp>

#include <cas/function.hpp>
#include <ik/chain.hpp>
#include <ik_export.hpp>

using namespace std;

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

using lf = ik_export::objects::armature::bones::forearm_left_front::endpoint;
using rf = ik_export::objects::armature::bones::forearm_right_front::endpoint;
using lb = ik_export::objects::armature::bones::forearm_left_back::endpoint;
using rb = ik_export::objects::armature::bones::forearm_right_back::endpoint;

using LFChain = ChainFromIKExport<lf>::ChainBuilder::Chain;
using RFChain = ChainFromIKExport<rf>::ChainBuilder::Chain;
using LBChain = ChainFromIKExport<lb>::ChainBuilder::Chain;
using RBChain = ChainFromIKExport<rb>::ChainBuilder::Chain;

int main(int, char**) {
  Matrix<double, 3,1> Q;
  auto P = LFChain::forward(Q);
  cout << P(0,0) << endl;
  cout << P(1,0) << endl;
  cout << P(2,0) << endl;
  return 0;
}
