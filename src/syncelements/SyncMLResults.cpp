/*/*
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

#include "SyncMLResults.h"

#include "datatypes.h"
#include "SyncMLMeta.h"
#include "SyncMLDevInf.h"

using namespace DataSync;

SyncMLResults::SyncMLResults( int aCmdID, int aMsgRef, int aCmdRef )
 : SyncMLCmdObject( SYNCML_ELEMENT_RESULTS )
{
    SyncMLCmdObject* cmdIdObject = new SyncMLCmdObject( SYNCML_ELEMENT_CMDID, QString::number( aCmdID ) );
    addChild( cmdIdObject );

    SyncMLCmdObject* msgRefObject = new SyncMLCmdObject( SYNCML_ELEMENT_MSGREF, QString::number( aMsgRef ) );
    addChild(msgRefObject);

    SyncMLCmdObject* cmdRefObject = new SyncMLCmdObject( SYNCML_ELEMENT_CMDREF, QString::number( aCmdRef ) );
    addChild(cmdRefObject);
}

SyncMLResults::SyncMLResults( int aCmdID, int aMsgRef, int aCmdRef,
                              const QList<StoragePlugin*> &aDataStores,
                              const DeviceInfo& aDeviceInfo,
                              const ProtocolVersion& aVersion,
                              const Role& aRole )
 : SyncMLCmdObject( SYNCML_ELEMENT_RESULTS )
{
    SyncMLCmdObject* cmdIdObject = new SyncMLCmdObject( SYNCML_ELEMENT_CMDID, QString::number( aCmdID ) );
    addChild( cmdIdObject );

    SyncMLCmdObject* msgRefObject = new SyncMLCmdObject( SYNCML_ELEMENT_MSGREF, QString::number( aMsgRef ) );
    addChild(msgRefObject);

    SyncMLCmdObject* cmdRefObject = new SyncMLCmdObject( SYNCML_ELEMENT_CMDREF, QString::number( aCmdRef ) );
    addChild(cmdRefObject);

    SyncMLCmdObject* targetRefObject = new SyncMLCmdObject( SYNCML_ELEMENT_TARGETREF,
            aVersion == SYNCML_1_1 ? SYNCML_DEVINF_PATH_11 : SYNCML_DEVINF_PATH_12 );
    addChild( targetRefObject );

    SyncMLMeta* metaObject = new SyncMLMeta;
    metaObject->addType( SYNCML_CONTTYPE_DEVINF_XML );
    addChild( metaObject );

    SyncMLDevInf* devInf = new SyncMLDevInf( aDataStores, aDeviceInfo, aVersion, aRole );
    addChild( devInf );

}

SyncMLResults::~SyncMLResults()
{

}
