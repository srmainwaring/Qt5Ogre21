#include "somecustomwidget.h"

SomeCustomWidget::~SomeCustomWidget()
{
    delete w1;
    w1 = nullptr;

    delete w2;
    w2 = nullptr;
}

SomeCustomWidget::SomeCustomWidget(QWidget *parent)
    : QWidget(parent)
{
    // Setup window
    setWindowTitle("Some Window");
    setMinimumSize(100, 100);
    resize(600, 900);

    // Setup layout
    layout = new QVBoxLayout();
    // layout->setContentsMargins(0, 0, 0, 0);
    // layout->setMargin(0);
    // layout->setSpacing(0);

    // Add Ogre viewports
    w1 = new QOgreViewport(0);
    layout ->addWidget(w1);

    QtOgre21::instance()->createNewScene();
    w2 = new QOgreViewport(1);
    layout->addWidget(w2);

    // Layout
    setLayout(layout);
}
