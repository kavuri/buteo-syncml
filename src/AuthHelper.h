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

#ifndef AUTHHELPER_H
#define AUTHHELPER_H

#include <QString>

namespace DataSync {

/*! \brief Utility class that is able to encode and decode SyncML basic and
 *         md5 authentication
 */
class AuthHelper {

public:

    /*! \brief Constructor
     *
     */
    AuthHelper();

    /*! \brief Destructor
     *
     */
    virtual ~AuthHelper();

    /*! \brief Encode SyncML basic base64-encoded authentication
     *
     * @param aUsername Username
     * @param aPassword Password
     * @return Encoded data
     */
    QByteArray encodeBasicB64Auth( const QString& aUsername, const QString& aPassword ) const;

    /*! \brief Encode SyncML md5 authentication
     *
     * Note that this function does not automatically base64-encode the data, so it must be done
     * separately if the information is passed through clear-text protocol like XML
     *
     * @param aUsername Username
     * @param aPassword Password
     * @param aNonce Nonce to use
     * @return Encoded data
     */
    QByteArray encodeMD5Auth( const QString& aUsername, const QString& aPassword, const QString& aNonce ) const;

protected:

private:

    QByteArray toMD5( const QByteArray& aString ) const;

};

}

#endif  //  AUTHHELPER_H
