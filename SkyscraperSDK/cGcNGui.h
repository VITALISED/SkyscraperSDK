#pragma once
#include "cTkTypes.h"
#include "cGcIdleAnimList.h"
#include "Mission.h"

enum eShape : __int8
{
	EShape_Rectangle = 0x0,
	EShape_Ellipse = 0x1,
	EShape_Line = 0x2,
	EShape_LineInverted = 0x3,
	EShape_Bezier = 0x4,
	EShape_BezierInverted = 0x5,
	EShape_BezierWide = 0x6,
	EShape_BezierWideInverted = 0x7,
	EShape_NumTypes = 0x8,
};

enum eTkBlendMode : __int32
{
	EBlendMode_None = 0x0,
	EBlendMode_Normal = 0x1,
	EBlendMode_Additive = 0x2,
	EBlendMode_Subtractive = 0x3,
	EBlendMode_SourceRGBIsAlpha = 0x4,
	EBlendMode_EngineBlend = 0x5,
	EBlendMode_EngineAdd = 0x6,
	EBlendMode_EngineMult = 0x7,
	EBlendMode_EngineBlend_OutputOneMinusAlpha = 0x8,
	EBlendMode_EngineBlend_OutputAlpha = 0x9,
	EBlendMode_EngineAdd_OutputOneMinusAlpha = 0xA,
	EBlendMode_InvSourceAlpha = 0xB,
	EBlendMode_SourceAlpha = 0xC,
	EBlendMode_RgbOnly = 0xD,
	EBlendMode_AlphaOnly = 0xE,
	EBlendMode_Num = 0xF,
};

enum eAnimate : __int8
{
	EAnimate_None = 0x0,
	EAnimate_WipeRightToLeft = 0x1,
	EAnimate_SimpleWipe = 0x2,
	EAnimate_SimpleWipeDown = 0x3,
	EAnimate_CustomWipe = 0x4,
	EAnimate_CustomWipeAlpha = 0x5,
	EAnimate_NumTypes = 0x6,
};

enum eCurve : __int8
{
	ECurve_Linear = 0x0,
	ECurve_SmoothInOut = 0x1,
	ECurve_FastInSlowOut = 0x2,
	ECurve_BellSquared = 0x3,
	ECurve_Squared = 0x4,
	ECurve_Cubed = 0x5,
	ECurve_Logarithmic = 0x6,
	ECurve_SlowIn = 0x7,
	ECurve_SlowOut = 0x8,
	ECurve_ReallySlowOut = 0x9,
	ECurve_SmootherStep = 0xA,
	ECurve_SmoothFastInSlowOut = 0xB,
	ECurve_SmoothSlowInFastOut = 0xC,
	ECurve_EaseInSine = 0xD,
	ECurve_EaseOutSine = 0xE,
	ECurve_EaseInOutSine = 0xF,
	ECurve_EaseInQuad = 0x10,
	ECurve_EaseOutQuad = 0x11,
	ECurve_EaseInOutQuad = 0x12,
	ECurve_EaseInQuart = 0x13,
	ECurve_EaseOutQuart = 0x14,
	ECurve_EaseInOutQuart = 0x15,
	ECurve_EaseInQuint = 0x16,
	ECurve_EaseOutQuint = 0x17,
	ECurve_EaseInOutQuint = 0x18,
	ECurve_EaseInExpo = 0x19,
	ECurve_EaseOutExpo = 0x1A,
	ECurve_EaseInOutExpo = 0x1B,
	ECurve_EaseInCirc = 0x1C,
	ECurve_EaseOutCirc = 0x1D,
	ECurve_EaseInOutCirc = 0x1E,
	ECurve_EaseInBack = 0x1F,
	ECurve_EaseOutBack = 0x20,
	ECurve_EaseInOutBack = 0x21,
	ECurve_EaseInElastic = 0x22,
	ECurve_EaseOutElastic = 0x23,
	ECurve_EaseInOutElastic = 0x24,
	ECurve_EaseInBounce = 0x25,
	ECurve_EaseOutBounce = 0x26,
	ECurve_EaseInOutBounce = 0x27,
	ECurve_NumTypes = 0x28,
};

enum eGradient : __int8
{
	EGradient_None = 0x0,
	EGradient_Vertical = 0x1,
	EGradient_Horizontal = 0x2,
	EGradient_HorizontalBounce = 0x3,
	EGradient_Radial = 0x4,
	EGradient_Box = 0x5,
	EGradient_NumTypes = 0x6,
};

enum eVertical : __int8
{
	EVertical_Top = 0x0,
	EVertical_Middle = 0x1,
	EVertical_Bottom = 0x2,
	EVertical_NumTypes = 0x3,
};

/* 748 */
enum eHorizontal : __int8
{
	EHorizontal_Left = 0x0,
	EHorizontal_Center = 0x1,
	EHorizontal_Right = 0x2,
	EHorizontal_NumTypes = 0x3,
};

enum eWindowState : __int8
{
	EWindowState_Open = 0x0,
	EWindowState_Minimised = 0x1,
	EWindowState_Closed = 0x2,
	EWindowState_NumTypes = 0x3,
};

enum eNGuiAlignmentType : __int32
{
	eAlignment_TopLeft = 0x0,
	eAlignment_TopCenter = 0x1,
	eAlignment_TopRight = 0x2,
	eAlignment_CenterLeft = 0x3,
	eAlignment_Center = 0x4,
	eAlignment_CenterRight = 0x5,
	eAlignment_BottomLeft = 0x6,
	eAlignment_BottomCenter = 0x7,
	eAlignment_BottomRight = 0x8,
	eAlignmentTypeMax = 0x9,
};

enum eNGuiInputType : __int8
{
	eInput_RightDragged = 0xF8,
	eInput_RightPressed = 0xF9,
	eInput_RightHeld = 0xFA,
	eInput_Hover = 0xFB,
	eInput_Dragged = 0xFC,
	eInput_TouchPressReady = 0xFD,
	eInput_Pressed = 0xFE,
	eInput_Held = 0xFF,
	eInput_None = 0x0,
	eInput_Released = 0x1,
	eInput_Click = 0x2,
	eInput_RightReleased = 0x3,
	eInput_RightClick = 0x4,
};

enum eNGuiForcedStyle : __int32
{
	ENGuiForcedStyle_None = 0x0,
	ENGuiForcedStyle_Default = 0x1,
	ENGuiForcedStyle_Highlight = 0x2,
	ENGuiForcedStyle_Active = 0x3,
	ENGuiForcedStyle_NumTypes = 0x4,
};

enum eNGuiAnimationEvent : __int8
{
	eAnimationEvent_None = 0xFF,
	eAnimationEvent_Hover = 0x0,
	eAnimationEvent_Selected = 0x1,
	eAnimationEvent_Active = 0x2,
	eAnimationEvent_Custom1 = 0x3,
	eAnimationEvent_Custom2 = 0x4,
	eAnimationEvent_Custom3 = 0x5,
	eAnimationEventNum = 0x6,
};

struct __declspec(align(4)) cTkNGuiWindowLayoutData
{
	cTkFixedString<128, char> macName;
	cTkFixedArray<cTkFixedString<128, char>, 32> maacTabs;
	float mfPositionX;
	float mfPositionY;
	float mfSizeX;
	float mfSizeY;
	float mfSeparator;
	int miActiveTabIdx;
	float mfScrollX;
	float mfScrollY;
	eWindowState meWindowState;
};

struct cTkNGuiElementID
{
	__int64 miCounter;
	unsigned __int64 miBase;
	int miFrameRenderTracker;
	int miPerFrameUseCount;
};

struct cTkNGuiAnimationData
{
	float mafEventTime[2][6];
	float mfUpdated;
};

struct cTkNGuiEditorStyleColour
{
	cTkFixedString<128, char> macName;
	cTkColour mColour;
};

struct cTkCurveType
{
	eCurve meCurve;
};

struct __declspec(align(16)) cTkNGuiGraphicStyle
{
	cTkNGuiGraphicStyleData mDefault;
	cTkNGuiGraphicStyleData mHighlight;
	cTkNGuiGraphicStyleData mActive;
	cTkVector2 mCustomMinStart;
	cTkVector2 mCustomMaxStart;
	float mfHighlightTime;
	float mfHighlightScale;
	float mfGlobalFade;
	float mfAnimTime;
	float mfAnimSplit;
	cTkCurveType mAnimCurve1;
	cTkCurveType mAnimCurve2;
	eAnimate meAnimate;
	bool mbInheritStyleFromParentLayer;
};

struct __declspec(align(8)) cTkNGuiGraphicStyleData
{
	cTkColour mColour;
	cTkColour mIconColour;
	cTkColour mStrokeColour;
	cTkColour mGradientColour;
	cTkColour mStrokeGradientColour;
	float mfPaddingX;
	float mfPaddingY;
	float mfMarginX;
	float mfMarginY;
	float mfGradientStartOffset;
	float mfGradientEndOffset;
	float mfCornerRadius;
	float mfStrokeSize;
	int miImage;
	int miIcon;
	float mfDesaturation;
	float mfStrokeGradientOffset;
	float mfStrokeGradientFeather;
	eShape meShape;
	eGradient meGradient;
	bool mbSolidColour;
	bool mbHasDropShadow;
	bool mbHasOuterGradient;
	bool mbHasInnerGradient;
	bool mbGradientOffsetPercent;
	bool mbStrokeGradient;
};

struct cTkNGuiAlignment
{
	eVertical meVertical;
	eHorizontal meHorizontal;
};

struct cTkNGuiUndoable
{
	void(__fastcall * ~cTkNGuiUndoable)(cTkNGuiUndoable* _this);
	void(__fastcall* Undo)(cTkNGuiUndoable* _this);
	void(__fastcall* Do)(cTkNGuiUndoable* _this);
	bool(__fastcall* End)(cTkNGuiUndoable* _this);
	void* (__fastcall* GetData)(cTkNGuiUndoable* _this);
	const char* (__fastcall* ToString)(cTkNGuiUndoable* _this);
	unsigned int(__fastcall* Icon)(cTkNGuiUndoable* _this);
	cTkFixedString<64, char> mDescription;
};

template <typename T>
struct cTkFrameData
{
	bool mbSet;
	T mValue;
};

struct cTkNGuiScrollData
{
	float mfScrollX;
	float mfScrollY;
};

struct cTkNGuiLayoutList
{
	cTkDynamicArray<cTkNGuiLayoutListData> maLayouts;
};

struct cTkNGuiUserSettings
{
	cTkFixedString<256, char> macLastLoadedModel;
	cTkFixedString<256, char> macLastActiveLayout;
	cTkFixedArray<cTkFixedString<256, char>, 10> maacFileBrowserRecents;
};

template <typename T>
struct cTkUiDataMap
{
	std::vector<T, TkSTLAllocatorShim<T> > maUiData;
	std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID> > maElementIndices;
};

struct cTkNGuiElementData
{
	cTkNGuiAnimationData mAnimationData;
	cTkFrameData<float> mfCurrentOffset;
	cTkFrameData<float> mfScrollOffset;
	cTkFrameData<float> mfStartTime;
	cTkFrameData<enum eNGuiInputType> meLastInput;
	cTkFrameData<bool> mbLastDraw;
};

struct cTkNGuiWindowData
{
	void(__fastcall* mGuiCreateCallback)(cTkNGuiElementID, void*);
	void(__fastcall* mGuiRenderCallback)(void*);
	void* mpCallbackData;
	cTkFixedString<128, char> macTitle;
	cTkNGuiWindowLayoutData* mpLayout;
	bool mbIsDragged;
	bool mbIsResizedX;
	bool mbIsResizedY;
	bool mbSearchActive;
	cTkFixedString<256, char> mSearchFilter;
	std::vector<cTkFixedString<128, char>, TkSTLAllocatorShim<cTkFixedString<128, char>> > maErrors;
	cTkNGuiElementID mSnappedIdX;
	cTkNGuiElementID mSnappedIdY;
	bool mbRequestClose;
	float mfDragOffsetX;
	float mfDragOffsetY;
	std::vector<cTkNGuiElementID> maTabArray;
};

struct cTkNGuiToggleData
{
	bool mbIsActive;
};

struct cTkNGuiPanelData
{
	float mfHeight;
	float mfLabelWidth;
};

struct cTkNGuiTreeData
{
	bool mbIsMaximised;
	bool mbTabled;
	cTkVector2 mStartPos;
	cTkVector2 mTitleStartPos;
	float mfHeight;
};

struct cTkNGuiLayer
{
	enum ELayoutType : __int32
	{
		eLayout_SameLine = 0x0,
		eLayout_NextLine = 0x1,
		eLayout_SetPosition = 0x2,
		eLayout_MoveCursor = 0x3,
	};

	cTkVector2 mContentSize;
	cTkVector2 mContentMin;
	cTkVector2 mPosition;
	cTkVector2 mSize;
	cTkVector2 mCursorPosition;
	cTkBBox2d mLastContentBox;
	cTkBBox2d mLastContentBoxInner;
	float mfScale;
	float mfIndent;
	float mfCurrentLineHeight;
	cTkNGuiLayer::ELayoutType meLayout;
	cTkNGuiElementID mID;
	eNGuiAlignmentType meAlignment;
	eNGuiInputType meInput;
	cTkVector2 mSavedCursor;
	eNGuiAlignmentType meSavedAlignment;
	float mfSavedLineHeight;
};

struct cTkNGuiEditorLayout
{
	cTkFixedArray<cTkNGuiWindowLayoutData, 256> maWindows;
};

struct __declspec(align(8)) cTkNGuiUndoStack
{
	std::vector<cTkNGuiUndoable*, TkSTLAllocatorShim<cTkNGuiUndoable*> > maUndoStack;
	int miUndoStackIndex;
};

struct __declspec(align(16)) cTkNGuiTextStyleData
{
	cTkColour mColour;
	cTkColour mShadowColour;
	cTkColour mOutlineColour;
	float mfFontHeight;
	float mfFontSpacing;
	float mfDropShadowAngle;
	float mfDropShadowOffset;
	float mfOutlineSize;
	int miFontIndex;
	cTkNGuiAlignment mAlign;
	bool mbIsIndented;
	bool mbHasDropShadow;
	bool mbHasOutline;
	bool mbIsParagraph;
	bool mbAllowScroll;
	bool mbForceUpperCase;
	bool mbAutoAdjustHeight;
	bool mbAutoAdjustFontHeight;
	bool mbBlockAudio;
};

struct cTkNGuiTextStyle
{
	cTkNGuiTextStyleData mDefault;
	cTkNGuiTextStyleData mHighlight;
	cTkNGuiTextStyleData mActive;
};

struct cTkNGuiEditorStyleData
{
	cTkFixedArray<float, 48> mafSizes;
	cTkFixedArray<cTkNGuiEditorStyleColour, 8> maSkinColours;
	float mfSkinFontHeight;
	cTkFixedString<128, char> macFont;
	cTkFixedArray<cTkNGuiGraphicStyle, 72> maGraphicStyles;
	cTkFixedArray<cTkNGuiTextStyle, 14> maTextStyles;
	cTkDynamicArray<float> mafSnapSettings;
};

