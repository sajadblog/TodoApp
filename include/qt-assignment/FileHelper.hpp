/**
 * Copyright (C) 2021 BladeInsight, S.A. - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited. Proprietary and confidential.
 */

#include <QString>
#include <QFile>
#include <QThread>
#include <QDebug>

namespace bi
{
    /**
     * @brief Save text content to a file, simulating a slow filesystem
     * @param content the content to save
     * @param location the full path of the file to save to, such as /path/to/filename.extension
     * @detail A forced 3-second delay is added to simulate a slow filesystem
     * @note This method is not optimal for large amounts of content, it is simplified for the purposes of the assignment
     */
    void saveToFileSlow(const QString content, const QString location)
    {
        qInfo() << "Saving to " << location << " ...";

        // Sleeps this thread for 3 seconds
        QThread::msleep(3 * 1000);

        QFile file(location);
        if(!file.open(QIODevice::WriteOnly)){
            qCritical() << "Could not open " << location << " to save";
            return;
        }
        QTextStream stream(&file);
        stream << content;
        file.close();

        qInfo() << "Save complete!";
    }

    /**
     * @brief load text content from a file
     * @return the content of location file
     * @param location the full path of the file that need to load, such as /path/to/filename.extension
     */
    QString loadFromFileSlow(const QString &location)
    {
        qInfo() << "Loading from " << location << " ..." ;

        QFile file(location);
        if(file.open(QIODevice::ReadOnly)){
            return file.readAll();
        }
        return "";
    }
}
