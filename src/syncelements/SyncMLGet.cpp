/*
* This file is part of meego-syncml package
*
* Copyright (C) 2010 Nokia Corporation. All rights reserved.
*
* Contact: Sateesh Kavuri <sateesh.kavuri@nokia.com>
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#include "SyncMLGet.h"

#include "SyncMLMeta.h"
#include "datatypes.h"

#include "LogMacros.h"

using namespace DataSync;

SyncMLGet::SyncMLGet( int aCmdID, const QString& aType, const QString& aTarget )
 : SyncMLCmdObject( SYNCML_ELEMENT_GET )
{
    SyncMLCmdObject* cmdObject = new SyncMLCmdObject( SYNCML_ELEMENT_CMDID,
                                                      QString::number( aCmdID ) );
    addChild( cmdObject );

    SyncMLMeta* metaObject = new SyncMLMeta;
    metaObject->addType( aType );
    addChild( metaObject );

    SyncMLCmdObject* item = new SyncMLCmdObject(SYNCML_ELEMENT_ITEM);

    SyncMLCmdObject* targetObject = new SyncMLCmdObject( SYNCML_ELEMENT_TARGET );

    SyncMLCmdObject* locURIObject = new SyncMLCmdObject( SYNCML_ELEMENT_LOCURI, aTarget );
    targetObject->addChild( locURIObject );

    item->addChild( targetObject );

    addChild( item );
}

SyncMLGet::~SyncMLGet()
{
    FUNCTION_CALL_TRACE;
}