struct cTkNGuiGraphicStyleEntry
{
	void(__fastcall* mpRenderFunction)(cTkNGui*, void*, cTkBBox2d*, eNGuiInputType, cTkNGuiElementData*);
	void(__fastcall* mpMarginFunction)(cTkNGui*, void*, float*, float*, float*, float*, cTkNGuiElementData*);
	void* mpData;
};

struct cTkNGuiTextStyleEntry
{
	void(__fastcall* mpRenderFunction)(cTkNGui*, void*, const char*, cTkBBox2d*, eNGuiInputType, cTkNGuiElementData*);
	void(__fastcall* mpSizeFunction)(cTkNGui*, void*, const char*, const char*, float*, float*, cTkNGuiElementData*);
	void* mpData;
};

struct cTkNGuiLayoutListData
{
	cTkFixedString<128, char> macName;
	cTkFixedString<128, char> macFilename;
	cTkFixedString<128, char> macDefault;
	bool mbAutosave;
};

struct cTkNGuiPopup
{
	bool(__fastcall* Render)(cTkNGuiPopup* _this);
	cTkNGuiEditor* mpGui;
	cTkVector2 mPosition;
	cTkVector2 mSize;
};

struct cTkIconSelectPopup : cTkNGuiPopup
{
	unsigned int* mpuIcon;
};

struct __declspec(align(4)) cTkComboBoxPopup : cTkNGuiPopup
{
	const char* mpacLabel;
	__int64* mpaiSelectionMap;
	const char** mpaacEntries;
	int miNumEntries;
	float mfContentWidth;
	unsigned int* mpuSelected;
	int* mpiSelected;
	int miSelectedSize;
	bool mbDoScrollBars;
};

struct cTkNGuiTextEditState
{
	void(__fastcall *cTkNGuiTextEditState)(cTkNGuiTextEditState* _this);
	cTkFixedString<512, char> macEditedText;
	cTkFixedString<512, char> macInitialText;
	cTkFixedString<512, char> macShelvedTextEdit;
	cTkNGuiElementID mShelvedEditID;
	float mfWidth;
	float mfScrollX;
	float mfInitTime;
	float mfNavigateTime;
	STB_TexteditState* mpStbState;
	bool mbDoubleClicked;
	cTkNGuiEditor* mpGui;
};

class cTkNGui
{
	//cTkNGui_vtbl* __vftable /*VFT*/;
	std::vector<enum eNGuiInputType, TkSTLAllocatorShim<enum eNGuiInputType> > mInputStack;
	float mafFrameInverseMatrix[6];
	eNGuiInputType meLastInput;
	int miInputDepth;
	cTkVector2 mScreenSize;
	bool mbRendering;
	std::vector<enum eNGuiForcedStyle, TkSTLAllocatorShim<enum eNGuiForcedStyle> > maeForcedStyleStack;
	eNGuiAnimationEvent meNextElementAnimateEvent;
	bool mbNextElementAnimateIn;
	bool mbNextElementAnimateReset;
	cTkUiDataMap<cTkNGuiElementData> mElementDataMap;
	std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID> > maIDStack;
	std::vector<cTkNGuiLayer, TkSTLAllocatorShim<cTkNGuiLayer> > maLayerStack;
	std::vector<std::vector<cTkNGuiGraphicStyleEntry, TkSTLAllocatorShim<cTkNGuiGraphicStyleEntry> >, TkSTLAllocatorShim<std::vector<cTkNGuiGraphicStyleEntry, TkSTLAllocatorShim<cTkNGuiGraphicStyleEntry> >> > maGraphicStyleArray;
	std::vector<std::vector<cTkNGuiTextStyleEntry, TkSTLAllocatorShim<cTkNGuiTextStyleEntry> >, TkSTLAllocatorShim<std::vector<cTkNGuiTextStyleEntry, TkSTLAllocatorShim<cTkNGuiTextStyleEntry> >> > maTextStyleArray;
	robin_hood::detail::Table<1, 80, unsigned __int64, unsigned int, robin_hood::hash<unsigned __int64, void>, std::equal_to<unsigned __int64>> maIDUseCounts;
	bool mbForceSpecialtextRebuild;
	bool mbRebuildSpecialText;
	bool mbClippingEnabled;
	bool mbUsingWindowClipRegion;
	bool mbNodeGraphNodeActive;
	cTkBBox2d mWindowClipRegion;

	int(__fastcall* GetFontID)(cTkNGui* _this, int);
	float(__fastcall* GetFontSpacing)(cTkNGui* _this, int);
	bool(__fastcall* IsActive)(cTkNGui* _this);
	bool(__fastcall* IsHighlightActive)(cTkNGui* _this);
	bool(__fastcall* IsNGUIEditor)(cTkNGui* _this);
};

struct cTkNGuiEditor : cTkNGui
{
	enum eMenu
	{
		EMenu_Closed = 0xFFFFFFFF,
		EMenu_Main = 0x0,
		EMenu_Layouts = 0x1,
		EMenu_NumMenus = 0x2
	};

	struct cTkNGuiCategoryLookup
	{
		cTkFixedString<64, char> mName;
		int miParentIndex;
		std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID> > maMembers;
	};

	struct cTkTaskbarStackItem
	{
		int miIndex;
		float mfYPos;
	};

	cTkNGuiLayoutList* mpLayoutList;
	cTkNGuiUserSettings* mpUserSettings;
	cTkNGuiEditorLayout* mpLayout;
	const char* mpacLayoutFilename;
	bool(__fastcall* mpPopupRender)(void*);
	void* mpPopupData;
	bool mbPopupRendering;
	__declspec(align(8)) cTkComboBoxPopup mComboBoxPopup;
	cTkIconSelectPopup mIconSelectPopup;
	bool mbAdvanceActiveTextEdit;
	cTkNGuiTextEditState mTextEditState;
	cTkNGuiElementID mActiveTextEditID;
	cTkNGuiElementID mPrevActiveTextEditID;
	bool mbHasPrevActiveText;
	cTkNGuiElementID mActiveWindowID;
	cTkNGuiElementID mCurrentWindowID;
	cTkNGuiElementID mMouseOverWindowID;
	cTkNGuiElementID mDragTargetWindowID;
	cTkNGuiElementID mDragTargetCanditateWindowID;
	std::vector<float, TkSTLAllocatorShim<float> > mafLabelWidthStack;
	std::vector<cTkNGuiEditor::cTkNGuiCategoryLookup, TkSTLAllocatorShim<cTkNGuiEditor::cTkNGuiCategoryLookup> > maCategoryLookup;
	std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID> > maActiveWindowStack;
	cTkUiDataMap<cTkNGuiScrollData> mScrollDataMap;
	cTkUiDataMap<cTkNGuiScrollData> mPanelDataMap;
	cTkUiDataMap<cTkNGuiWindowData> mWindowDataMap;
	cTkUiDataMap<cTkNGuiTreeData> mTreeDataMap;
	cTkUiDataMap<cTkNGuiToggleData> mToggleDataMap;
	cTkUiDataMap<cTkNGuiPanelData> mDynamicPanelDataMap;
	std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID> > maDynamicPanelStack;
	std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID> > maTreeNodeStack;
	std::vector<bool, TkSTLAllocatorShim<bool> > maTreeNodeFilterStack;
	bool mbTaskbarRendering;
	cTkNGuiEditor::eMenu meTaskbarMenu;
	std::vector<cTkNGuiEditor::cTkTaskbarStackItem, TkSTLAllocatorShim<cTkNGuiEditor::cTkTaskbarStackItem> > maTaskbarStack;
	std::vector<cTkBBox2d, TkSTLAllocatorShim<cTkBBox2d> > maTaskbarBBox2dList;
	cTkFixedString<64, char> mTaskbarSearch;
	cTkNGuiUndoStack mUndoStack;
	cTkNGuiUndoable* mpPendingUndo;
	cTkNGuiUndoable* mpDeferredUndo;
	bool mbDeferredUndoEnd;
	cTkNGuiEditorStyleData* mpStyleData;
	cTkNGuiGraphicStyleData* maGraphicStylesBuffer;
	cTkNGuiTextStyleData* maTextStylesBuffer;
	cTkColour* maSkinColoursBuffer;
	float mfDragValueAccumulator;
	int miFontID;
};

struct ITkNGuiDraggable
{
	ITkNGuiDraggable_vtbl* __vftable /*VFT*/;
};

struct cGcNGuiLayer : cGcNGuiElement
{
	std::vector<cGcNGuiElement*, TkSTLAllocatorShim<cGcNGuiElement*> > mapElements;
	std::vector<cGcNGuiLayer*, TkSTLAllocatorShim<cGcNGuiLayer*> > mapLayerElements;
	std::vector<cTkVector2, TkSTLAllocatorShim<cTkVector2> > maPinnedPositions;
	__declspec(align(16)) cTkNGuiGraphicStyleData mPreviousGraphicsStyle;
	void(__fastcall* mpRenderFunction)(void*);
	void* mpRenderFunctionData;
	cGcNGuiLayerData* mpLayerData;
	cTkLinearHashTable<cTkHashedNGuiElement, cGcNGuiElement*, -1, 0, cTkHashedNGuiElement>* mpElementHashTable;
	unsigned __int64 muUniqueID;
	bool mbExpanded;
};

struct cGcNGuiElement : ITkNGuiDraggable
{
	enum eLayoutChangeEvent : __int8
	{
		ELayoutChange_Nothing = 0x0,
		ELayoutChange_PositionMode = 0x1,
		ELayoutChange_WidthMode = 0x2,
		ELayoutChange_HeightMode = 0x3,
		ELayoutChange_ConstrainMode = 0x4,
		ELayoutChange_Size = 0x5,
		ELayoutChange_Width = 0x6,
		ELayoutChange_Height = 0x7,
		ELayoutChange_Value = 0x8,
		ELayoutChange_ColourPreset = 0x9,
	};

	cTkBBox2d mContentBBox;
	cTkVector2 mvParallaxOffset;
	cTkNGuiTypeUndoable<cGcNGuiLayoutData>* mpUndoMoveEvent;
	cTkNGuiTypeUndoable<cGcNGuiLayoutData>* mpUndoResizeEvent;
	cTkNGuiTypeUndoable<cGcNGuiLayoutData>* mpUndoLayoutEvent;
	cGcNGuiLayer* mpParent;
	cGcNGuiElementData* mpElementData;
	eNGuiInputType meInputThisFrame;
	cGcNGuiElement::eLayoutChangeEvent meLayoutChangeEvent;
	eNGuiAnimationEvent meRequestAnim;
	cGcNGuiElement::sGcNGuiElementAnimSettings mAnim;
	bool mbSelectedToEdit;

	struct sGcNGuiElementAnimSettings
	{
		__int8 mbRequestAnimActivate : 1;
		__int8 mbRequestAnimReset : 1;
	};
};

struct cTkNGuiInput
{
	bool mbControlHeld;
	bool mbShiftHeld;
	bool mbAltHeld;
	float mfRightStickX;
	float mfRightStickY;
	float mfCursorX;
	float mfCursorY;
	float mfCursorDeltaX;
	float mfCursorDeltaY;
	float mfCursorSpeedModifierX;
	float mfCursorSpeedModifierY;
	float mfMousePosX;
	float mfMousePosY;
	float mfMouseScroll;
	eNGuiInputButtonState meMouseButtonState;
	eNGuiInputButtonState meMouse2ButtonState;
	eNGuiInputButtonState meRightThumbState;
	eNGuiInputButtonState meTransferButtonState;
	eNGuiInputButtonState meUploadButtonState;
	eNGuiInputButtonState meDiscoveryUploadButtonState;
	bool mbCursorIsMouse;
	bool mbPadOnly;
	std::vector<std::pair<cTkNGuiElementID, enum eNGuiInputType>, TkSTLAllocatorShim<std::pair<cTkNGuiElementID, enum eNGuiInputType>, 8, -1> > maElementsPressed;
	std::vector<std::pair<cTkNGuiElementID, enum eNGuiInputType>, TkSTLAllocatorShim<std::pair<cTkNGuiElementID, enum eNGuiInputType>, 8, -1> > maElementsPressed2;
	int KeyMap[19];
	bool KeyCtrl;
	bool KeyShift;
	bool KeyAlt;
	bool maKeysDown[512];
	char maInputCharacters[17];
	bool mbPadActive;
	ITkNGuiDraggable* mpDragObject;
};

struct cTk2dLayer : cTk2dObject
{
	cTkBitArray<unsigned __int64, 512> mBitArray;
	eTkBlendMode meBlendMode;
	cTk2dObject* mpFirstChild;
	bool mbIsVisible;
	bool mbDynamicSize;
	cTkVector2 mScale;
	float mfAngle;
};

struct cTk3dLayer : cTk2dLayer
{
	enum eDepthTest : __int32
	{
		EDepthTest_None = 0x0,
		EDepthTest_Normal = 0x1,
		EDepthTest_Inverse = 0x2,
	};

	cTkVector3 mWorldPosition;
	cTkVector4 mScreenPosition;
	cTkVector4 mScreenPositionLeft;
	cTkVector4 mScreenPositionRight;
	float mfScreenDepth;
	float mfDefaultDistToCamera;
	float mfMinScale;
	float mfMaxScale;
	cTk3dLayer::eDepthTest meTestZ;
	bool mbEnable3d;
	bool mbScale3d;
};

struct __declspec(align(16)) cTk2dImage : cTk2dObject
{
	cTkVector2 maUVs[4];
	cTkTexture* mpTexture;
	cTkDynamicTexture* mpDynamicTexture;
	float mfTextureMipLevel;
	bool mbVisible;
	bool mbTiledUV;
	bool mbIsRenderTarget;
};

struct cGcNGui
{
	cGcNGuiLayer mRoot;
	cTkNGuiInput mInput;
	bool mbUseInput;
	float mfPixelRatio;
	bool mbFullscreen;
	cTkVector2 mCustomSize;
	bool mbHasCustomSize;
	bool mbIsInWorld;
	cTk3dLayer mTk3dLayer;
	cTk2dImage mTk2dImage;
};

struct ScrollBarState
{
	int miNumEntries;
	int miCurrentStartIndex;
	int miEntriesPerPage;
	cTkVector2 mfLastSeenPos;
	cTkVector2 mfLastSeenSize;
};

struct __declspec(align(16)) cTk2dImageEx : cTk2dImage
{
	cTkSmartResHandle mResource;
};

struct __declspec(align(16)) cGcHUDImage
{
	cTk2dImageEx mImage;
	cGcHUDImageData* mpData;
	cTkColour mColourStart;
	cTkColour mColourEnd;
	cTkTimerTemplate<0> mColourTimer;
};

struct __declspec(align(16)) cGcHUDText
{
	cTkFixedString<256, wchar_t> mBuffer;
	cTk2dText mText;
	cGcHUDTextData* mpData;
};

