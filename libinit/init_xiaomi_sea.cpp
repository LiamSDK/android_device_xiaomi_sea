/*
 * Copyright (C) 2021-2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

#define FINGERPRINT_SEA "Redmi/sea_global/sea:14/SP1A.210812.016/V816.0.5.0.UHZMIXM:user/release-keys"
#define FINGERPRINT_OCEAN "Redmi/ocean_global/ocean:14/SP1A.210812.016/V816.0.5.0.UHZMIXM:user/release-keys"

static const variant_info_t sea_info = {
    .hwc_value = "",
    .sku_value = "ksrn",
    .brand = "Redmi",
    .device = "sea",
    .marketname = "Redmi Note 12S",
    .model = "23030RAC7Y",
    .mod_device = "sea_global",
    .build_fingerprint = FINGERPRINT_SEA,
};

static const variant_info_t ocean_info = {
    .hwc_value = "",
    .sku_value = "k7sr",
    .brand = "Redmi",
    .device = "ocean",
    .marketname = "Redmi Note 12S",
    .model = "2303CRA44A",
    .mod_device = "ocean_global",
    .build_fingerprint = FINGERPRINT_OCEAN,
};

static const variant_info_t ocean_la_info = {
    .hwc_value = "",
    .sku_value = "ksrl",
    .brand = "Redmi",
    .device = "ocean",
    .marketname = "Redmi Note 12S",
    .model = "2303ERA42L",
    .mod_device = "ocean_global",
    .build_fingerprint = FINGERPRINT_OCEAN,
};

static const std::vector<variant_info_t> variants = {
    sea_info,
    ocean_info,
    ocean_la_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.product.first_api_level", "32");
}
