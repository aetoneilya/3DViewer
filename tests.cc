#include <gtest/gtest.h>

#include "model/filereader/filereader.h"

double cube_v[8][3] = {{1, -1, -1}, {1, -1, 1}, {-1, -1, 1}, {-1, -1, -1},
                       {1, 1, -1},  {1, 1, 1},  {-1, 1, 1},  {-1, 1, -1}};

class S21_3DViewer : public ::testing::Test, public s21::BaseFileReaderObserver {
 protected:
    S21_3DViewer() {
        filereader_->AddObserver(this);
    }
    ~S21_3DViewer() override = default;

    void Update(std::shared_ptr<s21::Figure const> figure) override {
        this->figure_ = figure;
    }

    std::unique_ptr<s21::BaseFileReader> filereader_ = std::make_unique<s21::FileReader>();
    std::shared_ptr<s21::Figure const> figure_ = nullptr;
};

TEST_F(S21_3DViewer, filereader_1) {
    filereader_->Parse("objects/cube.obj");

    while (figure_ == nullptr) {
    }

    for (std::size_t i = 0; i < figure_->GetVerticies().size(); ++i) {
        EXPECT_EQ(figure_->GetVerticies().at(i).GetPosition().x, cube_v[i][0]);
        EXPECT_EQ(figure_->GetVerticies().at(i).GetPosition().y, cube_v[i][1]);
        EXPECT_EQ(figure_->GetVerticies().at(i).GetPosition().z, cube_v[i][2]);
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
