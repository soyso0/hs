#pragma once

#include <memory>

#include "hs/member_store.hpp"

namespace hs {

enum class Action {
	Unspecified = 0,

	SignIn,
	SignUp,
	SignOut,
	DeleteAccount,
};

class App {
   public:
	bool hasSignedIn() {
		return current_member != nullptr;
	}

	Action promptInit();

	Action promptMain();

	void promptSignUp();

	void promptSignIn();

	void signOut() {
		std::cout << this->current_member->name.first << "님 안녕히 가세요!" << std::endl;

		this->current_member = nullptr;
	}

	void deleteCurrentAccount();

	hs::MemberStore members;

	//현재 로그인 상태인 멤버.
	std::shared_ptr<hs::Member> current_member;
};

}  // namespace hs
