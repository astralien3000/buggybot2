#include "mgd.hpp"

void MGD::addRootMatrix(const std::string name, const Matrix mat) {
  MatrixInfo& elem = mat_list[name];
  elem.mat = mat;
  elem.parent = 0;
}

void MGD::addConstantMatrix(const std::string name, const std::string parent, const Matrix mat) {
  MatrixInfo& elem = mat_list[name];
  elem.mat = mat;
  elem.parent = &mat_list.at(parent);
}

void MGD::addVariableMatrix(const std::string name, const std::string parameter_name, const std::string parent, const Function func) {
  MatrixInfo& elem = mat_list[name];
  ParamInfo& param = param_list[parameter_name];
  elem.mat = func(0);
  elem.parent = &mat_list.at(parent);
  param.mat = name;
  param.func = func;
}

MGD::MGD(void) {}

MGD::Matrix MGD::getFullMatrix(const std::string& name) const {
  const MatrixInfo* elem = &mat_list.at(name);
  Matrix ret = elem->mat;
  while(elem->parent != 0) {
    elem = elem->parent;
    ret = elem->mat * ret;
  }
  return ret;
}

void MGD::updateParam(const std::string& name, double value) {
  ParamInfo& param = param_list[name];
  MatrixInfo& elem = mat_list[param.mat];
  elem.mat = param.func(value);
}

std::vector<std::string>  MGD::getMatrixList(void) {
  std::vector<std::string> res;
  
  for (decltype(mat_list)::iterator it=mat_list.begin(); it!=mat_list.end(); ++it)
    res.push_back(it->first);
  
  return res;
}
