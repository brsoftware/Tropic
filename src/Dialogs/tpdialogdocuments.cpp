#include <QKeyEvent>

#include <Dialogs/TpDialogDocuments>
#include <Views/TpDocumentsView>
#include <TpMainWindow>

TP_NAMESPACE

TpDialogDocuments::TpDialogDocuments(TpMainWindow *parent)
    : QDialog(parent),
    m_parent(parent)
{
    m_layout = new QVBoxLayout();
    m_layout->setObjectName("dialogCommands_layout");
    m_layout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_layout);
    m_lineEdit = new TpGeneralLineEdit(this);
    m_lineEdit->setObjectName("dialogCommands_lineEdit");
    m_lineEdit->setPlaceholderText(tr("Search Menu Commands"));
    m_layout->addWidget(m_lineEdit);
    m_view = new TpDocumentsView(parent->m_widget->tabs());
    m_layout->addWidget(m_view);
    m_lineEdit->setFocus();

    connect(m_lineEdit,
            &TpGeneralLineEdit::returnPressed,
            this,
            &TpDialogDocuments::onLineEditReturnPressed);
    connect(m_lineEdit,
            &TpGeneralLineEdit::textChanged,
            m_view,
            &TpDocumentsView::onLineEditTextChanged);
    connect(m_view,
            &TpDocumentsView::actionCompleted,
            this,
            &TpDialogDocuments::close);
    m_lineEdit->installEventFilter(this);
}

void TpDialogDocuments::setView(TpDocumentsView *view)
{
    m_view = view;
}

TpDocumentsView *TpDialogDocuments::view() const
{
    return m_view;
}

void TpDialogDocuments::onLineEditReturnPressed()
{
    if (TpDocumentsItem *item = static_cast<TpDocumentsItem*>(m_view->currentItem()))
    {
        m_view->onItemDoubleClicked(item, 0);
    }
}

bool TpDialogDocuments::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == m_lineEdit)
    {
        if (event->type() == QEvent::Type::KeyRelease)
        {
            QKeyEvent *e = static_cast<QKeyEvent*>(event);

            if (e->key() == Qt::Key::Key_Down)
            {
                QTreeWidgetItem *cur = m_view->currentItem();

                if (!cur)
                {
                    if (m_view->topLevelItemCount() > 0)
                        m_view->setCurrentItem(m_view->topLevelItem(0));
                }

                else
                {
                    QTreeWidgetItem *next = m_view->itemBelow(cur);

                    if (next)
                    {
                        m_view->setCurrentItem(next);
                    }

                    else
                    {
                        if (m_view->topLevelItemCount() > 0)
                            m_view->setCurrentItem(m_view->topLevelItem(0));
                    }
                }

                return true;
            }

            else if (e->key() == Qt::Key::Key_Up)
            {
                QTreeWidgetItem *cur = m_view->currentItem();

                if (!cur)
                {
                    if (m_view->topLevelItemCount() > 0)
                        m_view->setCurrentItem(m_view->topLevelItem(m_view->topLevelItemCount() - 1));
                }

                else
                {
                    QTreeWidgetItem *prev = m_view->itemAbove(cur);

                    if (prev)
                    {
                        m_view->setCurrentItem(prev);
                    }

                    else
                    {
                        if (m_view->topLevelItemCount() > 0)
                            m_view->setCurrentItem(m_view->topLevelItem(m_view->topLevelItemCount() - 1));
                    }
                }

                return true;
            }
        }
    }

    return QDialog::eventFilter(obj, event);
}

TP_END_NAMESPACE
