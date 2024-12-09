#include "holi/rooms/implementation/factory.hpp"


namespace holi
{
     namespace rooms
     {
          factory_implementation::factory_implementation()
          {
          }

          factory_implementation::~factory_implementation()
          {
          }

          std::shared_ptr<room> factory_implementation::create(size_t id) const
          {
               return std::make_shared<room>(id);
          }
     };
};