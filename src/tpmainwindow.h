#ifndef TPMAINWINDOW_H
#define TPMAINWINDOW_H

#include <QMainWindow>

#include <Widgets/TpBookmarkDock>
#include <Widgets/TpDocumentDock>
#include <Widgets/TpFileDock>
#include <Widgets/TpFindDock>
#include <Widgets/TpFindInFilesDock>
#include <Widgets/TpFindToolBar>
#include <TpMenuBar>
#include <TpStackedWidget>
#include <TpStatusBar>

QT_BEGIN_NAMESPACE

class QTreeWidgetItem;

QT_END_NAMESPACE

TP_NAMESPACE

class TpMessageConfirmClose;
class TpTabWidget;

class TpMainWindow : public QMainWindow
{
    Q_OBJECT

    friend class TpDialogOpenDir;
    friend class TpDocumentView;
    friend class TpEditor;
    friend class TpFindContainer;
    friend class TpFindToolBar;
    friend class TpOpenAssistant;
    friend class TpSaveAssistant;
    friend class TpSaveCopyAssistant;
    friend class TpTabSplitter;
    friend class TpTabWidget;

public:
    TpMainWindow(bool create = false, bool open = false, QWidget *parent = nullptr);
    ~TpMainWindow();

public:
    Languages currentLexer() const;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onAppMessageReceived(int, QByteArray message);

