#include <algorithm>

#include <QCheckBox>
#include <QDateTime>
#include <QSpinBox>
#include <QRegularExpressionValidator>
#include <QTextStream>

#include <Views/TpSettingsView>
#include <Widgets/TpColoredLineEdit>

TP_NAMESPACE

static bool isCharPrintable(char c)
{
    return uchar(c) >= 32 && uchar(c) < 128;
}

static bool isPrintable(const QByteArray &byteArray)
{
    return std::all_of(byteArray.cbegin(), byteArray.cend(), isCharPrintable);
}

static QString byteArrayToString(const QByteArray &byteArray)
{
    if (isPrintable(byteArray))
        return QString::fromLatin1(byteArray);
    QString rst;

    for (char c : byteArray)
    {
        if (isCharPrintable(c))
        {
            if (c == '\\')
                rst += QLatin1Char(c);
            rst += QLatin1Char(c);
        }

        else
        {
            const uint uc = uchar(c);
            rst += "\\x";
            if (uc < 16)
                rst += '0';
            rst += QString::number(uc, 16);
        }
    }

    return rst;
}

TpVariantDelegate::TpVariantDelegate(const QSharedPointer<TpDelegateTypeChecker> &checker, TpSettingsView *parent)
    : QStyledItemDelegate(parent),
    m_checker(checker),
    m_parent(parent),
    m_history({})
{}

void TpVariantDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        QVariant value = index.model()->data(index, Qt::ItemDataRole::UserRole);

        if (!isSupported(value.userType()))
        {
            QStyleOptionViewItem opt = option;
            opt.state &= ~QStyle::StateFlag::State_Enabled;
            QStyledItemDelegate::paint(painter, opt, index);
            return;
        }
    }

    QStyledItemDelegate::paint(painter, option, index);
}

QWidget *TpVariantDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem&, const QModelIndex &index) const
{
    if (index.column() != 2)
        return nullptr;
    QVariant original = index.model()->data(index, Qt::ItemDataRole::UserRole);
    if (!isSupported(original.userType()))
        return nullptr;

    switch (original.userType())
    {
    case QMetaType::Type::Bool:
        return new QCheckBox(parent);
        break;

    case QMetaType::Type::Int:
    case QMetaType::Type::LongLong: {
        auto spin = new QSpinBox(parent);
        spin->setRange(-32767, 32767);
        return spin;
    }

    case QMetaType::Type::UInt:
    case QMetaType::Type::ULongLong: {
        auto spin = new QSpinBox(parent);
        spin->setRange(0, 65536);
        return spin;
    }

    case QMetaType::Type::QColor: {
        auto ed = new TpColoredLineEdit(parent);
        ed->setColor(qvariant_cast<QColor>(original));
        /*connect(ed,
                &TpColoredLineEdit::colorChangedByUser,
                this,
                &TpVariantDelegate::committingColoredLineEdit);*/
        return ed;
    }

    default:
        break;
    }

    TpGeneralLineEdit *lineEdit = new TpGeneralLineEdit(parent);
    lineEdit->setFrame(false);
    QRegularExpression regex;

    switch (original.userType())
    {
    case QMetaType::Type::Bool:
        regex = m_checker->regexBool;
        break;
    case QMetaType::Type::QByteArray:
        regex = m_checker->regexByteArray;
        break;
    case QMetaType::Type::QChar:
        regex = m_checker->regexChar;
        break;
    case QMetaType::Type::QColor:
        regex = m_checker->regexColor;
        break;
    case QMetaType::Type::QDate:
        regex = m_checker->regexDate;
        break;
    case QMetaType::Type::QDateTime:
        regex = m_checker->regexDateTime;
        break;
    case QMetaType::Type::Double:
        regex = m_checker->regexDouble;
        break;
    case QMetaType::Type::Int:
    case QMetaType::Type::LongLong:
        regex = m_checker->regexSignedInt;
        break;
    case QMetaType::Type::QPoint:
        regex = m_checker->regexPoint;
        break;
    case QMetaType::Type::QRect:
        regex = m_checker->regexRect;
        break;
    case QMetaType::Type::QSize:
        regex = m_checker->regexSize;
        break;
    case QMetaType::Type::QTime:
        regex = m_checker->regexTime;
        break;
    case QMetaType::Type::UInt:
    case QMetaType::Type::ULongLong:
        regex = m_checker->regexUnsignedInt;
        break;
    default:
        break;
    }

    if (regex.isValid())
    {
        QValidator *val = new QRegularExpressionValidator(regex, lineEdit);
        lineEdit->setValidator(val);
    }

    return lineEdit;
}

void TpVariantDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QVariant value = index.model()->data(index, Qt::ItemDataRole::UserRole);

    if (auto spin = qobject_cast<QSpinBox*>(editor))
    {
        const auto userType = value.userType();
        if (userType == QMetaType::Type::UInt || userType == QMetaType::Type::ULongLong)
            spin->setValue(value.toUInt());
        else
            spin->setValue(value.toInt());
    }

    else if (auto check = qobject_cast<QCheckBox*>(editor))
    {
        check->setChecked(value.toBool());
    }

    else if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(editor))
    {
        if (value.userType() == QMetaType::Type::QByteArray && !isPrintable(value.toByteArray()))
            lineEdit->setReadOnly(true);
        lineEdit->setText(displayText(value));
    }
}

void TpVariantDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    const QVariant original = index.model()->data(index, Qt::ItemDataRole::UserRole);
    QVariant value;

    if (auto spin = qobject_cast<QSpinBox*>(editor))
    {
        value.setValue(spin->value());
    }

    else if (auto check = qobject_cast<QCheckBox*>(editor))
    {
        value.setValue(check->isChecked());
    }

    else if (TpColoredLineEdit *coloredLineEdit = qobject_cast<TpColoredLineEdit*>(editor))
    {
        value.setValue(coloredLineEdit->color());
    }

    else if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(editor))
    {
        if (!lineEdit->isModified())
            return;

        QString text = lineEdit->text();
        const QValidator *val = lineEdit->validator();

        if (val)
        {
            int pos;
            if (val->validate(text, pos) != QValidator::State::Acceptable)
                return;
        }

        QRegularExpressionMatch match;

        switch (original.userType())
        {
        case QMetaType::Type::QChar:
            value = text.at(0);
            break;

        case QMetaType::Type::QColor:
            match = m_checker->regexColor.match(text);
            value = QColor(qMin(match.captured(1).toInt(), 255),
                           qMin(match.captured(2).toInt(), 255),
                           qMin(match.captured(3).toInt(), 255),
                           qMin(match.captured(4).toInt(), 255));
            break;

        case QMetaType::Type::QDate: {
            QDate date = QDate::fromString(text, Qt::DateFormat::ISODate);
            if (!date.isValid())
                return;
            value = date;
            break;
        }

        case QMetaType::Type::QDateTime: {
            QDateTime dateTime = QDateTime::fromString(text, Qt::DateFormat::ISODate);
            if (!dateTime.isValid())
                return;
            value = dateTime;
            break;
        }

        case QMetaType::Type::QPoint:
            match = m_checker->regexPoint.match(text);
            value = QPoint(match.captured(1).toInt(), match.captured(2).toInt());
            break;

        case QMetaType::Type::QRect:
            match = m_checker->regexRect.match(text);
            value = QRect(match.captured(1).toInt(), match.captured(2).toInt(),
                match.captured(3).toInt(), match.captured(4).toInt());
            break;

        case QMetaType::QSize:
            match = m_checker->regexSize.match(text);
            value = QSize(match.captured(1).toInt(), match.captured(2).toInt());
            break;

        case QMetaType::Type::QStringList:
            value = text.split(',');
            break;

        case QMetaType::Type::QTime: {
            QTime time = QTime::fromString(text, Qt::DateFormat::ISODate);
            if (!time.isValid())
                return;
            value = time;
            break;
        }

        default:
            value = text;
            value.convert(QMetaType(original.userType()));
        }
    }

    if (original == value)
        return;

    model->setData(index, displayText(value), Qt::ItemDataRole::DisplayRole);
    model->setData(index, value, Qt::ItemDataRole::UserRole);

    QPersistentModelIndex persistentIndex(index);

    if (!m_history.contains(persistentIndex))
        m_history.insert(persistentIndex, original);
}

