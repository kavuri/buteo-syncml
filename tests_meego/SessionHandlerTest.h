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

#ifndef SESSIONHANDLERTEST_H
#define SESSIONHANDLERTEST_H

#include <QTest>

#include "StorageProvider.h"

class SessionHandlerTest : public QObject, public DataSync::StorageProvider
{
Q_OBJECT

public:

    virtual bool getStorageContentFormatInfo( const QString& aURI,
                                              DataSync::StorageContentFormatInfo& aInfo );
    virtual DataSync::StoragePlugin* acquireStorageByURI( const QString& aURI );

    virtual DataSync::StoragePlugin* acquireStorageByMIME( const QString& aMIME );

    virtual void releaseStorage( DataSync::StoragePlugin* aStorage );

private slots:
    void init();
    void cleanup();
    void testClientWithClientInitiated();
    void testClientWithServerInitiated();
    void testServerWithClientInitiated();
    void testClientWithServerInitiatedSAN();

    void testClientAuthNone();
    void testClientAuthNoneFailed();
    void testClientAuthNoneChal1();
    void testClientAuthNoneChal2();
    void testClientAuthBasicNoCreds();
    void testClientAuthBasic();
    void testClientAuthBasicChalToMD5WithoutNonce();
    void testClientAuthBasicChalToMD5WithNonce();
    void testClientAuthBasicContinuous();
    void testClientAuthMD5NoCreds();
    void testClientAuthMD5WithoutNonce1();
    void testClientAuthMD5WithoutNonce2();
    void testClientAuthMD5WithoutNonce3();
    void testClientAuthMD5WithNonce();
    void testClientAuthMD5ChalToBasic();
    void testClientAuthMD5Continuous();

    void regression_NB153701_01();
    void regression_NB153701_02();
    void regression_NB153701_03();
    void regression_NB153701_04();
    void testNoRespSyncElement();

private:

};

#endif // SESSIONHANDLERTEST_H
