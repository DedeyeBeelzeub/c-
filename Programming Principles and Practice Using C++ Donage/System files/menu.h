#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

using menu_function = std::function<void()>;

struct page {
	std::string key;
	std::string name;
	menu_function func;
	int order;
};

struct chapter {
	std::string key;
	std::string name;
	std::unordered_map<std::string, page> pages;
	std::vector<std::pair<int, std::string>> page_order;
};

extern std::unordered_map<std::string, chapter> chapters;
extern std::vector<std::pair<int, std::string>> chapter_order;
void display_main_menu();
bool handle_main_menu_choice();
void register_page(const std::string& chapter_key, const std::string& page_key, const std::string& page_name, const menu_function& func, int order);
