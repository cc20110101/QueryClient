#include "userinfodisplay.h"

UserInfoDisplay::UserInfoDisplay(int flag, QWidget *parent):
    QWidget(parent) {
    m_iFlag = flag;
    m_bIsConnect = false;
    m_sNatsInfo.clear();

    m_cbOrgId = new QComboBox;
    m_cbOrgId->setEditable(true);

    QHBoxLayout *hBox2 = new QHBoxLayout;
    QHBoxLayout *hBox1 = new QHBoxLayout;
    hBox1->addWidget(m_lbServId = new QLabel("用户标识:"), 2);
    hBox1->addWidget(m_leServId = new QLineEdit, 3);
    hBox1->addStretch(1);
    hBox1->addWidget(m_lbAccNum = new QLabel("用户号码:"), 2);
    hBox1->addWidget(m_leAccNbr = new QLineEdit, 3);
    hBox1->addStretch(1);
    hBox1->addWidget(m_lbAcctId = new QLabel("用户账户:"), 2);
    hBox1->addWidget(m_leAcctId = new QLineEdit, 3);
    if(m_iFlag != User_Indep_Log_Display)
        hBox1->addStretch(1);
    hBox1->addWidget(m_lbQueryTime = new QLabel("查询时间:"), 2);
    hBox1->addWidget(m_leQueryTime = new QLineEdit, 3);

    m_leServId->setPlaceholderText("ServId");
    m_leAccNbr->setPlaceholderText("AccNbr");
    m_leAcctId->setPlaceholderText("AcctId");
    m_leQueryTime->setPlaceholderText("QueryTime");

    if(flag == User_Order_Display) {
        m_leQueryTime->setVisible(false);
        m_lbQueryTime->setVisible(false);

        m_dteStartTime = new QDateTimeEdit();
        m_dteStopTime = new QDateTimeEdit();
        m_dteStartTime->setCalendarPopup(true);
        m_dteStopTime->setCalendarPopup(true);
        m_dteStartTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        m_dteStopTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        m_dteStartTime->setDateTime(QDateTime::currentDateTime().addMonths(-1));
        //QDateTime endTime(QDate(3000, 1, 1), QTime(0, 0, 0));
        m_dteStopTime->setDateTime(QDateTime::currentDateTime());

        hBox1->addStretch(16);
        hBox2->addWidget(new QLabel("时间范围:"), 2);
        hBox2->addWidget(m_dteStartTime, 3);
        hBox2->addWidget(m_dteStopTime, 3);
        hBox2->addStretch(1);

        m_cbActionId = new QComboBox;
        m_cbActionId->setEditable(true);

        hBox2->addWidget(new QLabel("动作选择:"), 2);
        hBox2->addWidget(m_cbActionId,3);
        hBox2->addStretch(1);
        hBox2->addWidget(new QLabel("地市选择:"), 2);
        hBox2->addWidget(m_cbOrgId,3);
        hBox2->addStretch(3);
    } else if(flag == User_Acct_Make_Display) {
        m_leQueryTime->setVisible(false);
        m_lbQueryTime->setVisible(false);

        m_dteStartTime = new QDateTimeEdit();
        m_dteStopTime = new QDateTimeEdit();
        m_dteStartTime->setCalendarPopup(true);
        m_dteStopTime->setCalendarPopup(true);
        m_dteStartTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        m_dteStopTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        m_dteStartTime->setDateTime(QDateTime::currentDateTime().addMonths(-1));
        //QDateTime endTime(QDate(3000, 1, 1), QTime(0, 0, 0));
        m_dteStopTime->setDateTime(QDateTime::currentDateTime());

        hBox1->addWidget(new QLabel("时间范围:"), 1);
        hBox1->addWidget(m_dteStartTime, 2);
        hBox1->addWidget(m_dteStopTime, 2);
        hBox1->addStretch(1);
        hBox1->addWidget(new QLabel("地市选择:"), 2);
        hBox1->addWidget(m_cbOrgId);
        hBox1->addStretch(3);
    } else if(flag == User_Redis_Queue_Display) {
        m_leQueryTime->setVisible(false);
        m_leAcctId->setVisible(false);
        m_leServId->setVisible(false);

        m_lbServId->setVisible(false);
        m_lbAcctId->setVisible(false);
        m_lbQueryTime->setVisible(false);

        m_lbAccNum->setText("队列匹配模式");
        m_leAccNbr->setPlaceholderText("{MQ:BUFF:*}");
        m_leServId->setText("1");
        hBox1->addStretch(1);
        hBox1->addWidget(new QLabel("地市选择:"), 2);
        hBox1->addWidget(m_cbOrgId);
        hBox1->addStretch(3);
    } else if(flag == User_Redis_Indep_Display) {
        m_leQueryTime->setVisible(false);
        m_lbQueryTime->setVisible(false);
        hBox1->addWidget(new QLabel("地市选择:"), 2);
        hBox1->addWidget(m_cbOrgId);
        hBox1->addStretch(1);
    } else if(flag == User_Indep_Log_Display) {
        m_leAcctId->setVisible(false);
        m_lbAcctId->setVisible(false);
        m_leQueryTime->setVisible(false);
        m_lbQueryTime->setVisible(false);

        hBox1->addWidget(new QLabel("过滤信息:"), 2);
        hBox1->addWidget(m_leFilter = new QLineEdit, 3);
        hBox1->addStretch(1);

        hBox1->addWidget(new QLabel("流程选择:"), 2);
        m_cbActionId = new QComboBox;
        m_cbActionId->setEditable(true);
        hBox1->addWidget(m_cbActionId, 3);
        hBox1->addStretch(1);
        hBox1->addWidget(new QLabel("地市选择:"), 2);
        hBox1->addWidget(m_cbOrgId);
        hBox1->addStretch(3);
    } else {
        hBox1->addStretch(1);
        hBox1->addWidget(new QLabel("地市选择:"), 2);
        hBox1->addWidget(m_cbOrgId);
        hBox1->addStretch(3);
    }

    if(flag == User_Order_Display) {
        hBox2->addWidget(m_pbQuery = new QPushButton("查询"), 2);
        hBox2->addStretch(1);
        hBox2->addWidget(m_pbReSet = new QPushButton("重置"), 2);
        hBox2->addStretch(1);
        hBox2->addWidget(m_pbClear = new QPushButton("清屏"), 2);
    } else {
        hBox1->addWidget(m_pbQuery = new QPushButton("查询"), 2);
        hBox1->addStretch(1);
        hBox1->addWidget(m_pbReSet = new QPushButton("重置"), 2);
        hBox1->addStretch(1);
        hBox1->addWidget(m_pbClear = new QPushButton("清屏"), 2);
    }

    QFont font;
    font.setPointSize(10);
    m_tbDisplay = new QTextBrowser;
    m_tbDisplay->setFont(font);
    QVBoxLayout *vBox = new QVBoxLayout(this);

    vBox->addLayout(hBox1);
    vBox->addLayout(hBox2);
    vBox->addWidget(m_tbDisplay);

    connect(m_pbQuery, SIGNAL(clicked()), this, SLOT(onQuery()));
    connect(m_pbReSet, SIGNAL(clicked()), this, SLOT(onReSet()));
    connect(m_pbClear, SIGNAL(clicked()), this, SLOT(onClear()));
    connect(m_tbDisplay, SIGNAL(textChanged()), this, SLOT(autoScroll()));

    QObject::connect(&m_natsClient,
                     &Nats::Client::error, [this](const QString & error) {
        m_sNatsInfo = error;
        m_bIsConnect = false;
    });

    m_qTimeer.setInterval(10000); //3s
    m_qTimeer.setSingleShot(true);
    m_bTimeout = false;
    m_bAppendStr = false;
    connect(&m_qTimeer, &QTimer::timeout, [this]() // 超时处理
    {
                m_eventLoop.quit();
                m_bTimeout = true;
            });

    m_bJsonDisplay = true;
    if(m_iFlag == User_Data_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户内存资料信息");
    } else if(m_iFlag == User_Balance_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户余额信息");
    }  else if(m_iFlag == User_Indep_Balance_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户信控余额信息");
    } else if(m_iFlag == User_Accu_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户累积量信息");
    } else if(m_iFlag == User_Order_Display) {
        hBox2->addStretch(1);
        setStatusTip("查询用户信控工单信息");
        ActionId.clear();
        ActionId.insert(0, "0|所有工单");
        if(connectNats()) {
            m_bTimeout = false;
            m_sMsgInfo =
                    QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                            "\"ServId\":\"%4\"}").
                    arg(User_Indep_Action_Init).arg(m_sNatsRecvTopic).
                    arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).arg(1);
            m_natsClient.publish(m_nNtsSendTopic, m_sMsgInfo);
            m_qTimeer.start();
            m_eventLoop.exec();
            m_bAppendStr = true;
            if(!m_bTimeout) {
                int iIndex = 0;
                QStringList qStrList = m_sMsg.split(";", QString::SkipEmptyParts);
                foreach(QString value, qStrList) {
                    iIndex = value.indexOf("|");
                    if(iIndex == -1) {
                        continue;
                    }
                    ActionId.insert(value.mid(0,iIndex).toInt(),value);
                }
            } else {
                QMessageBox::about(this, "提示", "初始化信控工单超时");
                if(!m_natsClient.isOpen())
                    disConnectNats();
            }
            m_qTimeer.stop();
        } else {
            QMessageBox::about(this, "提示", QString("初始化信控工单失败:") + m_sNatsInfo);
        }
        foreach(QString value, ActionId)
            m_cbActionId->addItem(value);
    } else if(m_iFlag == User_Acct_Make_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户账务触发信息");
    } else if(m_iFlag == User_Accu_Out_Net_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户断网累积量信息");
    } else if(m_iFlag == User_Accu_Combine_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户累积量合并组信息");
    } else if(m_iFlag == User_Net_Slow_Speed_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户达量降速会话信息");
    } else if(m_iFlag == User_Redis_Queue_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询达量降速REDIS队列信息");
    } else if(m_iFlag == User_Redis_Indep_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户信控REDIS数据信息");
    } else if(m_iFlag == User_Indep_Log_Display) {
        hBox1->addStretch(1);
        setStatusTip("查询用户信控日志数据信息");
        m_bJsonDisplay = false;
        ActionId.clear();
        ActionId.insert(0, "0|所有流程");
        if(connectNats()) {
            m_bTimeout = false;
            m_sMsgInfo =
                    QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                            "\"ServId\":\"%4\"}").
                    arg(User_Indep_Flow_Init).arg(m_sNatsRecvTopic).
                    arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).arg(1);
            m_natsClient.publish(m_nNtsSendTopic, m_sMsgInfo);
            m_qTimeer.start();
            m_eventLoop.exec();
            m_bAppendStr = true;
            if(!m_bTimeout) {
                int iIndex = 0;
                qDebug() <<"1--" <<m_sMsg;
                QStringList qStrList = m_sMsg.split(";", QString::SkipEmptyParts);
                foreach(QString value, qStrList) {
                    iIndex = value.indexOf("|");
                    if(iIndex == -1) {
                        continue;
                    }
                    ActionId.insert(value.mid(0,iIndex).toInt(),value);
                }
            } else {
                QMessageBox::about(this, "提示", "初始化信控日志超时");
                if(!m_natsClient.isOpen())
                    disConnectNats();
            }
            m_qTimeer.stop();
        } else {
            QMessageBox::about(this, "提示", QString("初始化信控日志失败:") + m_sNatsInfo);
        }
        foreach(QString value, ActionId)
            m_cbActionId->addItem(value);
        if(ActionId.size() > 1)
            m_cbActionId->setCurrentIndex(1);
    } else {
        setStatusTip("未识别查询标识");
    }

    OrgId.clear();
    if(m_iFlag == User_Redis_Queue_Display)
        getOrgAreaId(OrgId);
    else
        getOrgId(OrgId);
    foreach(QString value, OrgId)
        m_cbOrgId->addItem(value);
}

