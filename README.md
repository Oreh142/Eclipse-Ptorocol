# Eclipse Protocol

Eclipse Protocol — это консольная текстовая RPG в жанре dungeon crawler, в которой игрок управляет подопытным, сбежавшим из криокапсулы в секретной лаборатории. 
Исследуя её тёмные коридоры, он сражается с мутировавшими экспериментальными подопытными и ищет выход. Основная цель игрока — уничтожить или поглотить Куб теней, ядро лаборатории, определяя судьбу себя и остальных подопытных. 
Реализована на C++17 с использованием CMake.
---

📄 Документация

Полная документация проекта доступна здесь:

[Диздок Eclipse Protocol](https://docs.google.com/document/d/16tUsokwYYw4cjxAmkBQpu8uMfsrEuscj5hxToNTWYoY/edit?usp=sharing)

[Архитектурное представление Eclipse Protocol](https://docs.google.com/document/d/1eRW4-mR1SSFGdVrtlJoEUCgwryVv8J_lXsIGOr3LlVw/edit?usp=sharing)


---

🚀 Быстрый старт

1. Клонировать репозиторий
   ```bash
   git clone https://github.com/ВашПользователь/EclipseProtocol.git
   cd EclipseProtocol
   ```
   
2. Создать папку для сборки и перейти в неё
   
3. Собрать проект
   Через CMake GUI (Windows):

   * Укажите «Where is the source code»: папку с `CMakeLists.txt`.
   * «Where to build the binaries»: `.../EclipseProtocol/build`.
   * Нажмите **Configure**, выберите генератор (например, Visual Studio 16 2019) и toolset (`v142` или `v143`).
   * Нажмите **Generate**, затем **Open Project** для сборки в VS.

4. Запустить
---

🗂 Структура проекта

```
EclipseProtocol/
├── CMakeLists.txt       # Конфигурация сборки
├── include/             # Заголовочные файлы
│   ├── core/            # Game, InputParser, ConsoleRenderer
│   ├── systems/         # MovementSystem, CombatSystem, ItemPickupSystem
│   ├── entities/        # Character, Player, Enemy, Item
│   └── level/           # Room, Floor
├── src/                 # Исходники (.cpp)
│   ├── core/
│   ├── systems/
│   ├── entities/
│   └── level/
├── docs/                # Дополнительная документация и спецификации
├── build/               # Папка для сборки (игнорируется Git)
└── .gitignore           # Правила игнорирования
```
---

⚙️ Зависимости

* CMake >= 3.10
* Компилятор C++17:
  * MSVC (Visual Studio 2019/2022)
  * GCC 7+
  * Clang 5+
---

📝 Roadmap

-
---

© 2025 Eclipse Protocol — проект на пачке пельменей и паре пачек дошика.
