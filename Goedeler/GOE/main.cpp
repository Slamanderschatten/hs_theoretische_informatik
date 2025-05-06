#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

int main() {

    using namespace std;
    using namespace boost::multiprecision;

    while(true) {
        std::cout << "enter tm-file" << endl;
        string filename;
        std::cin >> filename;
        if(filename == "c")
            break;

        ifstream file(filename);
        if (!file){
            cout << "!! file can not be opened !!" << endl << endl;
            continue;
        }

        cpp_int goedel = 0;

        char cVal = 0;
        while(file.get(cVal)) {
            goedel = goedel << 8;
            goedel += cVal;
        }

        cout << goedel << endl << endl;


    }




    return 0;
}
