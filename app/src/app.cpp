#include <iostream>
#include <string>

#include "hs/app.hpp"

namespace hs {

Action App::promptInit() {
	using namespace std;

	cout << "0. 회원가입" << endl;
	cout << "1. 로그인" << endl;

	int selected;
	do {
		cin >> selected;

		switch(selected) {
		case 0: return Action::SignUp;
		case 1: return Action::SignIn;

		default:
			cout << "값을 잘못 입력했습니다. " << endl;
			break;
		}
	} while(true);
}

/*
Action App::promptMain() {
	using namespace std;
	Member::Kind kind = Member::Kind::Unspecified;
	cout << "0. 로그아웃" << endl;

	cout << "9. 회원탈퇴" << endl;

	int selected;//
	do {
		cin >> selected;

		switch(selected) {
		case 0: return Action::SignOut;
		case 9: return Action::DeleteAccount;

		default:
			cout << "값을 잘못 입력했습니다. " << endl;
			break;
		}
	} while(true);
}
*/

Action promptMainForNormal() {
	using namespace std;
	cout << "0. 로그아웃" << endl;
	cout << "1. 채용 정보 조회" << endl;
	cout << "9. 회원탈퇴" << endl;

	int selected;
	do {
		cin >> selected;

		switch(selected) {
		case 0: return Action::SignOut;
		case 9: return Action::DeleteAccount;

		default:
			cout << "값을 잘못 입력했습니다. " << endl;
			break;
		}
	} while(true);
}

Action promptMainFormBusiness() {
	using namespace std;
	cout << "0. 로그아웃" << endl;
	cout << "1. 채용 정보 등록" << endl;
	cout << "9. 회원탈퇴" << endl;
}

void App::promptSignUp() {
	Member::Kind kind = Member::Kind::Unspecified;
	std::string  yn;
	do {
		std::cout << "일반 회원 입니까? [y/n]: ";
		std::cin >> yn;

		if(yn == "y") {
			kind = Member::Kind::Normal;
		} else if(yn == "n") {
			kind = Member::Kind::Business;
		} else {
			std::cout << "\"y\" 또는 \"n\"을 입력해주세요." << std::endl;
		}
	} while(kind == Member::Kind::Unspecified);

	std::shared_ptr<Member> member;
	switch(kind) {
	case Member::Kind::Normal: {
		member = std::make_shared<hs::NormalMember>();
		break;
	}

	case Member::Kind::Business: {
		member = std::make_shared<hs::BusinessMember>();
		break;
	}

	default: {
		throw std::logic_error("invalid member kind");
	}
	}

	std::cout << "ID를 입력 하세요.";
	std::cin >> member->id;

	if(member->id.empty()) {
		return;
	}

	std::cout << "비밀번호를 입력 하세요.";
	std::cin >> member->password;

	std::cout << "이름을 입력 하세요.";
	std::cin >> member->name.first;

	if(kind == Member::Kind::Business) {
		std::shared_ptr<BusinessMember> bm = std::dynamic_pointer_cast<BusinessMember>(member);

		std::cout << "회사명을 입력 하세요.";
		std::cin >> bm->company;
	}

	this->members.put(member);
}

void App::promptSignIn() {
	std::string id;
	std::string pw;

	while(true) {
		std::cout << "ID를 입력 하세요." << std::flush;
		std::cin >> id;

		if(!this->members.has(id)) {
			std::cout << "존재하지 않는 ID 입니다." << std::endl;
			continue;
		}

		break;
	}

	auto member = this->members.get(id);
	while(true) {
		std::cout << "비밀번호를 입력 하세요." << std::flush;
		std::cin >> pw;

		if(pw != member->password) {
			std::cout << "잘못된 비밀번호 입니다." << std::endl;
			continue;
		}

		break;
	}

	this->current_member = member;
	std::cout << member->name.first << "(" << hs::to_string(member->kind()) << ")"
	          << " 님 안녕하세요!" << std::endl;
}

void promptRegisterJobInfo() {
}

void App::deleteCurrentAccount() {
	this->members.remove(this->current_member->id);
	this->signOut();
}

}  // namespace hs
