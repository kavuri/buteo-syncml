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

#include "SyncMLItem.h"

#include "internals.h"

using namespace DataSync;

SyncMLItem::SyncMLItem() : SyncMLCmdObject( SYNCML_ELEMENT_ITEM )
{
}

SyncMLItem::~SyncMLItem()
{
}

void SyncMLItem::insertTarget( const SyncItemKey& aLocURI )
{
    SyncMLCmdObject* targetObject = new SyncMLCmdObject( SYNCML_ELEMENT_TARGET );

    SyncMLCmdObject* locURIObject = new SyncMLCmdObject( SYNCML_ELEMENT_LOCURI, aLocURI );
    targetObject->addChild( locURIObject );

    addChild( targetObject );
}

void SyncMLItem::insertSource( const SyncItemKey& aLocURI )
{
    SyncMLCmdObject* sourceObject = new SyncMLCmdObject( SYNCML_ELEMENT_SOURCE );

    SyncMLCmdObject* locURIObject = new SyncMLCmdObject( SYNCML_ELEMENT_LOCURI, aLocURI );
    sourceObject->addChild( locURIObject );

    addChild( sourceObject );
}

void SyncMLItem::insertTargetParent( const SyncItemKey& aLocURI )
{
    SyncMLCmdObject* targetObject = new SyncMLCmdObject( SYNCML_ELEMENT_TARGETPARENT );

    SyncMLCmdObject* locURIObject = new SyncMLCmdObject( SYNCML_ELEMENT_LOCURI, aLocURI );
    targetObject->addChild( locURIObject );

    addChild( targetObject );
}

void SyncMLItem::insertSourceParent( const SyncItemKey& aLocURI )
{
    SyncMLCmdObject* sourceObject = new SyncMLCmdObject( SYNCML_ELEMENT_SOURCEPARENT );

    SyncMLCmdObject* locURIObject = new SyncMLCmdObject( SYNCML_ELEMENT_LOCURI, aLocURI );
    sourceObject->addChild( locURIObject );

    addChild( sourceObject );
}

void SyncMLItem::insertData( const QByteArray& aData )
{

    // Data is always encoded in UTF-8, so make sure it's being read as such instead
    // of default behavior of latin
    QString data = QString::fromUtf8( aData.constData() );
    SyncMLCmdObject* dataObject = new SyncMLCmdObject( SYNCML_ELEMENT_DATA, data );

    dataObject->setCDATA( true );

    addChild( dataObject );
}

void SyncMLItem::insertMoreData()
{
    SyncMLCmdObject* moreDataObject = new SyncMLCmdObject( SYNCML_ELEMENT_MOREDATA );
    addChild( moreDataObject );
}
