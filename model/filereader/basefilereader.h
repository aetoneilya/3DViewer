#ifndef SRC_MODEL_FILEREADER_BASEFILEREADER_H_
#define SRC_MODEL_FILEREADER_BASEFILEREADER_H_

#include <memory>
#include <string>

#include "../drawer/figure/figure.h"
#include "observable.h"

namespace s21 {
class BaseFileReader : public BaseFileReaderObservable {
 public:
    virtual ~BaseFileReader() = default;

    virtual void Parse(std::string const& filename) = 0;
};
}  // namespace s21

#endif  // SRC_MODEL_FILEREADER_BASEFILEREADER_H_
