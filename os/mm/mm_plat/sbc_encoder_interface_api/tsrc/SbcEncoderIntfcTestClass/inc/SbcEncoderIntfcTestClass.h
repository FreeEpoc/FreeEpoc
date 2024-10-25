/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: SbcEncoderIntfcTest
*
*/



#ifndef CSbcEncoderIntfcTestClass_H
#define CSbcEncoderIntfcTestClass_H

//  INCLUDES
#include <StifLogger.h>
#include <TestScripterInternal.h>
#include <StifTestModule.h>

#include <e32svr.h>
#include <e32base.h>
#include <e32cons.h>
#include <customInterfaceUtility.h>
#include <SoundDevice.h>
#include <SbcEncoderIntfc.h>
#include <MdaAudioInputStream.h>
#include <Mda/Common/Audio.h>
#include "TimeoutController.h"


// CONSTANTS
const TInt KErrBadTestParameter= -1000;         // Error on configuration file

const TInt KErrEventPending =-2000;             // Timeout and not callback
const TInt KErrCallbackErrorCode = -2001;       // Callback return error code
const TInt KErrUnexpectedValue =-2002;          // Unexpected value at setting
const TInt KErrTimeoutController = -2007;		// Unexpected notification

const TInt KShortTimeout = 1000;
const TInt KMediumTimeout = 4000;
const TInt KLongTimeout = 100000;


_LIT( KMsgBadTestParameters, "[Error] No valid test case parameters");

// General
_LIT( KTagWma, "Wma");
_LIT( KTagOutput32Bit, "Output32Bit");
_LIT( KTagDownMixToStereo, "DownMixToStereo");
_LIT( KTagLostDataConcealment, "LostDataConcealment");
_LIT( KTagTrue, "True");
_LIT( KTagFalse, "False");
_LIT( KTagDevSound, "DevSound");
_LIT( KTagInputStream, "InputStream");

// MACROS
//#define ?macro ?macro_def
// Logging path
#ifdef __WINSCW__
_LIT( KSbcEncoderIntfcTestClassLogPath, "\\logs\\testframework\\" );
#else
_LIT( KSbcEncoderIntfcTestClassLogPath, "e:\\testing\\Log\\" );
#endif

// Log file
_LIT( KSbcEncoderIntfcTestClassLogFile, "SbcEncoderIntfcTestClass.txt" );


// FORWARD DECLARATIONS
class CSbcEncoderIntfcTestClass;


// CLASS DECLARATION