bool TpVariantDelegate::isSupported(int type)
{
    switch (type)
    {
    case QMetaType::Type::Bool:
    case QMetaType::Type::QByteArray:
    case QMetaType::Type::QChar:
    case QMetaType::Type::QColor:
    case QMetaType::Type::QDate:
    case QMetaType::Type::QDateTime:
    case QMetaType::Type::Double:
    case QMetaType::Type::Int:
    case QMetaType::Type::LongLong:
    case QMetaType::Type::QPoint:
    case QMetaType::Type::QRect:
    case QMetaType::Type::QSize:
    case QMetaType::Type::QString:
    case QMetaType::Type::QStringList:
    case QMetaType::Type::QTime:
    case QMetaType::Type::UInt:
    case QMetaType::Type::ULongLong:
        return true;
    default:
        return false;
    }
}

QString TpVariantDelegate::displayText(const QVariant &value)
{
    static const ushort unicodeBallotBox = 0x2610;
    static const ushort unicodeCheckmark = 0x2713;

    switch (value.userType())
    {
    case QMetaType::Type::Bool:
        return value.toBool()
            ? QString(QChar(unicodeCheckmark))
            : QString(QChar(unicodeBallotBox));
    case QMetaType::Type::QByteArray:
        return byteArrayToString(value.toByteArray());

    case QMetaType::Type::QChar:
    case QMetaType::Type::Double:
    case QMetaType::Type::Int:
    case QMetaType::Type::LongLong:
    case QMetaType::Type::QString:
    case QMetaType::Type::UInt:
    case QMetaType::Type::ULongLong:
        return value.toString();

    case QMetaType::Type::QColor: {
            QColor color = qvariant_cast<QColor>(value);
            return QString("(%1,%2,%3,%4)")
                   .arg(color.red()).arg(color.green())
                   .arg(color.blue()).arg(color.alpha());
    }

    case QMetaType::Type::QDate:
        return value.toDate().toString(Qt::ISODate);
    case QMetaType::Type::QDateTime:
        return value.toDateTime().toString(Qt::ISODate);
    case QMetaType::Type::UnknownType:
        return "<Invalid>";

    case QMetaType::Type::QPoint: {
            QPoint point = value.toPoint();
            return QString("(%1,%2)").arg(point.x()).arg(point.y());
    }

    case QMetaType::Type::QRect: {
            QRect rect = value.toRect();
            return QString("(%1,%2,%3,%4)")
                   .arg(rect.x()).arg(rect.y())
                   .arg(rect.width()).arg(rect.height());
    }

    case QMetaType::Type::QSize: {
            QSize size = value.toSize();
            return QString("(%1,%2)").arg(size.width()).arg(size.height());
    }

    case QMetaType::QStringList:
        return value.toStringList().join(',');
    case QMetaType::QTime:
        return value.toTime().toString(Qt::ISODate);
    default:
        break;
    }

    return QString("<%1>").arg(value.typeName());
}

void TpVariantDelegate::revertModelValues(QAbstractItemModel *model)
{
    for (auto it = m_history.begin(); it != m_history.end(); it++)
    {
        const QPersistentModelIndex &index = it.key();
        const QVariant &original = it.value();

        if (!index.isValid())
            continue;

        model->setData(index, original, Qt::ItemDataRole::UserRole);
        model->setData(index, displayText(original), Qt::ItemDataRole::DisplayRole);
    }

    m_history.clear();
}

QMap<QPersistentModelIndex, QVariant> TpVariantDelegate::history() const
{
    return m_history;
}

void TpVariantDelegate::committingColoredLineEdit()
{
    emit commitData(qobject_cast<QWidget*>(sender()));
}

TP_END_NAMESPACE
