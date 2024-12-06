#include "holi/room.hpp"
#include <iostream>

namespace holi
{
     size_t room::next_id = 1;

     room::room(
          const std::string& name
     )
     : id(next_id++), name(name)
     {
          std::cout << "room created: " << this->id << " " << this->name << "\n";
     }

     room::~room()
     {
          std::cout << "room destroyed: " << this->id << " " << this->name << "\n";
     }

     void room::join(std::shared_ptr<user>& user)
     {

     }

     void room::leave(size_t user_id)
     {

     }
};