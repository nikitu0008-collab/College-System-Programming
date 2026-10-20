#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <print>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
/*
 *  Напоминалка:
 *  ifstream -- Чтение
 *  ofstream -- Запись
 *  fstream -- Чтение и Запись (но я его не использовал)
 * 
 * */
auto main() -> int {
    const std::vector<std::string> files = { "file0.txt", "file1.txt", "file2.txt", "file3.txt" };
    const std::string output_file = "output.txt";

    std::ofstream os(output_file);

    if(!os.is_open()){
        throw std::invalid_argument("Error opening file");
    }

    /* START TASK - 1 */
    const time_t start1 = clock();

    for(const std::string& file : files){
        std::ifstream is(file);
        if(!is.is_open()){
            throw std::invalid_argument("Error opening: " + file);
        }

        std::string line;
        while(std::getline(is, line)){
            os << line << '\n';
        }
    }

    os.close();
    const time_t end1 = clock();

    double t1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
    std::println("output file time: {} s", t1);

    /* START TASK - 2 */

    std::string name_object;
    std::println("Enter name object: ");
    std::getline(std::cin, name_object);

    time_t start2 = clock();

    std::ofstream name_file("name.txt", std::ios::app);
    if(!name_file.is_open()){
        throw std::invalid_argument("Error opening name.txt");
    }

    {
        std::ifstream in(output_file);
        if(!in.is_open()){
            throw std::invalid_argument("Error opening: " + output_file);
        }

        std::string line;
        while(std::getline(in, line)){
            if(line.starts_with(name_object)){
                name_file << line << '\n';
            }
        }
    }

    name_file.close();
    const time_t end2 = clock();

    double t2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
    std::println("name.txt time: {} s", t2);

    /* START TASK - 3 */

    const time_t start3 = clock();

    double sum = 0.0;
    size_t count = 0;

    {
        std::ifstream in(output_file);
        if(!in.is_open()){
            throw std::invalid_argument("Error opening: " + output_file);
        }

        std::string line;
        while(std::getline(in, line)){
            std::istringstream iss(line);
            std::string name, letter;
            double value;

            if(!(iss >> name >> value >> letter)){
                continue;
            }
            sum += value;
            count++;
        }
    }

    const double avg = (count > 0) ? sum / count : 0.0;

    std::ofstream more_file("more_than_avg.txt");
    if(!more_file.is_open()){
        throw std::invalid_argument("Error opening more_than_avg.txt");
    }

    {
        std::ifstream in(output_file);
        if(!in.is_open()){
            throw std::invalid_argument("Error opening " + output_file);
        }

        std::string line;
        while(std::getline(in, line)){
            //Парсит данные из строки line
            std::istringstream iss(line);
            std::string name, letter;
            double value;

            if(!(iss >> name >> value >> letter)){
                continue;
            }

            if(value > avg){
                more_file << line << '\n';
            }
        }
    }

    more_file.close();
    time_t end3 = clock();

    double t3 = static_cast<double>(end3 - start3) / CLOCKS_PER_SEC;
    std::println("more_than_avg.txt time: {} s", t3);

    return EXIT_SUCCESS;
}
