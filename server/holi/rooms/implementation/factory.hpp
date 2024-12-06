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
               ~factory_implementation();

               std::shared_ptr<room> create(const std::string& name) const override final;
          };
     };
};