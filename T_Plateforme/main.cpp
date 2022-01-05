/*
    "T_Platform" is a video game platform.
    - It allows to manage peripherals such as controllers.
    - It allows to launch games
    ! Coming up!
    - Putting the games online
    - Construction of game servers
    - Profile building and messaging
    - Update management
* */

/* main.cpp is the application setup */


#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlContext> //permet de communiquer entre le qml et le c++
#include <QtGamepad/QGamepad>
#include <QGamepadManager>
#include <QtGamepad>
#include <QGamepad>

#include <QtQuick>
#include <QtQuick/QQuickView>
//#include <Qt3DQuickExtras/qt3dquickwindow.h>

#include <iostream>

#include "communication.h" //include the qml communication interface header

/**cube3D**/
//#include <QSurfaceFormat>
//#ifndef QT_NO_OPENGL
//#include "MainWidget.h"
//#endif

#define q2c(string) string.toStdString() //facilite le transtypage des strings

int main(int argc, char *argv[])
{
    //Qt::AA_ShareOpenGLContexts;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);



    /*3D cube*/
//        QSurfaceFormat format;
//        format.setDepthBufferSize(24);
//        QSurfaceFormat::setDefaultFormat(format);

//        #ifndef QT_NO_OPENGL
//            app.setApplicationName("cube");
//            app.setApplicationVersion("0.1");
//            MainWidget widget(0);
//            widget.setFormat(format);
//            widget.show();
//        #else
//            app.setApplicationName("T_Plateforme");
//            app.setApplicationVersion("0.1");
//            QLabel note("OpenGL Support required");
//            note.show();
//        #endif



    /*3D viewer*/
//        Qt3DExtras::Quick::Qt3DQuickWindow view3D;
//        view3D.setSource(QUrl("../T_Plateforme/SRC/OBJ/main.qml"));
//        view3D.show();



    /*GamePad viewer*/
        QQuickView view;
        communication com;
        view.rootContext()->setContextProperty("communication", &com);// nous passons ensuite notre object mainwindow comme contextProperty dans notre QML. C'est ainsi que nous pourrons l'utiliser.
            //QQmlApplicationEngine engine;
        view.setSource(QUrl(QLatin1String("../T_Plateforme/SRC/qml/main.qml")));
            //QQmlApplicationEngine engine("../T_Plateforme/main.qml");
            //QObject::connect(&com, SIGNAL(changeCpp(QString)), &app, SLOT(aboutQt()));
            //engine.load(QUrl(QStringLiteral("../T_Plateforme/main.qml")));
        com.setProperty("text", "text");
        //view.hide();

    /*GamePad Controller*/
        QList<int> manettes = QGamepadManager::instance()->connectedGamepads();
        if (manettes.isEmpty())
        {
            qDebug() << "Aucune manette détectée !";
        }
        else
        {
            qDebug() << "Nombre de manettes :" << manettes.size();
        }
        for (auto m : manettes)
        {
            QGamepad *manette = new QGamepad(m);
            qDebug() << "Manette :" << m;
            qDebug() << "  device id :   " << manette->deviceId();
            qDebug() << "  nom:        " << manette->name();
            qDebug() << "  connecte ?" << manette->isConnected();
        }



    /*Run App*/
        //if (engine.rootObjects().isEmpty())
        //    return -1;


        return app.exec();
}
