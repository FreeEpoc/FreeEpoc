// Copyright (c) 2006-2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

/**
 @file
 @publishedPartner
 @released
*/

#ifndef HCITYPES_H
#define HCITYPES_H

#include <bttypes.h>
#include <bttypespartner.h>


enum THWHCIVersion
/**
Controller version information
*/
	{
	EHWHCIv1_0 = 0, // HCIv1.0B
	EHWHCIv1_1 = 1, // HCIv1.1
	EHWHCIv1_2 = 2, // HCIv1.2
	EHWHCIv2_0 = 3, // HCIv2.0
	EHWHCIv2_1 = 4, // HCIv2.1
	};

enum TBTHardResetState 
/**
Controller 'reset' states
*/
	{
	//NB In chronologically reverse order
	EBTResetComplete = 0x00, /*!< The reset process is complete. */
	EBTResetStarted = 0x01 /*!< The reset process has started. */
	};

enum TBTPowerState 
/**
Controller 'power' states
*/
	{
	EBTOn = 0x00, /*!< Power on. */
	EBTOff = 0x01 /*!< Power off. */
	};

enum THCISimplePairingMode
/**
Simple pairing mode
*/
	{
	ESimplePairingDisabled = 0x00,
	ESimplePairingEnabled = 0x01
	};
	
enum THCIIoCapability
/**
IO capability
*/
	{
	EIOCapsDisplayOnly = 0x00,
	EIOCapsDisplayYesNo = 0x01,
	EIOCapsKeyboardOnly = 0x02,
	EIOCapsNoInputNoOutput = 0x03
	};
	
enum THCIOobDataPresence
/**
OOB data presence
*/
	{
	EOOBDataNotPresent = 0x00,
	EOOBDataPresent = 0x01
	};
	
enum THCIAuthenticationRequirement
/**
Authentication requirement
*/
	{
	EMitmNotReqNoBonding = 0x00,
	EMitmReqNoBonding = 0x01,
	EMitmNotReqDedicatedBonding = 0x02,
	EMitmReqDedicatedBonding = 0x03,
	EMitmNotReqGeneralBonding = 0x04,
	EMitmReqGeneralBonding = 0x05
	};

const TUint KAuthenticationMitmReqMask = 0x1;

enum THCIPasskeyEntryNotificationType
/**
Passkey entry notification type
*/
	{
	EPasskeyEntryStarted = 0x00,
	EPasskeyDigitEntered = 0x01,
	EPasskeyDigitDeleted = 0x02,
	EPasskeyCleared = 0x03,
	EPasskeyEntryCompleted = 0x04
	};
	
enum TLinkType
/**
Bluetooth link type (ACL / SCO)
*/
	{
	ESCOLink = 0x00, /*!< Synchronous Connection Oriented link */
	EACLLink = 0x01, /*!< Asynchronous ConnectionLess link */
	EeSCOLink = 0x02 /*!< eSCO link */
	};

enum TEncryptMode
/**
Bluetooth encryption mode
*/
	{
	EDisabled = 0x00, /*!< Encryption disabled */
	EPointToPoint = 0x01, /*!< Point to point encryption enabled */
	EAll = 0x02 /*!< Device wide encryption enabled */
	};

enum TAirMode
/**
Air mode of synchronous connection
*/
	{
	ECVSD = 0x00, /*!< CVSD */
	EuLawLog = 0x01, /*!< u-law log */
	EALawLog = 0x02, /*!< A-law log */
	ETransparentData = 0x03	/*!< Transparent data */
	};

enum THCIDeleteAllKeysFlag
/**
HCI delete all keys flag
*/
	{
	EDeleteBdaddrLinkKey = 0x00, /*!< Delete Bluetooth device address link key */
	EDeleteAllLinkKeys = 0x01 /*!< Delete all link keys */
	};
 
enum THCITimeoutType
/**
HCI timeout type
*/
	{
	EConnectionAcceptTimeout = 0x00, /*!< Connection accept timeout */
	EPageTimeout = 0x01, /*!< Page timeout */
	};

