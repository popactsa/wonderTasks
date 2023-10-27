#ifndef FOW_OI
#define FOW_OI

class OI{
    public:
        OI() = default;
        void show_file_edit_menu(library io_lib){
            while (true){
                std::cout<<"--- 1.Append word ---"<<std::endl;
                std::cout<<"--- 2.Change file ---"<<std::endl;
                unsigned short item_choose;
                std::string enter;
                std::cin>>enter;
                if (enter == "1"){
                    item_choose = 1;
                    std::cout<<"Enter word to append"<<std::endl;
                    std::string word_to_append;
                    word_to_append = getWord();
                    io_lib.append(word_to_append);
                    break;
                }
                else if(enter == "2"){
                    item_choose = 2;
                    io_lib.change_file_directory();
                    break;
                }
                else{
                    std::cout<<"Enter 1 or 2"<<std::endl<<std::endl;
                    continue;
                }
            }
            show_menu(io_lib);
        };
        void show_menu(library io_lib){
            while (true){
                std::cout<<"--- 1.Start new game ---"<<std::endl;
                std::cout<<"--- 2.Edit data file ---"<<std::endl<<std::endl;
                unsigned short item_choose;
                std::string enter;
                std::cin>>enter;
                if (enter == "1"){
                    item_choose = 1;
                    true; //function ends, nothing in return
                    break;
                }
                else if (enter == "2"){
                    item_choose = 2;
                    show_file_edit_menu(io_lib);
                    break;
                }
                else{
                    std::cout<<"Enter 1 or 2"<<std::endl<<std::endl;
                }
            }
        };
        std::string getWord(){
            std::string word;
            bool sw;
            while (true){
                sw = 1;
                std::cout<<"Enter your word:"<<std::endl;
                std::cin>>word;
                for (auto it : word){
                    if ((it >= 'a' && it <= 'z') == false){
                        std::cout<<"Incorrect enter, use low register"<<std::endl;
                        sw = 0;
                        break;
                    }
                }
                if (sw == 1){
                    return word;
                }
            }
        };
        char getLetter(){
            std::string let;
            while(true){
                std::cin>>let;
                if (let.size() != 1){
                    std::cout<<"Enter only one letter"<<std::endl;
                    continue;
                }
                else if ((let[0] >= 'a' && let[0] <= 'z') == false){
                    std::cout<<"Incorrect enter, use low register"<<std::endl;
                    continue;
                }
                else{
                    return let[0];
                }
            }
        };
        void show_turn_result(std::vector <bool> revealed, std::string word, unsigned short let_status){
            if (let_status == 0){
                std::cout<<"Open a letter!"<<std::endl;
            }
            else if (let_status == 1){
                std::cout<<"Do I have to say 'no' twice?"<<std::endl;
            }
            else if (let_status == 2){
                std::cout<<"No such letter!"<<std::endl;
            }
            show_opened(revealed, word);
        };
        void show_opened(std::vector <bool> revealed, std::string word){
            for (int i = 0; i < word.size(); ++i){
                if (revealed[i] == true){
                    std::cout<<word[i]<< ' ';
                }
                else if (revealed[i] == false){
                    std::cout<<'-'<<' ';
                }
            }
            std::cout<<std::endl;
        };
        bool show_congrats_and_ask_restart(){
            std::cout<<"You've won! Congratulations!"<<std::endl;
            std::cout<<"Do you wish to try again? Enter Y/N"<<std::endl;
            std::string decision;
            std::cin>>decision;
            if (decision == "Y" || decision == "y" || decision == "yes"){
                return true;
            }
            else if (decision == "N" || decision == "n" || decision == "no"){
                return false;
            }
        };
        unsigned short enter_word_menu(){
            while (true){
                std::cout<<"How do you wish to enter word?"<<std::endl;
                std::cout<<"--- 1.Use random pick from library file ---"<<std::endl;
                std::cout<<"--- 2.Enter manually ---"<<std::endl<<std::endl;
                unsigned short item_choose;
                std::string enter;
                std::cin>>enter;
                if (enter == "1"){
                    return 1;
                }
                else if (enter == "2"){
                    return 2;
                }
                else{
                    std::cout<<"Enter 1 or 2"<<std::endl<<std::endl;
                }
            }
        }
};
#endif