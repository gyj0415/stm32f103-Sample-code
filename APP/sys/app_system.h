//
// Created by guan on 2025/5/20.
//

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <stdint.h>

typedef struct{
    uint8_t k_state[4];
    uint8_t k_count[4];
}app_key;

app_key *get_key_s();
bool app_sys_ready();

#ifdef __cplusplus
}
#endif