enum THCIReadAllKeysFlag
/**
HCI read all keys flag
*/
	{
	EReadBdaddrLinkKey = 0x00, /*!< Read Bluetooth device address link key */
	EReadAllLinkKeys = 0x01, /*!< Read all link keys */
	};

enum THCIEncryptModeFlag
/**
HCI encryption mode flag
*/
	{
	EEncryptionDisabled = 0x00, /*!< Encryption disabled */
	EPointToPointEncryption = 0x01, /*!< Point to point encryption enabled */
	EPointToPointAndBroadcastEncryption = 0x02, /*!< Point to point and broadcast encryption enabled */
	};

enum THCIInquiryMode 
/**
HCI Inquiry mode flag
*/
	{
	EStandardInquiryFormat = 0x00, /*!< Standard Inquiry Result event Format */
	EInquiryWithRssi = 0x01, /*!< Inquiry result format with RSSI */
	EInquiryWithRssiOrEir = 0x02 /*!< Inquiry result with RSSI format or Extended Inquiry Result format */
	};

/**
HCI Link-key type
*/
enum THCILinkKeyType
	{
	ECombinationKey = 0x00, /*!< Combination link-key generated by classic Bluetooth pairing */
	ELocalUnitKey = 0x01, /*!< Unit link-key for local device */
	ERemoteUnitKey = 0x02, /*!< Unit link-key for remote device */
	EDebugCombinationKey = 0x03, /*!< Combination link-key generated when simple pairing debug mode is enabled */
	EUnauthenticatedCombinationKey = 0x04, /*!< Combination link-key generated with simple pairing with no MITM protection */
	EAuthenticatedCombinationKey = 0x05, /*!< Combination link-key generated with simple pairing with MITM protection */
	EChangedCombinationKey = 0x06, /*!< An indication that the link-key is of the same type previously provided */
	};

enum THCITransmitPowerLevelType
	{
	ECurrentTransmitPowerLevel  = 0x00,
	EMaximumTransmitPowerLevel  = 0x01,
	};

/**
HCI event mask
This can be used to specify the mask used to control which events the controller reports.
*/
NONSHARABLE_CLASS(THCIEventMask)
	{
public:
	enum TLoByteMask
		{
		EInquiryCompleteEvent						= 0x00000001,
		EInquiryResultEvent							= 0x00000002,
		EConnectionCompleteEvent					= 0x00000004,
		EConnectionRequestEvent						= 0x00000008,
		EDisconnectionCompleteEvent					= 0x00000010,
		EAuthenticationCompleteEvent				= 0x00000020,
		ERemoteNameRequestCompleteEvent				= 0x00000040,
		EEncryptionChangeEvent						= 0x00000080,
		EChangeConnectionLinkKeyCompleteEvent		= 0x00000100,
		EMasterLinkKeyCompleteEvent					= 0x00000200,
		EReadRemoteSupportedFeaturesCompleteEvent	= 0x00000400,
		EReadRemoteVersionInformationCompleteEvent	= 0x00000800,
		EQoSSetupCompleteEvent						= 0x00001000,
		EHardwareErrorEvent							= 0x00008000,
		EFlushOccurredEvent							= 0x00010000,
		ERoleChangeEvent							= 0x00020000,
		EModeChangeEvent							= 0x00080000,
		EReturnLinkKeysEvent						= 0x00100000,
		EPINCodeRequestEvent						= 0x00200000,
		ELinkKeyRequestEvent						= 0x00400000,
		ELinkKeyNotificationEvent					= 0x00800000,
		ELoopbackCommandEvent						= 0x01000000,
		EDataBufferOverflowEvent					= 0x02000000,
		EMaxSlotsChangeEvent						= 0x04000000,
		EReadClockOffsetCompleteEvent				= 0x08000000,
		EConnectionPacketTypeChangedEvent			= 0x10000000,
		EQoSViolationEvent							= 0x20000000,
		EPageScanModeChangeEvent					= 0x40000000,
		EPageScanRepetitionModeChangeEvent			= 0x80000000
		};
	
	enum THiByteMask
		{
		EFlowSpecificationCompleteEvent					= 0x00000001,
		EInquiryResultWithRSSIEvent						= 0x00000002,
		EReadRemoteExtendedFeaturesCompleteEvent		= 0x00000004,
		ESynchronousConnectionCompleteEvent				= 0x00000800,
		ESynchronousConnectionChangedEvent				= 0x00001000,
		ESniffSubratingEvent							= 0x00002000,
		EExtendedInquiryResultEvent						= 0x00004000,
		EEncryptionKeyRefreshCompleteEvent				= 0x00008000,
		EIOCapabilityRequestEvent						= 0x00010000,
		EIOCapabilityRequestReplyEvent					= 0x00020000,
		EUserConfirmationRequestEvent					= 0x00040000,
		EUserPasskeyRequestEvent						= 0x00080000,
		ERemoteOOBDataRequestEvent						= 0x00100000,
		ESimplePairingCompleteEvent						= 0x00200000,
		ELinkSupervisionTimeoutChangedEvent				= 0x00800000,
		EEnhancedFlushCompleteEvent						= 0x01000000,
		EUserPasskeyNotificationEvent					= 0x04000000,
		EKeypressNotificationEvent						= 0x08000000,
		ERemoteHostSupportedFeaturesNotificationEvent	= 0x10000000,
		};
	
	static const TUint32 KDefaultLoBytes = 0xffffffff;
	static const TUint32 KDefaultHiBytes = 0x00001fff;
	
public:
	TUint32 iLoBytes; /*!< Least significant bytes (bytes 0 - 3) */
	TUint32 iHiBytes; /*!< Most significant bytes (bytes 4 - 7) */
	};

