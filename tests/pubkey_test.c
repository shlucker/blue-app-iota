#include "test_common.h"
#include <string.h>
#include "api_tests.h"
#include "api.h"
#include "iota/conversion.h"

void seed_derive_from_bip32(const unsigned int *path, unsigned int pathLength,
                            unsigned char *seed_bytes)
{
    UNUSED(path);
    UNUSED(pathLength);

    chars_to_bytes(mock_ptr_type(char *), seed_bytes, NUM_HASH_TRYTES);
}

void io_send(const void *ptr, unsigned int length, unsigned short sw)
{
    check_expected(ptr);
    check_expected(length);
    check_expected(sw);
}

static void test_valid_index_level_one(void **state)
{
    UNUSED(state);
    static const int security = 1;

    for (unsigned idx = 0; idx <= MAX_ADDRESS_INDEX; idx++) {

        api_initialize();
        EXPECT_API_SET_SEED_OK(PETER_VECTOR.seed, security);
        {
            PUBKEY_INPUT input = {idx};
            PUBKEY_OUTPUT output;
            strncpy(output.address, PETER_VECTOR.addresses[security][idx],
                    NUM_HASH_TRYTES);

            EXPECT_API_DATA_OK(pubkey, 0, input, output);
        }
    }
}

static void test_valid_index_level_two(void **state)
{
    UNUSED(state);
    static const int security = 2;

    for (unsigned idx = 0; idx <= MAX_ADDRESS_INDEX; idx++) {

        api_initialize();
        EXPECT_API_SET_SEED_OK(PETER_VECTOR.seed, security);
        {
            PUBKEY_INPUT input = {idx};
            PUBKEY_OUTPUT output;
            strncpy(output.address, PETER_VECTOR.addresses[security][idx],
                    NUM_HASH_TRYTES);

            EXPECT_API_DATA_OK(pubkey, 0, input, output);
        }
    }
}

static void test_valid_index_level_three(void **state)
{
    UNUSED(state);
    static const int security = 3;

    for (unsigned idx = 0; idx <= MAX_ADDRESS_INDEX; idx++) {

        api_initialize();
        EXPECT_API_SET_SEED_OK(PETER_VECTOR.seed, security);
        {
            PUBKEY_INPUT input = {idx};
            PUBKEY_OUTPUT output;
            strncpy(output.address, PETER_VECTOR.addresses[security][idx],
                    NUM_HASH_TRYTES);

            EXPECT_API_DATA_OK(pubkey, 0, input, output);
        }
    }
}

static void test_change_security(void **state)
{
    UNUSED(state);

    api_initialize();
    EXPECT_API_SET_SEED_OK(PETER_VECTOR.seed, 1);
    EXPECT_API_SET_SEED_OK(PETER_VECTOR.seed, 2);
    {
        PUBKEY_INPUT input = {0};
        PUBKEY_OUTPUT output;
        strncpy(output.address, PETER_VECTOR.addresses[2][0], NUM_HASH_TRYTES);

        EXPECT_API_DATA_OK(pubkey, 0, input, output);
    }
}

static void test_not_set_seed(void **state)
{
    UNUSED(state);

    api_initialize();

    PUBKEY_INPUT input = {0};
    EXPECT_API_EXCEPTION(pubkey, 0, input);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_valid_index_level_one),
        cmocka_unit_test(test_valid_index_level_two),
        cmocka_unit_test(test_valid_index_level_three),
        cmocka_unit_test(test_change_security),
        cmocka_unit_test(test_not_set_seed)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
