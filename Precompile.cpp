
/*
	Precompiles HTML files. 

	Command line usage: 
		Precompile @PCindex.html
		(This would output a new file called index.html)

	HTML usage:
		Any lines in the html file that start with <!-- PRECOMPILE are used as
		commands for the precompiler.

	Valid Commands:
		<!-- PRECOMPILE Nav -->
			Insert the nav 


*/

#include <iostream>
#include <fstream>
#include <sstream>


void insertNav(std::ofstream *ofile){
	std::string html = "<nav><ul>\n"
		"<a href=\"index.html\"><li class=\"active\">Home</li></a>\n"
		"<a href=\"index.html\"><li>Projects</li></a>\n"
		"<a href=\"index.html\"><li>About Me</li></a>\n"
		"<a href=\"index.html\"><li>Contact</li></a>\n"
		"</ul></nav>\n";
	*ofile << html;
}

void precompile(char* filename){
	std::cout<<"\nPrecompiling "<<filename<<std::endl;

	// Open files

	std::ifstream ifile(filename);
	if(!ifile.is_open()){
		std::cout<<"Error opening input file.\n";
		return;
	}

	std::string oFilename = filename;
	oFilename = oFilename.substr(3); // e.g. "@PCindex.html" -> "index.html"

	std::ofstream ofile(oFilename);
	if(!ofile.is_open()){
		std::cout<<"Error opening output file.\n";
		return;
	}

	// Read lines
	std::string line;
	while(getline(ifile, line)){

		// Print the line to the output file
		ofile << line << std::endl;

		std::stringstream stream(line);
		std::string word;

		// Check for a "<!-- PRECOMPILE" command
		stream >> word;
		if(word.compare("<!--") != 0)
			continue;
		stream >> word;
		if(word.compare("PRECOMPILE") != 0)
			continue;

		// Process command

		stream >> word;
		if(word.compare("Nav") == 0){
			insertNav(&ofile);
		}


	}

	// Close files
	ifile.close();
	ofile.close();
}


int main(int argc, char** argv){
	for(int i = 1; i < argc; i++){
		precompile(argv[i]);
	}
}