struct __declspec(align(16)) cGcHUD
{
	enum eCrosshair : __int32
	{
		ECrosshair_None = 0x0,
		ECrosshair_Normal = 0x1,
		ECrosshair_Target = 0x2,
	};

	cTkSmartResHandle mUIMaterial;
	cGcHUDLayer maLayers[128];
	int miNumLayers;
	cGcHUDImage maImages[128];
	int miNumImages;
	cGcHUDText maTexts[128];
	int miNumTexts;
};

struct __declspec(align(8)) cGcHUDMarker
{
	typedef cGcFrontendManager::eState eState;

	enum eShowLargeState : __int32
	{
		EShowLarge_Inactive = 0x0,
		EShowLarge_In = 0x1,
		EShowLarge_ShowLarge = 0x2,
		EShowLarge_Out = 0x3,
		EShowLarge_NumStates = 0x4,
	};

	enum eHoverState : __int32
	{
		EHoverState_Inactive = 0x0,
		EHoverState_VisibleIn = 0x1,
		EHoverState_Visible = 0x2,
		EHoverState_ActiveIn = 0x3,
		EHoverState_Active = 0x4,
		EHoverState_StayActive = 0x5,
		EHoverState_ActiveLocked = 0x6,
		EHoverState_StayActiveLocked = 0x7,
		EHoverState_ActiveOut = 0x8,
		EHoverState_VisibleOut = 0x9,
		EHoverState_NumStates = 0xA,
	};

	struct CompassUpdate
	{
		bool mbHasCompassIcon;
		bool mbIsOnCurrentPlanet;
		bool mbClosestMarkerToCentreCompass;
	};

	cTkColour mColour;
	cGcMarkerPoint mData;
	cTk2dImageEx mArrowIcon;
	cTkVector2 mCachedCompassPos;
	float mfFade;
	float mfScaleFactor;
	cTkFixedString<128, char> mDebugTextBuffer;
	cGcNGui mMarkerIconsNGui;
	cGcNGuiLayer* mpMarkerIconsLayer;
	cGcNGuiLayer* mpMarkerAnimsLayer;
	cGcNGuiGraphic* mpMarkerIconNormal;
	cGcNGuiGraphic* mpMarkerIconSmall;
	cGcNGuiGraphic* mpMarkerIconBinocs;
	cGcNGuiGraphic* mpMarkerIconHighlight;
	cGcNGuiGraphic* mapMarkerIconAnims[3];
	cTkColour mMarkerColour;
	cTkColour mHighlightColour;
	cTkColour maAnimsColours[3];
	float mfMarkerNGuiSize;
	cGcNGui mDistanceTextNGui;
	cGcNGui mCompassDistanceNGui;
	cGcNGuiLayer* mpDistanceTextBottomLayer;
	cGcNGuiLayer* mpDistanceTextTopLayer;
	cGcNGuiLayer* mpDistanceTextCentered;
	cGcNGuiLayer* mpCompassDistanceLayer;
	cGcNGuiLayer* mpCrossplayLayer;
	bool mbDistanceTextShowBottomLayer;
	bool mbDistanceTextShowTopLayer;
	bool mbDistanceTextShowCentered;
	cTkFixedString<128, char> mNGuiDistanceText;
	cTkFixedString<128, char> mNGuiNameText;
	cTkFixedString<128, char> mNGuiCompassDistanceText;
	cGcNetworkConstants::OnlinePlatformType mePlatformIcon;
	cTk2dLayer mCompassLayer;
	cTk2dImageEx maCompassIcons[3];
	cTk2dImageEx mCompassPrimaryIconIndicator;
	bool mbHasCompassIcon;
	bool mbHasLightBeam;
	bool mbDistanceFades;
	bool mbReset;
	cTkSmoothCD<float> mIconSize;
	cTkPhysRelVec3 mFinalPosition;
	cGcHUDMarker::CompassUpdate mCompassUpdate;
	cGcHUDMarker::eHoverState meHoverState;
	float mfHoverTimer;
	float mfShowTagLabelTimer;
	float mfHoverLockTimer;
	float mfHoverLockedTime;
	float mfCreationTime;
	cGcHUDMarker::eState meState;
	eIcon meCurrentIcon;
	bool mbShowMarker;
	bool mbShowLabels;
	float mfStartTime;
	float mfTagRingFade;
	float mfActiveFactor;
	cGcHUDMarker::eShowLargeState meShowLargeState;
	float mfShowLargeTimer;
	cTkSmartResHandle mDefaultIconTexture;
	unsigned int mLineHandle;
	cTkColour mOverwriteColour;
	int miAbandonedFreighterRoom;
	bool mbAbandonedFreighterRoomSet;
	cTkFixedArray<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, 3> maIconsHandles;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mIconHighlightHandle;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mAnimHandle;
	cTkClassPoolHandle mMarkerHandle;
	cTkClassPoolHandle mDistLabelHandle;
};

enum eIcon : __int32
{
	EIcon_Scanner = 0x0,
	EIcon_Scanner_Small = 0x1,
	EIcon_Binoculars = 0x2,
	EIcon_NumTypes = 0x3,
};

enum eGcTrackArrowTypes : __int32
{
	ETrackArrow_WantedCombat = 0x0,
	ETrackArrow_WantedHunting = 0x1,
	ETrackArrow_Investigate = 0x2,
	ETrackArrow_Predator = 0x3,
	ETrackArrow_HazardHot = 0x4,
	ETrackArrow_HazardCold = 0x5,
	ETrackArrow_HazardRadiation = 0x6,
	ETrackArrow_HazardToxic = 0x7,
	ETrackArrow_ShipsArriving = 0x8,
	ETrackArrow_PiratesArriving = 0x9,
	ETrackArrow_PoliceArriving = 0xA,
	ETrackArrow_Ship = 0xB,
	ETrackArrow_PrimaryShip = 0xC,
	ETrackArrow_SecondaryShip = 0xD,
	ETrackArrow_Freighter = 0xE,
	ETrackArrow_Missile = 0xF,
	ETrackArrow_Building = 0x10,
	ETrackArrow_Friend = 0x11,
	ETrackArrow_FriendScared = 0x12,
	ETrackArrow_FriendSearching = 0x13,
	ETrackArrow_NetworkPlayer = 0x14,
	ETrackArrow_Fiend = 0x15,
	ETrackArrow_Repair = 0x16,
	ETrackArrow_Summoning = 0x17,
	ETrackArrow_NumTypes = 0x18,
};

struct cGcHUDTrackArrow
{
	enum eReticuleState : __int32
	{
		EReticule_Inactive = 0x0,
		EReticule_Active = 0x1,
		EReticule_Deactivating = 0x2,
	};

	cTkVector2 mSize;
	cTkColour mColour;
	float mfArrowScale;
	float mfFadeTime;
	bool mbFade;
	cTkSmartResHandle maReticules[24];
	cTkSmartResHandle maReticuleGlows[24];
	cTkSmartResHandle maArrows[24];
	cTkSmartResHandle maArrowGlows[24];
	cTkSmartResHandle maIcons[24];
	__declspec(align(8)) TkAudioID maAudioPings[24];
	cTkSmartResHandle mCriticalIcon;
	cTkSmartResHandle mCriticalGlowIcon;
	cTkSmartResHandle mDamageGlow;
	cTkSmartResHandle mEnergyShieldGlow;
	cTkSmartResHandle mTypeIcon;
	float mfTypeIconPulse;
	float mfTypeIconFade;
	float mafBaseSizes[24];
	float mafBaseDotSizes[24];
	eGcTrackArrowTypes meType;
	cTkSmartResHandle mExternalIcon;
	cTkAttachmentPtr mpTarget;
	cTkPhysRelVec3 mFixedTarget;
	cTkPhysRelVec3 mWorldPos;
	cTkPhysRelVec3 mProjWorldPos;
	cTkVector2 mScreenPos;
	cTkVector2 mReticulePos;
	float mfAngle;
	float mfBorderFactor;
	float mfCentreOffsetMultiplier;
	cTkColour mHealthColour;
	cTkColour mHealthCriticalHitColour;
	float mfHealthBar;
	float mfIconFade;
	bool mbUseLabelOffset;
	cTkColour mEnergyShieldColour;
	float mfEnergyShieldBar;
	bool mbFixedTarget;
	bool mbOnScreen;
	bool mbUsingSmallIcon;
	cGcHUDTrackArrow::eReticuleState meReticuleState;
	float mfReticuleActiveTime;
	float mfReticuleDeactiveTime;
	float mfReticuleScale;
	cTkColour mGlowColour;
	cTkColour mDamageGlowColour;
	cTkColour mEnergyShieldGlowColour;
	cTkFixedString<128, char> mText;
	cTkClassPoolHandle mTrackArrowHandle;
	cTkClassPoolHandle mHealthHandle;
};

struct __declspec(align(16)) cGcPositionMarker
{
	enum eType : __int32
	{
		EPositionMarkerType_Creature = 0x0,
		EPositionMarkerType_CreatureDiscovered = 0x1,
		EPositionMarkerType_CreatureOutOfRange = 0x2,
		EPositionMarkerType_NumTypes = 0x3,
	};

	cGcPositionMarker::eType meType;
	float mfAlpha;
	cTkSmoothCD<float> mfDistanceAlpha;
	float mfDistance;
	bool mbAnimation;
	float mfAnimationValue;
	cTkVector2 mSize;
	cTkVector2 mScreenPos;
	cTkPhysRelVec3 mPosition;
	cTkSmartResHandle mIcon;
	cTkSmartResHandle mAnimation;
	cTkColour mColour;
	cTkClassPoolHandle mScreenHandle;
};

struct __declspec(align(16)) cGcHUDPulseEffect
{
	cGcNGuiLayer* mpLayer;
	cTkNGuiRectanglePulseEffect* mpData;
	cTkColour mColour;
	float mfStartTime;
};

struct cGcHUDPulseManager
{
	cTkClassPool<cGcHUDPulseEffect, 32> mArray;
};

