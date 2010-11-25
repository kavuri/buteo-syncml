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
#ifndef SESSIONAUTHENTICATION_H
#define SESSIONAUTHENTICATION_H

#include "SyncAgentConsts.h"
#include "Fragments.h"

namespace DataSync {

class ResponseGenerator;
class DatabaseHandler;
class NonceStorage;

/*! \brief Manages session authentication happening over SyncML protocol
 *
 */
class SessionAuthentication
{
public:

    /*! \brief Describes analysis result of SyncML header
     *
     */
    enum HeaderStatus
    {
        HEADER_HANDLED_OK,          ///< Header was handled, all OK
        HEADER_HANDLED_ABORT,       ///< Header was handled, should abort session
        HEADER_NOT_HANDLED          ///< Header was not handled
    };

    /*! \brief Describes analysis result of Status of SyncML header
     *
     */
    enum StatusStatus
    {
        STATUS_HANDLED_OK,          ///< Status was handled, all OK
        STATUS_HANDLED_ABORT,       ///< Status was handled, should abort session
        STATUS_HANDLED_RESEND,      ///< Status was handled, should resend last message
        STATUS_NOT_HANDLED          ///< Status was not handled
    };

    /*! \brief Constructor
     *
     */
    SessionAuthentication();

    /*! \brief Destructor
     *
     */
    ~SessionAuthentication();

    /*! \brief Sets parameters to use for this session
     *
     * If remote authentication is not required, aAuthType of AUTH_NONE should be used,
     * and empty QStrings should be passed. If remote device is not required to authenticate
     * with local device, empty QStrings should be passed to aLocalUsername and aLocalPassword.
     *
     * @param aAuthType Authentication type to use when authenticating
     * @param aRemoteUsername Username to use when authenticating with remote device
     * @param aRemotePassword Password to use when authenticating with remote device
     * @param aRemoteNonce Explicitly defined nonce that should be used when authenticating with remote device
     * @param aLocalUsername Username that remote device should use when authenticating
     * @param aLocalPassword Password that remote device should use when authenticating
     * @param aLocalNonce Explicitly defined nonce that remote device should use when authenticating
     */
    void setSessionParams( AuthType aAuthType,
                           const QString& aRemoteUsername,
                           const QString& aRemotePassword,
                           const QString& aRemoteNonce,
                           const QString& aLocalUsername,
                           const QString& aLocalPassword,
                           const QString& aLocalNonce );

    /*! \brief Returns whether remote device has been authenticated to us
     *
     * @return True if remote device has been authenticatied, otherwise false
     */
    bool remoteIsAuthed() const;

    /*! \brief Returns whether we have been authenticated to the remote device
     *
     */
    bool authedToRemote() const;

    /*! \brief Analyze SyncML header sent by remote device
     *
     * @param aHeader Header to analyze
     * @param aDbHandler DatabaseHandler to utilize
     * @param aLocalDeviceName Local device name
     * @param aRemoteDeviceName Remote device name
     * @param aResponseGenerator Response generator to utilize
     */
    HeaderStatus analyzeHeader( const HeaderParams& aHeader,
                                DatabaseHandler& aDbHandler,
                                const QString& aLocalDeviceName,
                                const QString& aRemoteDeviceName,
                                ResponseGenerator& aResponseGenerator );

    /*! \brief Analyze Status sent by remote device in response to SyncML header sent by us
     *
     * @param aStatus Status to analyze
     * @param aDbHandler DatabaseHandler to utilize
     * @param aLocalDeviceName Local device name
     * @param aRemoteDeviceName Remote device name
     */
    StatusStatus analyzeHeaderStatus( const StatusParams& aStatus,
                                      DatabaseHandler& aDbHandler,
                                      const QString& aLocalDeviceName,
                                      const QString& aRemoteDeviceName );

    /*! \brief Compose authentication to be sent in the next message
     *
     * @param aResponseGenerator Response generator to use
     * @param aDbHandler DatabaseHandler to utilize
     * @param aLocalDeviceName Local device name
     * @param aRemoteDeviceName Remote device name
     */
    void composeAuthentication( ResponseGenerator& aResponseGenerator,
                                DatabaseHandler& aDbHandler,
                                const QString& aLocalDeviceName,
                                const QString& aRemoteDeviceName );

    /*! \brief Return human-readable description of the last occurred error
     *
     * @return
     */
    QString getLastError() const;

protected:

private:

    HeaderStatus handleAuthentication( const HeaderParams& aHeader,
                                       DatabaseHandler& aDbHandler,
                                       const QString& aLocalDeviceName,
                                       const QString& aRemoteDeviceName,
                                       ResponseGenerator& aResponseGenerator );

    StatusStatus handleChallenge( const ChalParams& aChallenge,
                                  DatabaseHandler& aDbHandler,
                                  const QString& aLocalDeviceName,
                                  const QString& aRemoteDeviceName );

    QByteArray decodeNonce( const ChalParams& aChallenge ) const;

    ChalParams generateChallenge();

    ChalParams generateChallenge( NonceStorage& aNonces );

    bool                iAuthedToRemote;
    bool                iRemoteAuthPending;
    bool                iRemoteAuthed;
    bool                iLocalAuthPending;

    AuthType            iAuthType;
    QString             iRemoteUsername;
    QString             iRemotePassword;
    QString             iRemoteNonce;
    QString             iLocalUsername;
    QString             iLocalPassword;
    QString             iLocalNonce;

    QString             iLastError;

};

}

#endif // SESSIONAUTHENTICATION_H
