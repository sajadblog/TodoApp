#include "TodoApp.h"
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TodoApp myApp;

     return app.exec();
}
