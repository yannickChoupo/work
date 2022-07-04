#include <check.h>
#include "../line/line.h"

START_TEST(sanity_check)
{
    fail_unless(5 == 5);
}
END_TEST

Suite *line_suite(void)
{
    Suite *suite;
    TCase *core;

    suite = suite_create("line");

    core = tcase_create("Core");
    tcase_add_test(core, sanity_check);
    suite_add_tcase(suite, core);

    return (suite);
}
