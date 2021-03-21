#include <iostream>
#include <fstream>

int main(){
    int in;
    while(true){
        std::cin >> in; 
        std::ofstream outfile;

        outfile.open("test.txt", std::ios_base::app);
        outfile << in;
    }

    return 0;
}