struct cGcPlayerHUD : cGcHUD
{
	cGcNGui mHelmetGUI;
	cGcNGui mCrosshairGui;
	cGcNGui mHelmetLines;
	bool mabHelmetLinesVisible[5];
	cGcNGuiLayer mQuickMenu;
	cTk2dLayer mHUDEffectLayer;
	float mfWeaponActiveTime;
	cGcPlayerHUD::eCrosshair meCrosshair;
	bool mbShowReload;
	cGcHUDMarker maMarkers[128];
	cTk2dImageEx mLeadTargetInner;
	cTkHitCurve mLeadTargetHitCurve;
	float mfLeadTargetLastHit;
	cTk2dLayer mDroneNearLayer;
	cTk2dImageEx mDroneNearIndicator;
	cTk2dLayer mPainLayer;
	cTk2dImageEx mPainIndicator;
	float mfPainTime;
	cTkVector2 mShieldPanelBasePos;
	cTkVector2 mHazardPanelBasePos;
	cTkVector2 mWeaponPanelBasePos;
	cTkVector2 mIndicatorPanelBasePos;
	cTkVector2 mBuildInfoPanelBasePos;
	cTkVector2 mOSDMessagePanelBasePos;
	cTkVector2 mMissionMessagePanelBasePos;
	cTkVector2 mMissionDetailMessageBasePos;
	float mfLastEnergyDischargeTime;
	cTkVector2 mQuickMenuPos;
	cTkVector2 mTextChatLayerPos;
	cTkVector2 mPlayerListPos;
	cTkSmoothCD<cTkVector2> mShieldPanelPos;
	cTkSmoothCD<cTkVector2> mHazardPanelPos;
	cTkSmoothCD<cTkVector2> mWeaponPanelPos;
	cTkSmoothCD<cTkVector2> mIndicatorPanelPos;
	cTkSmoothCD<cTkVector2> mBuildInfoPanelPos;
	cTkSmoothCD<cTkVector2> mOSDMessagePanelPos;
	cTkSmoothCD<cTkVector2> mMissionMessagePanelPos;
	cTkSmoothCD<cTkVector2> mMissionDetailMessagePos;
	cTkSmoothCD<float> mZoomFadeFactor;
	cTkSmoothCD<cTkVector3> mAimTargetInterceptOffset;
	cTkVector2 mAimTargetInterceptPos;
	cTkSmoothCD<float> mfLeadTargetOverTargetFactor;
	float mfLeadTargetLockFactor;
	bool mbLeadTargetLocked;
	bool mbLeadTargetActive;
	bool mbLeadTargetIsThreat;
	float mfLeadTargetLockTime;
	float mfAimTargetAngle;
	cTkDynamicTexture* mpActiveUITexture;
	cTkDynamicTexture mUITexture;
	cTkDynamicTexture mUIMaskTexture;
	cTkSmartResHandle mWeaponScreenTextureRes;
	cTkSmartResHandle mUITextureRes;
	cTkSmartResHandle mUIMaskTextureRes;
	cTkSmartResHandle maHazardFullscreenTextures[6];
	cTkSmartResHandle maHazardFullscreenNormals[6];
	cTkSmartResHandle maHazardFullscreenRefractionTextures[6];
	cTkSmartResHandle mCamoFullscreenTexture;
	cTkSmartResHandle mCamoFullscreenNormalTexture;
	cTkFixedArray<cGcHUDTrackArrow, 8> maTrackArrows;
	cTkFixedArray<cGcPositionMarker, 500> maPositionMarkers;
	int miPositionMarkersNum;
	float mfHazardRestoreTime;
	int miHazardFullscreenSamplerIndex;
	int miHazardFullscreenNormalSamplerIndex;
	int miHazardFullscreenRefractionSamplerIndex;
	cTkSmartResHandle mHazardFullscreenActiveTexture;
	cTkSmartResHandle mHazardFullscreenActiveNormalTexture;
	cTkSmartResHandle mHazardFullscreenActiveRefractionTexture;
	cTkSmoothCD<float> mfHazardEffect;
	cTkSmoothCD<float> mfLowShieldFullscreenEffect;
	float mfShieldDownScanLine;
	cTkSmoothCD<cTkVector4> mFinalLowHealthVignetteUniform;
	cTkSmoothCD<cTkVector4> mFinalCriticalHitUniform;
	cTkSmoothCD<cTkVector3> mFinalGeneralVignetteUniform;
	cTkSmoothCD<float> mfFinalZoomVignetteUniform;
	float mfLastPlayerDamageTime;
	float mfLastFlashTime;
	float mfFlashDuration;
	float mfFlashDelay;
	float mfFlashIntensity;
	float mfExtraWarningTimer;
	cTkSmoothCD<float> mfShieldBar;
	float mfHeatBar;
	float mfCooldownBar;
	cTkSmoothCD<float> mfAimAmount;
	float mfLastShieldHitTime;
	int miLastWeaponModeIndex;
	int miLastWeaponAltModeIndex;
	int miLastTerrainEditMode;
	bool mbRechargeShield;
	float mfTimeSentinelsLastSearchedForPlayer;
	cGcHUDPulseManager mPulseEffects;
	float mfShowHUDTime;
	float mfHideHUDTime;
	float mfFreeLookAlpha;
	eHazard mePrimaryHazard;
	eHazard meSecondaryHazard;
	float mfPrimaryHazardTimer;
	float mfSecondaryHazardTimer;
	float mfPrimaryHazardStrength;
	float mfEnvironmentUpdateTimer;
	float mfAssertTimer;
	float mfOriginalMessageBoxOffset;
	float mfInitialMarkerWidth;
	float mfInitialMarkerHeight;
	cGcNGuiLayer* mpMarkerParent;
	cGcNGuiLayer* mapHelmetLinesLayer[5];
	cGcNGuiLayer* mpHelmetCompassLinesLayer;
	cGcNGuiLayer* mpReloadLayer;
	cGcNGuiLayer* mpReloadVRLayer;
	cGcNGuiLayer* mpReticleLayer;
	cGcNGuiLayer* mpShipCursorLayer;
	cGcNGuiTextSpecial* mpCrosshairControlsTextSpecial;
	cGcNGuiLayer* mpCrosshairNormalLayer;
	cGcNGuiLayer* mpCrosshairTargetLayer;
	cGcNGuiLayer* mpCrosshairDotLayer;
	cGcNGuiLayer* mpCrosshairAimLayer;
	cGcNGuiLayer* mpHitMarkerLayer;
	cGcNGuiLayer* mpNoShootLayer;
	cGcNGuiLayer* mpHUDShieldLayer;
	cGcNGuiLayer* mpShieldBarLayer;
	cGcNGuiLayer* mpShieldIconLayer;
	cGcNGuiLayer* mpShieldTechLayer;
	cGcNGuiLayer* mpHealthIconsLayer;
	cGcNGuiLayer* mpHUDWeaponLayer;
	cGcNGuiLayer* mpCombatMessageLayer;
	cGcNGuiTextSpecial* mpWeaponNameText;
	cGcNGuiTextSpecial* mpSwitchPrimaryTextSpecial;
	cGcNGuiTextSpecial* mpSwitchSecondaryTextSpecial;
	cGcNGuiTextSpecial* mpAltWeaponNameText;
	cGcNGuiGraphic* mpWeaponLabelBackgroundGraphic;
	cGcNGuiLayer* mpWeaponStatsLayer;
	cGcNGuiLayer* mpWeaponIconLayer;
	cGcNGuiLayer* mpWeaponTerrainLayer;
	cGcNGuiLayer* mpWeaponTerrainIconLayer;
	cGcNGuiTextSpecial* mpWeaponTerrainText;
	cGcNGuiLayer* mpWeaponGrenadeLayer;
	cGcNGuiLayer* mpGrenadeIconLayer;
	cGcNGuiLayer* mpWantedLayer;
	cGcNGuiLayer* mpHUDHazardLayer;
	cGcNGuiLayer* mpEnergyBarLayer;
	cGcNGuiLayer* mpHUDIndicatorsLayer;
	cGcNGuiLayer* mpStaminaLayer;
	cGcNGuiLayer* mpJetpackLayer;
	cGcNGuiLayer* mpStealthLayer;
	cGcNGuiLayer* mpScannerLayer;
	cGcNGuiLayer* mpSentinelLayer;
	cGcNGuiLayer* mpHUDInventoryLayer;
	cGcNGuiLayer* mpHUDOSDMessageLayer;
	cGcNGuiLayer* mpHUDBuildInfoLayer;
	cGcNGuiLayer* mpHUDBuildInfoLargeLayer;
	cGcNGuiTextSpecial* mpHUDBuildAvailableTextSpecial;
	cGcNGuiTextSpecial* mpHUDBuildPinTextSpecial;
	cGcNGuiTextSpecial* mpBaseOwnerTextSpecial;
	cGcNGuiLayer* mpBaseOwnerOfflineLayer;
	cGcNGuiLayer* mpBaseOwnerOnlineLayer;
	cGcNGuiLayer* mpHUDBasePowerLayer;
	cGcNGuiLayer* mpMissionMessageLayer;
	cGcNGuiLayer* mpMissionDetailMessageLayer;
	cGcNGuiLayer* mpTextChatLayer;
	cGcNGuiLayer* mpTextChatBackgroundLayer;
	cGcNGuiLayer* mpPlayerListLayer;
	cGcNGuiLayer* mpVoiceChatBackgroundLayer;
	TkID<128> mLastKnownCrosshairStyle;
	TkID<128> mNextCrosshairStyle;
	TkID<128> mRenderCrosshairStyle;
	float mfMouseLength;
	cTkVector2 mCrosshairScreen;
	cTkVector2 mCrosshairAimScreen;
	cTkVector2 mCrosshairMoveScreen;
	cTkVector2 mCrosshairLineStartScreen;
	float mfTaggedMarkerChangedTime;
	float mfTagButtonNotHeldTime;
	cGcBinoculars::eMode meBinocularsUIOverlay;
	bool mbBuildingMessageActive;
	const cGcBuilding* mpLastBuildingEntered;
	float mfLastBuildingExitTime;
	int miAbandonedFreighterRoomIndex;
	__int16 miAbandonedFreighterRoomsVisited;
	float mfPhonePulse;
	float mfSentinelPulse;
	cTkSmoothCD<float> mSentinelFade;
	bool mbShowDroneIcon;
	bool mbWantsTargetCrosshair;
	bool mbWasZoomingLastFrame;
	bool mbShowBaseDefence;
	float mfBaseDefenceActivation;
	float mfWeaponHeatWarningFactor;
	float mfWeaponHeatFactor;
	float mfWeaponAlertPoint;
	float mfWeaponCooldownFactor;
	int miCurrentMaxHealthPips;
	float mfJetpackAmount;
	float mfStealthAmount;
	float mfVehicleFuelRegen;
	std::vector<cGcPlayerHUD::DisplayNumber, TkSTLAllocatorShim<cGcPlayerHUD::DisplayNumber> > maNumbers;
	std::vector<std::pair<int, cTkClassPoolHandle>, TkSTLAllocatorShim<std::pair<int, cTkClassPoolHandle>> > maDamageHandles;
	std::vector<int, TkSTLAllocatorShim<int> > maiShootableImpactsIndices;
	std::vector<cGcPlayerImpact, TkSTLAllocatorShim<cGcPlayerImpact> > maProjectileImpacts;
};

enum ePlanetLabelState : __int32
{
	EPlanetLabelState_None = 0x0,
	EPlanetLabelState_Planet = 0x1,
	EPlanetLabelState_PlanetTimingOut = 0x2,
};

struct cGcShipHUD : cGcHUD
{
	struct __declspec(align(16)) cGcVehicleScreen
	{
		cTkDynamicTexture mScreenTexture;
		cGcNGui mScreenGUI;
		bool mbValid;
	};

	cTk2dLayer mHUDLayer;
	cTk2dImageEx mCrosshairOuterCircleLarge;
	cTk3dLayer mCrosshairOuterCircleLargeLayer;
	cTk2dImageEx mCrosshairOuterCircleSmall;
	cTk3dLayer mCrosshairOuterCircleSmallLayer;
	cTk2dLayer mMouseArrowLayer;
	cTk2dImageEx mMouseArrowIcon;
	cTkVector3 mShipForwardScreenPos;
	float mfShipAngle;
	float mfShipPitch;
	EffectInstance mLandingEffect;
	cTkFixedArray<cGcHUDTrackArrow, 8> maTrackArrows;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maShootList;
	int miSelectedPlanet;
	ePlanetLabelState meSelectedPlanetLabelState;
	float mfSelectedPlanetPanelTime;
	float mfSelectedPlanetPanelFadeTime;
	bool mbSelectedPlanetPanelVisible;
	bool mbSelectedPlanetIsTargeted;
	float mfLastKnownScanTime;
	float mfScanRevealTimer;
	ePulseDriveState meMiniJumpState;
	bool mbHasPulseEncounterOnHUD;
	cGcRenderableScreen* mapScreens[2];
	int miCurrentScreen;
	cTkDynamicTexture maSideScreenTextures[4];
	cGcNGui maSideScreenGUI[4];
	cTkVector2 maSideScreenCursor[4];
	bool mbSideScreenActive;
	TkHandle maSideScreenMeshes[4];
	TkHandle mCurrentCockpit;
	cGcShipHUD::cGcVehicleScreen maVehicleScreens[7];
	TkHandle mSpeedoReverseMesh;
	TkHandle mSpeedoPulseMesh;
	TkHandle maSpeedoBarsMeshes[5];
	int miCurrentSpeedoBar;
	int miFinalSpeedReadout;
	cTkDynamicTexture mMainScreenTexture;
	cGcNGui mMainScreenGUI;
	cTkFixedString<127, char> mTargetProcName;
	cTkVector3 maPlanetWorldPositions[6];
	cTkVector3 maPlanetScreenPositions[6];
	cGcNGui mHeadsUpGUI;
	cTkClassPoolHandle mHeadsUpScreenHandle;
	cTkSmartResHandle mEnemyTargetSceneRes;
	float mfBoostMultiplier;
};

enum eFrontendPage
{
	EFrontendPage_None = 0xFFFFFFFF,
	EFrontendPage_Suit = 0x0,
	EFrontendPage_Ship = 0x1,
	EFrontendPage_Vehicle = 0x2,
	EFrontendPage_Freighter = 0x3,
	EFrontendPage_Weapon = 0x4,
	EFrontendPage_Discovery = 0x5,
	EFrontendPage_Journey = 0x6,
	EFrontendPage_MissionLog = 0x7,
	EFrontendPage_Wiki = 0x8,
	EFrontendPage_Catalogue = 0x9,
	EFrontendPage_InfoPortal = 0xA,
	EFrontendPage_Season = 0xB,
	EFrontendPage_Options = 0xC,
	EFrontendPage_Switcher = 0xD,
	EFrontendPage_Controls = 0xE,
	EFrontendPage_Network = 0xF,
	EFrontendPage_NetworkPlayers = 0x10,
	EFrontendPage_NetworkManageFriends = 0x11,
	EFrontendPage_NetworkManageBlocked = 0x12,
	EFrontendPage_Difficulty = 0x13,
	EFrontendPage_Credits = 0x14,
	EFrontendPage_Redeem = 0x15,
	EFrontendPage_Interact = 0x16,
	EFrontendPage_InteractDialog = 0x17,
	EFrontendPage_InteractConsole = 0x18,
	EFrontendPage_InteractShip = 0x19,
	EFrontendPage_Trade = 0x1A,
	EFrontendPage_TechTrade = 0x1B,
	EFrontendPage_BuildingTrade = 0x1C,
	EFrontendPage_SpecialsTrade = 0x1D,
	EFrontendPage_MissionList = 0x1E,
	EFrontendPage_MissionHandInList = 0x1F,
	EFrontendPage_MissionRenounce = 0x20,
	EFrontendPage_MissionDescription = 0x21,
	EFrontendPage_BuyScreen = 0x22,
	EFrontendPage_CompareScreen = 0x23,
	EFrontendPage_DisplayTech = 0x24,
	EFrontendPage_DisplayProduct = 0x25,
	EFrontendPage_DisplayPatchNotes = 0x26,
	EFrontendPage_FreighterTransferScreen = 0x27,
	EFrontendPage_InventoryTransferScreen = 0x28,
	EFrontendPage_Message = 0x29,
	EFrontendPage_PhotoMode = 0x2A,
	EFrontendPage_ReportBase = 0x2B,
	EFrontendPage_PhotoBaseForUpload = 0x2C,
	EFrontendPage_BaseUpload = 0x2D,
	EFrontendPage_BasePartsMenu = 0x2E,
	EFrontendPage_BasePartPalette = 0x2F,
	EFrontendPage_Popup = 0x30,
	EFrontendPage_Maintenance = 0x31,
	EFrontendPage_Portal = 0x32,
	EFrontendPage_PortalRunes = 0x33,
	EFrontendPage_PortalActivate = 0x34,
	EFrontendPage_PortalUaDisplay = 0x35,
	EFrontendPage_Refiner = 0x36,
	EFrontendPage_SystemHoover = 0x37,
	EFrontendPage_EggMachine = 0x38,
	EFrontendPage_VehicleRace = 0x39,
	EFrontendPage_ManageFleet = 0x3A,
	EFrontendPage_ManageExpeditions = 0x3B,
	EFrontendPage_ExpeditionDebrief = 0x3C,
	EFrontendPage_FrigateDetails = 0x3D,
	EFrontendPage_FrigateCaptain = 0x3E,
	EFrontendPage_ExpeditionDetails = 0x3F,
	EFrontendPage_ExpeditionSelection = 0x40,
	EFrontendPage_ExpeditionOutfitting = 0x41,
	EFrontendPage_Customisation = 0x42,
	EFrontendPage_Teleporter = 0x43,
	EFrontendPage_Teleporter_Nexus = 0x44,
	EFrontendPage_ByteBeat = 0x45,
	EFrontendPage_BaseGridPart = 0x46,
	EFrontendPage_UnlockItemTree = 0x47,
	EFrontendPage_CreatureFeeder = 0x48,
	EFrontendPage_CreatureHarvester = 0x49,
	EFrontendPage_Multiplayer_MissionList = 0x4A,
	EFrontendPage_Multiplayer_MissionDescription = 0x4B,
	EFrontendPage_CraftingTree = 0x4C,
	EFrontendPage_ByteBeatSwitch = 0x4D,
	EFrontendPage_RadialInteraction = 0x4E,
	EFrontendPage_Pet = 0x4F,
	EFrontendPage_IntermediateInteraction = 0x50,
	EFrontendPage_ByteBeatLibrary = 0x51,
	EFrontendPage_SettlementHub = 0x52,
	EFrontendPage_SettlementJudgement = 0x53,
	EFrontendPage_RocketLockerInventory = 0x54,
	EFrontendPage_SquadronRecruitment = 0x55,
	EFrontendPage_SquadronManagement = 0x56,
	EFrontendPage_SquadronPilotDetails = 0x57,
	EFrontendPage_NumPages = 0x58,
};

enum eIconStyle : __int32
{
	EIconStyle_Default = 0x0,
	EIconStyle_Large = 0x1,
	EIconStyle_Square = 0x2,
	EIconStyle_NoFrame = 0x3,
	EIconStyle_NumTypes = 0x4,
};

struct cGcPlayerNotifications
{
	struct __declspec(align(8)) SimpleMessage
	{
		cTkFixedString<128, char> msTitle;
		cTkFixedString<512, char> msMessage;
		cTkColour mColour;
		unsigned int miAudioID;
		bool mbShown;
		eFrontendPage mePageHint;
		cGcSlotIcon mIcon;
		bool mbShowIconBackground;
		bool mbShowIconGlow;
	};
};

struct cGcNotificationSequenceEditor
{
	cGcMissionTable* mpMissionTable;
	std::vector<cGcGenericMissionSequence*, TkSTLAllocatorShim<cGcGenericMissionSequence*> > maMissions;
};

