#include "mainwindow.h"
#include "databaseconnection.h"

#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connect c;
    bool test=c.openConnection();
    MainWindow w;

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        QNetworkSession *networkSession = new QNetworkSession(config, &a);
        networkSession->open();
        networkSession->waitForOpened();

        if (networkSession->isOpen()) {
            QNetworkConfiguration config = networkSession->configuration();
            QString id;
            if (config.type() == QNetworkConfiguration::UserChoice) {
                id = networkSession->sessionProperty(
                        QLatin1String("UserChoiceConfiguration")).toString();
            } else {
                id = config.identifier();
            }

            QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
            settings.beginGroup(QLatin1String("QtNetwork"));
            settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
            settings.endGroup();
        }
    }


    if(test)
    {
        w.show();
        QMessageBox :: information(nullptr, QObject :: tr("database is open"),
                                   QObject::tr("Connection Successful\n" "Click Cancel To Exit"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox :: critical(nullptr, QObject :: tr("database is not open"),
                                   QObject::tr("Connection Failed\n" "Click Cancel To Exit"),QMessageBox::Cancel);

    }

    return a.exec();


}
