#pragma once

#include <map>
#include <string>

#include "hs/member.hpp"

namespace hs {

class MemberStore {
   public:
	void put(Member member);

	// 입력한 id가 이미 존재하는 id인지 확인
	bool has(std::string id);

	Member get(std::string id);

   private:
	std::map<std::string, Member> members_;
};

}  // namespace hs
