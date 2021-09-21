//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_BOOK_H
#define GAME_BOOK_H

#include "Item.h"

// Subclass of item class, adds an extra value to character's gained exp
class Book : public Item {
public:
  // Randomly generates modifier value for this item
  explicit Book(int);
  ~Book() override;
};


#endif //GAME_BOOK_H