enum THCIEventFilterType
/**
HCI event filter type
*/ 
	{
	EClearAllFilters = 0x00, /*!< Clear all filters */
	EInquiryResultFilter = 0x01, /*!< Inquiry result filter */
	EConnectionSetupFilter = 0x02 /*!< Connection setup filter */
	};

NONSHARABLE_CLASS(THCIEventCondition)
/**
HCI event condition definition.
*/
	{
public:
	THCIEventFilterType iEventFilterType; /*!< Event filter type */
	TUint8 iConditionType; /*!< Condition type */
	TUint iCoD; /*!< Class of device */
	TUint iCoDMask; /*!< Class of device mask */
	TBTDevAddr iDevAddr; /*!< Bluetooth device address */
	TUint8 iAutoAcceptFlag; /*!< Auto accept flag */
	};

/**
Provides a representation of a RSSI value returned over the
Bluetooth HCI.
Intended for use within an RArray type class.
*/
NONSHARABLE_CLASS(THCIRssi)
	{
public:
	IMPORT_C THCIRssi();
	IMPORT_C THCIRssi(TUint8 aRssi);
	IMPORT_C THCIRssi& operator=(TUint8 aRssi);

	IMPORT_C TUint8 Rssi() const;
	IMPORT_C operator TUint8() const;


	IMPORT_C THCIRssi(TInt8 aRssi);
	IMPORT_C THCIRssi& operator=(TInt8 aRssi);

	IMPORT_C TInt8 RSSI() const;
private:
	TInt8 iRssi;
	TUint8 iPad1; // To pad the class out making it 4 bytes in total (for use in RArray).
	TUint16 iPad2;
	};


const static TUint8 KInqLogEntryStandard = 0; /*!< TInquiryLogEntry */
const static TUint8 KInqLogEntryWithRssi = 1; /*!< TInquiryLogEntryWithRssi */
const static TUint8 KInqLogEntryWithEir = 2; /*!< TInquiryLogEntryWithEir */

NONSHARABLE_CLASS(TInquiryLogEntry)
/**
Inquiry log entry.  Used to pass information from a BT inquiry operation.
*/
	{
public:
	TUint8 iPageScanRepetitionMode; /*!< Page scan repetition mode */
	TUint8 iPageScanPeriodMode; /*!< Page scan period mode */
	TUint8 iPageScanMode; /*!< Page scan mode */
/**
iSpare: Used to identify Inquiry log entry type
This is for internal sub-system use only and should be not be used otherwise.
@internalComponent
*/
	TUint8 iSpare;

	TUint16 iClockOffset; /*!< Clock offset */
	TBTDevAddr iBdaddr; /*!< Bluetooth device address */
	TUint iCoD; /*!< Class of device */
	};

