#include "dialogstatus.h"
#include "ui_dialogstatus.h"

DialogStatus::DialogStatus(QWidget *parent, Peer *mainPeer) :QDialog(parent), ui(new Ui::DialogStatus),  peerStatus(mainPeer)
{
    ui->setupUi(this);

    ui->lineEditLocal->setText(peerStatus->getGuid().toString().append("  :  ").append(peerStatus->getLocalIP().toString()).append("  :  ").append( QString::number(peerStatus->getLocalPort()))  );
    ui->lineEditPredecessor->setText(peerStatus->getPredecessorGuid().toString().append("  :  ").append(peerStatus->getPredecessorIP().toString()).append("  :  ").append(QString::number(peerStatus->getPredecessorPort())));
    ui->lineEditSuccessor->setText(peerStatus->getSuccessorGuid().toString().append("  :  ").append(peerStatus->getSuccessorIP().toString()).append("  :  ").append(QString::number(peerStatus->getSuccessorPort())));
    ui->lineEditAuxiliary->setText(peerStatus->getAuxiliaryGuid().toString().append("  :  ").append(peerStatus->getAuxiliaryIP().toString()).append("  :  ").append(QString::number(peerStatus->getAuxiliaryPort())));
}

DialogStatus::~DialogStatus()
{
    delete ui;
}

void DialogStatus::updateChordWidget(Peer *peer)
{
    ui->lineEditLocal->setText(peer->getGuid().toString().append("  :  ").append(peer->getLocalIP().toString()).append("  :  ").append( QString::number(peer->getLocalPort()))  );
    ui->lineEditPredecessor->setText(peer->getPredecessorGuid().toString().append("  :  ").append(peer->getPredecessorIP().toString()).append("  :  ").append(QString::number(peer->getPredecessorPort())));
    ui->lineEditSuccessor->setText(peer->getSuccessorGuid().toString().append("  :  ").append(peer->getSuccessorIP().toString()).append("  :  ").append(QString::number(peer->getSuccessorPort())));
    ui->lineEditAuxiliary->setText(peer->getAuxiliaryGuid().toString().append("  :  ").append(peer->getAuxiliaryIP().toString()).append("  :  ").append(QString::number(peer->getAuxiliaryPort())));
}
