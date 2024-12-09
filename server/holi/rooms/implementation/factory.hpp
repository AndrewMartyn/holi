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

               std::shared_ptr<room> create(size_t id) const override final;
          };
     };
};