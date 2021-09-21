//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_NULLITEM_H
#define GAME_NULLITEM_H

#include "Item.h"

// Subclass of Item class
class NullItem : public Item {
public:
  NullItem();
  ~NullItem() override;
};


#endif //GAME_NULLITEM_H
