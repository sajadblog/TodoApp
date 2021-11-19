#ifndef TODOAPP_H
#define TODOAPP_H

#include <QObject>
#include <QQuickView>

namespace Todo {
class TodoApp : public QObject
{
    Q_OBJECT
public:
    explicit TodoApp(QObject *parent = nullptr);

private :
    QQuickView m_quickView;

signals:

};
}

#endif // TODOAPP_H
