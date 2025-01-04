//implicit ( automatic)  and explicit( precede value with new data type)

#include <iostream>

int main(){

    //double x = 100;
    //char x = 100;
    //std::cout << (char)100;

    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions*100;

    std::cout << score << "%";





    
    return 0;
}