    void onAction_F_N_T(bool);
    void onAction_F_N_W(bool);
    void onAction_F_O_T(bool);
    void onAction_F_O_W(bool);
    void onAction_F_R(bool);
    void onAction_F_R_C(bool);
    void onAction_F_R_O(bool);
    void onAction_F_R_L(bool);
    void onAction_F_T_F(bool);
    void onAction_F_T_C(bool);
    void onAction_F_T_T(bool);
    void onAction_F_E(bool);
    void onAction_F_D(bool);
    void onAction_F_W(bool);
    void onAction_F_B_R(bool);
    void onAction_F_B_D(bool);
    void onAction_F_B_F(bool);
    void onAction_F_B_A(bool);
    void onAction_F_B_N(bool);
    bool onAction_F_S(bool);
    bool onAction_F_A(bool);
    bool onAction_F_Y(bool);
    void onAction_F_d(bool);
    int onAction_F_C(bool);
    void onAction_F_L(bool);
    void onAction_F_p(bool);
    void onAction_F_M_B(bool);
    void onAction_F_M_L(bool);
    void onAction_F_M_R(bool);
    void onAction_F_M_U(bool);
    void onAction_F_Q(bool);
    void onAction_E_U(bool);
    void onAction_E_R(bool);
    void onAction_E_C(bool);
    void onAction_E_O(bool);
    void onAction_E_P(bool);
    void onAction_E_D_D(bool);
    void onAction_E_D_B(bool);
    void onAction_E_D_I(bool);
    void onAction_E_D_L(bool);
    void onAction_E_D_R(bool);
    void onAction_E_D_E(bool);
    void onAction_E_D_N(bool);
    void onAction_E_D_G(bool);
    void onAction_E_M_A(bool);
    void onAction_E_M_B(bool);
    void onAction_E_M_C(bool);
    void onAction_E_M_D(bool);
    void onAction_E_M_E(bool);
    void onAction_E_M_F(bool);
    void onAction_E_M_G(bool);
    void onAction_E_M_H(bool);
    void onAction_E_M_I(bool);
    void onAction_E_M_J(bool);
    void onAction_E_M_K(bool);
    void onAction_E_M_L(bool);
    void onAction_E_M_M(bool);
    void onAction_E_M_N(bool);
    void onAction_E_M_O(bool);
    void onAction_E_M_P(bool);
    void onAction_E_M_Q(bool);
    void onAction_E_M_R(bool);
    void onAction_E_M_S(bool);
    void onAction_E_M_T(bool);
    void onAction_E_M_U(bool);
    void onAction_E_M_V(bool);
    void onAction_E_M_W(bool);
    void onAction_E_M_X(bool);
    void onAction_E_M_Y(bool);
    void onAction_E_M_Z(bool);
    void onAction_E_S_A(bool);
    void onAction_E_S_B(bool);
    void onAction_E_S_C(bool);
    void onAction_E_S_D(bool);
    void onAction_E_S_E(bool);
    void onAction_E_S_F(bool);
    void onAction_E_S_G(bool);
    void onAction_E_S_H(bool);
    void onAction_E_S_I(bool);
    void onAction_E_S_J(bool);
    void onAction_E_S_K(bool);
    void onAction_E_S_L(bool);
    void onAction_E_S_M(bool);
    void onAction_E_S_N(bool);
    void onAction_E_S_O(bool);
    void onAction_E_S_P(bool);
    void onAction_E_S_Q(bool);
    void onAction_E_S_R(bool);
    void onAction_E_S_S(bool);
    void onAction_E_S_T(bool);
    void onAction_E_S_U(bool);
    void onAction_E_S_V(bool);
    void onAction_E_S_W(bool);
    void onAction_E_S_X(bool);
    void onAction_E_S_Y(bool);
    void onAction_E_S_Z(bool);
    void onAction_E_S_0(bool);
    void onAction_E_S_1(bool);
    void onAction_E_S_2(bool);
    void onAction_E_S_3(bool);
    void onAction_E_S_4(bool);
    void onAction_E_S_5(bool);
    void onAction_E_S_6(bool);
    void onAction_E_S_7(bool);
    void onAction_E_S_8(bool);
    void onAction_E_S_9(bool);
    void onAction_E_I_I(bool);
    void onAction_E_I_D(bool);
    void onAction_E_L_D(bool);
    void onAction_E_L_C(bool);
    void onAction_E_L_O(bool);
    void onAction_E_L_T(bool);
    void onAction_E_L_U(bool);
    void onAction_E_L_W(bool);
    void onAction_E_A_L(bool);
    void onAction_E_A_S(bool);
    void onAction_E_G(bool);
    void onAction_E_E_F(bool);
    void onAction_E_E_N(bool);
    void onAction_E_E_P(bool);
    void onAction_E_E_X(bool);
    void onAction_E_E_U(bool);
    void onAction_E_E_L(bool);
    void onAction_E_E_M(bool);
    void onAction_E_E_S(bool);
    void onAction_E_B_T(bool);
    void onAction_E_B_N(bool);
    void onAction_E_B_P(bool);
    void onAction_E_B_C(bool);
    void onAction_E_B_O(bool);
    void onAction_E_B_R(bool);
    QString onAction_E_B_A(bool);
    QString onAction_E_B_h(bool);
    void onAction_E_B_I(bool);
    void onAction_V_A(bool isChecked);
    void onAction_V_F(bool isChecked);
    void onAction_V_h(bool isChecked);
    void onAction_V_Y_S(bool isChecked);
    void onAction_V_Y_A(bool isChecked);
    void onAction_V_Y_T(bool isChecked);
    void onAction_V_Y_N(bool isChecked);
    void onAction_V_Y_W(bool isChecked);
    void onAction_V_Y_I(bool isChecked);
    void onAction_V_Z_I(bool);
    void onAction_V_Z_O(bool);
    void onAction_V_Z_T(bool);
    void onAction_V_T_1(bool);
    void onAction_V_T_2(bool);
    void onAction_V_T_3(bool);
    void onAction_V_T_4(bool);
    void onAction_V_T_5(bool);
    void onAction_V_T_6(bool);
    void onAction_V_T_7(bool);
    void onAction_V_T_8(bool);
    void onAction_V_T_9(bool);
    void onAction_V_T_0(bool);
    void onAction_V_T_L(bool);
    void onAction_V_T_N(bool);
    void onAction_V_T_F(bool);
    void onAction_V_T_P(bool);
    void onAction_V_T_M(bool);
    void onAction_V_T_R(bool);
    void onAction_V_T_S(bool);
    void onAction_V_T_T(bool);
    void onAction_V_W_N(bool);
    void onAction_V_W_W(bool);
    void onAction_V_W_C(bool);
    void onAction_V_W_H(bool);
    void onAction_V_L_M(bool);
    void onAction_V_I(bool isChecked);
    void onAction_V_C_D(bool);
    void onAction_V_C_U(bool);
    void onAction_V_C_S(bool);
    void onAction_V_C_E(bool);
    void onAction_V_C_V(bool);
    void onAction_V_O_H(bool);
    void onAction_V_O_A(bool);
    void onAction_V_O_C(bool);
    void onAction_V_O_E(bool);
    void onAction_V_O_S_D(bool);
    void onAction_V_O_S_P(bool);
    void onAction_V_O_S_C(bool);
    void onAction_V_O_S_B(bool);
    void onAction_V_O_S_T(bool);
    void onAction_V_O_S_X(bool);
    void onAction_I_F(bool);
    void onAction_I_T(bool);
    void onAction_I_V(bool);
    void onAction_I_N_W(bool);
    void onAction_I_N_M(bool);
    void onAction_I_N_U(bool);
    void onAction_I_D_D(bool);
    void onAction_I_D_T(bool);
    void onAction_I_D_A(bool);
    void onAction_O_L_p(bool);
    void onAction_O_L_A_C(bool);
    void onAction_O_L_A_S(bool);
    void onAction_O_L_A_A(bool);
    void onAction_O_L_B_B(bool);
    void onAction_O_L_B_T(bool);
    void onAction_O_L_B_S(bool);
    void onAction_O_L_B_A(bool);
    void onAction_O_L_B_F(bool);
    void onAction_O_L_C_C(bool);
    void onAction_O_L_C_pl(bool);
    void onAction_O_L_C_p(bool);
    void onAction_O_L_C_s(bool);
    void onAction_O_L_C_M(bool);
    void onAction_O_L_C_O(bool);
    void onAction_O_L_C_S(bool);
    void onAction_O_L_D_D(bool);
    void onAction_O_L_D_I(bool);
    void onAction_O_L_F_F(bool);
    void onAction_O_L_F_7(bool);
    void onAction_O_L_G_G(bool);
    void onAction_O_L_H_H(bool);
    void onAction_O_L_H_T(bool);
    void onAction_O_L_I_I(bool);
    void onAction_O_L_I_H(bool);
    void onAction_O_L_J_J(bool);
    void onAction_O_L_J_S(bool);
    void onAction_O_L_J_O(bool);
    void onAction_O_L_L_T(bool);
    void onAction_O_L_L_L(bool);
    void onAction_O_L_M_F(bool);
    void onAction_O_L_M_D(bool);
    void onAction_O_L_M_M(bool);
    void onAction_O_L_M_L(bool);
    void onAction_O_L_N_N(bool);
    void onAction_O_L_O_O(bool);
    void onAction_O_L_P_P(bool);
    void onAction_O_L_P_E(bool);
    void onAction_O_L_P_H(bool);
    void onAction_O_L_P_O(bool);
    void onAction_O_L_P_S(bool);
    void onAction_O_L_P_V(bool);
    void onAction_O_L_P_R(bool);
    void onAction_O_L_P_2(bool);
    void onAction_O_L_P_3(bool);
    void onAction_O_L_P_X(bool);
    void onAction_O_L_Q_Q(bool);
    void onAction_O_L_Q_S(bool);
    void onAction_O_L_Q_U(bool);
    void onAction_O_L_R_R(bool);
    void onAction_O_L_S_S(bool);
    void onAction_O_L_S_Q(bool);
    void onAction_O_L_S_R(bool);
    void onAction_O_L_T_T(bool);
    void onAction_O_L_T_H(bool);
    void onAction_O_L_T_X(bool);
    void onAction_O_L_V_V(bool);
    void onAction_O_L_V_H(bool);
    void onAction_O_L_X_X(bool);
    void onAction_O_L_Y_Y(bool);
    void onAction_O_N_U(bool);
    void onAction_O_N_C(bool);
    void onAction_O_N_E(bool);
    void onAction_O_N_T(bool);
    void onAction_O_N_M(bool);
    void onAction_O_N_X(bool);
    void onAction_O_I_T(bool isChecked);
    void onAction_O_I_B(bool isChecked);
    void onAction_O_I_I(bool isChecked);
    void onAction_O_R_L(bool);
    void onAction_O_R_S(bool);
    void onAction_O_S(bool isChecked);
    void onAction_O_h(bool isChecked);
    void onAction_O_A_U(bool);
    void onAction_O_A_L(bool);
    void onAction_T_A_C(bool isChecked);
    void onAction_T_A_F(bool isChecked);
    void onAction_T_A_R(bool isChecked);
    void onAction_T_A_W_N(bool);
    void onAction_T_A_W_O(bool);
    void onAction_T_A_W_D(bool);
    void onAction_T_A_S_D(bool);
    void onAction_T_A_S_A(bool);
    void onAction_T_A_S_O(bool);
    void onAction_T_A_S_L(bool);
    void onAction_T_A_T_A(bool);
    void onAction_T_A_T_D(bool);
    void onAction_T_A_T_L(bool);
    void onAction_T_h_A(bool isChecked);
    void onAction_T_h_S_A(bool isChecked);
    void onAction_T_h_S_M(bool isChecked);
    void onAction_T_h_S_O(bool isChecked);
    void onAction_T_h_S_C(bool isChecked);
    void onAction_T_B_N(bool);
    void onAction_T_B_S(bool);
    void onAction_T_B_B(bool);
    void onAction_T_C_T(bool);
    void onAction_T_C_P_B(bool);
    void onAction_T_C_P_A(bool);
    void onAction_T_C_S_D(bool);
    void onAction_T_C_S_N(bool);
    void onAction_T_C_S_A(bool);
    void onAction_T_C_S_W(bool);
    void onAction_T_E_N(bool);
    void onAction_T_E_L(bool);
    void onAction_T_E_B(bool);
    void onAction_T_V_S(bool isChecked);
    void onAction_T_V_M(bool isChecked);
    void onAction_T_V_A(bool isChecked);
    void onAction_T_V_P(bool isChecked);
    void onAction_T_V_V_D(bool);
    void onAction_T_V_V_R(bool);
    void onAction_T_V_V_U(bool);
    void onAction_T_V_V_W(bool);
    void onAction_T_V_R_C(bool);
    void onAction_T_V_R_A(bool);
    void onAction_T_V_C_O(bool);
    void onAction_T_V_C_N(bool);
    void onAction_T_V_C_W(bool);
    void onAction_T_S_R_N(bool);
    void onAction_T_S_R_S(bool);
    void onAction_T_S_R_P(bool);
    void onAction_T_S_R_pl(bool);
    void onAction_T_S_C(bool isChecked);
    void onAction_T_S_O(bool isChecked);
    void onAction_T_S_W(bool isChecked);
    void onAction_T_S_S(bool isChecked);
    void onAction_T_S_G(bool isChecked);
    void onAction_T_V_L(bool isChecked);
    void onAction_T_W_I_P(bool);
    void onAction_T_W_I_S(bool);
    void onAction_T_W_I_I(bool);
    void onAction_T_W_I_D(bool);
    void onAction_T_W_S_N(bool);
    void onAction_T_W_S_T(bool);
    void onAction_T_W_S_B(bool);
    void onAction_T_W_S_M(bool);
    void onAction_T_W_E_N(bool);
    void onAction_T_W_E_T(bool);
    void onAction_T_W_E_B(bool);
    void onAction_T_W_E_M(bool);
    void onAction_T_M_B(bool isChecked);
    void onAction_T_M_P_O(bool);
    void onAction_T_M_P_T(bool);
    void onAction_T_M_P_M(bool);
    void onAction_T_M_Q_D(bool);
    void onAction_T_M_Q_N(bool);
    void onAction_T_M_Q_A(bool);
    void onAction_T_M_Q_L(bool);
    void onAction_W_F(bool isChecked);
    void onAction_W_L(bool isChecked);
    void onAction_W_B(bool isChecked);
    void onAction_W_D(bool isChecked);
    void onAction_W_I(bool isChecked);

