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
				try {
					app.promptSignUp();
				} catch(std::exception const& e) {
					// Exception handling.
				}

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

		hs::Action action;
		switch(app.current_member->kind()) {
		case hs::Member::Kind::Normal: {
			action = app.promptMainForNormal();
			break;
		}

		case hs::Member::Kind::Business: {
			action = app.promptMainFormBusiness();
			break;
		}

		default: throw std::logic_error("invalid member kind");
		}

		switch(action) {
		case hs::Action::SignOut: {
			app.signOut();
			break;
		}

		case hs::Action::DeleteAccount: {
			app.deleteCurrentAccount();
		}

		case hs::Action::REgistr...: {
			app.promptRegisterJobInfo();
		}

		default:
			break;
		}
	}

	return 0;
}
