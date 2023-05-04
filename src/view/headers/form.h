#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "../controller/s21_controller.h"


namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

public:
  explicit Form(QWidget *parent = nullptr);
  void paintGraph(std::string Y1, double X1, double xMax, double yMax, double xMin, double yMin, double step);
  ~Form();
  Controller model;

private slots:

private:
  Ui::Form *ui;
};

#endif // FORM_H