struct cGcAtlasCommunityData
{
	unsigned __int64 muCurrentCMIndex;
	unsigned __int64 muCurrentCMStartEpoch;
	unsigned __int64 muCurrentCMEndEpoch;
	unsigned __int64 muNextCMStartEpoch;
	unsigned __int64 muNextCMEndEpoch;
	unsigned __int64 muMyCMContribution;
	unsigned __int64 muMaxIndividualContribution;
	std::vector<unsigned __int64, TkSTLAllocatorShim<unsigned __int64> > maContributionLevels;
	unsigned __int64 muCurrentTotalContribution;
	std::vector<AtlasCommunalMissionTier, TkSTLAllocatorShim<AtlasCommunalMissionTier> > mPreviousTiersReached;
	unsigned int muSecondsBetweenCmRefreshes;
	bool mbUpdatePending;
	bool mbRequestUpdate;
	unsigned __int64 muTimeOfLastRefresh;
	unsigned __int64 mRequestHandle;
};

struct __declspec(align(8)) cGcNotificationScheduler
{
	const cGcMissionTable* mpRecurringMissionTable;
	const cGcMissionCommunityData* mpCommunityData;
	const cGcMissionSchedulesTable* mpSchedulesTable;
	std::unordered_map<TkID<128>, cGcNotificationScheduler::MissionSchedulingData, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcNotificationScheduler::MissionSchedulingData>> > mMissionIDToSchedulingData;
	std::unordered_map<TkID<128>, unsigned __int64, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, unsigned __int64>> > mMissionIDToRecurrenceDeadline;
	cGcAtlasCommunityData mCachedAtlasCommunityData;
	bool mbAtlasCommunityDataAvailable;
};

struct cGcPlayerNotifications
{
	cGcNGuiLayer mPlayerNotificationLayer;
	cGcNGuiLayer* mpHUDIndicatorLayer;
	std::vector<cGcPlayerNotifications::cGcMissionRequest, TkSTLAllocatorShim<cGcPlayerNotifications::cGcMissionRequest> > maRequestedMissions;
	std::vector<cGcPlayerNotifications::cGcMissionRequest, TkSTLAllocatorShim<cGcPlayerNotifications::cGcMissionRequest> > maRestartRequestedMissions;
	std::vector<std::pair<TkID<128>, cTkSeed>, TkSTLAllocatorShim<std::pair<TkID<128>, cTkSeed>> > maRequestedMissionsToComplete;
	std::vector<std::pair<TkID<128>, cTkSeed>, TkSTLAllocatorShim<std::pair<TkID<128>, cTkSeed>> > maCompletedProcMissions;
	std::vector<cGcNotificationSequence*, TkSTLAllocatorShim<cGcNotificationSequence*> > maSequences;
	std::pair<TkID<128>, cTkSeed> mPreviousSequence;
	int miSequenceIndex;
	int miHighPrioritySequenceCounter;
	const cGcNotificationSequence* mpLastActiveSequence;
	std::vector<cGcNotificationSequence*, TkSTLAllocatorShim<cGcNotificationSequence*> > maDeletedPinnedMissions;
	std::vector<cGcPlayerNotifications::TimedMessage, TkSTLAllocatorShim<cGcPlayerNotifications::TimedMessage> > mTimedMessages;
	std::vector<cGcPlayerNotifications::ConstantMessage, TkSTLAllocatorShim<cGcPlayerNotifications::ConstantMessage> > maConstantMessages;
	int miCurrentConstantMessageIndex;
	float mfConstantMessageCycleTimer;
	bool mbConstantMessageChanged;
	bool mbNeedsGPSText;
	std::array<float, 6> mafPreviousHazardLevels;
	std::array<float, 6> mafHazardWarningTimer;
	std::array<bool, 6> mabHazardActive;
	TkID<128> mPinnedRecipe;
	TkID<128> mPinnedJourneyMilestone;
	float mfPreviousPersonalShield;
	float mfPreviousShipShield;
	int miPreviousHealth;
	float mfPreviousEnergy;
	float mfPreviousFuel;
	float mfLastHitTime;
	float mfLowEnergyTime;
	float mfExtremePlanetTimer;
	float mfMissionDisplayTimer;
	bool mbMissionDisplayPause;
	int miMissionDisplayIndex;
	float mfJumpTimer;
	float mfThrustTimer;
	float mfJetpackHintTimer;
	float mfLastBoostTime;
	float mfLastJumpTime;
	bool mbBoosted;
	bool mbJumped;
	float mfLastHazardMessageTime;
	float mfTechHintTimer;
	float mfTechHintLastTime;
	TkID<128> mActiveTechHint;
	bool mbRequestedNotify;
	float mfRequestedNotifyTimer;
	float mfRequestedNotifyTime;
	float mfRequestedNotifyDelay;
	eFrontendPage meRequestedNotifyPageHint;
	cGcSlotIcon mRequestedSlotIcon;
	TkID<128> mNextMissionHint;
	eFrontendPage mePageHint;
	TkID<256> mPageLocID;
	TkID<128> mInventoryHint;
	InventoryChoice mInventoryHintChoice;
	cGcSlotIcon mUpperMessageIcon;
	cTkVector2 mSmallIconStartPos;
	cTkVector2 mIconStartPos;
	int miFreighterTutorialStage;
	const cGcPlayerNotifications::SimpleMessage* mpCurrentLowerMessage;
	__declspec(align(16)) cGcPlayerNotifications::SimpleMessage mRenderLowerMessage;
	bool mbRenderLowerMessageFresh;
	cGcNotificationSequenceEditor mNotificationSequenceEditor;
	cGcNotificationScheduler mNotificationScheduler;
	bool mbCanShowLowerMessages;
	float mfCabShowLowerMessagesTimer;
	std::vector<std::pair<TkID<128>, cTkSeed>, TkSTLAllocatorShim<std::pair<TkID<128>, cTkSeed>> > maMissionsToClear;
	std::vector<cGcNotificationSequence*, TkSTLAllocatorShim<cGcNotificationSequence*> > maRenouncedMissions;
	std::vector<cGcNotificationSequence*, TkSTLAllocatorShim<cGcNotificationSequence*> > mapMissionsToRefreshLogInfo;
	std::pair<TkID<128>, cTkSeed> mDebugReloadMission;
	bool mbWeeklyAbandonedFreighterDone;
	int miDailyAbandonedFreighterCount;
	cGcRpcCallBase* SMIS;
	cGcRpcCallBase* RMMM;
	cGcRpcCallBase* RMMS;
};

struct cGcPhotoManager
{
	std::vector<cGcPhotoRequest, TkSTLAllocatorShim<cGcPhotoRequest> > maPhotoRequests;
};

enum eQuickMenuActions : __int32
{
	EQuickMenuActions_None = 0x0,
	EQuickMenuActions_CallFreighter = 0x1,
	EQuickMenuActions_DismissFreighter = 0x2,
	EQuickMenuActions_SummonNexus = 0x3,
	EQuickMenuActions_CallShip = 0x4,
	EQuickMenuActions_CallSquadron = 0x5,
	EQuickMenuActions_SummonVehicleSubMenu = 0x6,
	EQuickMenuActions_SummonBuggy = 0x7,
	EQuickMenuActions_SummonBike = 0x8,
	EQuickMenuActions_SummonTruck = 0x9,
	EQuickMenuActions_SummonWheeledBike = 0xA,
	EQuickMenuActions_SummonHovercraft = 0xB,
	EQuickMenuActions_SummonSubmarine = 0xC,
	EQuickMenuActions_SummonMech = 0xD,
	EQuickMenuActions_VehicleAIToggle = 0xE,
	EQuickMenuActions_VehicleScan = 0xF,
	EQuickMenuActions_VehicleScanSelect = 0x10,
	EQuickMenuActions_VehicleRestartRace = 0x11,
	EQuickMenuActions_Torch = 0x12,
	EQuickMenuActions_GalaxyMap = 0x13,
	EQuickMenuActions_PhotoMode = 0x14,
	EQuickMenuActions_ChargeMenu = 0x15,
	EQuickMenuActions_Charge = 0x16,
	EQuickMenuActions_ChargeSubMenu = 0x17,
	EQuickMenuActions_Repair = 0x18,
	EQuickMenuActions_BuildMenu = 0x19,
	EQuickMenuActions_CommunicatorReceive = 0x1A,
	EQuickMenuActions_CommunicatorInitiate = 0x1B,
	EQuickMenuActions_ThirdPersonCharacter = 0x1C,
	EQuickMenuActions_ThirdPersonShip = 0x1D,
	EQuickMenuActions_ThirdPersonVehicle = 0x1E,
	EQuickMenuActions_EconomyScan = 0x1F,
	EQuickMenuActions_EmoteMenu = 0x20,
	EQuickMenuActions_Emote = 0x21,
	EQuickMenuActions_UtilitySubMenu = 0x22,
	EQuickMenuActions_SummonSubMenu = 0x23,
	EQuickMenuActions_SummonShipSubMenu = 0x24,
	EQuickMenuActions_ChangeSecondaryWeaponMenu = 0x25,
	EQuickMenuActions_ChangeSecondaryWeapon = 0x26,
	EQuickMenuActions_ChooseCreatureFoodMenu = 0x27,
	EQuickMenuActions_ChooseCreatureFood = 0x28,
	EQuickMenuActions_EmergencyWarp = 0x29,
	EQuickMenuActions_SwapMultitool = 0x2A,
	EQuickMenuActions_SwapMultitoolSubMenu = 0x2B,
	EQuickMenuActions_CreatureSubMenu = 0x2C,
	EQuickMenuActions_SummonPet = 0x2D,
	EQuickMenuActions_SummonPetSubMenu = 0x2E,
	EQuickMenuActions_WarpToNexus = 0x2F,
	EQuickMenuActions_PetUI = 0x30,
	EQuickMenuActions_ByteBeatSubMenu = 0x31,
	EQuickMenuActions_ByteBeatPlay = 0x32,
	EQuickMenuActions_ByteBeatStop = 0x33,
	EQuickMenuActions_ByteBeatLibrary = 0x34,
	EQuickMenuActions_ReportBase = 0x35,
	EQuickMenuActions_CargoShield = 0x36,
	EQuickMenuActions_CallRocket = 0x37,
	EQuickMenuActions_Invalid = 0x38,
	EQuickMenuActions_NumTypes = 0x39,
};

struct __declspec(align(8)) MenuAction
{
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mActionIcon;
	eQuickMenuActions meAction;
	bool mbUseInventryElement;
	cGcInventoryElement mInventoryElement;
	InventoryChoice mActionInventory;
	cGcInventoryIndex mActionInventoryIndex;
	bool mbDisabled;
	bool mbShowBackground;
	eWeaponMode meWeaponMode;
	bool mbGlow;
	bool mbAllowPrimaryWhenDisabled;
	bool mbDisableWhenNotSelected;
	cTkColour mPrimaryColour;
	cTkColour mSecondaryColour;
	bool mbAnimateIn;
	int miSavedActionIndex;
	TkID<128> mActionID;
	cTkFixedString<64, char> mName;
	int miBoundHotAction;
};

struct AnimateItems
{
	bool mbRequested;
	float mfFrom;
	float mfTo;
	float mfAnimTime;
	float mfTimer;
	float mfWait;
};

struct __declspec(align(16)) QuickMenuRenderState
{
	cTkFixedString<256, char> msControlsString;
	cTkFixedString<256, char> msExtraControlsString;
	bool mbShowMenu;
	bool mbShowCategories;
	TkID<256> maCategories[3];
	float mfCursorX;
	float mfCursorY;
	cTkFixedString<512, char> mLabelID;
	cTkColour mLabelTextColour;
	cTkColour mLabelBGColour;
	cTkFixedString<128, char> mItemName;
	bool mbShowChargeArrows;
	bool mbForceShowUpArrow;
	bool mbShowBackButton;
	std::vector<MenuAction, TkSTLAllocatorShim<MenuAction> > mNextActions;
	MenuAction mPreviousAction;
	std::vector<MenuAction, TkSTLAllocatorShim<MenuAction> > mCurrentActions;
	bool mbItemChanged;
	AnimateItems mAnimateItems;
	AnimateItems mAnimateNextItems;
	AnimateItems mEnterMenuAnimation;
	AnimateItems mUpArrowAnimation;
	AnimateItems mLeftArrowAnimation;
	AnimateItems mRightArrowAnimation;
	int miCurrentAction;
	int miNextAction;
	bool mbWrapCurrentActions;
	int miCurrentActionDepth;
	cTkBitArray<unsigned int, 1> mxValidSlots;
	bool mbCurrentActionIsSubMenu;
	std::atomic<bool> mbLocked;
};

enum eQuickMenuState : __int32
{
	EQuickMenuState_Closed = 0x0,
	EQuickMenuState_QuickActions = 0x1,
	EQuickMenuState_Build = 0x2,
	EQuickMenuState_TerrainEditor = 0x3,
	EQuickMenuState_GalaxyPath = 0x4,
};

struct __declspec(align(8)) cGcAnalogueMenuNavigator
{
	typedef cGcPlayer::eRocketBootsDoubleTapState Output;

	bool mbWasActive;
	cGcAnalogueMenuNavigator::Output meOutput;
	cGcAnalogueMenuNavigator::Output mePrevOutput;
	cTkPhysRelMat34 mMoveOrigin;
	cTkVector3 mLocalIntersect;
	cTkVector3 mLocalDir;
	cTkVector2 mCursorPos;
	bool mbScrolling;
	bool mbValid;
};

struct cGcQuickMenuState
{
	cGcQuickMenuState_vtbl* __vftable /*VFT*/;
	__declspec(align(16)) cGcAnalogueMenuNavigator mAnalogueMenuNav;
	cTkFixedString<512, char> mErrorID;
	cTkColour mErrorColour;
	cTkColour mErrorHighlightColour;
	float mfErrorTimer;
};

struct cGcQuickActionMenu : cGcQuickMenuState
{
	struct HotAction
	{
		MenuAction mKeyAction;
		MenuAction mOpenMenuToAction[5];
	};

	struct __declspec(align(8)) ActionTable
	{
		int miCurrentActionDepth;
		std::array<std::vector<MenuAction, TkSTLAllocatorShim<MenuAction> >, 3> maActionDepths;
		std::array<int, 3> maSelectedActions;
	};

