# College System Programming

[![ci](https://github.com/nikitu0008-collab/College-System-Programming/actions/workflows/ci.yml/badge.svg)](https://github.com/nikitu0008-collab/College-System-Programming/actions/workflows/ci.yml)

Лабораторные работы по системному программированию на C++20/23: работа с памятью, измерение времени, многопоточность, обработка исключений, сортировки, файловый ввод-вывод.

Каждая задача — отдельный каталог со своей структурой `include/` + `src/`, собирается через CMake.

## Содержание

| Лабораторная | Тема | Что внутри |
|---|---|---|
| **2** | Векторы и многопоточность | Заполнение `std::vector` последовательно, в 2 потока и в N потоков (`std::thread::hardware_concurrency`), замер времени через `std::clock`, `std::ref`, `join()`, рост объёма до 10⁹ элементов |
| **3** | Исключения и сортировки | Обработка ошибок через `std::invalid_argument`, bubble sort против quick sort с замером времени, работа со строками и `std::string::starts_with` |
| **4** | Гонки данных | Вывод в консоль из нескольких потоков: без синхронизации, с `std::mutex` и с `try_lock` |
| **5** | Файловый ввод-вывод | `ifstream` / `ofstream` / `fstream`: склейка файлов, выборка строк по префиксу, расчёт среднего и выборка значений выше среднего через `std::istringstream` |

## Используемое

- C++20/23: `std::print` / `std::println`, `std::string::starts_with`, `auto main() -> int`
- `std::vector`, `std::string`, `std::filesystem`-подобная работа с файлами через `fstream`
- `std::jthread`, `std::thread`, `std::mutex`, `std::unique_lock`, `std::ref`
- `std::chrono::steady_clock` для замеров, `std::mt19937` из `<random>` вместо C-стиля `rand()`
- `std::function` для передачи заданий с замером, `std::expected` и `std::from_chars` в лабе 5
- CMake ≥ 3.16 + GitHub Actions CI (сборка и запуск всех задач на GCC 14)

## Сборка

В каталоге задачи:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Требуется CMake ≥ 3.16 и компилятор с полной поддержкой C++23 `<print>`/`<format>`
(GCC 14+; Clang — libc++ 19+). CI репозитория собирает и запускает все задачи на GCC 14,
для `lesson_1` дополнительно нужна `libwxgtk3.2-dev` (wxWidgets).

## Структура

```text
College-System-Programming/
├── .github/workflows/ci.yml  # сборка и запуск всех задач на GCC 14
├── Laboratory/
│   ├── 2/                  # векторы и многопоточность
│   │   ├── Task_1/         # последовательное заполнение
│   │   ├── Task_2/         # заполнение в отдельном потоке
│   │   ├── Task_3/         # два потока на половины вектора
│   │   ├── Task_4/         # N потоков по hardware_concurrency
│   │   └── documentation.txt
│   ├── 3/                  # исключения и сортировки (Task_1..Task_5)
│   ├── 4/                  # гонки данных и синхронизация (Task_1..Task_3 + вариант
│   │                       Ярового)
│   ├── 5/                  # файловый ввод-вывод: отдельный main.cpp + CMakeLists
│   └── ...
├── lesson_1/               # минимальное wxWidgets-приложение
├── LICENSE
└── README.md
```

Внутри задачи структура одинаковая:

```text
Task_N/
├── CMakeLists.txt
├── include/     # заголовки
└── src/         # реализация
```

Исключения: у `Laboratory/5` код лежит в `main.cpp` рядом с `CMakeLists.txt`,
а `lesson_1` содержит только `CMakeLists.txt` и `main.cpp`.

## Замечания

- Собранные бинарники в репозиторий не коммитятся — они в `.gitignore`.
- Результаты замеров из `documentation.txt` получены на Linux, поэтому абсолютные значения зависят от машины.
- В части заданий есть развлекательные варианты, помеченные в именах каталогов и не входящие в основную программу.
- Лаба 5 при запуске ожидает рядом с бинарником файлы `file0.txt`–`file3.txt`
  в формате `ИМЯ ЗНАЧЕНИЕ МОДИФИКАТОР` (пример: `sword 150 fire`);
  в CI они генерируются автоматически перед запуском.

## Лицензия

MIT — файл [LICENSE](LICENSE).

## Автор

NikiZIP — студент колледжа IT TOP.
