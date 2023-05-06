#pragma once
#include "cTkTypes.h"

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
