#include "headers/form.h"
#include "ui_form.h"
#include "qcustomplot.h"


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}


void Form::paintGraph(std::string Y1, double X1, double xMax, double yMax, double xMin, double yMin, double step)
{
   double xBegin = xMin, xEnd = xMax, h = step, Y;
   QVector<double> x,y;

    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);

    for (X1 = xBegin; X1 <= xEnd; X1 += h) {
        model.set_string(Y1);
        model.set_value_X(X1);
        Y = model.get_itog();
        x.push_back(X1);
        y.push_back(Y);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    x.clear();
    y.clear();
}