	cGcQuickActionMenu::HotAction maHotActionKeys[3][10];
	cGcQuickActionMenu::ActionTable mActionTable;
	cTkSmartResHandle mSummonNexusIcon;
	cTkSmartResHandle mSummonSquadronIcon;
	cTkSmartResHandle mSummonFreighterIcon;
	cTkSmartResHandle mSummonShipMenuIcon;
	cTkSmartResHandle mSummonVehicleMenuIcon;
	cTkSmartResHandle maSummonVehicleIcons[7];
	cTkSmartResHandle mVehicleAIToggleIcon;
	cTkSmartResHandle mVehicleScanIcon;
	cTkSmartResHandle mVehicleResetRaceIcon;
	cTkSmartResHandle mTorchOnIcon;
	cTkSmartResHandle mTorchOffIcon;
	cTkSmartResHandle mGalaxyMapIcon;
	cTkSmartResHandle mPhotoModeIcon;
	cTkSmartResHandle mCommunicatorIcon;
	cTkSmartResHandle mThirdPersonCharacterIcon;
	cTkSmartResHandle mThirdPersonShipIcon;
	cTkSmartResHandle mThirdPersonVehicleIcon;
	cTkSmartResHandle mTerrainAdvancedIconOn;
	cTkSmartResHandle mTerrainAdvancedIconOff;
	cTkSmartResHandle mChargeMenuIcon;
	cTkSmartResHandle mSummonMenuIcon;
	cTkSmartResHandle mPetMenuIcon;
	cTkSmartResHandle mPetManagerIcon;
	cTkSmartResHandle mUtilityMenuIcon;
	cTkSmartResHandle mSecondaryWeaponMenuIcon;
	cTkSmartResHandle mCreatureBaitIcon;
	cTkSmartResHandle mEconomyScannerIcon;
	cTkSmartResHandle mCargoShieldIcon;
	cTkSmartResHandle mWarpToNexusIcon;
	cTkSmartResHandle mByteBeatIcon;
	cTkSmartResHandle mByteBeatPlayIcon;
	cTkSmartResHandle mReportBaseIcon;
	cTkSmartResHandle mSummonRocketIcon;
	cTkSmartResHandle mEmoteMenuIcon;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > mEmoteIcons;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > mUnderWaterEmoteIcons;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > mPetCommandEmoteIcons;
	cTkSmartResHandle mRocketLockerRes;
	eQuickMenuActions mStartOverrideAction;
	bool mbTriggerOverrideAction;
	bool mbOverrideToFirstActionInSubMenu;
	bool mbOverrideToLastActionInSubMenu;
	bool mbFirstUpdate;
	bool mbEnteredSubMenu;
	int miOpenToHotKey;
	float mfAutoCloseTimer;
};

struct cGcBaseBuildingPlayerPlacement
{
	enum RotationAxis : __int32
	{
		ERotationAxis_XAxis = 0x0,
		ERotationAxis_YAxis = 0x1,
		ERotationAxis_ZAxis = 0x2,
		ERotationAxis_NumEntries = 0x3,
	};
};

enum eBuildMenuOption : __int32
{
	EBuildMenuOption_Place = 0x0,
	EBuildMenuOption_ChangeColour = 0x1,
	EBuildMenuOption_FreeRotate = 0x2,
	EBuildMenuOption_Scale = 0x3,
	EBuildMenuOption_SnapRotate = 0x4,
	EBuildMenuOption_Move = 0x5,
	EBuildMenuOption_Duplicate = 0x6,
	EBuildMenuOption_Delete = 0x7,
	EBuildMenuOption_ToggleBuildCam = 0x8,
	EBuildMenuOption_ToggleSnappingAndCollision = 0x9,
	EBuildMenuOption_ToggleSelectionMode = 0xA,
	EBuildMenuOption_ToggleWiringMode = 0xB,
	EBuildMenuOption_ViewRelatives = 0xC,
	EBuildMenuOption_CyclePart = 0xD,
	EBuildMenuOption_PlaceWire = 0xE,
	EBuildMenuOption_CycleRotateMode = 0xF,
	EBuildMenuOption_NumTypes = 0x10,
};

enum eBaseBuildingMode : __int32
{
	EBaseBuildingMode_Inactive = 0x0,
	EBaseBuildingMode_Selection = 0x1,
	EBaseBuildingMode_Placement = 0x2,
	EBaseBuildingMode_Browse = 0x3,
	EBaseBuildingMode_Relatives = 0x4,
	EBaseBuildingMode_NumTypes = 0x5,
};


struct __declspec(align(16)) cGcBuildMenu : cGcQuickMenuState
{
	enum eSelectModeStage : __int32
	{
		ESelectModeStage_Root = 0x0,
		ESelectModeStage_Colour = 0x1,
		ESelectModeStage_Material = 0x2,
	};

	enum eSelectModeOption : __int32
	{
		ESelectModeOption_BrowseMode = 0x0,
		ESelectModeOption_Pickup = 0x1,
		ESelectModeOption_Duplicate = 0x2,
		ESelectModeOption_Delete = 0x3,
		ESelectModeOption_Colour = 0x4,
		ESelectModeOption_Material = 0x5,
		ESelectModeOption_ReportBase = 0x6,
	};

	struct __declspec(align(4)) sBuildOptionsGui
	{
		struct __declspec(align(8)) sBuildOptionsRenderData
		{
			TkID<128> mCyclePartId;
			cTkVector2 mScreenPos;
			cTkBitArray<unsigned int, 1> mLastActionWasError;
			float mafLastInputTime[16];
			float mfErrorAlpha;
			bool mbTransitioningToOrFromFrontendMode;
			bool mbRenderMenu;
		};

		struct __declspec(align(8)) sRotation
		{
			TkAudioObject mAudioObject;
			float mfStartTime;
			float mfStopTime;
			float mfPreviousInput;
			cGcBaseBuildingPlayerPlacement::RotationAxis meCurrentRotationAxis;
			bool mbCameraSpace;
			bool mbHasChangedAxis;
			bool mbPlayingAudio;
		};

		struct __declspec(align(8)) sScale
		{
			TkAudioObject mAudioObject;
			float mfStartTime;
			float mfStopTime;
			bool mbPlayingAudio;
		};

		cGcBuildMenu::sBuildOptionsGui::sBuildOptionsRenderData mRender;
		cGcNGui mGui;
		cTkFixedString<256, char> mPlacementErrorString;
		cTkFixedString<256, char> mInvalidPlacementString;
		float mfLastValidPlacementTime;
		cTkFixedString<128, char> maActionText[16];
		cTkSmoothCD<cTkVector2> mSmoothScreenPos;
		cTkSmoothCD<float> mErrorAlpha;
		TkID<128> mPreviousPartBeingPlaced;
		TkID<128> mCyclePartId;
		TkID<128> mHighlightedPart;
		cTkVector3 mWorldPos;
		cTkVector2 mScreenPos;
		TkHandle mSelectionTarget;
		float mfButtonWidth;
		float mfSpacerWidth;
		float mafLastInputTime[16];
		cGcBuildMenu::sBuildOptionsGui::sRotation mRotation;
		cGcBuildMenu::sBuildOptionsGui::sScale mScale;
		cTkBitArray<unsigned int, 1> mVisibleOptions;
		cTkBitArray<unsigned int, 1> mEnabledOptions;
		cTkBitArray<unsigned int, 1> mToggledOptions;
		cTkBitArray<unsigned int, 1> mShowInputIcon;
		cTkBitArray<unsigned int, 1> mLastActionWasError;
		float mfTimeSinceMostRecentActionWithDescription;
		eBuildMenuOption meMostRecentActionWithDescription;
		eBuildMenuOption meHighlightedOption;
		eBuildMenuOption meSelectedOption;
		eBaseBuildingMode mePreviousMode;
		unsigned __int8 mu8PaletteIndex;
		unsigned __int8 mu8MaterialIndex;
		bool mbLastFrameWasViewingPalette;
		bool mbShowColourSwatch;
		bool mbShowMaterialSwatch;
		bool mbShowCursor;
	};

	struct __declspec(align(8)) BuildGroups
	{
		std::unordered_map<unsigned __int64, int> mGroupIndicies;
		std::vector<cGcBuildMenu::BuildGroups::GroupNode, TkSTLAllocatorShim<cGcBuildMenu::BuildGroups::GroupNode> > mGroupNodes;
		int miCurrentSelectedGroup;
	};

	TkID<128> mBreadcrumbID;
	bool mbFirstUpdateAfterOpening;
	bool mbInputThisFrame;
	bool mbActivateRequested;
	float mfLastClosedTime;
	cGcBuildMenu::eSelectModeStage meSelectionModeStage;
	cGcBuildMenu::eSelectModeOption meSelectionModeOption;
	cGcBuildMenu::sBuildOptionsGui mBuildOptionsGui;
	std::vector<BaseBuildingObjectTemplate const*, TkSTLAllocatorShim<BaseBuildingObjectTemplate const*> > maAvailableWires;
	cGcBuildMenu::BuildGroups mBuildingGroups;
};

struct __declspec(align(16)) cGcTerrainEditMenu : cGcQuickMenuState
{
	enum eMenuGroup : __int32
	{
		EMenuGroup_Materials = 0x0,
		EMenuGroup_Shapes = 0x1,
		EMenuGroup_NumGroups = 0x2,
	};

	struct MenuGroup
	{
		TkID<256> mGroupName;
		int miCurrentOption;
		int miSize;
	};

	cGcTerrainEditMenu::MenuGroup maMenuGroup[2];
	cGcTerrainEditMenu::eMenuGroup meCurrentGroup;
	cTkSmartResHandle mTerrainBallMaterial[5];
	cTkModelResourceRenderer mTerrainEditBallRenderer[5];
	bool mbRenderRequested[5];
	cTkSmartResHandle maTerrainBalls[5];
	TkHandle mTerrainBallsGroup;
	cTkSmartResHandle maShapeIcons[2];
	eVoxelType meTerrainType;
	eTerrainEditShape meEditShape;
	bool mbWasChangingMaterial;
};

struct __declspec(align(16)) cGcGalaxyPathMenu : cGcQuickMenuState
{
	GalaxyNavigationMode meCurrentNavigationMode;
	float mfTriggerCloseTimer;
	cTkSmartResHandle mPathIcons[7];
};

struct __declspec(align(16)) cGcQuickMenu
{
	int miUpdateIndex;
	int miRenderIndex;
	std::array<QuickMenuRenderState, 2> maRenderStates;
	bool mbOpenQuickMenu;
	bool mbActivatedThisFrame;
	eQuickMenuState meQuickMenuState;
	cGcQuickActionMenu mQuickActionMenu;
	cGcBuildMenu mBuildMenu;
	cGcTerrainEditMenu mTerrainMenu;
	cGcGalaxyPathMenu mGalaxyPathMenu;
	int miUpdateCount;
	bool mbRenderActive;
	bool mbRenderStartHidden;
	AnimateItems mItemsAnimation;
	AnimateItems mNextItemsAnimation;
	AnimateItems mEnterMenuAnimation;
	AnimateItems mUpArrowAnimation;
	AnimateItems mLeftArrowAnimation;
	AnimateItems mRightArrowAnimation;
	cTkSmartResHandle maHotKeyIcons[10];
	float mfMenuClosedTime;
};

struct __declspec(align(8)) OSDMessageEffect
{
	cGcNGuiLayer* mpLayer;
	float mfStartTime;
};

struct OSDMessageEffectReward : OSDMessageEffect
{
	eRarity meRarity;
	bool mbOverrideColour;
	cTkColour mColour;
};

struct __declspec(align(4)) StatsMessages
{
	std::vector<OSDMessage, TkSTLAllocatorShim<OSDMessage> > maMessages;
	unsigned int mAudioCue;
	bool mbIsShowing;
	bool mbStatsRequireBars;
};

enum eHUDStartup : __int32
{
	EHUDStartup_WaitingForInit = 0x0,
	EHUDStartup_Startup = 0x1,
	EHUDStartup_Booting = 0x2,
	EHUDStartup_LifeSupport = 0x3,
	EHUDStartup_Shield = 0x4,
	EHUDStartup_ShieldEffect = 0x5,
	EHUDStartup_Scanner = 0x6,
	EHUDStartup_Jetpack = 0x7,
	EHUDStartup_Weapon = 0x8,
	EHUDStartup_Finishing = 0x9,
	EHUDStartup_DiscoverPlanet = 0xA,
	EHUDStartup_Done = 0xB,
	EHUDStartup_Inactive = 0xC,
	EHUDStartup_NumTypes = 0xD,
};

struct cGcHUDScreensPool
{
	cTkClassPoolHandle maScreens[200];
	cTkClassPoolHandle* mapScreenPools[6];
	int maCurrentScreens[6];
};

struct cTkNGuiElementID
{
	__int64 miCounter;
	unsigned __int64 miBase;
	int miFrameRenderTracker;
	int miPerFrameUseCount;
};

struct cTkNGuiTextEditState
{
	cTkNGuiTextEditState_vtbl* __vftable /*VFT*/;
	cTkFixedString<512, char> macEditedText;
	cTkFixedString<512, char> macInitialText;
	cTkFixedString<512, char> macShelvedTextEdit;
	cTkNGuiElementID mShelvedEditID;
	float mfWidth;
	float mfScrollX;
	float mfInitTime;
	float mfNavigateTime;
	STB_TexteditState* mpStbState;
	bool mbDoubleClicked;
	cTkNGuiEditor* mpGui;
};

enum FrontendTextInputState : __int32
{
	EFrontendTextInputState_Free = 0x0,
	EFrontendTextInputState_WaitingForText = 0x1,
	EFrontendTextInputState_TextReady = 0x2,
	EFrontendTextInputState_ProfanityChecking = 0x3,
	EFrontendTextInputState_ProfanityChecked = 0x4,
};

struct __declspec(align(4)) cGcFrontendTextInput
{
	cTkNGuiTextEditState mTextEditState;
	FrontendTextInputState meTextInputState;
	cTkFixedString<64, char> msTitle;
	cTkFixedString<64, char> msPlaceholder;
	cTkFixedString<64, wchar_t> msTitleWide;
	cTkFixedString<64, wchar_t> msPlaceholderWide;
	cTkFixedString<256, wchar_t> msInputStringUTF16;
	cTkFixedString<256, char> msTextInputString;
	bool mbUsingDefaultInput;
	bool mbWaitingForNoKeyboardInput;
	bool mbProfanityFilter;
	bool mbIsNaughty;
	unsigned int miMaxCharacters;
	bool mbTextEntryFinished;
};

struct cGcTextChatInput
{
	cTkNGuiTextEditState mEditText;
	cTkFixedString<1023, char> msText;
	cTkFixedString<1023, char> msInputTextDisplayString;
	bool mbTextInputActive;
	bool mbWaitingForNoKeyboardInput;
	bool mbButtonReleased;
	byte meCurrentCommand[1];
	byte mePendingCommand[1];
	const cGcTextChatInput::SCommandLookup* mpLookupTable;
};

struct cGcFrontendBackgroundEffect
{
	cGcNGuiLayer* mpLayer;
	cTkVector2 mMousePos;
};

enum eShipOperation : __int32
{
	EShipOperation_None = 0x0,
	EShipOperation_Teleport = 0x1,
	EShipOperation_Full = 0x2,
};

