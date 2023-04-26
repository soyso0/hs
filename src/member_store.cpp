#include "hs/member_store.hpp"
#include "hs/member.hpp"

namespace hs {

void MemberStore::put(Member member) {
	this->members_[member.id] = member;
}

bool MemberStore::has(std::string id) {
	return this->members_.contains(id);
}

Member MemberStore::get(std::string id) {
	return this->members_[id];
}

}  // namespace hs
