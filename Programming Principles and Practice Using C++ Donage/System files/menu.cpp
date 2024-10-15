#include "menu.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <ranges>

std::unordered_map<std::string, chapter> chapters;
std::vector<std::pair<int, std::string>> chapter_order;

void register_page(const std::string& chapter_key, const std::string& page_key, const std::string& page_name, const menu_function& func, int order) {
	if (!chapters.contains(chapter_key)) {
		chapter new_chapter;
		new_chapter.key = chapter_key;
		new_chapter.name = "Chapter " + chapter_key;
		chapters[chapter_key] = new_chapter;
		chapter_order.emplace_back(std::stoi(chapter_key), chapter_key);
		std::ranges::sort(chapter_order);
	}
	page page;
	page.key = page_key;
	page.name = page_name;
	page.func = func;
	page.order = order;
	auto& [key, name, pages, page_order] = chapters[chapter_key];
	pages[page_key] = page;
	page_order.emplace_back(order, page_key);
	std::ranges::sort(page_order);
}

void display_main_menu() {
	std::cout << "\nMain Menu:\n";
	for (const auto& chapter_key : chapter_order | std::views::values) {
		const auto& [key, name, pages, page_order] = chapters.at(chapter_key);
		std::cout << key << ". " << name << "\n";
	}
	std::cout << "e. Exit\n";
	std::cout << "Enter your choice: ";
}

void display_chapter_menu(const std::string& chapter_key) {
	const auto& [key, name, pages, page_order] = chapters.at(chapter_key);
	std::cout << "\n" << name << ":\n";
	for (const auto& page_key : page_order | std::views::values) {
		const auto& [p_key, p_name, func, order] = pages.at(page_key);
		std::cout << p_key << ". " << p_name << "\n";
	}
	std::cout << "b. Back to Main Menu\n";
	std::cout << "Enter your choice: ";
}

bool handle_main_menu_choice() {
	std::string choice;
	std::cin >> choice;

	if (choice == "e") {
		std::cout << "Exiting...\n";
		return false;
	}
	if (chapters.contains(choice)) {
		const std::string& chapter_key = choice;
		while (true) {
			display_chapter_menu(chapter_key);
			std::string page_choice;
			std::cin >> page_choice;

			if (page_choice == "b") {
				break;
			}
			if (auto& [ch_key, ch_name, ch_pages, ch_page_order] = chapters.at(chapter_key);
				ch_pages.contains(page_choice)) {
				if (auto& [p_key, p_name, func, p_order] = ch_pages.at(page_choice); true) {
					func();
				}
			}
			else {
				std::cout << "Invalid choice. Please try again.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	else {
		std::cout << "Invalid choice. Please try again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return true;
}


