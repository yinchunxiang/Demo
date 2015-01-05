#include <stdlib.h>
#include <string>

using namespace std;


bool ValidateIsFile(const char* flag_name, const string& value) {
    return access(value.c_str(), F_OK) != -1;
}
