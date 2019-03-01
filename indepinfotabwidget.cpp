#include "indepinfotabwidget.h"

IndepInfoTabWidget::IndepInfoTabWidget(QWidget *parent) :
    QTabWidget(parent) {
    userMemInfo = new UserInfoDisplay(User_Data_Display);
    userIndepBalanInfo = new UserInfoDisplay(User_Indep_Balance_Display);
    userAccuInfo = new UserInfoDisplay(User_Accu_Display);
    userAccuCombineInfo = new UserInfoDisplay(User_Accu_Combine_Display);
    userAcctMakeInfo = new UserInfoDisplay(User_Acct_Make_Display);
    userOrderInfo = new UserInfoDisplay(User_Order_Display);
    userAccuOutNetInfo = new UserInfoDisplay(User_Accu_Out_Net_Display);
    userRedisDuplicateInfo = new UserInfoDisplay(User_Redis_Indep_Display);
    userPlcaIndepLogInfo = new UserInfoDisplay(User_Indep_Log_Display);
    userBalanInfo = new UserInfoDisplay(User_Balance_Display);

    addTab(userMemInfo, "用户资料信息");
    addTab(userAccuInfo, "用户累积量信息");
    addTab(userBalanInfo, "用户余额信息");
    addTab(userIndepBalanInfo, "用户信控余额信息");
    addTab(userAccuCombineInfo, "用户累积量合并组信息");
    addTab(userAccuOutNetInfo, "用户断网累积量信息");
    addTab(userAcctMakeInfo, "用户账务触发信息");
    addTab(userRedisDuplicateInfo, "用户信控REDIS信息");
    addTab(userPlcaIndepLogInfo, "用户信控日志信息");
    addTab(userOrderInfo, "用户信控工单信息");
}
