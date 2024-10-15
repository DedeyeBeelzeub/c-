#pragma once
#include <string>


void register_all_pages();
void append_to_page_registry(const std::string& page_name, const std::string& description, int order);

