// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef TERANOVA_CharacterV1_generated_h
#error "CharacterV1.generated.h already included, missing '#pragma once' in CharacterV1.h"
#endif
#define TERANOVA_CharacterV1_generated_h

#define ACharacterV1_EVENTPARMS
#define ACharacterV1_RPC_WRAPPERS
#define ACharacterV1_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define ACharacterV1_CALLBACK_WRAPPERS
#define ACharacterV1_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesACharacterV1(); \
	friend TERANOVA_API class UClass* Z_Construct_UClass_ACharacterV1(); \
	public: \
	DECLARE_CLASS(ACharacterV1, ACharacter, COMPILED_IN_FLAGS(0), 0, TeraNova, NO_API) \
	DECLARE_SERIALIZER(ACharacterV1) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<ACharacterV1*>(this); }


#define ACharacterV1_INCLASS \
	private: \
	static void StaticRegisterNativesACharacterV1(); \
	friend TERANOVA_API class UClass* Z_Construct_UClass_ACharacterV1(); \
	public: \
	DECLARE_CLASS(ACharacterV1, ACharacter, COMPILED_IN_FLAGS(0), 0, TeraNova, NO_API) \
	DECLARE_SERIALIZER(ACharacterV1) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<ACharacterV1*>(this); }


#define ACharacterV1_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACharacterV1(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACharacterV1) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ACharacterV1(const ACharacterV1& InCopy); \
public:


#define ACharacterV1_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ACharacterV1(const ACharacterV1& InCopy); \
public: \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACharacterV1)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME ACharacterV1


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
ACharacterV1_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ACharacterV1_RPC_WRAPPERS \
	ACharacterV1_CALLBACK_WRAPPERS \
	ACharacterV1_INCLASS \
	ACharacterV1_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ACharacterV1_RPC_WRAPPERS_NO_PURE_DECLS \
	ACharacterV1_CALLBACK_WRAPPERS \
	ACharacterV1_INCLASS_NO_PURE_DECLS \
	ACharacterV1_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP


