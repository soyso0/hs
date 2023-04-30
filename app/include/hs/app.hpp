#pragma once

#include "hs/member_store.hpp"

namespace hs {

enum class Action {
	Unspecified = 0,

	SignIn,
	SignUp,
	SignOut,
};

class App {
   public:
	bool hasSignedIn() {
		return !this->current_member.name.first.empty();
	}

	Action promptInit();

	Action promptMain();

	void promptSignUp();

	void promptSignIn();

	void signOut() {
		std::cout << this->current_member.name.first << "님 안녕히 가세요!" << std::endl;
		this->current_member.name.first.clear();
	}

	hs::MemberStore members;

	hs::Member current_member;
};

}  // namespace hs
