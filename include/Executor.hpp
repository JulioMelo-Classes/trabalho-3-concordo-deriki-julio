#ifndef Executor_hpp
#define Executor_hpp
#include "Sistema.hpp"
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

class Executor {
  private:
  Sistema * sistema;
  stringstream ss;
  bool sair = false;

  public:
  Executor(Sistema &sistema);

  void iniciar(istream &in, ostream &out);

  string processarLinha(string linha);
};

#endif //Executor_hpp
