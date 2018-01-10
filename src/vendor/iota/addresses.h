#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "iota_types.h"

int add_index_to_seed(trit_t trits[], uint32_t index);
int generate_private_key(trit_t *seed_trits, uint32_t index, trint_t *private_key);
int generate_public_address(const trit_t private_key[], trit_t address_out[]);

#endif // ADDRESSES_H
