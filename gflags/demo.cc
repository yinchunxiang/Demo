#include <iostream>
#include "foo.h"         // foo.h has a line "DECLARE_int32(start);"
#include "validators.h"  // hypothetical file defining ValidateIsFile()
#include <stdio.h>

using namespace std;
using namespace gflags;


DEFINE_int32(end, 1000, "The last record to read");

DEFINE_string(filename, "my_file.txt", "The file to read");
// Crash if the specified file does not exist.
static bool dummy = RegisterFlagValidator(&FLAGS_filename, &ValidateIsFile);


DECLARE_bool(verbose); // some other file has a DEFINE_bool(verbose, ...)
void MyFunc() {
    cout << "FLAGS_verbose:" << FLAGS_verbose << endl;
    if (FLAGS_verbose) printf("Records %d-%d\n", FLAGS_start, FLAGS_end);
}



int main(int argc, char *argv[])
{
    ParseCommandLineFlags(&argc, &argv, true);
    MyFunc();
    return 0;
}

