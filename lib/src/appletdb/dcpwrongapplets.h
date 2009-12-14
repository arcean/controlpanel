#ifndef DCPWRONGAPPLETS_H
#define DCPWRONGAPPLETS_H

#include <QSet>
#include <QHash>
#include <QString>

/** class is internal, handles wrong applet markings and queries */
/*
 * TODO: We need a tool to temporary turn this protection off, because it makes
 * the debugging very hard.
 */
class DcpWrongApplets
{
public:
    static DcpWrongApplets* instance();
    static void destroyInstance();
    static void disable();
    static bool isDisabled() { return sm_Disabled; }

    void markAsMaybeBad(const QString& badSoPath);
    void unmarkAsMaybeBad(const QString& badSoPath);
    bool isBad(const QString& badSoPath);
    const QSet<QString>& badApplets() const;
    static QSet<QString> queryBadApplets();

private:
    DcpWrongApplets();
    ~DcpWrongApplets();
    static DcpWrongApplets* sm_Instance;

    // some speed up caches to avoid unnecessery gconf access
    QSet<QString> m_BadApplets;
    QHash<QString, int> m_MaybeBadApplets;
    static bool sm_Disabled;
};

//convenience methods:
void dcpMarkAsMaybeBad(const class DcpAppletMetadata* metadata);
void dcpUnmarkAsMaybeBad(const class DcpAppletMetadata* metadata);

#endif // DCPWRONGAPPLETS_H

