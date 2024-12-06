#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include "holi/room.hpp"

namespace holi
{
     class room_implementation : public room
     {
     public:
          size_t id;
          std::string& name;

          room_implementation(size_t id, std::string& name);
          ~room_implementation();

          void join(user& user);
          void leave(size_t user_id);
     };
};