UserInfoDisplay::~UserInfoDisplay() {
    disConnectNats();
}

void UserInfoDisplay::disConnectNats() {
    m_natsClient.unsubscribe(m_ullSid);
    m_natsClient.disconnect();
    m_bIsConnect = false;
}

void UserInfoDisplay::onQuery() {

    m_bTimeout = false;
    m_bAppendStr = false;
    m_sServID = m_leServId->text().trimmed();
    m_sAcctID = m_leAcctId->text().trimmed();
    m_sAccNbr = m_leAccNbr->text().trimmed();
    m_sQueryTime = m_leQueryTime->text().trimmed();
    m_sOrgId = QString("%1").arg(OrgId.key(m_cbOrgId->currentText(), 0));

    if(m_sServID.isEmpty() && m_sAcctID.isEmpty() && m_sAccNbr.isEmpty()) {
        QMessageBox::about(this, "提示", "用户标识或用户账户或用户号码不可都为空");
        return;
    }

    if(m_sQueryTime.isEmpty()) {
        m_sQueryTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    }

    if(m_sAccNbr.isEmpty() && m_sOrgId == "0") {
        QMessageBox::about(this, "提示", "号码和地市不可同时为空");
        return;
    }

    if(!connectNats()) {
        QMessageBox::about(this, "提示", m_sNatsInfo);
        return;
    }

    m_tbDisplay->append("##################### The query information is as follows #####################");
    if(m_iFlag == User_Order_Display) {
        m_sRes1 = m_dteStartTime->dateTime().toString("yyyyMMddhhmmss");
        m_sRes2 = m_dteStopTime->dateTime().toString("yyyyMMddhhmmss");
        m_sRes3 = QString("%1").arg(ActionId.key(m_cbActionId->currentText(), 0));
        m_sMsgInfo =
                QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                        "\"ServId\":\"%4\",\"AccNbr\":\"%5\",\"AcctId\":\"%6\",\"Res1\":\"%7\","
                        "\"Res2\":\"%8\",\"Res3\":\"%9\",\"OrgId\":\"%10\"}").
                arg(m_iFlag).arg(m_sNatsRecvTopic).arg(m_sQueryTime).arg(m_sServID).
                arg(m_sAccNbr).arg(m_sAcctID).arg(m_sRes1).arg(m_sRes2).arg(m_sRes3)
                .arg(m_sOrgId);
    } else if(m_iFlag == User_Acct_Make_Display) {
        m_sRes1 = m_dteStartTime->dateTime().toString("yyyyMMddhhmmss");
        m_sRes2 = m_dteStopTime->dateTime().toString("yyyyMMddhhmmss");
        m_sMsgInfo =
                QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                        "\"ServId\":\"%4\",\"AccNbr\":\"%5\",\"AcctId\":\"%6\",\"Res1\":\"%7\","
                        "\"Res2\":\"%8\",\"OrgId\":\"%9\"}").
                arg(m_iFlag).arg(m_sNatsRecvTopic).arg(m_sQueryTime).arg(m_sServID).
                arg(m_sAccNbr).arg(m_sAcctID).arg(m_sRes1).arg(m_sRes2).arg(m_sOrgId);
    } else if(m_iFlag == User_Redis_Queue_Display) {
        if(m_sAccNbr.isEmpty()) {
            m_sAccNbr = "{MQ:BUFF:*}";
        }
        m_sMsgInfo =
                QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                        "\"Res1\":\"%4\",\"ServId\":\"%5\",\"OrgId\":\"%6\"}").
                arg(m_iFlag).arg(m_sNatsRecvTopic).arg(m_sQueryTime).arg(m_sAccNbr).arg(
                    m_sServID).arg(m_sOrgId);
    } else if(m_iFlag == User_Indep_Log_Display) {
        m_sRes1 = m_leFilter->text().trimmed();
        m_sRes2 = QString("%1").arg(ActionId.key(m_cbActionId->currentText(), 0));
        m_sMsgInfo =
                QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                        "\"ServId\":\"%4\",\"AccNbr\":\"%5\",\"Res1\":\"%6\","
                        "\"Res2\":\"%7\",\"OrgId\":\"%8\"}").
                arg(m_iFlag).arg(m_sNatsRecvTopic).arg(m_sQueryTime).arg(m_sServID).
                arg(m_sAccNbr).arg(m_sRes1).arg(m_sRes2).arg(m_sOrgId);
    } else {
        m_sMsgInfo =
                QString("{\"QueryFlag\":\"%1\",\"ReplySubject\":\"%2\",\"RequestTime\":\"%3\","
                        "\"ServId\":\"%4\",\"AccNbr\":\"%5\",\"AcctId\":\"%6\",\"OrgId\":\"%7\"}").
                arg(m_iFlag).arg(m_sNatsRecvTopic).arg(m_sQueryTime).arg(m_sServID).arg(
                    m_sAccNbr).arg(m_sAcctID).arg(m_sOrgId);
    }
    m_natsClient.publish(m_nNtsSendTopic, m_sMsgInfo);

    m_qTimeer.start();
    m_eventLoop.exec();
    m_bAppendStr = true;
    if(m_bTimeout) {
        m_tbDisplay->append("Ten seconds have passed");
        if(!m_natsClient.isOpen())
            disConnectNats();
    } else {
        setDisPlay();
    }
    m_qTimeer.stop();
}

