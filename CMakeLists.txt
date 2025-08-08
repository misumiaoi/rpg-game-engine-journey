# CMake 最低版本要求，这是一个好习惯
cmake_minimum_required(VERSION 3.10)

# 定义你的项目名称
# 这会成为最终生成的可执行文件的名字
project(rpg_game_engine_journey)

# 设置 C++ 标准为 C++17，确保我们能使用现代 C++ 的特性
# 你可以根据需要改成 C++20 或其他
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 告诉 CMake，我们的可执行文件是由哪些源文件编译而成的
# 因为文件现在在 src 文件夹下，所以需要加上路径前缀
add_executable(${PROJECT_NAME}
    "rpg-game-engine-base/src/ActionSystem.cpp"
    "rpg-game-engine-base/src/Characters.cpp"
    "rpg-game-engine-base/src/rpg-game-engine-base.cpp"
    # 如果你未来有更多的 .cpp 文件，就像这样一个个加进来
    # "src/MondstadtCharacter.cpp"
    # "src/LiyueCharacter.cpp"
)

# 这是一个好习惯，告诉 CMake 在哪里可以找到头文件
# 现在我们的头文件都在 src 文件夹里了
target_include_directories(${PROJECT_NAME} PUBLIC "src")
