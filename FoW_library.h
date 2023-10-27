#ifndef FOW_LIBRARY
#define FOW_LIBRARY

class library{
    private:
        std::string file;
        unsigned int words_count; //add word_check_format for entire file
    public:
        library(std::string data_file){
            file = data_file;
            std::ifstream fget(file);
            if (fget.is_open() == false){
                std::cout<<"Something went wrong, check file manually and restart program";
            }
            std::string line;
            words_count = 0;
            while(getline(fget, line)){
                words_count++;
            }
            if (fget.eof()){
            }
            else{
                std::cout<<"Something went wrong, check file manually and restart program";
            }
            fget.close();
        }
        library() : library("lib_data.txt"){
        };
        void append(std::string word_to_append){
            std::fstream fapp(file, std::ios::app);
            if (fapp.is_open() == false){
                std::cout<<"Something went wrong, check file manually and restart program";
            }
            fapp<<std::endl<<word_to_append;
            fapp.close();
        }
        void change_file_directory(){
            std::string path;
            while (true){
                std::cout<<"Enter new path:";
                std::cin>>path;
                std::fstream check_app_file("path", std::ios::app);
                if (check_app_file.is_open() == false){
                    continue;
                }
                check_app_file.close();

                std::ifstream check_in_file("path");
                if (check_in_file.is_open() == false){
                    continue;
                } // doesnt find errors
                check_in_file.close();
                break;
            }
            file = path;
            std::cout<<"Directory changed successul"<<std::endl;
        };
        std::string random_pick(){
            unsigned int number;
            number = rand() % words_count;
            std::string lib_word;
            std::ifstream fget(file);
            if (fget.is_open() == false){
                std::cout<<"Something went wrong, check file manually and restart program";
            }
            for (int i = 0; i < number; ++i){
                std::getline(fget, lib_word);
            }
            fget.close();
            return lib_word;
        }
};

#endif