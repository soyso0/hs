#include <chrono>
#include <cstddef>
#include <memory>

#include "hs/job_info.hpp"

namespace hs {

namespace {

std::size_t job_info_id = 0;

}

JobInfo::JobInfo(
    std::shared_ptr<BusinessMember>       member,
    std::chrono::system_clock::time_point deadline)
    : id_(job_info_id++)
    , registrant_(member)
    , deadline_(deadline) { }

}  // namespace hs
