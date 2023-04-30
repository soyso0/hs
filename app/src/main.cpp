#include <iostream>
#include <stdexcept>

#include "hs/app.hpp"
#include "hs/member.hpp"
#include "hs/member_store.hpp"

int main(int argc, char* argv[]) {
	hs::App app;

	while(true) {
		if(!app.hasSignedIn()) {
			hs::Action const action = app.promptInit();
			switch(action) {
			case hs::Action::SignUp: {
				app.promptSignUp();
				break;
			}

			case hs::Action::SignIn: {
				app.promptSignIn();
				break;
			}

			default:
				throw std::logic_error("unexpected user action");
				break;
			}

			continue;
		}

		hs::Action const action = app.promptMain();
		switch(action) {
		case hs::Action::SignOut:
			app.signOut();
			break;

		default:
			break;
		}
	}

	return 0;
}
