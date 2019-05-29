#ifndef INDEPINFOTABWIDGET_H
#define INDEPINFOTABWIDGET_H

#include <QTabWidget>
#include "userinfodisplay.h"

class IndepInfoTabWidget : public QTabWidget {
    Q_OBJECT
  public:
    explicit IndepInfoTabWidget(QWidget *parent = nullptr);
  private:
    UserInfoDisplay *userMemInfo;
    UserInfoDisplay *userIndepBalanInfo;
    UserInfoDisplay *userBalanInfo;
    UserInfoDisplay *userAccuInfo;
    UserInfoDisplay *userOrderInfo;
    UserInfoDisplay *userAcctMakeInfo;
    UserInfoDisplay *userAccuCombineInfo;
    UserInfoDisplay *userOfferAccuInfo;
    UserInfoDisplay *userAccuOutNetInfo;
    UserInfoDisplay *userRedisDuplicateInfo;
    UserInfoDisplay *userPlcaIndepLogInfo;
    UserInfoDisplay *hostCmdInfo;

};

#endif // INDEPINFOTABWIDGET_H
