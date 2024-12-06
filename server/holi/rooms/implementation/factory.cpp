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

          std::shared_ptr<room> factory_implementation::create(const std::string& name) const
          {
               return std::make_shared<room>(name);
          }
     };
};