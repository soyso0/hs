#pragma once

#include <map>
#include <memory>
#include <string>

#include "hs/member.hpp"

namespace hs {

class MemberStore {
   public:
	void put(std::shared_ptr<Member> member);

	// 입력한 id가 이미 존재하는 id인지 확인
	bool has(std::string id);

	std::shared_ptr<Member> get(std::string id);

	void remove(std::string id) {
		this->members_.erase(id);
	}

   private:
	std::map<std::string, std::shared_ptr<Member>> members_;
};

}  // namespace hs