/**
*  CRadioUtilityTestClass test class for STIF Test Framework TestScripter.
*  ?other_description_lines
*
*  @lib ?library
*  @since Series60_3_2
*/
NONSHARABLE_CLASS(CSbcEncoderIntfcTestClass) : public CScriptBase,
											public MTimeoutObserver,
											public MDevSoundObserver,
											public MMdaAudioInputStreamCallback
										//	public MRadioFmTunerObserver,
										//	public MRadioPlayerObserver,
										//	public MRadioRdsObserver
											/*public MRadioPresetObserver*/
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        */
        static CSbcEncoderIntfcTestClass* NewL( CTestModuleIf& aTestModuleIf );

        /**
        * Destructor.
        */
        virtual ~CSbcEncoderIntfcTestClass();

		enum TWmaExpectedEvent
		{
			EInitializeComplete,
			EMaiscOpenComplete,

		};

    public: // New functions

        /**
        * ?member_description.
        * @since ?Series60_version
        * @param ?arg1
        * @return
        */
        //?type ?member_function( ?type ?arg1 );

    public: // Functions from base classes

        /**
        * From CScriptBase Runs a script line.
        * @since ?Series60_version
        * @param aItem Script line containing method name and parameters
        * @return Symbian OS error code
        */
        virtual TInt RunMethodL( CStifItemParser& aItem );

		// Required for MDevSoundObserver:
        virtual void InitializeComplete(TInt /*aError*/);
        virtual void ToneFinished(TInt /*aError*/);
        virtual void BufferToBeFilled(CMMFBuffer* /*aBuffer*/);
        virtual void PlayError(TInt /*aError*/);
        virtual void BufferToBeEmptied(CMMFBuffer* /*aBuffer*/);
        virtual void RecordError(TInt /*aError*/);
        virtual void ConvertError(TInt /*aError*/);
        virtual void DeviceMessage(TUid /*aMessageType*/, const TDesC8& /*aMsg*/);

	    // Audio Input Stream
    	virtual void MaiscOpenComplete(TInt aError);
	    virtual void MaiscBufferCopied(TInt aError, const TDesC8& aBuffer);
    	virtual void MaiscRecordComplete(TInt aError);

	    // From MTimeoutObserver

	    /**
	    * @since ?Series60_version
	    * @param none
	    * Review if all the expected events have ocurred once the time is over
	    */
	    void HandleTimeout(TInt error);




    protected:  // New functions

        /**
        * ?member_description.
        * @since ?Series60_version
        * @param ?arg1
        * @return
        */
        //?type ?member_function( ?type ?arg1 );

    protected:  // Functions from base classes

        /**
        * From ?base_class ?member_description
        */
        //?type ?member_function();

    private:

        /**
        * C++ default constructor.
        */
        CSbcEncoderIntfcTestClass( CTestModuleIf& aTestModuleIf );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();

        // Prohibit copy constructor if not deriving from CBase.
        // ?classname( const ?classname& );
        // Prohibit assigment operator if not deriving from CBase.
        // ?classname& operator=( const ?classname& );

        /**
        * Frees all resources allocated from test methods.
        * @since ?Series60_version
        */
        void Delete();

        /**
        * Test methods are listed below.
        */

        /**
        * Example test method.
        * @since ?Series60_version
        * @param aItem Script line containing parameters.
        * @return Symbian OS error code.
        */

	    /**
	    * Set an event as expected and set default timeout
	    * @since ?Series60_version
	    */
	    void AddExpectedEvent(TWmaExpectedEvent event, TInt ms);


	    /**
	    * Unset an event as expected
	    * @since ?Series60_version
	    */
	    TBool RemoveExpectedEvent(TWmaExpectedEvent event);


	    /**
	    * @since ?Series60_version
	    * @param none
	    * Removes all expected events
	    */
	    void RemoveAllExpectedEvents();

	    /**
	    * Verify that the event was expected, removes it from the list
	    * Signal the TestScripter with the returned error code
	    * @since ?Series60_version
	    */
	    void ProcessEvent(TWmaExpectedEvent aEvent, TInt aError);

	    /**
	    * Maps a event with a descriptor with its name
	    * @since ?Series60_version
	    */
	    TPtrC EventName( TInt aKey );

	    /*
	    * Test methods are listed below.
	    */

	    /**
	    * Sets a timeout different since the default
	    * @since Series60_3_2
	    * @param aItem Script line containing parameters.
	    * @return Symbian OS error code.
	    */
	    TInt SetTimeout( CStifItemParser& aItem );

	    /**
	    *
	    * @since Series60_3_2
	    * @param aItem Script line containing parameters.
	    * @return Symbian OS error code.
	    */
	    TInt SetExpectedEvents( CStifItemParser& aItem );

	    /**
	    *
	    * @since Series60_3_2
	    * @param aItem Script line containing parameters.
	    * @return Symbian OS error code.
	    */
	    TInt SetAllowedPanic( CStifItemParser& aItem );

	    /**
	    * Connect to the default client to the server
	    * @since ?Series60_version
	    * @param aItem Script line containing parameters.
	    * @return Symbian OS error code.
	    */

		TInt ExampleL( CStifItemParser& aItem );
		TInt CreateSbcEncoderIntfc( CStifItemParser& aItem );
		TInt CreateObject( CStifItemParser& aItem );
		TInt InitializeDevSound( CStifItemParser& aItem );
		TInt SetDataTypeInputStream( CStifItemParser& aItem );

		TInt SetConfigureData();
		TInt GetConfigureData();

		TInt SetSamplingFrequency();
		TInt SetChannelMode();
		TInt SetNumOfSubbands();
		TInt SetNumOfBlocks();
		TInt SetAllocationMethod();
		TInt SetBitpoolSize();

		TInt GetSupportedSamplingFrequencies();
		TInt GetSupportedChannelModes();
		TInt GetSupportedNumOfBlocks();
		TInt GetSupportedNumOfSubbands();
		TInt GetSupportedAllocationMethods();
		TInt GetSupportedBitpoolRange();
		TInt GetSamplingFrequency();
		TInt GetChannelMode();
		TInt GetNumOfSubbands();
		TInt GetNumOfBlocks();
		TInt GetAllocationMethod();
		TInt GetBitpoolSize();

		TInt ApplyConfig();



    public:     // Data
        // ?one_line_short_description_of_data
        //?data_declaration;

    protected:  // Data
        // ?one_line_short_description_of_data
        //?data_declaration;

    private:    // Data

    	// reference to TestModuleIf
    	CTestModuleIf& iTestModuleIf;

    	CMMFDevSound*	iDevSound;
		CMdaAudioInputStream*     iAudioInputStream;
		CSbcEncoderIntfc* iSbcEncoder;

		RArray<TUint> iSupportedSamplingFrequencies;
		RArray<CSbcEncoderIntfc::TSbcChannelMode> iSupportedChannelModes;
		RArray<TUint> iSupportedNumOfBlocks;
		RArray<TUint> iSupportedNumOfSubbands;
		RArray<CSbcEncoderIntfc::TSbcAllocationMethod> iSupportedAllocationMethods;


		// Active object with a timer to timeout the test case
		CSimpleTimeout * iTimeoutController;

		// Indicates if the test case use a normal exit reason
		TBool iNormalExitReason;

		// List of expected events
		RArray<TWmaExpectedEvent> iExpectedEvents;

		// List of notification event (by the callback)
		RArray<TWmaExpectedEvent> iOcurredEvents;

		TMdaAudioDataSettings 		iStreamSettings;
        // ?one_line_short_description_of_data
        //?data_declaration;

        // Reserved pointer for future extension
        //TAny* iReserved;

    public:     // Friend classes
        //?friend_class_declaration;
    protected:  // Friend classes
        //?friend_class_declaration;
    private:    // Friend classes
        //?friend_class_declaration;

    };

#endif      // CSbcEncoderIntfcTestClass_H

// End of File
