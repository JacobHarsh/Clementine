#ifndef GLBLOCKANALYZER_H
#define GLBLOCKANALYZER_H

#include "analyzer.h"

#include <boost/scoped_array.hpp>

#include <QGLShaderProgram>

class GLBlockAnalyzer : public AnalyzerBase {
  Q_OBJECT
 public:
  Q_INVOKABLE GLBlockAnalyzer(QWidget* parent = 0);

  static const char* kName;

 protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

 protected slots:
  // AnalyzerBase
  void SpectrumAvailable(const QVector<float>& spectrum);

 private:
  QVector<float> current_spectrum_;

  boost::scoped_array<float> rectangles_;
  boost::scoped_array<float> colours_;
  size_t rectangles_size_;

  static const int kNumRectangles = 10;
  static const int kRectPixels = 5;

  int num_columns_;

  QGLShaderProgram shader_;
};

#endif
