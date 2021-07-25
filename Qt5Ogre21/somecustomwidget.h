#ifndef SOMECUSTOMWIDGET_H
#define SOMECUSTOMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "qogreviewport.h"

class SomeCustomWidget : public QWidget
{
    Q_OBJECT
public:
    virtual ~SomeCustomWidget();
    explicit SomeCustomWidget(QWidget *parent = 0);

    QOgreViewport *w1 = nullptr;
    QOgreViewport *w2 = nullptr;

signals:

public slots:

private:
    QVBoxLayout* layout = nullptr;
};

#endif // SOMECUSTOMWIDGET_H
