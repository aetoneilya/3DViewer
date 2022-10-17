#ifndef SRC_MODEL_FILEREADER_OBSERVABLE_H_
#define SRC_MODEL_FILEREADER_OBSERVABLE_H_

#include "observer.h"

namespace s21 {
class BaseFileReaderObservable {
 public:
    virtual ~BaseFileReaderObservable() = default;

    virtual void AddObserver(BaseFileReaderObserver *observer) = 0;
    virtual void Notify(std::shared_ptr<Figure const> figure) = 0;
};
}  // namespace s21

#endif  // SRC_MODEL_FILEREADER_OBSERVABLE_H_
