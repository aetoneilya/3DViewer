#ifndef SRC_MODEL_FILEREADER_FILEREADER_H_
#define SRC_MODEL_FILEREADER_FILEREADER_H_

#include <fstream>
#include <memory>
#include <mutex>  // NOLINT [build/c++11]
#include <sstream>
#include <string>
#include <thread>  // NOLINT [build/c++11]
#include <vector>

#include "basefilereader.h"

namespace s21 {
class FileReader : public BaseFileReader {
 public:
    FileReader() {
    }
    ~FileReader() {
    }

    void AddObserver(BaseFileReaderObserver* observer) override {
        observers_.push_back(observer);
    }
    void Notify(std::shared_ptr<Figure const> figure) override {
        for (std::size_t i = 0; i < observers_.size(); ++i) {
            observers_[i]->Update(figure);
        }
    }

    void Parse(std::string const& filename) override;

 protected:
    FileReader(FileReader const& other);
    FileReader(FileReader&& other);
    void operator=(FileReader const& other);
    void operator=(FileReader&& other);

 private:
    Vertex ParseVertex(std::string const& s);
    std::vector<unsigned int> ParseSurface(std::string const& s);

    std::string const kVertexEntry = "v ";
    std::string const kSurfaceEntry = "f ";

    std::vector<BaseFileReaderObserver*> observers_;
    std::mutex mutex_;
};
}  // namespace s21

#endif  // SRC_MODEL_FILEREADER_FILEREADER_H_
