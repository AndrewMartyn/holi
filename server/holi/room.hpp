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
          std::unordered_map<size_t, std::shared_ptr<holi::user>> users;

          room(const std::string& name);
          virtual ~room();

          virtual void join(std::shared_ptr<user>& user);
          virtual void leave(size_t user_id);

     private:
          static size_t next_id;
     };
};