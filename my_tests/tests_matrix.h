#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <QMatrix4x4>
#include <QVector>

#include "../model/drawer/matrix_builder/matrix_builder.h"

TEST(S21MatrixBuilderTest, ortho1) {
  QVector4D x = {1, 1, 2, 1};
  QMatrix4x4 mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kOrthographic);
  QVector4D result1 = mvp_matrix * x;

  s21::MatrixBuilder::MoveModel(1, 1, 2);

  mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kOrthographic);
  QVector4D result2 = mvp_matrix * x;

  result1.setX(-2);
  result1.setY(2);
  result1.setZ(-0.70297);
  EXPECT_NEAR(result1.x(), result2.x(), 0.000001);
  EXPECT_NEAR(result1.y(), result2.y(), 0.000001);
  EXPECT_NEAR(result1.z(), result2.z(), 0.000001);
  EXPECT_NEAR(result1.w(), result2.w(), 0.000001);
}

TEST(S21MatrixBuilderTest, ortho2) {
  QVector4D x = {1, 1, 2, 1};
  QMatrix4x4 mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kOrthographic);
  QVector4D result1 = mvp_matrix * x;

  s21::MatrixBuilder::RotateModel(5, 1, 1, 1);

  mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kOrthographic);
  QVector4D result2 = mvp_matrix * x;

  result1.setX(-2.05159);
  result1.setY(1.95095);
  result1.setZ(-0.703021);
  EXPECT_NEAR(result1.x(), result2.x(), 0.00001);
  EXPECT_NEAR(result1.y(), result2.y(), 0.00001);
  EXPECT_NEAR(result1.z(), result2.z(), 0.00001);
  EXPECT_NEAR(result1.w(), result2.w(), 0.00001);
}

TEST(S21MatrixBuilderTest, ortho3) {
  QVector4D x = {1, 1, 2, 1};
  QMatrix4x4 mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kOrthographic);
  QVector4D result1 = mvp_matrix * x;

  s21::MatrixBuilder::ScaleModel(2, 2, 2);

  mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kOrthographic);
  QVector4D result2 = mvp_matrix * x;

  result1.setX(-3.10318);
  result1.setY(2.9019);
  result1.setZ(-0.663467);
  EXPECT_NEAR(result1.x(), result2.x(), 0.00001);
  EXPECT_NEAR(result1.y(), result2.y(), 0.00001);
  EXPECT_NEAR(result1.z(), result2.z(), 0.00001);
  EXPECT_NEAR(result1.w(), result2.w(), 0.00001);
}

TEST(S21MatrixBuilderTest, persp1) {
  QVector4D x = {1, 1, 2, 1};
  QMatrix4x4 mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kPerspective);
  QVector4D result1 = mvp_matrix * x;

  s21::MatrixBuilder::MoveModel(1, 1, 2);

  mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kPerspective);
  QVector4D result2 = mvp_matrix * x;

  result1.setX(-9.90594);
  result1.setY(9.42001);
  result1.setZ(16.02214);
  result1.setW(17.99492);
  EXPECT_NEAR(result1.x(), result2.x(), 0.00001);
  EXPECT_NEAR(result1.y(), result2.y(), 0.00001);
  EXPECT_NEAR(result1.z(), result2.z(), 0.00001);
  EXPECT_NEAR(result1.w(), result2.w(), 0.00001);
}

TEST(S21MatrixBuilderTest, persp2) {
  QVector4D x = {1, 1, 2, 1};
  QMatrix4x4 mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kPerspective);
  QVector4D result1 = mvp_matrix * x;

  s21::MatrixBuilder::RotateModel(5, 1, 1, 1);

  mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kPerspective);
  QVector4D result2 = mvp_matrix * x;

  result1.setX(-10.1654);
  result1.setY(9.19723);
  result1.setZ(16.0069);
  result1.setW(17.9797);
  EXPECT_NEAR(result1.x(), result2.x(), 0.0001);
  EXPECT_NEAR(result1.y(), result2.y(), 0.0001);
  EXPECT_NEAR(result1.z(), result2.z(), 0.0001);
  EXPECT_NEAR(result1.w(), result2.w(), 0.0001);
}

TEST(S21MatrixBuilderTest, persp3) {
  QVector4D x = {1, 1, 2, 1};
  QMatrix4x4 mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kPerspective);
  QVector4D result1 = mvp_matrix * x;

  s21::MatrixBuilder::ScaleModel(2, 2, 2);

  mvp_matrix = s21::MatrixBuilder::make_mvp_matrix(
      s21::Settings::Projection::kPerspective);
  QVector4D result2 = mvp_matrix * x;

  result1.setX(-15.5023);
  result1.setY(13.566);
  result1.setZ(19.993);
  result1.setW(21.9595);
  EXPECT_NEAR(result1.x(), result2.x(), 0.0001);
  EXPECT_NEAR(result1.y(), result2.y(), 0.0001);
  EXPECT_NEAR(result1.z(), result2.z(), 0.0001);
  EXPECT_NEAR(result1.w(), result2.w(), 0.0001);
}