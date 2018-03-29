#ifndef INIT_SEC_H
#define INIT_SEC_H

#include <string.h>

#define TOTAL_VARIANTS 3 //Total number of variants

typedef struct {
    std::string model;
    std::string codename;
} variant;

static const variant J701F_model = {
    .model = "SM-J701F",
    .codename = "j7veltedx"
};

static const variant J701M_model = {
    .model = "SM-J701M",
    .codename = "j7veltedd"
};

static const variant J701MT_model = {
    .model = "SM-J701MT",
    .codename = "j7veltekk"
};

static const variant *all_variants[TOTAL_VARIANTS] = {
    &J701F_model,
    &J701M_model,
    &J701MT_model,
};

#endif // INIT_SEC_H
