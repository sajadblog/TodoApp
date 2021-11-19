#include "TodoApp.h"
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Todo::TodoApp myApp;

     return app.exec();
}
