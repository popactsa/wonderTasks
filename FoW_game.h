#ifndef FOW_GAME
#define FOW_GAME

class game{
    private:
        bool status; //можно добавить время
        std::string word;
        std::vector <bool> revealed;
        std::string history;
        OI io_user;
        library io_lib;
        unsigned short check_letter_history(char let){
            if (history.find(let) == std::string::npos){
                history += let;
                return 0;
            }
            else{
                return 1;
            }
        };
        unsigned short check_letter_word(char let){
            unsigned short let_status = 2;
            std::size_t pos, pos_prev;
            pos = -1;
            while (true){
                pos_prev = pos;
                pos = word.find(let, pos_prev + 1);
                if (pos != std::string::npos){
                    revealed[pos] = true;
                    let_status = 0;
                }
                else if(pos == std::string::npos){
                    return let_status;
                }
            }
        };
        unsigned short check_letter(char let){
            // 0 - OK
            // 1 - found in history
            // 2 - no such letter in word(if haven't found in history)
            unsigned short let_status;
            let_status = check_letter_history(let);
            if (let_status == 1){
                return let_status; //end further checking
            }
            let_status = check_letter_word(let);
            return let_status;
        };
        bool check_game_status(){
            for (const auto it : revealed){
                if (it == false){
                    return true;
                }
            }
            return false;
        }
    public:
        game(){
            game_start();
        };
        void game_start(){
            io_user.show_menu(io_lib);
            status = true;
            unsigned short how_to_enter_a_word_switch;
            how_to_enter_a_word_switch = io_user.enter_word_menu();
            if (how_to_enter_a_word_switch == 1){
                word = io_lib.random_pick();
            }
            else if(how_to_enter_a_word_switch == 2){
                word = io_user.getWord();
            }
            revealed.assign(word.length(), false);
            history.clear();
            game_in_progress();
        };
        void game_in_progress(){
            char let;
            unsigned short let_status;
            while (status == true){
                let_status = 0;
                let = io_user.getLetter();
                let_status = check_letter(let);
                io_user.show_turn_result(revealed, word, let_status);
                status = check_game_status();
                if (status == false){
                    game_end();
                }
            }
        };
        void game_end(){
            status = io_user.show_congrats_and_ask_restart();
            if (status == true){
                game_start();
            }
            //if status == false : game ends, nothing happens
        }
};

#endif