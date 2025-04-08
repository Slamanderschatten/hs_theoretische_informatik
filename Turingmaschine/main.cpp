#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>


using namespace std;

int main() {
    while(true) {
        std::cout << "enter tm-file" << endl;
        string filename;
        std::cin >> filename;
        if(filename == "c")
            break;
        string filetype = ".tm";
        if (filename.length() < filetype.length() ||
            filename.compare(filename.length() - filetype.length(), filetype.length(), filetype) != 0)
            filename.append(filetype);

        ifstream file(filename);
        if (!file){
            cout << "!! file can not be opened !!" << endl << endl;
            continue;
        }

        string line;
        int lineNumber = 0;

        regex format_regex(R"(^\s*\w+\s+\S+\s+->\s+\w+\s+\S+\s+[LRN](\s+//.*)?\s*$)");

        bool error = false;
        getline(file, line);
        if(line.find("//") != 0)
            error = true;
        line.erase(0,2);
        int numberOfInputs = stoi(line);
        getline(file, line);
        if(line != "start s")
            error = true;
        getline(file, line);
        if(line != "end e")
            error = true;
        if(error) {
            cout << "begin of file have to be : \n//[NUMBER OF_INPUTS]\nstart s\nend e" << endl << endl;
            continue;
        }

        while(getline(file, line)) {
            ++lineNumber;

            string trimmed = line;
            trimmed.erase(0, trimmed.find_first_not_of(" \t"));
            if(trimmed.empty() || trimmed.rfind("//", 0) == 0) {
                continue;
            }

            if(!regex_match(trimmed, format_regex)) {
                cout << "error in line " << lineNumber << ": " << line << endl;
                error = true;
            }
        }
        if(error)
            continue;
        file.close();

        string command = "java -jar tm.jar " + filename + " ";
        cout << "enter tm input" << endl;
        for(int i = 0; i < numberOfInputs; i++) {
            string in;
            cin >> in;
            command.append(in + " ");
        }
        command.append("-step");


        int state = system(command.c_str());


        cout << endl << endl;


    }


    return 0;
}