enum eInputAction : __int32
{
	EInputAction_Invalid = 0x0,
	EInputAction_Player_Forward = 0x1,
	EInputAction_Player_Back = 0x2,
	EInputAction_Player_Left = 0x3,
	EInputAction_Player_Right = 0x4,
	EInputAction_Player_SwimUp = 0x5,
	EInputAction_Player_SwimDown = 0x6,
	EInputAction_Player_Interact = 0x7,
	EInputAction_Player_Melee = 0x8,
	EInputAction_Player_Scan = 0x9,
	EInputAction_Player_Torch = 0xA,
	EInputAction_Player_Binoculars = 0xB,
	EInputAction_Player_Zoom = 0xC,
	EInputAction_Player_ShowHUD = 0xD,
	EInputAction_Player_Jump = 0xE,
	EInputAction_Player_Run = 0xF,
	EInputAction_Player_Shoot = 0x10,
	EInputAction_Player_Grenade = 0x11,
	EInputAction_Player_Reload = 0x12,
	EInputAction_Player_ChangeWeapon = 0x13,
	EInputAction_Player_Deconstruct = 0x14,
	EInputAction_Player_ChangeAltWeapon = 0x15,
	EInputAction_Player_PlaceMarker = 0x16,
	EInputAction_Quick_Menu = 0x17,
	EInputAction_Build_Menu = 0x18,
	EInputAction_Ship_AltLeft = 0x19,
	EInputAction_Ship_AltRight = 0x1A,
	EInputAction_Ship_Thrust = 0x1B,
	EInputAction_Ship_Brake = 0x1C,
	EInputAction_Ship_Boost = 0x1D,
	EInputAction_Ship_RollLeft = 0x1E,
	EInputAction_Ship_RollRight = 0x1F,
	EInputAction_Ship_Exit = 0x20,
	EInputAction_Ship_Land = 0x21,
	EInputAction_Ship_Shoot = 0x22,
	EInputAction_Ship_ChangeWeapon = 0x23,
	EInputAction_Ship_Scan = 0x24,
	EInputAction_Ship_PulseJump = 0x25,
	EInputAction_Ship_GalacticMap = 0x26,
	EInputAction_Ship_TurnLeft = 0x27,
	EInputAction_Ship_TurnRight = 0x28,
	EInputAction_Ship_FreeLook = 0x29,
	EInputAction_Ship_AutoFollow_Toggle = 0x2A,
	EInputAction_Ship_AutoFollow_Hold = 0x2B,
	EInputAction_Vehicle_Forward = 0x2C,
	EInputAction_Vehicle_Reverse = 0x2D,
	EInputAction_Vehicle_Left = 0x2E,
	EInputAction_Vehicle_Right = 0x2F,
	EInputAction_Vehicle_Exit = 0x30,
	EInputAction_Vehicle_Shoot = 0x31,
	EInputAction_Vehicle_ChangeWeapon = 0x32,
	EInputAction_Vehicle_Scan = 0x33,
	EInputAction_Vehicle_Boost = 0x34,
	EInputAction_Vehicle_Jump = 0x35,
	EInputAction_Vehicle_Horn = 0x36,
	EInputAction_Vehicle_AddCheckpoint = 0x37,
	EInputAction_Vehicle_DeleteCheckpoint = 0x38,
	EInputAction_Fe_Select = 0x39,
	EInputAction_Fe_AltSelect = 0x3A,
	EInputAction_Fe_SelectX = 0x3B,
	EInputAction_Fe_Back = 0x3C,
	EInputAction_Fe_Alt1 = 0x3D,
	EInputAction_Fe_Alt1X = 0x3E,
	EInputAction_Fe_Transfer = 0x3F,
	EInputAction_Fe_Destroy = 0x40,
	EInputAction_Gm_Select = 0x41,
	EInputAction_Gm_Restart = 0x42,
	EInputAction_UI_Left = 0x43,
	EInputAction_UI_Right = 0x44,
	EInputAction_UI_Left_Sub = 0x45,
	EInputAction_UI_Right_Sub = 0x46,
	EInputAction_UI_Down_Sub = 0x47,
	EInputAction_UI_Up_Sub = 0x48,
	EInputAction_UI_NetworkPageShortcut = 0x49,
	EInputAction_UI_StackSplitUp = 0x4A,
	EInputAction_UI_StackSplitDown = 0x4B,
	EInputAction_Fe_ExitMenu = 0x4C,
	EInputAction_Fe_Options = 0x4D,
	EInputAction_Fe_Quit = 0x4E,
	EInputAction_Fe_MsgSkip = 0x4F,
	EInputAction_Fe_TouchscreenPress = 0x50,
	EInputAction_Quick_Left = 0x51,
	EInputAction_Quick_Right = 0x52,
	EInputAction_Quick_Action = 0x53,
	EInputAction_Quick_Back = 0x54,
	EInputAction_Quick_Up = 0x55,
	EInputAction_Quick_Down = 0x56,
	EInputAction_Build_Place = 0x57,
	EInputAction_Build_Rotate_Left = 0x58,
	EInputAction_Build_Rotate_Right = 0x59,
	EInputAction_Build_AnalogRotateMode1 = 0x5A,
	EInputAction_Build_AnalogRotateMode2 = 0x5B,
	EInputAction_Build_AnalogRotateLeftY = 0x5C,
	EInputAction_Build_AnalogRotateRightY = 0x5D,
	EInputAction_Build_AnalogRotateY = 0x5E,
	EInputAction_Build_AnalogRotateLeftZ = 0x5F,
	EInputAction_Build_AnalogRotateRightZ = 0x60,
	EInputAction_Build_AnalogRotateZ = 0x61,
	EInputAction_Build_ScaleUp = 0x62,
	EInputAction_Build_ScaleDown = 0x63,
	EInputAction_Build_AnalogueScale = 0x64,
	EInputAction_Build_SelectionMode = 0x65,
	EInputAction_Build_Camera = 0x66,
	EInputAction_Photo_Hide = 0x67,
	EInputAction_Photo_Sun = 0x68,
	EInputAction_Photo_Cam = 0x69,
	EInputAction_Photo_Exit = 0x6A,
	EInputAction_Photo_CamDown = 0x6B,
	EInputAction_Photo_CamUp = 0x6C,
	EInputAction_Photo_Capture = 0x6D,
	EInputAction_Ambient_Camera = 0x6E,
	EInputAction_Ambient_Planet = 0x6F,
	EInputAction_Ambient_System = 0x70,
	EInputAction_Ambient_Photo = 0x71,
	EInputAction_Ambient_NxtSong = 0x72,
	EInputAction_Ambient_Spawn = 0x73,
	EInputAction_Terrain_Edit = 0x74,
	EInputAction_Terrain_ModeBack = 0x75,
	EInputAction_Terrain_Menu = 0x76,
	EInputAction_Terrain_SizeUp = 0x77,
	EInputAction_Terrain_SizeDown = 0x78,
	EInputAction_Terrain_RotTerrainLeft = 0x79,
	EInputAction_Terrain_RotTerrainRight = 0x7A,
	EInputAction_Terrain_ChangeShape = 0x7B,
	EInputAction_Ship_NextTarget = 0x7C,
	EInputAction_Ship_PreviousTarget = 0x7D,
	EInputAction_Ship_ClosestTarget = 0x7E,
	EInputAction_CameraLook = 0x7F,
	EInputAction_CameraLookX = 0x80,
	EInputAction_CameraLookY = 0x81,
	EInputAction_PlayerMove = 0x82,
	EInputAction_PlayerMoveX = 0x83,
	EInputAction_PlayerMoveY = 0x84,
	EInputAction_SpaceshipThrust = 0x85,
	EInputAction_SpaceshipBrake = 0x86,
	EInputAction_VehicleMove = 0x87,
	EInputAction_VehicleSteer = 0x88,
	EInputAction_VehicleThrust = 0x89,
	EInputAction_VehicleBrake = 0x8A,
	EInputAction_ShipStrafe = 0x8B,
	EInputAction_ShipStrafeHorizontal = 0x8C,
	EInputAction_ShipStrafeVertical = 0x8D,
	EInputAction_HeldRotate = 0x8E,
	EInputAction_HeldRotateLeft = 0x8F,
	EInputAction_HeldRotateRight = 0x90,
	EInputAction_ShipSteer = 0x91,
	EInputAction_ShipTurn = 0x92,
	EInputAction_ShipPitch = 0x93,
	EInputAction_ShipLook = 0x94,
	EInputAction_ShipLookX = 0x95,
	EInputAction_ShipLookY = 0x96,
	EInputAction_ShipLand = 0x97,
	EInputAction_ShipPulse = 0x98,
	EInputAction_PlayerSmoothTurnLeft = 0x99,
	EInputAction_PlayerSmoothTurnRight = 0x9A,
	EInputAction_PlayerSnapTurnLeft = 0x9B,
	EInputAction_PlayerSnapTurnRight = 0x9C,
	EInputAction_PlayerSnapTurnAround = 0x9D,
	EInputAction_PlayerMoveAround = 0x9E,
	EInputAction_TeleportDirection = 0x9F,
	EInputAction_PlayerAutoWalk = 0xA0,
	EInputAction_InteractLeft = 0xA1,
	EInputAction_MeleeLeft = 0xA2,
	EInputAction_HandCtrlHolster = 0xA3,
	EInputAction_ShipUp = 0xA4,
	EInputAction_ShipDown = 0xA5,
	EInputAction_ShipLeft = 0xA6,
	EInputAction_ShipRight = 0xA7,
	EInputAction_ShipZoom = 0xA8,
	EInputAction_Inventory = 0xA9,
	EInputAction_DiscoveryNetworkRetry = 0xAA,
	EInputAction_QuitGame = 0xAB,
	EInputAction_ReportBase = 0xAC,
	EInputAction_GalacticMap_Select = 0xAD,
	EInputAction_GalacticMap_Deselect = 0xAE,
	EInputAction_GalacticMap_Exit = 0xAF,
	EInputAction_GalacticMap_Scan = 0xB0,
	EInputAction_GalacticMap_Home = 0xB1,
	EInputAction_GalacticMap_PlanetBase = 0xB2,
	EInputAction_GalacticMap_Accelerate = 0xB3,
	EInputAction_GalacticMap_ExpandMenu = 0xB4,
	EInputAction_GalacticMap_ScreenshotToggle = 0xB5,
	EInputAction_GalacticMap_ScanChooseNext = 0xB6,
	EInputAction_GalacticMap_ToggleWaypoint = 0xB7,
	EInputAction_GalacticMap_ClearAllWaypoints = 0xB8,
	EInputAction_GalacticMap_NextNavType = 0xB9,
	EInputAction_GalacticMap_PreviousNavType = 0xBA,
	EInputAction_GalacticMap_PreviousFilter = 0xBB,
	EInputAction_GalacticMap_NextFilter = 0xBC,
	EInputAction_GalacticMap_CameraLook = 0xBD,
	EInputAction_GalacticMap_CameraLookX = 0xBE,
	EInputAction_GalacticMap_CameraLookY = 0xBF,
	EInputAction_GalacticMap_PlayerMove = 0xC0,
	EInputAction_GalacticMap_PlayerMoveX = 0xC1,
	EInputAction_GalacticMap_PlayerMoveY = 0xC2,
	EInputAction_GalacticMap_PlayerMoveForward = 0xC3,
	EInputAction_GalacticMap_PlayerMoveBackward = 0xC4,
	EInputAction_GalacticMap_PlayerMoveLeft = 0xC5,
	EInputAction_GalacticMap_PlayerMoveRight = 0xC6,
	EInputAction_GalacticMap_Up = 0xC7,
	EInputAction_GalacticMap_Down = 0xC8,
	EInputAction_GalacticMap_Gesture = 0xC9,
	EInputAction_UI_Cursor = 0xCA,
	EInputAction_UI_CursorX = 0xCB,
	EInputAction_UI_CursorY = 0xCC,
	EInputAction_UI_Camera = 0xCD,
	EInputAction_UI_CameraX = 0xCE,
	EInputAction_UI_CameraY = 0xCF,
	EInputAction_UI_ViewPlayerInfo = 0xD0,
	EInputAction_UI_NextInputControls = 0xD1,
	EInputAction_UI_PrevInputControls = 0xD2,
	EInputAction_UI_ToggleBuySell = 0xD3,
	EInputAction_UI_ToggleTradeInventory = 0xD4,
	EInputAction_UI_TouchScrollY = 0xD5,
	EInputAction_UI_TouchScrollX = 0xD6,
	EInputAction_CharacterCustomisation_ShowCharacter = 0xD7,
	EInputAction_UI_CharacterCustomisation_Camera = 0xD8,
	EInputAction_UI_CharacterCustomisation_RotateCamera = 0xD9,
	EInputAction_UI_CharacterCustomisation_PitchCamera = 0xDA,
	EInputAction_GameMode_CancelDelete = 0xDB,
	EInputAction_GameMode_TitleStart = 0xDC,
	EInputAction_GameMode_ChangeUser = 0xDD,
	EInputAction_Binocs_NextMode = 0xDE,
	EInputAction_Binocs_PrevMode = 0xDF,
	EInputAction_BaseBuilding_PinRecipe = 0xE0,
	EInputAction_BaseBuilding_SwitchBase = 0xE1,
	EInputAction_PhotoMode_CatLeft = 0xE2,
	EInputAction_PhotoMode_CatRight = 0xE3,
	EInputAction_PhotoMode_ValueIncrease = 0xE4,
	EInputAction_PhotoMode_ValueDecrease = 0xE5,
	EInputAction_PhotoMode_OptionUp = 0xE6,
	EInputAction_PhotoMode_OptionDown = 0xE7,
	EInputAction_PhotoMode_CameraRollLeft = 0xE8,
	EInputAction_PhotoMode_CameraRollRight = 0xE9,
	EInputAction_PhotoMode_PauseApplication = 0xEA,
	EInputAction_PhotoMode_CopyLocation = 0xEB,
	EInputAction_PhotoMode_HideLocation = 0xEC,
	EInputAction_UI_Up_Sub_Discovery = 0xED,
	EInputAction_UI_Down_Sub_Discovery = 0xEE,
	EInputAction_Fe_Upload_Discovery = 0xEF,
	EInputAction_HMD_Recenter = 0xF0,
	EInputAction_HMD_Recenter2 = 0xF1,
	EInputAction_HMD_FEOpen = 0xF2,
	EInputAction_TextChatOpenClose = 0xF3,
	EInputAction_TextChatSend = 0xF4,
	EInputAction_TextChatPasteHold = 0xF5,
	EInputAction_TextChatPaste = 0xF6,
	EInputAction_TextChatAutocomplete = 0xF7,
	EInputAction_TextChatAutocompleteModifier = 0xF8,
	EInputAction_TextChatCursorLeft = 0xF9,
	EInputAction_TextChatCursorRight = 0xFA,
	EInputAction_TextChatCursorHome = 0xFB,
	EInputAction_TextChatCursorEnd = 0xFC,
	EInputAction_TextChatDelete = 0xFD,
	EInputAction_Player_InteractSecondary = 0xFE,
	EInputAction_BaseBuilding_ToggleVisions = 0xFF,
	EInputAction_BaseBuilding_Browse = 0x100,
	EInputAction_BaseBuilding_Pickup = 0x101,
	EInputAction_BaseBuilding_Duplicate = 0x102,
	EInputAction_BaseBuilding_Delete = 0x103,
	EInputAction_BaseBuilding_ToggleRotationAxis = 0x104,
	EInputAction_Build_AnalogRotateZ2 = 0x105,
	EInputAction_BaseBuilding_ToggleSnapping = 0x106,
	EInputAction_BaseBuilding_ToggleWiring = 0x107,
	EInputAction_BaseBuilding_Paint = 0x108,
	EInputAction_BaseBuilding_NextPart = 0x109,
	EInputAction_TogglePause = 0x10A,
	EInputAction_TogglePlanet = 0x10B,
	EInputAction_Suicide = 0x10C,
	EInputAction_Reset = 0x10D,
	EInputAction_AddLastToolbox = 0x10E,
	EInputAction_AddLastToolboxAtPos = 0x10F,
	EInputAction_TerrainInvalidate = 0x110,
	EInputAction_TogglePipeline = 0x111,
	EInputAction_TakeScreenshot = 0x112,
	EInputAction_TakeExrScreenshot = 0x113,
	EInputAction_ToggleDebugStats = 0x114,
	EInputAction_ToggleDebugSubpage = 0x115,
	EInputAction_DumpNodeStats = 0x116,
	EInputAction_ToggleTaa = 0x117,
	EInputAction_DebugDropMeasurementAnchor = 0x118,
	EInputAction_QuickWarp = 0x119,
	EInputAction_DumpStats = 0x11A,
	EInputAction_DiscoverOwnBase = 0x11B,
	EInputAction_ClearTerrainEdits = 0x11C,
	EInputAction_SelectRegion = 0x11D,
	EInputAction_SwitchRegionRow = 0x11E,
	EInputAction_SwitchRegionAxis = 0x11F,
	EInputAction_OpenLog = 0x120,
	EInputAction_DumpVertStats = 0x121,
	EInputAction_Player_TagMarker = 0x122,
	EInputAction_NumTypes = 0x123,
};

