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
#ifndef SYNCMLRESULTS_H
#define SYNCMLRESULTS_H

#include "SyncMLCmdObject.h"
#include "SyncAgentConsts.h"
#include "datatypes.h"

namespace DataSync {

class StoragePlugin;
class DeviceInfo;

/*! \brief SyncMLResults is a class for generating SyncML
 *         Resulst XML object
 */
class SyncMLResults : public SyncMLCmdObject
{
public:

    /*! \brief Constructor
     *
     * @param aCmdID Command id for this element
     * @param aMsgRef Message referenced by this element
     * @param aCmdRef Command referenced by this element
     * @param aDataStores Datastores available to use in generation
     * @param aDeviceInfo Device info object
     * @param aVersion Protocol version to use
     * @param aRole Role to use
     */
    SyncMLResults( int aCmdID, int aMsgRef, int aCmdRef,
                   const QList<StoragePlugin*> &aDataStores,
                   const DeviceInfo& aDeviceInfo,
                   const ProtocolVersion& aVersion,
                   const Role& aRole );

    /*! \brief Destructor
     *
     */
    virtual ~SyncMLResults();

protected:

private:
};

}

#endif  //  SYNCMLRESULTS_H
