#include <stdio.h>
#include <stdlib.h>

#include <android-base/logging.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_sec.h"

#define MODEL_NAME_LEN 5  // e.g. "J701F"
#define BUILD_NAME_LEN 8  // e.g. "DDU3ARB1"
#define CODENAME_LEN   10 // e.g. "j7velte"


static void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    const std::string bootloader = android::base::GetProperty("ro.bootloader", "");
    const std::string bl_model = bootloader.substr(0, MODEL_NAME_LEN);
    const std::string bl_build = bootloader.substr(BUILD_NAME_LEN);
    const std::string device = "j7velte";

    std::string model;
    std::string name;
    std::string description;
    std::string fingerprint;

    model = "SM-" + bl_model;

    for (size_t i = 0; i < TOTAL_VARIANTS; i++) {
        if (model.compare(all_variants[i]->model) == 0) {
            name = all_variants[i]->codename;
        }
    }

    if (name.size() == 0) {
        LOG(ERROR) << "Could not detect codename, forcing j7velte";
        name = "j7veltedx";
    }

    description = name + "-user 7.0 NRD90M " + bl_model + bl_build + " release-keys";
    fingerprint = "Xiaomi/sagit/sagit:7.1.1/NMF26X/V8.2.17.0.NCACNEC:user/release-keys";

    LOG(INFO) << "Found bootloader: %s", bootloader.c_str();
    LOG(INFO) << "Setting ro.product.model: %s", model.c_str();
    LOG(INFO) << "Setting ro.product.device: %s", device.c_str();
    LOG(INFO) << "Setting ro.product.name: %s", name.c_str();
    LOG(INFO) << "Setting ro.build.product: %s", device.c_str();
    LOG(INFO) << "Setting ro.build.description: %s", description.c_str();
    LOG(INFO) << "Setting ro.build.fingerprint: %s", fingerprint.c_str();

    property_override("ro.product.model", model.c_str());
    property_override("ro.product.device", device.c_str());
    property_override("ro.product.name", name.c_str());
    property_override("ro.build.product", device.c_str());
    property_override("ro.build.description", description.c_str());
    property_override("ro.build.fingerprint", fingerprint.c_str());
}
