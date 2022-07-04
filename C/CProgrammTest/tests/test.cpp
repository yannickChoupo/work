#include <check.h>
#include "test.h"

int main(void)
{
    int failed;
    Suite *suite;
    SRunner *runner;

    suite = line_suite();
    runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return failed == 0 ? 1 : 0;
}