NONSHARABLE_CLASS(TInquiryLogEntryWithRssi) : public TInquiryLogEntry
/**
Inquiry log entry.  Used to pass information from a BT inquiry operation.
*/
	{
public:
	THCIRssi iRssi; /*!< RSSI (dBm) */
	};

static const TUint8 KHCIExtendedInquiryResponseMaxLength = 240; /*!< Extended Inquiry Response max length. */
NONSHARABLE_CLASS(TInquiryLogEntryWithEir) : public TInquiryLogEntryWithRssi
/**
Inquiry log entry.  Used to pass information from a BT inquiry operation.
*/
	{
public:
    TBuf8<KHCIExtendedInquiryResponseMaxLength> iExtendedInquiryResponse; /*!< Extended Inquiry Response (240 bytes max) */
    };

NONSHARABLE_CLASS(TBTConnect)
/**
Definition of the parameters required to make a HCI connection.
*/
	{
public:
	THCIConnHandle iConnH; /*!< Handle to the HCI connection */
	TBTDevAddr iBdaddr; /*!< Bluetooth device address */
	TUint iCoD; /*!< Class of device */
	TLinkType iLinkType; /*!< Link type (ACL / SCO) */
/**
Encryption mode 
@see TEncryptMode
*/
	TEncryptMode iEncryptMode;
	};

NONSHARABLE_CLASS(TBTSyncConnectOpts)
/**
Parameters returned by HCI after a successful Synchronous connection.
*/
	{
public:
	inline TBTSyncConnectOpts(const TUint8 aTransmissionInterval, const TUint8 aRetransmissionWindow, 
		const TUint16 aRxPacketLength, const TUint16 aTxPacketLength, const TAirMode aAirMode)
		: iTransmissionInterval(aTransmissionInterval), iRetransmissionWindow(aRetransmissionWindow),
		  iRxPacketLength(aRxPacketLength), iTxPacketLength(aTxPacketLength),
		  iAirMode(aAirMode)
		{}
		
public:
	TUint8 iTransmissionInterval;
	TUint8 iRetransmissionWindow;
	TUint16 iRxPacketLength;
	TUint16 iTxPacketLength;
	TAirMode iAirMode;
	};

NONSHARABLE_CLASS(TBTDevHCIVersion)
/**
BT HCI version definition.
*/
	{
public:
	TUint8 iHCIVersion; /*!< HCI version */
	TUint16 iHCIRevision; /*!< HCI Revision */
	};

NONSHARABLE_CLASS(TBTDevLMPVersion)
/**
BT Link Manager Protocol (LMP) version definition.
*/
	{
public:
	TUint8 iLMPVersion; /*!< LMP version */
	TUint16	iManufacturerID; /*!< Manufacturer ID */
	TUint16	iLMPSubVersion; /*!< LMP sub version */ 
	};

NONSHARABLE_CLASS(TBTQOS)
/**
BT quality of service definition.
@see BT code specification.
*/
	{
public:
	TUint8 iFlags; /*!< QoS flags */ 
	TUint8 iServiceType; /*!< Service type */
	TUint iTokenRate; /*!< Token rate */
	TUint iPeakBandwidth; /*!< Peak bandwidth */
	TUint iLatency; /*!< Latency */
	TUint iDelayVariation; /*!< Delay variation */
	};

