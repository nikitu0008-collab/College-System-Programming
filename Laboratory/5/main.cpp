/*
 *  Напоминалка:
 *  ifstream -- Чтение
 *  ofstream -- Запись
 *
 *  Формат строки в файлах: ИМЯ ЗНАЧЕНИЕ МОДИФИКАТОР
 *  Пример: sword 150 fire
 *
 * */

#include <expected>
#include <functional>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <thread>
#include <ctime>
#include <print>
#include <cstdlib>
#include <filesystem>

// Читает один файл построчно и складывает строки в буфер (buffer -- для своего потока свой, поэтому без мьютексов)
static auto read_file(const std::string& filename, std::vector<std::string>& buffer) -> std::expected<std::vector<std::string>, std::string>{
    std::ifstream in(filename);
    if (!in.is_open()) {
        return std::unexpected("Error opening: {}" + filename);
    }

    std::string line;
    while (std::getline(in, line)) {
        buffer.push_back(line);
    }
    return buffer;
}

// Достаёт ЗНАЧЕНИЕ из строки в формате "ИМЯ ЗНАЧЕНИЕ МОДИФИКАТОР".
// istringstream на больших файлах непозволительно медленный (каждая строка -- новый потоковый объект),
// поэтому парсим руками: пропускаем имя, а число забираем через strtod.
// Если строка кривая (значения нет) -- вернём через ok значение false.
static auto parse_value(const std::string& line, bool& ok) -> double {
    const char* p = line.c_str();

    while (*p == ' ' || *p == '\t') { // пропускаем пробелы в начале
        p++;
    }
    while (*p != ' ' && *p != '\t' && *p != '\0') { // пропускаем имя
        p++;
    }

    if (*p == '\0') { // значения в строке нет
        ok = false;
        return 0.0;
    }

    char* end = nullptr;
    const double value = strtod(p, &end);
    ok = (end != p);
    return value;
}

auto main() -> int {
    const std::vector<std::string> files = { "file0.txt", "file1.txt", "file2.txt", "file3.txt" };

    /* ПРОВЕРКА ВХОДНЫХ ФАЙЛОВ ПЕРЕД СТАРТОМ */
    for (const std::string& file : files) {
        if (!std::filesystem::exists(file)) {
            std::cerr << "Критическая ошибка: Входной файл " << file << " не найден на диске!\n";
            std::system("pause");
            return EXIT_FAILURE; // Завершаем программу, так как читать нечего
        }
    }

    /* START TASK - 1 */
    const time_t start1 = clock();

    // Каждому потоку -- свой буфер, чтобы они не дрались за один вектор
    std::vector<std::vector<std::string>> buffers(files.size());

    std::vector<std::jthread> threads;
    std::size_t index = 0;
    for (const std::string& file : files) {
        threads.emplace_back(read_file, file, std::ref(buffers.at(index)));
        index++;
    }

    threads.clear();

    std::ofstream out("output.txt");
    if (!out.is_open()) {
        throw std::invalid_argument("Error opening output.txt");
    }

    for (const std::vector<std::string>& buffer : buffers) {
        for (const std::string& line : buffer) {
            out << line << '\n';
        }
    }
    out.close(); // Задание 1 считается от начала до записи последнего элемента, поэтому закрываем файл до конца замера

    const std::filesystem::path my_path = "output.txt";

    //Проверяет есть ли файл вообще на диске
    if(!std::filesystem::exists(my_path)){
        std::cerr << "Error: File " << my_path << "Not Found this Disk" << '\n';
    }

    const time_t end1 = clock();
    const double t1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
    std::println("output file time: {} s", t1);

    system("pause"); // Пауза после первого задания, как требует ТЗ

    /* START TASK - 2 */
    std::string name_object;
    std::print("Enter name object: ");
    std::getline(std::cin, name_object);

    const time_t start2 = clock(); // Замер начинаем сразу после ввода имени

    std::ofstream name_file("name.txt");
    if (!name_file.is_open()) {
        throw std::invalid_argument("Error opening name.txt");
    }

    /* Ищем точное совпадение имени (первое слово в строке).
    Без istringstream -- на больших файлах потоки на строку жрут вечность.
    Просто смотрим: начинается ли строка с имени, а следом идёт разделитель. 
    */
    const std::string name_sep_space = name_object + " ";
    const std::string name_sep_tab = name_object + "\t";

    std::size_t found = 0;
    for (const std::vector<std::string>& buffer : buffers) {
        for (const std::string& line : buffer) {
            // точное совпадение: имя + разделитель. \t тоже разделитель, на всякий случай
            if (line.starts_with(name_sep_space) or line.starts_with(name_sep_tab)) {
                name_file << line << '\n';
                found++;
            }
        }
    }

    name_file.close();

    // Если имени в данных нет -- показываем пример реального имени (первое из file0).
    // Имена в данных генерируются случайно, по памяти такое не угадать.
    if (found == 0) {
        const std::string example_line = buffers.at(0).empty() ? std::string() : buffers.at(0).at(0);
        const std::size_t sep = example_line.find(' ');
        const std::string example = (sep != std::string::npos) ? example_line.substr(0, sep) : "?";
        std::println("Object '{}' not found in data. Try, for example: {}", name_object, example);
    }

    const time_t end2 = clock();
    const double t2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
    std::println("name.txt time: {} s", t2);

    /* START TASK - 3 */
    const time_t start3 = clock();

    double sum = 0.0;
    std::size_t count = 0;

    for (const std::vector<std::string>& buffer : buffers) {
        for (const std::string& line : buffer) {
            bool ok = false;
            const double value = parse_value(line, ok);

            if (ok) { // кривые строки пропускаем
                sum += value;
                count++;
            }
        }
    }

    const double avg = (count > 0) ? sum / static_cast<double>(count) : 0.0;

    std::ofstream more_file("more_than_avg.txt");
    if (!more_file.is_open()) {
        throw std::invalid_argument("Error opening more_than_avg.txt");
    }

    for (const std::vector<std::string>& buffer : buffers) {
        for (const std::string& line : buffer) {
            bool ok = false;
            const double value = parse_value(line, ok);

            if (ok && value > avg) {
                more_file << line << '\n';
            }
        }
    }

    more_file.close();

    const time_t end3 = clock();
    const double t3 = static_cast<double>(end3 - start3) / CLOCKS_PER_SEC;
    std::println("more_than_avg.txt time: {} s", t3);

    return EXIT_SUCCESS;
}
/*
заменил thread на -> std::jthread, он сам вызывает .join() в деструкторе это из 26 стандарта.
*/