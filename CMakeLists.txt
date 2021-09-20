cmake_minimum_required(VERSION 3.17)
project(Game)

set(CMAKE_CXX_STANDARD 20)
add_executable(main main.cpp Game.cpp Game.h
        Characters/Character.cpp Characters/Character.h Characters/Swordsman.cpp Characters/Swordsman.h
        Items/Item.cpp Items/Item.h Items/NullItem.cpp Items/NullItem.h Items/Weapon.cpp Items/Weapon.h
        Items/Armor.cpp Items/Armor.h Items/Book.cpp Items/Book.h
        Enemy.cpp Enemy.h RandomNumberGenerator.cpp RandomNumberGenerator.h)