#ifndef EXTRALEVEL_HPP
#define EXTRALEVEL_HPP

#include "../Levels/Level.hpp"
#include "ThreadWitch.hpp"

namespace OgrO {
  namespace MultiplesThreads {

    class ExtraLevel : public Levels::Level {
    private:
      int key_event_id;
      std::vector<ThreadWitch*> Witch;
    public:
      ExtraLevel(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr, const std::string _backgroundPath = "");
      ~ExtraLevel();
      void initialize();
      void load(const std::string &path);

    //   void playFromStart();
    //   int exec() ;
    };

  }
}

#endif