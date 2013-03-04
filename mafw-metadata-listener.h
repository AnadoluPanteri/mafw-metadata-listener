#ifndef MAFW_METADATA_LISTENER_H
#define MAFW_METADATA_LISTENER_H

#include <QtCore>
#include <QtDBus>

#include <MafwShared.h>
#include <MafwRegistry.h>
#include <MafwRenderer.h>
#include <MafwContent.h>

class Receiver : public QObject {
    Q_OBJECT
    public:
        Receiver(QObject *parent=NULL)
            : QObject(parent),
              registry(NULL),
              renderer(NULL),
              title(""),
              artist("")
        {
            registry = MafwRegistry::instance();
            MafwShared *shared = MafwShared::instance();
            shared->initTracking(registry);
            renderer = registry->renderer("mafw_gst_renderer");
            QObject::connect(renderer,
                    SIGNAL(metadataChanged(QString,QList<QVariant>)),
                    this,
                    SLOT(metadataChanged(QString,QList<QVariant>)));
        }

    private slots:
        void metadataChanged(QString key, QList<QVariant> values) {
            if (key == "title") {
                title = values[0].toString();
                //qDebug() << "current title: " << title;
            } else if (key == "artist") {
                artist = values[0].toString();
                //qDebug() << "current artist: " << artist;
            } else if (key == "audio-codec") {
                emit songChanged(title, artist);
            }
            //qDebug() << __FUNCTION__ << key << values;
        }

    signals:
        void songChanged(QString title, QString artist);

    private:
        MafwRegistry *registry;
        MafwRenderer *renderer;

        QString title;
        QString artist;
};

#endif /* MAFW_METADATA_LISTENER_H */
