#ifndef SRC_MODEL_FILEREADER_OBSERVER_H_
#define SRC_MODEL_FILEREADER_OBSERVER_H_

#include <memory>

#include "../drawer/figure/figure.h"

namespace s21 {
class BaseFileReaderObserver {
 public:
    virtual ~BaseFileReaderObserver() = default;

    virtual void Update(std::shared_ptr<Figure const> figure) = 0;
};
}  // namespace s21

#endif  // SRC_MODEL_FILEREADER_OBSERVER_H_
