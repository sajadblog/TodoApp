#include "TodoApp.h"
#include "TodoModel.h"
#include <QQmlEngine>

TodoApp::TodoApp(QObject *parent) : QObject(parent)
{
    qmlRegisterType<FilterTodoModel>("FilterTodoModel", 1, 0, "FilterTodoModel");
    m_quickView.engine()->addImportPath("qrc:/");
    m_quickView.setSource(QUrl(("qrc:/main.qml")));
    m_quickView.show();
}
