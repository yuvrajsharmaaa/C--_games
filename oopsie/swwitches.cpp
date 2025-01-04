#include<iostream>

int main(){

    int month;
    std::cout << "Enter a month (1-12): ";
    std::cin >> month;

    switch(month){
        case 1:
        std::cout << "Its JAnuary ";
        break;
        case 2:
        std::cout << "Its February ";
        break;
        case 3:
        std::cout << "Its March ";
        break;
        case 4:
        std::cout << "Its April ";
        break;
        case 5:
        std::cout << "Its May ";
        break;
        case 6:
        std::cout << "Its June ";
        break;
        case 7:
        std::cout << "Its July ";
        break;
        case 8:
        std::cout << "Its August ";
        break;
        case 9:
        std::cout << "Its September ";
        break;
        case 10:
        std::cout << "Its October ";
        break;
        case 11:
        std::cout << "Its November ";
        break;
        case 12:
        std::cout << "Its December ";
        break;
        default:
        std::cout << "Invalid month ";
        break;
     
    }


    return 0;
}