#pragma once

#include <string>
#include <memory>
#include <mutex>
#include <unordered_map>
#include "holi/user.hpp"

namespace holi
{
     class room
     {
     public:
          mutable std::mutex mutex;
          size_t id;
          std::string name;
          std::unordered_map<size_t, std::shared_ptr<user>> users;

          room(size_t id);
     };
};