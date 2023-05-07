#pragma once

#include <chrono>
#include <cstddef>
#include <map>
#include <memory>
#include <string>

#include "hs/member.hpp"

namespace hs {

class JobInfo {
   public:
	JobInfo(
	    std::shared_ptr<BusinessMember>       member,
	    std::chrono::system_clock::time_point deadline);

	void close() {
		if(!is_closed()) {
			this->deadline_ = std::chrono::system_clock::now();
		}
	}

	bool is_closed() {
		return std::chrono::system_clock::now() > this->deadline_;
	}

	bool is_full() {
		return this->capacity <= this->applicants_.size();
	}

	bool insert(std::shared_ptr<NormalMember> member) {
		if(is_full()) {
			return false;
		}

		auto [_, ok] = this->applicants_.insert(std::make_pair(member->id, member));
		return ok;
	}

	std::size_t id() {
		return this->id_;
	}

	std::string company() {
		return this->registrant_->company;
	}

	std::string title;
	std::size_t capacity;

   private:
	std::size_t id_;

	std::shared_ptr<BusinessMember>                      registrant_;
	std::map<std::string, std::shared_ptr<NormalMember>> applicants_;

	std::chrono::system_clock::time_point deadline_;
};

}  // namespace hs
