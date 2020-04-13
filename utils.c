#include "utils.h"


//-------------------------------------------------
const char* yesorno(bool condition) {
  static char yes[] = "YES";
  static char no[]  = "NO";

  return condition ? yes : no;
}

