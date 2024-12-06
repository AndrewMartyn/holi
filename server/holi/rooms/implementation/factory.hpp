#pragma once

#include <string>
#include <memory>
#include "holi/room.hpp"
#include "holi/rooms/factory.hpp"


namespace holi
{
     namespace rooms
     {
          class factory_implementation : public factory
          {
          public:
               factory_implementation();

               std::shared_ptr<room> create(const std::string& room_name) const override final;
          };
     };
};