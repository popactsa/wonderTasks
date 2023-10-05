#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <ctime>

std::string get_date()
{
    std::string date;
    int dot_counter = 0;
    bool sw = 1;
    while (true)
    {
        sw = 1;
        std::cin >> date;
        for (const auto &i : date)
        {
            if (i == '.')
            {
                dot_counter++;
            }
            // РґРѕРїРёСЃР°С‚СЊ РїСЂРѕРІРµСЂРєРё РЅР° СЂР°СЃРїРѕР»РѕР¶РµРЅРёРµ С‚РѕС‡РєРё
            if ((i < '0' || i > '9') && i != '.' || dot_counter >= 3)
            {
                std::cout << "Unappropriate date format";
                sw = 0;
                continue;
            }
        }
        if (sw == 1 && dot_counter == 2)
        {
            return date;
        }
        dot_counter = 0;
    }
}

void num_from_date(std::string date, int &sum, std::vector<int> &date_separated)
{
    int dot_counter, digit_counter, temp;
    dot_counter = 0;
    digit_counter = 0;
    temp = 0;
    for (const auto &i : date)
    {
        if (i != '.')
        {
            temp *= 10;
            temp += i - '0';
            sum += i - '0';
            digit_counter++;
        }
        else
        {
            dot_counter++;
            date_separated.push_back(temp);
            digit_counter = 0;
            temp = 0;
        }
    }
    date_separated.push_back(temp);
}

std::vector<int> noise_maker(int sum, std::vector<int> date_separated)
{
    int patient;
    patient = pow(sum, date_separated[1]);

    int noise_add[3] = {0, 11111111, 22222222};
    int rand;
    rand = std::rand() % 3;
    patient += noise_add[rand];
    std::cout<<patient<<std::endl;

    int mask, counter;
    mask = 15;
    counter = 0;
    std::vector<int> noise_values;
    while (counter < 5)
    {
        noise_values.push_back(patient & mask);
        patient = patient >> 4;
        counter++;
    }
    return noise_values;
}

int main()
{
    std::srand(std::time(nullptr));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string date;
    date = get_date();
    int sum;
    sum = 0;
    std::vector<int> date_separated;
    num_from_date(date, sum, date_separated);
    date.clear();
    std::vector<int> noise_values;
    noise_values = noise_maker(sum, date_separated);
    for (const auto &i : noise_values)
    {
        std::cout << i << ' ';
    }
    std::cout<<std::endl<<std::endl;

    std::vector<std::string> music = {"Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1", "Червяк Даргомыжский", "Russian Ebunny", "Enemy Imagine dragons", " Зизазай Огги и тараканы", "Valentine Justice", "Swimming pools Kendrick Lamar", "Night Call Kovinsky", "Yesterday The Beatles", "Так закалялась сталь Гражданская оборона", "За деньги да Инстасамка", "Bad habits Ed sheeran"};
    std::vector<std::string> movies = { "Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести", "Джентльмены", "Ван Хельсинк", "Операция Ы", "Драйв", "Большая игра", "Игра в имитацию", "Всё везде и сразу", "Форрест Гамп", "Терминал", "Не смотрите наверх"};
    std::vector<std::string> actors = { "Райан Гослинг", "Кристиан Бейл", "Джеки Чан", "Эндрю Гарфилд", "Леонардо ДиКаприо", "Бенедикт Кембербетч", "Мэтью Макконахи", "Дэвид Линч", "Дэниэлл Рэдклифф", "Джейк Джиллехолл", "Александр Петров", "Рональд Рейган", "Том Круз", "Брэд Питт"};
    std::vector<std::string> actress = { "Наталия Крачковская", "Меган Фокс", "Джениффер Лопез", "Эмма Стоун", "Эмма Уотсон", "Кира Найтли", "Милла Йовович", "Марго Робби", "Мерил Стрип", "Скарлет Йоханссон", "Александра Бортич", "Анджелина Джоли", "Шарлиз Терон", "Ингеборга Дапкунайте"};
    std::vector<std::string> celeb = { "Дейв Майнстейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева", "Павел Воля", "Криштиану Роналду", "Борис Бурда", "Ким Кардашьян", "Клава Кока"};
    std::cout << music[noise_values[0]] << std::endl;
    std::cout << movies[noise_values[1]] << std::endl;
    std::cout << actors[noise_values[2]] << std::endl;
    std::cout << actress[noise_values[3]] << std::endl;
    std::cout << celeb[noise_values[4]] << std::endl;
}
