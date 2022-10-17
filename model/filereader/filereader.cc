#include "filereader.h"

namespace s21 {
void FileReader::Parse(std::string const& filename) {
    std::thread([this, filename]() {
        auto figure = std::make_shared<Figure>();

        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (line.find(kVertexEntry) == 0) {
                    figure->AddVertex(ParseVertex(line));
                } else if (line.find(kSurfaceEntry) == 0) {
                    figure->AddSurface(ParseSurface(line));
                }
            }

            file.close();
        }

        Notify(figure);
    }).detach();
}

Vertex FileReader::ParseVertex(std::string const& s) {
    std::stringstream ss(s.substr(s.find(' ')));
    float x = 0, y = 0, z = 0;

    ss >> x >> y >> z;

    return Vertex(x, y, z);
}

std::vector<unsigned int> FileReader::ParseSurface(std::string const& s) {
    std::vector<unsigned int> numbers;

    auto n = s.find(' ');
    while (n != std::string::npos) {
        if (std::isdigit(s.at(n + 1))) {
            auto value = std::stoi(s.substr(n + 1), nullptr) - 1;

            if (numbers.size() != 0) {
                numbers.push_back(value);
            }
            numbers.push_back(value);
        }

        n = s.find(' ', n + 1);
    }
    numbers.push_back(numbers.at(0));

    return numbers;
}
}  // namespace s21