    void onEditorFileNameChanged(const QString &, const QString &);
    void onEditorCheckBoxChecked(bool);
    void onEditorSelectionChanged();
    void onEditorPositionChanged(int position, int line, int index);
    void onEditorPunctuation();

    void onTabChanged(TpTabWidget *tab, int index);
    void onTabCloseRequested(TpTabWidget *tab, int index);
    void onTabNameChanged();
    void onWrapVisualFlagChanged();

    void onFileDockVisibilityChanged(bool isVisible);
    void onFileDockDoubleClicked(const QString &path);
    void onDocumentDockVisibilityChanged(bool isVisible);
    void onDocumentDockDoubleClicked(TpTabWidget *tab, const QString &path);
    void onBookmarkDockVisibilityChanged(bool isVisible);
    void onFindDockVisibilityChanged(bool isVisible);
    void onFindInFilesDockVisibilityChanged(bool isVisible);
    void onFindInFilesDockDoubleClicked(const QString &path, int position);

    void onFindToolBarTextChanged(const QString &text);

    void onStatusBarSpinBoxTabWidthChanged(int value);
    void onStatusBarComboBoxLangIndexChanged(int index);
    void onStatusBarComboBoxNewLineIndexChanged(int index);

private:
    void clearDocumentDock(QTreeWidgetItem *item);
    void updateDocumentDock();
    void updateRecentFiles();
    void updateIncrementalSearch(const QString &text);
    void updateEditorsMap();
    void updateLexerComboBox();
    void updateNewLineComboBox();

signals:
    void wrapVisualFlagChanged();

private:
    TpMenuBar *m_menuBar;
    TpStackedWidget *m_widget;
    TpFileDock *m_fileDock;
    TpDocumentDock *m_documentDock;
    TpBookmarkDock *m_bookmarkDock;
    TpFindDock *m_findDock;
    TpFindInFilesDock *m_findInFilesDock;
    TpFindToolBar *m_findToolBar;
    TpStatusBar *m_statusBar;

private:
    TpMessageConfirmClose *m_confirmClose;
};

TP_END_NAMESPACE

#endif // TPMAINWINDOW_H
