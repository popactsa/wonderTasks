#include <iostream>
#include <vector>
#include <string> 
#include <windows.h> 

int guess_counter = 0;

void show(std::string word, std::vector<bool>revealed){
    int n = word.size();
    char blank = '-';
    for (int i = 0; i < n; ++i){
        if(revealed[i] == true){
            std::cout<<word[i]<<' ';
        }
        else{
            std::cout<<blank<<' ';
        }
    }
    std::cout<<std::endl<<std::endl;
}

bool finder_letter(std::string word, char let, std::vector<bool> &revealed){
    int n = word.size();
    bool status = false;
    for (int i = 0; i < n; ++i){
        if (word[i] == let & revealed[i] == false){
            revealed[i] = 1;
            status = true;
            guess_counter++;
        }
        else if(word[i] == let & revealed[i] == true){
            status = false;
            break;
        }
    }
    return status;
}

int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string word_ = "молоко";
    std::cout<<word_<<std::endl;
    // int cp = GetConsoleCP();
    // SetConsoleCP(1251);
    // setlocale(LC_ALL, "Russian");
    int wsize = word_.size();
    std::vector<bool>revealed(wsize, false);
    int status = 1;
    char let;
    bool f; 
    while(status == 1){
        std::cout<<"Ваша буква?"<<std::endl;
        std::cin>>let;
        f = finder_letter(word_, let, revealed);

        if (f == 0){
            std::cout<<std::endl<<"Да что Вы!"<<std::endl;
        }
        else{
            std::cout<<std::endl<<"Откройте букву!"<<std::endl;
        }
        show(word_, revealed);
        if (guess_counter == wsize){
            status = 0;
            std::cout<<"Вы выиграли!"<<std::endl;
        }
    }
}