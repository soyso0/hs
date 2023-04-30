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

Action App::promptMain() {
	using namespace std;

	cout << "0. 로그아웃" << endl;

	int selected;
	do {
		cin >> selected;

		switch(selected) {
		case 0: return Action::SignOut;

		default:
			cout << "값을 잘못 입력했습니다. " << endl;
			break;
		}
	} while(true);
}

void App::promptSignUp() {
	hs::Member member;

	std::cout << "ID를 입력 하세요.";
	std::cin >> member.id;

	std::cout << "비밀번호를 입력 하세요.";
	std::cin >> member.password;

	std::cout << "이름을 입력 하세요.";
	std::cin >> member.name.first;

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

	Member member = this->members.get(id);
	while(true) {
		std::cout << "비밀번호를 입력 하세요." << std::flush;
		std::cin >> pw;

		if(pw != member.password) {
			std::cout << "잘못된 비밀번호 입니다." << std::endl;
			continue;
		}

		break;
	}

	this->current_member = member;
	std::cout << member.name.first << "님 안녕하세요!" << std::endl;
}

}  // namespace hs
