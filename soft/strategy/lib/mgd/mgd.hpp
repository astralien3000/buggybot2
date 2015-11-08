#include <Eigen/Core>
#include <Eigen/Geometry>

#include <map>
#include <string>
#include <functional>

class MGD {
public:
  using Matrix = Eigen::Matrix<double,4,4>;
  using Function = std::function<Matrix(double)>;
  
private:
  struct MatrixInfo {
    MatrixInfo* parent;
    Matrix mat;
  };

  struct ParamInfo {
    std::string mat;
    Function func;
  };

  std::map<std::string, MatrixInfo> mat_list;
  std::map<std::string, ParamInfo> param_list;

protected:
  void addRootMatrix(const std::string name, const Matrix mat);

  void addConstantMatrix(const std::string name, const std::string parent, const Matrix mat);

  void addVariableMatrix(const std::string name, const std::string parameter_name, const std::string parent, const Function func);

public:
  MGD(void);

  Matrix getFullMatrix(const std::string& name) const;

  void updateParam(const std::string& name, double value);
};
