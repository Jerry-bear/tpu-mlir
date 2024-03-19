#include "cpu_layer.h"
#include <unordered_map>
#include <string>

#include "cpu_impl_mycpuop.h"
#include "cpu_impl_topk.h"

namespace bmcpu {


} // end of namespace

extern "C" {
typedef bmcpu::cpu_layer* (*CreateInstanceFunc)();

std::map<std::string, CreateInstanceFunc>& getFactoryMap() {
    static std::map<std::string, CreateInstanceFunc> factoryMap;
    return factoryMap;
}


// extern "C" bmcpu::cpu_layer* createLayerInstance(const char* layerType) {
bmcpu::cpu_layer* createLayerInstance(const char* layerType) {
    printf("call createLayerInstance\n");
    std::string typeStr(layerType);
    auto it = getFactoryMap().find(typeStr);
    if (it != getFactoryMap().end()) {
        return it->second();
    }
    return nullptr;
}

bmcpu::cpu_layer* createTopkLayer() {
    return new bmcpu::cpu_topklayer();
}

void registerFactoryFunctions() {
    getFactoryMap()[std::string("TOPK")] = createTopkLayer;
    // Register other class creators
    // ...
}

__attribute__((constructor))
void onLibraryLoad() {
    registerFactoryFunctions();
}

} // end extern