enum ePlanetDisplayTargetDisplayState : __int32
{
	ETargetDisplayState_None = 0x0,
	ETargetDisplayState_System = 0x1,
	ETargetDisplayState_Planet = 0x2,
	ETargetDisplayState_PlanetaryMapping = 0x3,
	ETargetDisplayState_Discovery = 0x4,
};

enum ePlanetaryMappingDataState : __int32
{
	ETargetDisplayState_Idle = 0x0,
	ETargetDisplayState_SetNodes = 0x1,
	ETargetDisplayState_Complete = 0x2,
	ETargetDisplayState_CompleteCurrentPlanet = 0x3,
	ETargetDisplayState_NumTypes = 0x4,
};

struct cGcDiscoveryPageData
{
	enum eUploadType : __int32
	{
		EUploadType_All = 0x0,
		EUploadType_Single = 0x1,
	};

	enum eDiscoveryPageDataState : __int32
	{
		EDiscoveryPageDataState_Begin = 0x0,
		EDiscoveryPageDataState_CleanUp = 0x1,
		EDiscoveryPageDataState_Done = 0x2,
	};

	enum eSystemFilters : __int32
	{
		EDiscoveryPageFilter_Normal = 0x0,
		EDiscoveryPageFilter_Gek = 0x1,
		EDiscoveryPageFilter_Korvax = 0x2,
		EDiscoveryPageFilter_Vykeen = 0x3,
		EDiscoveryPageFilter_Empty = 0x4,
		EDiscoveryPageFilter_Abandoned = 0x5,
		EDiscoveryPageFilter_Red = 0x6,
		EDiscoveryPageFilter_Green = 0x7,
		EDiscoveryPageFilter_Blue = 0x8,
		EDiscoveryPageFilter_Hidden = 0x9,
		EDiscoveryPageFilter_NumFilters = 0xA,
	};

	struct SelectedDiscoveryAnimData
	{
		TkHandle mDiscoveryNode;
		__declspec(align(8)) cGcIdleAnimList mDiscoveryAnimList;
		bool mbPlayedFirstAnim;
		float mfWaitTimer;
		bool mbRequestAnim;
	};

	struct DiscoveryPagePlanetInfo
	{
		struct DiscoveryPreview
		{
			int miDiscoveriesIndex;
			int miThumbnailIndex;
			int miNextThumbnailIndex;
		};

		std::vector<cGcDiscoveryPageData::DiscoveryPageSector, TkSTLAllocatorShim<cGcDiscoveryPageData::DiscoveryPageSector> > maSectors;
		std::vector<cGcDiscoveryPageData::DiscoveryPageDiscovery, TkSTLAllocatorShim<cGcDiscoveryPageData::DiscoveryPageDiscovery> > maDiscoveries;
		std::vector<cGcDiscoveryPageData::DiscoveryPageDiscovery, TkSTLAllocatorShim<cGcDiscoveryPageData::DiscoveryPageDiscovery> > maExtinctDiscoveries;
		int miNumAnimals;
		int miNumMinerals;
		int miNumFlora;
		int miDiscoveryMissionProgress;
		bool mabVisibleDiscoveries[9];
		float mfDiscoveryDisplayTimer;
		cGcPlanetData mPlanetGenerationData;
		cGcDiscoveryPageData::DiscoveryPagePlanetInfo::DiscoveryPreview mAnimalPreview;
		cGcDiscoveryPageData::DiscoveryPagePlanetInfo::DiscoveryPreview mFloraPreview;
		cGcDiscoveryPageData::DiscoveryPagePlanetInfo::DiscoveryPreview mMineralPreview;
		int miDiscoveriesPage;
		int miSelectedDiscovery;
		eDiscoveryType meDiscoveryTypeFilter;
	};

	struct cGcViewOnOpenRequest
	{
		enum eRequestType
		{
			ERequestType_Invalid = 0x0,
			ERequestType_MostRecentDiscovery = 0x1,
			ERequestType_SpecificDiscovery = 0x2,
			ERequestType_CurrentPlanet = 0x3,
		};

		cGcDiscoveryPageData::cGcViewOnOpenRequest::eRequestType meRequestType;
		eDiscoveryType meDiscoveryType;
		cGcDiscoveryData mDiscovery;
	};

	const float kfPlanetInfoAnimOutTime;
	const float kfDiscoveryInfoAnimOutTime;
	float mfPlanetPageStartTime;
	float mfPlanetInfoStartTime;
	float mfDiscoveryInfoAnimTimer;
	float mfDiscoveryPreviewRefreshTimer;
	ScrollBarState mSystemScrollBarState;
	ScrollBarState mDiscoveriesScrollBarState;
	std::array<float, 11> mafActivityPulses;
	float mfNanitesAwardedTime;
	int miNanitesAwarded;
	cGcDiscoveryPageData::eUploadType meUploadType;
	bool mbUsedPageHint;
	unsigned __int64 mLastPlanetPositionsSystemUA;
	TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maTagImages[3];
	cGcSolarSystemQuery mSystemQuery;
	cGcDiscoveryPageData::eDiscoveryPageDataState meDataState;
	cGcDiscoveryPageData::eSystemFilters meSystemFilter;
	std::vector<cGcDiscoveryPageData::DiscoveryPageSystem, TkSTLAllocatorShim<cGcDiscoveryPageData::DiscoveryPageSystem> > maSystems;
	int miSystemsListWindowStartIndex;
	cTkStackVector<cGcDiscoveryPageDataSearchTask*> maDiscoveryPageTasks;
	cGcDiscoveryData mSelectedSolarSystem;
	int miSelectedSolarSystemIndex;
	cGcDiscoveryData mSelectedPlanet;
	unsigned __int64 mNextPlanetUA;
	cTkFixedString<127, char> mSelectedSolarSystemName;
	cGcDiscoveryPageData::DiscoveryPagePlanetInfo mSelectedPlanetInfo;
	cGcDiscoveryExport* mpDiscoveryExport;
	cGcDiscoveryData mRenameDiscovery;
	cGcDiscoveryData mReportDiscovery;
	cGcDiscoveryData mAssignCustomWonderDiscovery;
	int miNextFreeSectorImageResource;
	std::array<cTkSmartResHandle, 64> mSectorImageResources;
	int miTotalNanitesAwarded;
	std::vector<cGcDiscoveryData, TkSTLAllocatorShim<cGcDiscoveryData> > maRecentlyUploaded;
	float mfLastDiscoveryUploadedTime;
	float mfLastOfflineUploadTime;
	cGcDiscoveryPageData::SelectedDiscoveryAnimData mSelectedDiscoveryAnimData;
	ePlanetDisplayTargetDisplayState meDiscoveryDisplayState;
	ePlanetaryMappingDataState mePlanetaryMappingDataState;
	cTkSmartResHandle mMappingSphereResource;
	cGcDiscoveryPageData::cGcViewOnOpenRequest mViewOnOpenRequest;
};

struct __declspec(align(4)) TextScrollBarState
{
	float mfCurrentScrollOffsetPercentage;
	float mfTextOnScreenPercentage;
	int miCurrentPage;
	int miMaxPageIndex;
	bool mbInactive;
	bool mbFirstUpdateAfterReset;
	bool mbMoveToPreviousPage;
	bool mbMoveToNextPage;
	bool mbNewTextSet;
	bool mbForceScrollToBottom;
};

struct cGcWikiPageData
{
	int miCurrentCategoryIdx;
	int miCurrentTopic;
	int miCurrentTopicPage;
	int miCurrentPage;
	float mfTimeSinceLastTransition;
	TextScrollBarState mTextScrollBarState;
	cGcCustomWonderTextEntryHandler mCustomWonderTextEntryHandler;
};

struct __declspec(align(4)) cGcMissionPageData
{
	bool mbReset;
	int miCurrentSecMissionPage;
	float mfTimeSinceLastTransition;
	bool mbAutoScrollDone;
};

struct cGcJourneyPageData
{
	cGcJourney* mpJourney;
	TextScrollBarState mTextScrollBarState;
	int miCurrentCategory;
	int miCategoriesCount;
	float mfTimeSinceLastTransition;
	int miPinnedJourneyMilestone;
};

enum ePopupType : __int32
{
	EPopupType_Chemical = 0x0,
	EPopupType_HoverStart = 0x0,
	EPopupType_Technology = 0x1,
	EPopupType_Discovery = 0x2,
	EPopupType_DiscoveryItem = 0x3,
	EPopupType_DiscoverySystemInfo = 0x4,
	EPopupType_Empty = 0x5,
	EPopupType_RepairSlot = 0x6,
	EPopupType_Mission = 0x7,
	EPopupType_Wiki = 0x8,
	EPopupType_NetworkPlayer = 0x9,
	EPopupType_ByteBeat = 0xA,
	EPopupType_ByteBeatToolTip = 0xB,
	EPopupType_ByteBeatLibrary = 0xC,
	EPopupType_Pet = 0xD,
	EPopupType_SeasonMilestone = 0xE,
	EPopupType_BuildMenuItem = 0xF,
	EPopupType_SquadronPilot = 0x10,
	EPopupType_Build = 0x11,
	EPopupType_ActionStart = 0x11,
	EPopupType_Charge = 0x12,
	EPopupType_Transfer = 0x13,
	EPopupType_TransferSend = 0x14,
	EPopupType_BuySell = 0x15,
	EPopupType_BuySellTech = 0x16,
	EPopupType_Outfitting = 0x17,
	EPopupType_ByteBeatSend = 0x18,
	EPopupType_NumTypes = 0x19,
};

enum ePopupScreenAdjust : __int32
{
	EPopupScreenAdjust_Default = 0x0,
	EPopupScreenAdjust_AlwaysFit = 0x1,
	EPopupScreenAdjust_Tooltip = 0x2,
};

enum ePopupAction
{
	EPopupAction_None = 0xFFFFFFFF,
	EPopupAction_Transfer = 0x0,
	EPopupAction_TransferSend = 0x1,
	EPopupAction_BuildTech = 0x2,
	EPopupAction_BuildProduct = 0x3,
	EPopupAction_TechCharge = 0x4,
	EPopupAction_Repair = 0x5,
	EPopupAction_Outfitting = 0x6,
	EPopupAction_ByteBeatSend = 0x7,
	EPopupAction_NumTypes = 0x8,
};

struct cGcFrontendPopup
{
	enum ePopupClass
	{
		EPopupClass_Hover = 0x0,
		EPopupClass_Action = 0x1,
	};

	enum ePopupState : __int32
	{
		EPopupState_Inactive = 0x0,
		EPopupState_AnimateIn = 0x1,
		EPopupState_Active = 0x2,
		EPopupState_AnimateOut = 0x3,
	};

	ePopupType meType;
	ePopupScreenAdjust meScreenAdjust;
	cGcNGuiLayer mPopup;
	cGcNGuiLayer* mpSlot;
	cGcNGuiLayer* mpHoverSlotParent;
	cGcFrontendPopup::ePopupClass meClass;
	bool mbStayActive;
	bool mbActivatedWithTouch;
	bool mbHasPositionForTouch;
	float mfActiveTime;
	cGcFrontendPopup::ePopupState meState;
	InventoryChoice meActivatedInventory;
	cGcInventoryStore* mpPopupInventory;
	cGcNGuiLayer* mpPressedPopupButtonLayer;
	eInputAction mePressedPopupButtonAction;
	bool mbPressedButonActionCompleted;
};

struct cGcLayerInteractControl
{
	enum eConfirmState
	{
		EConfirmState_None = 0x0,
		EConfirmState_Confirming = 0x1,
		EConfirmState_Confirmed = 0x2,
	};
};

struct __declspec(align(8)) cGcHoldInteraction
{
	typedef cGcLayerInteractControl::eConfirmState eConfirmState;

	enum eInputAction
	{
		EInputAction_Confirm = 0x0,
		EInputAction_Transfer = 0x1,
		EInputAction_Upload = 0x2,
		EInputAction_DiscoveryUpload = 0x3,
		EInputAction_Delete = 0x4,
	};

	enum eButtonHoverState : __int32
	{
		EButtonHoverState_None = 0x0,
		EButtonHoverState_NoneStart = 0x1,
		EButtonHoverState_Instant = 0x2,
		EButtonHoverState_InstantStart = 0x3,
		EButtonHoverState_Long = 0x4,
		EButtonHoverState_LongStart = 0x5,
	};

	cGcHoldInteraction_vtbl* __vftable /*VFT*/;
	cGcNGuiLayer* mpConfirm;
	float mfConfirmTime;
	cGcHoldInteraction::eConfirmState meConfirmState;
	int miConfirmByButtonEvent;
	bool mbConfirmActiveThisFrame;
	bool mbNeedsWarning;
	TkAudioObject mAudioObject;
	cGcHoldInteraction::eInputAction meAction;
	bool mbPlayingHoldAudio;
	FrontendHold meButtonHoldType;
	cGcHoldInteraction::eButtonHoverState meButtonHoverState;
	bool mbImportant;
};

struct __declspec(align(8)) cGcCountInteraction : cGcHoldInteraction
{
	enum eCountState
	{
		ECountState_None = 0x0,
		ECountState_Counting = 0x1,
	};

	cGcCountInteraction::eCountState meCountState;
	float mfCountTime;
	bool mbCountedOnce;
	bool mbInstant;
};

struct cGcFrontendStatCircle
{
	cGcNGuiLayer* mpLayer;
	const cGcStatsGroup* mpStats;
	std::array<float, 189> mValues;
	std::array<float, 189> mValuesNoBonus;
	float mfWidth;
	float mfAnim;
};
