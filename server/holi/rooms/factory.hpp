#pragma once

#include <string>
#include <memory>
#include "holi/room.hpp"

namespace holi
{
     namespace rooms
     {
          class factory
          {
          public:
               factory() = default;
               factory(const factory& obj) = delete;
               factory(factory&& obj) = delete;
               factory& operator=(const factory& obj) = delete;
               factory& operator=(factory&& obj) = delete;
               virtual ~factory() = default;

               virtual std::shared_ptr<room> create(const std::string& room_name) const = 0;
          };
     };
};