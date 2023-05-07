#pragma once

#include <memory>

#include "hs/job_info.hpp"
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

	Action promptMainForNormal();

	Action promptMainFormBusiness();

	void promptSignUp();

	void promptSignIn();

	void promptRegisterJobInfo() {
		std::cout << "업무를 입력하세요.";
		std::string title;
		std::cin >> title;

		std::cout << "채용 인원을 입력하세요.";
		std::size_t capacity;
		std::cin >> capacity;

		std::cout << "채용 기간(일)을 입력하세요.";
		std::size_t period;
		std::cin >> period;

		auto deadline = std::chrono::system_clock::now()
		    + std::chrono::hours(period * 24);

		auto job_info = std::make_shared<hs::JobInfo>(
		    std::static_pointer_cast<hs::BusinessMember>(current_member), deadline);

		job_info->id();
		jobs.insert(std::make_pair(job_info->id(), job_info));
	}

	void signOut() {
		std::cout << this->current_member->name.first << "님 안녕히 가세요!" << std::endl;

		this->current_member = nullptr;
	}

	void deleteCurrentAccount();

	hs::MemberStore members;

	std::map<std::size_t, std::shared_ptr<JobInfo>> jobs;

	//현재 로그인 상태인 멤버.
	std::shared_ptr<hs::Member> current_member;
};

}  // namespace hs
