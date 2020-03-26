#include "WarmupPhase.h"
#include <observatory/Benchmark.h>

#include <utility>

namespace Observatory {

WarmupPhase::WarmupPhase(Benchmark &benchmark, Operation &operation, uint32_t operationCount) :
        BenchmarkPhase(benchmark),
        operation(operation),
        operationCount(operationCount) {}

const char* WarmupPhase::getName() {
    return "WarmupPhase";
}

Status WarmupPhase::execute() {
    if(!getBenchmark().synchronize()) {
        return Status::SYNC_ERROR;
    }

    return operation.warmUp(operationCount);
}

}