void UserInfoDisplay::autoScroll() {
    m_tbDisplay->moveCursor(QTextCursor::End);
}

void UserInfoDisplay::onReSet() {

    m_leServId->clear();
    m_leAccNbr->clear();
    m_leAcctId->clear();
    if(m_iFlag == User_Order_Display ||
            m_iFlag == User_Acct_Make_Display) {
        m_dteStartTime->setDateTime(QDateTime::currentDateTime().addMonths(-1));
        m_dteStopTime->setDateTime(QDateTime::currentDateTime());
    }

    m_natsClient.unsubscribe(m_ullSid);
    m_natsClient.disconnect();
    m_bIsConnect = false;
}

void UserInfoDisplay::onClear() {
    m_tbDisplay->clear();
}

void UserInfoDisplay::setDisPlay() {
    if(m_bJsonDisplay) {
        m_jdJsonDocument = QJsonDocument::fromJson(m_sMsg.toUtf8(), &m_jpError);
        if(m_jpError.error == QJsonParseError::NoError) {
            m_tbDisplay->append(QString(m_jdJsonDocument.toJson(
                                            QJsonDocument::JsonFormat::Indented)));
        } else {
            m_tbDisplay->append(m_jpError.errorString());
        }
    } else {
        m_tbDisplay->append(m_sMsg);
    }
}

