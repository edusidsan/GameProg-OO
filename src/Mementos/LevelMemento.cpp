#include "LevelMemento.hpp"
// #include "../json.hpp"
#include <fstream>
namespace OgrO
{
    namespace Mementos
    {

        LevelMemento::LevelMemento()
        {
        }
        LevelMemento::~LevelMemento()
        {
        }
        bool LevelMemento::save(const std::string &path)
        {
            std::ofstream file(path);
            if (file.fail())
            {
                return false;
            }
            file << toJSON();
            file.close();
            return true;
        }
    }
}