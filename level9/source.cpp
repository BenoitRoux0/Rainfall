#include <stddef.h>
#include <string.h>

class N {
  public:
  N(int param_1) {
    *(int *)(this + 0x68) = param_1;
    return;
  }

  void setAnnotation(char *param_1) {
    size_t __n;
    
    __n = strlen(param_1);
    memcpy(this + 4,param_1,__n);
    return;
  }

};

int main(int param_1,char **param_2) {
  N *this_01;
  N *this_00;
  
  if (param_1 < 2) {
    _exit(1);
  }
  this_01 = new N(5);
  this_00 = new N(6);
  this_01->setAnnotation(param_2[1]);
  (**this_00)(this_00,this_01);
  return;
}