#pragma once

#include <memory>
#include "holi/room.hpp"

namespace holi
{
     namespace rooms
     {
          class manager
          {
          public:
               manager() = default;
               manager(const manager& obj) = delete;
               manager(manager&& obj) = delete;
               manager& operator=(const manager& obj) = delete;
               manager& operator=(manager&& obj) = delete;
               virtual ~manager() = default;

               virtual std::unordered_map<size_t, std::shared_ptr<room>> get(void) const = 0;
               virtual void get(std::unordered_map<size_t, std::shared_ptr<room>>& rooms) const = 0;
               virtual std::shared_ptr<room> get(size_t id) const = 0;
          };
     };
};