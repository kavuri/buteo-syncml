/*
* This file is part of buteo-syncml package
*
* Copyright (C) 2010 Nokia Corporation. All rights reserved.
*
* Contact: Sateesh Kavuri <sateesh.kavuri@nokia.com>
*
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, 
* this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation nor the names of its contributors may 
* be used to endorse or promote products derived from this software without 
* specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#include "DatabaseHandler.h"

#include "LogMacros.h"
#include "SyncCommonDefs.h"

using namespace DataSync;

const QString CONNECTIONNAME( "dbhandler" );

DatabaseHandler::DatabaseHandler( const QString& aDbFile )
{
    FUNCTION_CALL_TRACE;

    static unsigned connectionNumber = 0;

    iConnectionName = CONNECTIONNAME + QString::number( connectionNumber++ );
    iDb = QSqlDatabase::addDatabase( "QSQLITE", iConnectionName );

    QDir cacheDir;
    cacheDir.mkdir( Sync::syncCacheDir() );
    QString path( Sync::syncCacheDir() );
    path.append( QDir::separator() ).append( aDbFile );
    path = QDir::toNativeSeparators( path );

    iDb.setDatabaseName( path );
    if(!iDb.open())
	    LOG_CRITICAL("can not open database");

}


DatabaseHandler::~DatabaseHandler()
{
    FUNCTION_CALL_TRACE;

    iDb.close();
    iDb = QSqlDatabase();
    QSqlDatabase::removeDatabase( iConnectionName );

}

bool DatabaseHandler::isValid() const
{
    FUNCTION_CALL_TRACE;

    return iDb.isOpen();
}

QSqlDatabase& DatabaseHandler::getDbHandle()
{
    return iDb;
}
