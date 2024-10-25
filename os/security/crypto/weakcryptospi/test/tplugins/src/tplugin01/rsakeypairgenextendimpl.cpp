/*
* Copyright (c) 2006-2010 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
* RSA Keypair (Extended Characteristics) implementation
* RSA keypair generation implementation
*
*/


/**
 @file
*/

#include "rsakeypairgenextendimpl.h"
#include "pluginconfig.h"

#include <ct.h>
#include <cryptospi/keypair.h>
#include <cryptospi/cryptospidef.h>

#include "../../../source/common/inlines.h"    // For TClassSwap

//Extended Charcteristics

static const TInt32 KExtendCharAttribute1 = 0x102ABCD1;
static const TUid KExtendCharAttribute1Uid ={KExtendCharAttribute1};

static const TInt32 KExtendCharAttribute2 = 0x102ABCD2;
static const TUid KExtendCharAttribute2Uid ={KExtendCharAttribute2};

static const TInt32 KExtendCharAttribute3 = 0x102ABCD3;
static const TUid KExtendCharAttribute3Uid ={KExtendCharAttribute3};

using namespace SoftwareCrypto;

/* CRSAKeyPairGenExtendImpl */
CRSAKeyPairGenExtendImpl::CRSAKeyPairGenExtendImpl(TUid aImplementationUid) : CKeyPairGenImpl(aImplementationUid)
	{
	}

CRSAKeyPairGenExtendImpl::~CRSAKeyPairGenExtendImpl()
	{
	delete iExtendChars;
	}

CRSAKeyPairGenExtendImpl* CRSAKeyPairGenExtendImpl::NewL(TUid aImplementationUid)
	{
	CRSAKeyPairGenExtendImpl* self = CRSAKeyPairGenExtendImpl::NewLC(aImplementationUid);
	CleanupStack::Pop(self);
	return self;
	}

