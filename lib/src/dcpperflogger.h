/***************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel.
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/
#ifndef DCPPERFLOGGER_H__
#define DCPPERFLOGGER_H__

#include <sys/types.h>
#include <QString>

class DcpPerfLogger {
    public:
        ~DcpPerfLogger();
        static DcpPerfLogger *instance();
        void startLogging(const QString &filename);
        void recordEvent(const QString &event);

    protected:
        DcpPerfLogger();

    private:
        int m_logFd;
};

/**
 * \param event: event identification, must not contain spaces
 */
inline
void DCP_PERF_RECORD_EVENT(const QString &event) {
#ifdef PERF_MEASUREMENT
    DcpPerfLogger::instance()->recordEvent(event);
#else
    Q_UNUSED(event)
#endif
}

inline
void DCP_PERF_START_LOGGING(const QString &filename) {
#ifdef PERF_MEASUREMENT
    DcpPerfLogger::instance()->startLogging(filename);
#else
    Q_UNUSED(filename);
#endif
}

#endif
