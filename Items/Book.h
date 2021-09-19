//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_BOOK_H
#define GAME_BOOK_H

#include "Item.h"

class Book : public Item {
public:
  explicit Book(int);
  ~Book() override;
};


#endif //GAME_BOOK_H
