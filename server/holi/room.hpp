#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include "holi/user.hpp"

namespace holi
{
     class room
     {
     public:
          size_t id;
          std::string name;
          std::unordered_map<size_t, std::shared_ptr<holi::user>> users;

          room(size_t id, std::string& name);
          virtual ~room();


          virtual void join(user& user) const = 0;
          virtual void leave(size_t user_id) const = 0;
     };
};