/**
Connection handle class for use in the HCI API.

Although THCIConnHandle is a valid type to use for representing 
a connection handle, as there are commands that require an array
of the type to be provided, RArray instances are used as the
API. The type contents RArrays use must be at a minimum 4 bytes
in size.  This class provides a 4 byte encapsulation of a 2 byte
connection handle.

@see THCIConnHandle.
*/
NONSHARABLE_CLASS(THCIConnectionHandle)
	{
public:
	IMPORT_C THCIConnectionHandle();
	IMPORT_C THCIConnectionHandle(THCIConnHandle aConnHandle);
	IMPORT_C THCIConnectionHandle& operator=(THCIConnHandle aConnHandle);

	IMPORT_C THCIConnHandle ConnHandle() const;
	IMPORT_C operator THCIConnHandle() const;

private:
	THCIConnHandle iConnHandle;
	TUint16 iPad; // To pad the class out making it 4 bytes in total (for use in RArray).
	};

/**
Class for reporting the number of completed packets by either the
host or the controller over the HCI API.

Although a simple TUint16 would be sufficient, as there are commands
that require an array of the type to be provided as RArray instances
are used as the API. The type contents RArrays use must be at a 
minimum 4 bytes in size.  This class provides a 4 byte encapsulation
of a 2 byte value representing the {Host,HC}NumOfCompletedPackets.
*/
NONSHARABLE_CLASS(THCINumOfCompletedPackets)
	{
public:
	IMPORT_C THCINumOfCompletedPackets();
	IMPORT_C THCINumOfCompletedPackets(TUint16 aNumOfCompletedPackets);
	IMPORT_C THCINumOfCompletedPackets& operator=(TUint16 aNumOfCompletedPackets);

	IMPORT_C TUint16 NumOfCompletedPackets() const;
	IMPORT_C operator TUint16() const;

private:
	TUint16 iNumOfCompletedPackets;
	TUint16 iPad; // To pad the class out making it 4 bytes in total (for use in RArray).
	};

/**
Provides a representation of a clock offset value returned over the
Bluetooth HCI.
Intended for use within an RArray type class.
*/
NONSHARABLE_CLASS(THCIClockOffset)
	{
public:
	IMPORT_C THCIClockOffset();
	IMPORT_C THCIClockOffset(TUint16 aClockOffset);
	IMPORT_C THCIClockOffset& operator=(TUint16 aClockOffset);

	IMPORT_C TUint16 ClockOffset() const;
	IMPORT_C operator TUint16() const;

private:
	TUint16 iClockOffset;
	TUint16 iPad; // To pad the class out making it 4 bytes in total (for use in RArray).
	};

/**
Provides a representation of the page scan repetition mode value returned 
over the Bluetooth HCI.
Intended for use within an RArray type class.
*/
NONSHARABLE_CLASS(THCIPageScanRepetitionMode)
	{
public:
	IMPORT_C THCIPageScanRepetitionMode();
	IMPORT_C THCIPageScanRepetitionMode(TUint8 aPageScanRepetitionMode);
	IMPORT_C THCIPageScanRepetitionMode& operator=(TUint8 aPageScanRepetitionMode);

	IMPORT_C TUint8 PageScanRepetitionMode() const;
	IMPORT_C operator TUint8() const;

private:
	TUint8 iPageScanRepetitionMode;
	TUint8 iPad1; // To pad the class out making it 4 bytes in total (for use in RArray).
	TUint16 iPad2;
	};

/**
Acts as a suitable place holder for reserved octets that are returned over the
Bluetooth HCI.
Intended for use within an RArray type class.
*/
NONSHARABLE_CLASS(THCIReservedOctet)
	{
public:
	IMPORT_C THCIReservedOctet();
	IMPORT_C THCIReservedOctet(TUint8 aReservedOctet);
	IMPORT_C THCIReservedOctet& operator=(TUint8 aReservedOctet);

	IMPORT_C TUint8 ReservedOctet() const;
	IMPORT_C operator TUint8() const;

private:
	TUint8 iReservedOctet;
	TUint8 iPad1; // To pad the class out making it 4 bytes in total (for use in RArray).
	TUint16 iPad2;
	};

typedef TBTDevLMPVersion TBTDevRemoteHwVersion; /*!< Definition of the TBTDevRemoteHwVersion type */
typedef TUint16 THCIOpcode; /*!< Definition of the THCIOpcode type */
typedef TUint16 TBasebandTime; /*!< Definition of the TBasebandTime type */

#endif // HCITYPES_H
