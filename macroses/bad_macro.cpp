#include "test_runner.h"

#include <ostream>
#include <string>

using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");

    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, "", "");
        ASSERT_EQUAL(output.str(), "\n\n");
    }, "void strings");

    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, "\n", "\n");
        ASSERT_EQUAL(output.str(), "\n\n\n\n");
    }, "endl strings");

    tr.RunTest([] {
        ostringstream output;
        int x = 5;
        PRINT_VALUES(output, x++, ++x);
        ASSERT_EQUAL(output.str(), "5\n7\n");
    }, "increment");

    tr.RunTest([] {
    ostringstream output;
    for(int i = 0; i < 2; ++i)
        PRINT_VALUES(output, i, i + 1);
    ASSERT_EQUAL(output.str(), "0\n1\n1\n2\n");
    }, "for");

    tr.RunTest([] {
    ostringstream output;
    if(true)
        PRINT_VALUES(output, 1, "red");
    else
        PRINT_VALUES(output, 10, "red");
    ASSERT_EQUAL(output.str(), "1\nred\n");
    }, "if");

    return 0;
}
