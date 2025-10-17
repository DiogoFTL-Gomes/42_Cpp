#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]){

	if (argc != 4){
		std::cerr << "Program needs <file> <string_to_replace> <new_string>" << std::endl;
		return (1);
	}

	std::string	sourcefile = argv[1];
	std::string	s_target = argv[2];
	std::string	s_new = argv[3];
	if (sourcefile.length() == 0 || s_target.length() == 0){
		std::cerr << "Cannot have empty strings" << std::endl;
		return (1);
	}

	//antigo open(fd) :)
	std::ifstream	input_file(sourcefile);
	if (!input_file.is_open()){
		std::cerr << "Could not open input file " << sourcefile << std::endl;
		return (1);
	}
	input_file.close();

	std::string	content;
	std::getline(input_file, content, '\0');//delimitador para evitar que pare em \n

	size_t	pos = content.find(s_target);//position where a s_target is found in content starting at 0 by default
	while (pos != std::string::npos){//npos is value that is usualy returned when a string fails?
		content = content.substr(0, pos) + s_new + content.substr(pos + s_target.length());//substr(a,b) returns string from a to b.
		pos = content.find(s_target, pos + s_new.length());
	}

	std::ofstream	output_file(sourcefile + ".replace");
	if (!output_file.is_open()){
		std::cerr << "Could not open output file " << sourcefile << ".replace" << std::endl;
		return (1);
	}

	output_file << content;
	output_file.close();
	return 0;
}
