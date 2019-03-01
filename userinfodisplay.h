#ifndef USERINFODISPLAY_H
#define USERINFODISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTextBrowser>
#include <QApplication>
#include <QSettings>
#include <QDateTime>
#include <QJsonDocument>
#include <QDateTimeEdit>
#include <QComboBox>
#include "define.h"
#include "natsclient.h"

class UserInfoDisplay : public QWidget {
    Q_OBJECT
  public:
    explicit UserInfoDisplay(int flag = 0, QWidget *parent = nullptr);
    ~UserInfoDisplay();

  private:
    QLabel *m_lbQueryTime;
    QLabel *m_lbServId;
    QLabel *m_lbAcctId;
    QLabel *m_lbAccNum;
    QLineEdit *m_leServId;
    QLineEdit *m_leAcctId;
    QLineEdit *m_leAccNbr;
    QLineEdit *m_leQueryTime;
    QLineEdit *m_leFilter;
    QPushButton *m_pbQuery;
    QPushButton *m_pbReSet;
    QPushButton *m_pbClear;
    QTextBrowser *m_tbDisplay;
    QDateTimeEdit *m_dteStartTime;
    QDateTimeEdit *m_dteStopTime;
    QComboBox *m_cbActionId;
    QComboBox *m_cbOrgId;

    int m_iFlag;
    bool m_bIsConnect;
    bool m_bJsonDisplay;
    QString natsAddr;
    QString natsPort;
    QString natsUser;
    QString natsPasswd;
    QString natsLableName;
    QString m_nNtsSendTopic;
    QString m_sNatsRecvTopic;
    QString m_sNatsInfo;
    QString m_sServID;
    QString m_sAcctID;
    QString m_sAccNbr;
    QString m_sMsgInfo;
    QString m_sQueryTime;
    QString m_sRes1;
    QString m_sRes2;
    QString m_sRes3;
    QString m_sOrgId;
    QString m_sMsg;
    uint64_t m_ullSid = 0;
    QJsonDocument m_jdJsonDocument;
    QJsonParseError m_jpError;
    Nats::Client m_natsClient;
    Nats::Options m_natsOptions;
    QEventLoop m_eventLoop;
    QTimer m_qTimeer;
    bool m_bTimeout;
    bool m_bAppendStr;
    QMap<int, QString> ActionId;
    QMap<int, QString> OrgId;

  private:
    bool connectNats();
    void disConnectNats();
    void setDisPlay();
    void getOrgId(QMap<int, QString> &OrgId);
    void getOrgAreaId(QMap<int, QString> &OrgId);

  signals:

  public slots:
    void onQuery();
    void onReSet();
    void onClear();
    void autoScroll();

};

#endif // USERINFODISPLAY_H
