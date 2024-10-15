#include "register_all_pages.h"
#include "chapter_1.h"
#include "chapter_2.h"
#include "chapter_3.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"


void register_all_pages() {
	// Chapter 1
	register_page("1", "1", "Chapter 1 Exercises 1", chapter_1_exercises_1, 1);

	// Chapter 2
	register_page("2", "1", "Chapter 2 Exercises Practice 1", chapter_2_exercises_1, 1);

	// Chapter 3
	register_page("3", "1", "Chapter 3 Exercises 1", chapter_3_exercises_1, 1);

}

void append_to_page_registry(const std::string& page_name, const std::string& description, int order) {
	if (std::ifstream registry_file_in("PageRegistry.cpp"); registry_file_in.is_open()) {
		if (std::ofstream temp_file("temp.cpp"); temp_file.is_open()) {
			std::string line;
			bool in_register_function = false;
			bool include_inserted = false;
			while (getline(registry_file_in, line)) {
				temp_file << line << "\n";
				if (!include_inserted && line.find("#include") != std::string::npos) {
					temp_file << "#include \"" << page_name << ".h\"\n";
					include_inserted = true;
				}
				if (line.find("void register_all_pages()") != std::string::npos) {
					in_register_function = true;
				}
				if (auto const closing_brace_pos = line.find('}'); in_register_function && closing_brace_pos != std::string::npos) {
					temp_file << "    register_page(\"" << order << "\", \"" << description
						<< "\", " << page_name << ", " << order << ");\n";
					in_register_function = false;
				}
			}
			std::cout << "Page successfully registered in PageRegistry.cpp, and #include added.\n";
		}
		else {
			std::cerr << "Failed to open temp.cpp for writing.\n";
		}
	}
	else {
		std::cerr << "Failed to open PageRegistry.cpp for reading.\n";
	}
}