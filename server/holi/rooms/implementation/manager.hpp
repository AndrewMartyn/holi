#pragma once

#include <memory>
#include "holi/rooms/manager.hpp"
#include "holi/rooms/factory.hpp"


namespace holi
{
     namespace rooms
     {
          class manager_implementation : public manager
          {
          public:
               mutable std::mutex mutex;
               std::unordered_map<size_t, std::shared_ptr<room>> rooms;

               holi::rooms::factory& rooms_factory;

               manager_implementation(
                    holi::rooms::factory& rooms_factory
               );
               ~manager_implementation();

               std::unordered_map<size_t, std::shared_ptr<room>> get(void) const;
               void get(std::unordered_map<size_t, std::shared_ptr<room>>& rooms) const;
               std::shared_ptr<room> get(size_t id) const;
               std::shared_ptr<room> create(const std::string& name);
          private:
               size_t next_id;
          };
     };
};