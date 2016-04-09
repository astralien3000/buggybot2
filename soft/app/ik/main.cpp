#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/archives/json.hpp>

#include <cas/function.hpp>
#include <ik_export.hpp>

using namespace std;

int main(int, char**) {
  using test = ik_export::objects::armature::bones::forearm_left_front::endpoint::parent::parent::parent::parent::parent::parent::parent::parent::parent;
  return 0;
}
