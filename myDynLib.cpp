#include "myDynLib.h"

const char* fDyn()
{
  return "Hello from Dynamic lib";
}

using namespace std;

const string version()
{
  const string str = to_string(PROJECT_VERSION_MAJOR) + "."
                     + to_string(PROJECT_VERSION_MINOR) + "."
                     + to_string(PROJECT_VERSION_PATCH);
  return str;
}