bool UserInfoDisplay::connectNats() {

    if(m_bIsConnect) {
        m_sNatsInfo = "已成功连接Nats集群";
        return true;
    }

    // 初始化配置
    QString sPath = QCoreApplication::applicationDirPath() + "/" + IniFileName;
    //settings.setPath(QSettings::IniFormat, QSettings::SystemScope, sPath);
    QSettings settings(sPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    // 读取上次登入信息
    QString lastLable = settings.value("natsLastLable").toString();
    int size = settings.beginReadArray("natsinfo");
    natsLableName.clear();
    natsAddr.clear();
    natsPort.clear();
    natsUser.clear();
    natsPasswd.clear();
    m_nNtsSendTopic.clear();
    for(int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        natsLableName = settings.value("natsLableName").toString().trimmed();
        if(natsLableName == lastLable) {
            natsAddr = settings.value("natsAddr").toString().trimmed();
            natsPort = settings.value("natsPort").toString().trimmed();
            natsUser = settings.value("natsUser").toString().trimmed();
            natsPasswd = settings.value("natsPasswd").toString().trimmed();
            m_nNtsSendTopic = settings.value("natsSendTopic").toString().trimmed();
            break;
        }
    }
    settings.endArray();

    if(natsAddr.isEmpty()) {
        m_sNatsInfo = "错误,Nats连接地址未配置";
        return m_bIsConnect;
    }
    if(natsPort.isEmpty()) {
        m_sNatsInfo = "错误,Nats连接端口未配置";
        return m_bIsConnect;
    }
    if(m_nNtsSendTopic.isEmpty()) {
        m_sNatsInfo = "错误,Nats发送主题未配置";
        return m_bIsConnect;
    }

    m_natsClient.setdebugmode(false);
    m_natsOptions.user = natsUser;
    m_natsOptions.pass = natsPasswd;
    if(!m_natsClient.connectSync(natsAddr, natsPort.toUShort(), m_natsOptions)) {
        return m_bIsConnect;
    }

    m_sNatsRecvTopic = QString("PlcaToolRecvNT.F%1.T%2").
            arg(m_iFlag).arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz"));
    m_ullSid = m_natsClient.subscribe(m_sNatsRecvTopic,
                                      [this](QString message,
                                      QString reply_inbox,
                                      QString subject) {
            m_sMsg = message;
            if(m_bAppendStr)
                setDisPlay();
            m_eventLoop.quit();
            subject = reply_inbox; // 消除未使用警告
});

    m_bIsConnect = true;
    return m_bIsConnect;
}

void UserInfoDisplay::getOrgAreaId(QMap<int, QString> &OrgId) {
    OrgId.insert(100501,"100501|深圳地市");
    OrgId.insert(100512,"100512|东莞地市");
    OrgId.insert(100513,"100513|佛山地市");
    OrgId.insert(100514,"100514|广州地市");
}

void UserInfoDisplay::getOrgId(QMap<int, QString> &OrgId) {
    OrgId.insert(0,"0|号码求取");
    OrgId.insert(100500,"100500|韶关地市");
    OrgId.insert(100501,"100501|深圳地市");
    OrgId.insert(100503,"100503|清远地市");
    OrgId.insert(100504,"100504|汕头地市");
    OrgId.insert(100505,"100505|汕尾地市");
    OrgId.insert(100506,"100506|肇庆地市");
    OrgId.insert(100507,"100507|中山地市");
    OrgId.insert(100508,"100508|珠海地市");
    OrgId.insert(100509,"100509|阳江地市");
    OrgId.insert(100510,"100510|云浮地市");
    OrgId.insert(100511,"100511|湛江地市");
    OrgId.insert(100512,"100512|东莞地市");
    OrgId.insert(100513,"100513|佛山地市");
    OrgId.insert(100514,"100514|广州地市");
    OrgId.insert(100516,"100516|潮州地市");
    OrgId.insert(100517,"100517|揭阳地市");
    OrgId.insert(100518,"100518|茂名地市");
    OrgId.insert(100519,"100519|梅州地市");
    OrgId.insert(100520,"100520|河源地市");
    OrgId.insert(100521,"100521|惠州地市");
    OrgId.insert(100522,"100522|江门地市");
}
