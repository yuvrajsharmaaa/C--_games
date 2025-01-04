#include<iostream>

int main(){

    int age;

    std::cout<<"Enter your age ";
    std::cin>>age;

    if(age>=100){
    std::cout<<"You are an adult";
}
    else if(age >= 18){
        std::cout<<"You are an adult";
    }
    else if( age = 0){
        std::cout<<"no issues";
    }
    else{
        std::cout<<"fuck off";
    }


    return 0;
}