//
// Created by Damir on 9/18/2021.
//

#include "NullItem.h"

NullItem::NullItem() {
  name = "No item";
  description = "you can gain item after defeating an enemy";
  modifier = 0;
}

NullItem::~NullItem() = default;