#include <memory>
#include "holi/rooms/implementation/manager.hpp"
#include <iostream>

namespace holi
{
     namespace rooms
     {
               manager_implementation::manager_implementation(
                    holi::rooms::factory& rooms_factory
               )
               : rooms_factory(rooms_factory)
               {
                    this->next_id = 1;
               }

               manager_implementation::~manager_implementation()
               {
               }

               std::shared_ptr<room> manager_implementation::get(size_t id) const
               {
                    std::scoped_lock lock(this->mutex);

                    auto rooms_itr = this->rooms.find(id);
                    if (rooms_itr != this->rooms.end())
                    {
                         return rooms_itr->second;
                    }

                    return nullptr;
               }

               std::unordered_map<size_t, std::shared_ptr<room>> manager_implementation::get(void) const
               {
                    std::scoped_lock lock(this->mutex);

                    return this->rooms;
               }

               void manager_implementation::get(std::unordered_map<size_t, std::shared_ptr<room>>& rooms) const
               {
                    std::scoped_lock lock(this->mutex);

                    rooms = this->rooms;
               }

               std::shared_ptr<room> manager_implementation::create(const std::string& name)
               {

                    auto room = this->rooms_factory.create(this->next_id++);
                    room->name = name;

                    this->rooms[room->id] = room;

                    return room;
               }
     };
};