#ifndef DIALOGSTATUS_H
#define DIALOGSTATUS_H

#include <QDialog>
#include "peer.h"
#include "dialog.h"

namespace Ui {
class DialogStatus;
}

class DialogStatus : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStatus(QWidget *parent = 0, Peer *mainPeer=nullptr);
    ~DialogStatus();

    void updateChordWidget(Peer *peer);

private:
    Ui::DialogStatus *ui;
    Peer *peerStatus;
};

#endif // DIALOGSTATUS_H
