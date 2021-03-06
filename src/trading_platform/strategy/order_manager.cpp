// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#include "strategy/order_manager.h"

namespace ft {

void OrderManager::update_order_status(const OrderResponse& rsp) {
  if (rsp.completed) {
    order_map_.erase(rsp.order_id);
    return;
  }

  auto& order_info = order_map_[rsp.order_id];
  if (order_info.ticker_index == 0) {
    order_info.user_order_id = rsp.user_order_id;
    order_info.order_id = rsp.order_id;
    order_info.ticker_index = rsp.ticker_index;
    order_info.direction = rsp.direction;
    order_info.offset = rsp.offset;
    order_info.original_volume = rsp.original_volume;
    order_info.traded_volume = rsp.traded_volume;
  } else {
    order_info.traded_volume = rsp.traded_volume;
  }
}

}  // namespace ft
