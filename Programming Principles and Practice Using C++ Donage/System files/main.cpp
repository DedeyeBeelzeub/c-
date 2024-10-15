#include "menu.h"
#include "register_all_pages.h"  


int main() {
	register_all_pages();

	while (true) {
		display_main_menu();
		if (!handle_main_menu_choice()) {
			break;
		}
	}

	return 0;
}