CRSAKeyPairGenExtendImpl* CRSAKeyPairGenExtendImpl::NewLC(TUid aImplementationUid)
	{
	CRSAKeyPairGenExtendImpl* self = new(ELeave) CRSAKeyPairGenExtendImpl(aImplementationUid);
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

void CRSAKeyPairGenExtendImpl::ConstructL(void)
	{
	CKeyPairGenImpl::ConstructL();
	iExtendChars = CreateExtendedCharacteristicsL();
	}
	
CExtendedCharacteristics* CRSAKeyPairGenExtendImpl::CreateExtendedCharacteristicsL()
	{
	//***************************************************************
	CExtendedCharacteristics* exChars = CExtendedCharacteristics::NewL(KMaxTInt, EFalse);
	CleanupStack::PushL(exChars);
	
	exChars->AddCharacteristicL(9999,KExtendCharAttribute1Uid);
	exChars->AddCharacteristicL(1010,KExtendCharAttribute2Uid);
	exChars->AddCharacteristicL(_L8("SYMBIANTESTCHARACTERISTIC"),KExtendCharAttribute3Uid);
	//**************************************************************
	CleanupStack::Pop(exChars);
	
	return exChars;
	}

const CExtendedCharacteristics* CRSAKeyPairGenExtendImpl::GetExtendedCharacteristicsL()
	{
	return iExtendChars;
	}

TUid CRSAKeyPairGenExtendImpl::ImplementationUid() const
	{
	return iImplementationUid;
	}

void CRSAKeyPairGenExtendImpl::Reset()
	{
	// does nothing in this plugin
	}

void CRSAKeyPairGenExtendImpl::GenerateKeyPairL(TInt aKeySize, const CCryptoParams& aKeyParameters, CKeyPair*& aKeyPair)
	{
	/*
	 * extract e
	 */ 
	const TInt aKeyType = aKeyParameters.GetTIntL(KRsaKeyTypeUid);
	const TInt aPublicExponent = aKeyParameters.GetTIntL(KRsaKeyParameterEUid);

	RInteger e = RInteger::NewL(aPublicExponent);
	CleanupStack::PushL(e);

	/*
	 * calculate p, q, n & d
	 */ 
	RInteger p;
	RInteger q;
	
	//these make sure n is a least aKeySize long
	TInt pbits=(aKeySize+1)/2;
	TInt qbits=aKeySize-pbits;

	//generate a prime p such that GCD(e,p-1) == 1
	for (;;)
		{
		p = RInteger::NewPrimeL(pbits,TInteger::ETop2BitsSet);
		CleanupStack::PushL(p);
		--p;

		RInteger gcd = e.GCDL(p);
		if( gcd == 1 )
			{
			++p;
			gcd.Close();
			//p is still on cleanup stack
			break;
			}
		CleanupStack::PopAndDestroy(&p);
		gcd.Close();
		}

	//generate a prime q such that GCD(e,q-1) == 1 && (p != q)
	for (;;)
		{
		q = RInteger::NewPrimeL(qbits,TInteger::ETop2BitsSet);
		CleanupStack::PushL(q);
		--q;

		RInteger gcd = e.GCDL(q);
		if( gcd == 1 )
			{
			++q;
			if( p != q )
				{
				gcd.Close();
				//q is still on cleanup stack
				break;
				}
			}
		CleanupStack::PopAndDestroy(&q);
		gcd.Close();
		}
		
	//make sure p > q
	if ( p < q)
		{
		TClassSwap(p,q);
		}

	//calculate n = p * q
	RInteger n = p.TimesL(q);
	CleanupStack::PushL(n);

	--p;
	--q;

	//temp = (p-1)(q-1)
	RInteger temp = p.TimesL(q);
	CleanupStack::PushL(temp);

	//e * d = 1 mod ((p-1)(q-1))
	//d = e^(-1) mod ((p-1)(q-1))
	RInteger d = e.InverseModL(temp);
	CleanupStack::PopAndDestroy(&temp); //temp
	CleanupStack::PushL(d);

	/*
	 * create private key depending on aKeyType
	 */ 
	CCryptoParams* privateKeyParameters = CCryptoParams::NewLC();
	privateKeyParameters->AddL(n, KRsaKeyParameterNUid);
	TKeyProperty* privateKeyProperties = NULL;
	TKeyProperty privateKeyProperties_RsaPrivateKeyCRT = {KRSAKeyPairGeneratorUid, iImplementationUid,
									KRsaPrivateKeyCRTUid, KNonEmbeddedKeyUid };
	TKeyProperty privateKeyProperties_RsaPrivateKeyStandard = {KRSAKeyPairGeneratorUid, iImplementationUid,
									KRsaPrivateKeyStandardUid, KNonEmbeddedKeyUid };

	CCryptoParams*publicKeyParameters = CCryptoParams::NewLC();
	publicKeyParameters->AddL(n, KRsaKeyParameterNUid);
	publicKeyParameters->AddL(e, KRsaKeyParameterEUid);
	TKeyProperty publicKeyProperties = {KRSAKeyPairGeneratorUid, iImplementationUid,
									KRsaPublicKeyUid, KNonEmbeddedKeyUid };

	if (aKeyType == KRsaPrivateKeyCRT)			// cleanup stack contains e, p, q, n, d and privateKeyParameters
	{

		/*
		 * calculate dP, dQ and qInv
		 */ 
		//calculate dP = d mod (p-1)
		RInteger dP = d.ModuloL(p); //p is still p-1
		CleanupStack::PushL(dP);
		privateKeyParameters->AddL(dP, KRsaKeyParameterDPUid);
		CleanupStack::PopAndDestroy(&dP);

		//calculate dQ = d mod (q-1)
		RInteger dQ = d.ModuloL(q); //q is still q-1
		CleanupStack::PushL(dQ);
		privateKeyParameters->AddL(dQ, KRsaKeyParameterDQUid);
		CleanupStack::PopAndDestroy(&dQ);

		++p;
		++q;
		//calculate inverse of qInv = q^(-1)mod(p)
		RInteger qInv = q.InverseModL(p);
		CleanupStack::PushL(qInv);
		privateKeyParameters->AddL(qInv, KRsaKeyParameterQInvUid);
		CleanupStack::PopAndDestroy(&qInv);
		
		privateKeyParameters->AddL(p, KRsaKeyParameterPUid);
		privateKeyParameters->AddL(q, KRsaKeyParameterQUid);
		
		privateKeyProperties = &privateKeyProperties_RsaPrivateKeyCRT;
	}
	else if (aKeyType == KRsaPrivateKeyStandard)
	{
		privateKeyParameters->AddL(d, KRsaKeyParameterDUid);
		privateKeyProperties = &privateKeyProperties_RsaPrivateKeyStandard;
	}
	else
	{
		User::Leave(KErrNotSupported);
	}
	// cleanup stack contains e, p, q, n, d and privateKeyParameters
	CKey* privateKey = CKey::NewL(*privateKeyProperties, *privateKeyParameters);
	CleanupStack::PushL(privateKey);

	/*
	 * create public key
	 */
	CKey* publicKey = CKey::NewL(publicKeyProperties, *publicKeyParameters);
	CleanupStack::PushL(publicKey);

	/*
	* create the key pair
	*/
	aKeyPair = CKeyPair::NewL(publicKey, privateKey);

	CleanupStack::Pop(2, privateKey); //privateKey and publicKey
	CleanupStack::PopAndDestroy(7, &e); //e, p, q, n, d, privateKeyParameters and publicKeyParameters
	}
