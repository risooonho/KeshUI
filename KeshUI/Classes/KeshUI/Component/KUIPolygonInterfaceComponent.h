// Copyright 2014-2015 Matt Chapman. All Rights Reserved.

#pragma once

#include "KeshUI/Component/KUICanvasItemInterfaceComponent.h"
#include "KeshUI/KUIMacros.h"
#include "KUIPolygonInterfaceComponent.generated.h"

/**
 * KeshUI UI Framework (KUI) Polygon render component.
 */
UCLASS(ClassGroup="KeshUI|Component", Blueprintable, BlueprintType)
class KESHUI_API UKUIPolygonInterfaceComponent : public UKUICanvasItemInterfaceComponent
{
	GENERATED_BODY()
	KUI_CLASS_HEADER( UKUIPolygonInterfaceComponent )

	UKUIPolygonInterfaceComponent( const class FObjectInitializer& oObjectInitializer );

public:

	/* Gets the position of the component. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual const FVector2D& GetPosition() const;

	/* Sets the position of the component. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual void SetPositionStruct( const FVector2D& v2Position );

	/* Sets the position of the component. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual void SetPosition( float fX, float fY );

	/* Gets the radius of the component. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual const FVector2D& GetRadius() const;

	/* Sets the radius of the component. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual void SetRadiusStruct( const FVector2D& v2Radius );

	/* Sets the radius of the component.  If 0 height is given, it will be the same as the width. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual void SetRadius( float fWidth, float fHeight = 0.f );

	/* Gets the side count of the texture from the screen. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual int32 GetSideCount() const;

	/* Sets the texture location. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual void SetSideCount( int32 iSideCount );

	/* Gets the texture. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual UTexture* GetTexture() const;

	/* Sets the texture. Sets the screen size to match this if it's zero. */
	UFUNCTION(Category="KeshUI|Component|Polygon", BlueprintCallable)
	virtual void SetTexture( UTexture* tTexture );

	/* Gets the size of this component. */
	virtual const FVector2D& GetSize() const override;

	/* Returns true if there's enough information to render. */
	virtual bool HasValidComponents() const override;

protected:

	FVector2D v2Position;
	FVector2D v2Radius;
	FVector2D v2Size;
	int32 iSideCount;

	UPROPERTY() // Ensures reference count
	UTexture* tTexture;

	/* Tries to construct a new FCanvasPolygonItem! */
	virtual void ConstructNewItem() override;

};
