#include "settings.h"

namespace s21 {
void Settings::Save(std::string const& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&data_), sizeof(Data));

        file.close();
    }
}

void Settings::Load(std::string const& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&data_), sizeof(Data));

        file.close();
    }
}
}  // namespace s21
