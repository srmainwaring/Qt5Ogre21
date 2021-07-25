#include "qogreviewport.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>

#include <memory>

#include "somecustomwidget.h"

int main(int argc, char *argv[])
{
    //Initialize the Qt Application
    QApplication a(argc, argv);

    //Initialize the QtOgre system
    QtOgre21 qtOgre(QtOgre21::RenderAPI::OpenGL,
        "/Users/rhys/Code/ogre/Qt5Ogre21/testMedia/");

#if 0
    //Create the widget directly
    QWidget *window = new QWidget;
    window->setWindowTitle("Main Window");
    window->setMinimumSize(100, 100);
    window->resize(600, 900);

    QVBoxLayout *layout = new QVBoxLayout();

    QOgreViewport *w1 = new QOgreViewport(0);
    layout->addWidget(w1);

    QtOgre21::instance()->createNewScene();
    QOgreViewport *w2 = new QOgreViewport(1);
    layout->addWidget(w2);

    window->setLayout(layout);
    window->show();
#else
    //Create the widget
    SomeCustomWidget widget;
    widget.show();

    auto w1 = widget.w1;
    auto w2 = widget.w2;
#endif
    //Resource locations
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
        "/Users/rhys/Code/ogre/Qt5Ogre21/testMedia",
        "FileSystem");

    //HighLevelMaterialSystem shader libraries
    qtOgre.declareHlmsLibrary();

    //Initialize the resources
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups(true);

    //Setup 1st scene (that is in 1st widget
    auto scene = qtOgre.getScene(0);
    auto suzanneItem = scene->createItem(qtOgre.loadFromV1Mesh("Suzanne.mesh"));
    auto suzanneNode = scene->getRootSceneNode()->createChildSceneNode();
    suzanneNode->attachObject(suzanneItem);
    auto sunlight = scene->createLight();
    auto sunNode = scene->getRootSceneNode()->createChildSceneNode();
    sunNode->attachObject(sunlight);
    sunlight->setType(Ogre::Light::LT_DIRECTIONAL);
    sunlight->setDirection(Ogre::Vector3(-1, -1, -0.5f).normalisedCopy());
    sunlight->setPowerScale(Ogre::Math::PI);
    auto Camera = w1->getCamera();
    Camera->setPosition(0, 1, 3.5f);
    Camera->setAutoAspectRatio(true);

    //Setup 2nd scene (2nd widget)
    auto scene2 = qtOgre.getScene(1);
    auto knotItem = scene2->createItem(qtOgre.loadFromV1Mesh("knot.mesh"));
    auto knotNode = scene2->getRootSceneNode()->createChildSceneNode();
    knotNode->attachObject(knotItem);
    knotNode->setScale(0.01f, 0.01f, 0.01f);
    auto sunlight2 = scene2->createLight();
    auto sunNode2 = scene2->getRootSceneNode()->createChildSceneNode();
    sunNode2->attachObject(sunlight2);
    sunlight2->setType(Ogre::Light::LT_DIRECTIONAL);
    sunlight2->setDirection(Ogre::Vector3(-1, -1, -0.5f).normalisedCopy());
    sunlight2->setPowerScale(Ogre::Math::PI);
    auto Camera2 = w2->getCamera();
    Camera2->setPosition(0, 2.5, 0);
    Camera2->setOrientation(Ogre::Quaternion(Ogre::Degree(-90),
                                             Ogre::Vector3::UNIT_X));
    Camera2->setAutoAspectRatio(true);


    return a.exec();
}
