// modified for import uses

////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// BandiCaptureLibrary 2.5
/// 
/// Copyright(C) 2008-2017 Bandicam.com, All rights reserved.
///
/// Author: denny
///
/// Visit http://www.bandicam.com for more information.
///
////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX_PATH 260

// Capture mode
enum BCAP_MODE
{
    BCAP_MODE_GDI,                // GDI Screen Capture 
    BCAP_MODE_D3D9,                // Direct3D 9 Screen Capture 
    BCAP_MODE_D3D9_SCALE,        // Direct3D 9 Screen Capture (with rescale)
    BCAP_MODE_D3D9_SWAPCHAIN,    // Direct3D 9 Screen Capture (with IDirect3DSwapChain9)
    BCAP_MODE_D3D8,                // Direct3D 8 Screen Capture 
    BCAP_MODE_D3D10,            // Direct3D 10 Screen Capture 
    BCAP_MODE_GL,                // OpenGL Screen Capture 
    BCAP_MODE_DDRAW7,            // DirectDraw 7 Screen Capture 
    BCAP_MODE_D3D11,            // Direct3D 11 Screen Capture 
};

// Image file format
enum BCAP_IMAGE
{
    BCAP_IMAGE_BMP,                // BMP
    BCAP_IMAGE_PNG,                // PNG
    BCAP_IMAGE_JPG,                // JPG
};

// Capture config structure 
struct BCAP_CONFIG
{
    enum { F_AVI };
    enum { V_CBR, V_VBR };
    enum { A_CBR, A_VBR };

    // How to auto-complete recording
    enum { BY_NONE, BY_TIME, BY_SIZE };

    // Video file format
    INT        FileType;                

    // Video settings
    INT        VideoSizeW;                
    INT        VideoSizeH;                
    FLOAT    VideoFPS;                

    DWORD    VideoCodec;                // FOURCC_MPEG, FOURCC_MJPG, FOURCC_MP4V
    INT        VideoRateControl;        // V_CBR, V_VBR 
    INT        VideoKBitrate;            // 10k ~ 50000k        
    INT        VideoQuality;            // 30 ~ 100            
    INT        VideoKeyframeInterval;    // 0 ~ 1000 frames
    
    // Audio settings
    INT        AudioChannels;            // 1: mono, 2:stereo 
    INT        AudioSampleRate;        // samplerate

    INT        AudioCodec;                // WAVETAG_MP2, WAVETAG_PCM, WAVETAG_NULL
    INT        AudioRateControl;        // A_CBR, A_VBR 
    INT        AudioKBitrate;            // 32k ~ 320k 
    INT        AudioQuality;            // 30 ~ 100 

    // Logo settings
    WCHAR    LogoPath[MAX_PATH];        // Path of logo file(32bit png)
    INT        LogoAlpha;                // Transparency of logo [0 ~ 100]%
    INT        LogoPosX;                // Horizontal location of logo [0 ~ 100]%
    INT        LogoPosY;                // Vertical location of logo [0 ~ 100]%
    INT        LogoSizeW;                // Horizontal width of logo [0 ~ 999]%
    INT        LogoSizeH;                // Vertical height of logo [0 ~ 999]%

    // Auto-complete recording settings
    INT        AutoCompleteType;        // How to auto-complete recording
    INT        AutoCompleteValue;        // auto-complete recording value (seconds or MB)

    // etc
    RECT    CaptureRect;            // Capture target rectange

    BOOL    IncludeCursor;            // Include the mouse cursor image
    BOOL    AdjustAudioMixer;        
    BOOL    SaveAudioTracksAsWav;    // Save audio tracks while recording (.wav)
};

#define STDMETHOD(method)        virtual HRESULT __stdcall method
#define STDMETHOD_(type,method)  virtual type __stdcall method
    
struct IBandiCapture
{
    virtual HRESULT __stdcall QueryInterface(ITypeInfo *This, const IID *const riid, void **ppvObject);
    virtual ULONG __stdcall AddRef(ITypeInfo *This);
    virtual ULONG __stdcall Release(ITypeInfo *This);
    
    STDMETHOD (Verify)(LPCSTR szID, LPCSTR szKey);                // Verify the license

    STDMETHOD_(INT, GetVersion)();                                // Version number

    STDMETHOD (Start)(LPCWSTR pwszFilePath, HWND hParentWnd, INT nCaptureMode, LONG_PTR lpParam);        // Start capture
    STDMETHOD (Pause)(BOOL bPause);                            // Pause capture
    STDMETHOD (Stop)();                                        // Stop capture
    STDMETHOD (Work)(LONG_PTR lpParam);                        
    STDMETHOD_(BOOL, IsCapturing)();                            

    STDMETHOD (CheckConfig)(BCAP_CONFIG *pCfg);                
    STDMETHOD (SetConfig)(BCAP_CONFIG *pCfg);                    
    STDMETHOD (GetConfig)(BCAP_CONFIG *pCfg);                    

    STDMETHOD_(INT, GetCaptureTime)();                            // msec
    STDMETHOD_(INT64, GetCaptureFileSize)();                    // bytes

    STDMETHOD (SetPriority)(INT nPriority);                    
    STDMETHOD_(INT, GetPriority)();                            

    STDMETHOD (SetMinMaxFPS)(INT nMin, INT nMax);                
    STDMETHOD (GetMinMaxFPS)(INT *pnMin, INT *pnMax);            

    STDMETHOD (CaptureImage)(LPCWSTR pwszFilePath, INT nFileType, INT nQuality, INT nCaptureMode, BOOL bIncludeCursor, LONG_PTR lpParam);    

    STDMETHOD_(DWORD, GetSuggestedVideoCodec)();                
    STDMETHOD_(BOOL, IsSupportedVideoCodec)(DWORD dwCodec);    
};

struct CBandiCaptureLibrary : IBandiCapture {
    HMODULE          m_hDll;
    LPCREATEBANDICAP m_pCreateBandiCap;
    IBandiCapture*   m_pCap;
};

typedef HRESULT (__stdcall *LPCREATEBANDICAP)(UINT SDKVersion, void** pp);

// IBandiCapture error code
typedef enum BCAP_STATUS_s {
    BC_OK                    = 0x00000000L,
    BC_FALSE                 = 0x00000001L,
    BC_OK_ONLY_VIDEO         = 0x07770010L,
    BC_OK_ONLY_AUDIO         = 0x07770011L,
    BC_OK_IS_NOT_CAPTURING   = 0x07770020L,
    BC_OK_COMPLETED_BY_TIME  = 0x07770030L,
    BC_OK_COMPLETED_BY_SIZE  = 0x07770031L,
    BC_OK_COMPLETED_BY_FAT32 = 0x07770032L,

    BCERR_FAIL                 = 0x80004005L,
    BCERR_INVALIDARG           = 0x87771010L,
    BCERR_VIDEO_CAPTURE        = 0x87771011L,
    BCERR_AUDIO_CAPTURE        = 0x87771012L,
    BCERR_FILE_CREATE          = 0x87771013L,
    BCERR_FILE_WRITE           = 0x87771014L,
    BCERR_NOT_ENOUGH_DISKSPACE = 0x87771015L,

    BCERR_LOAD_LIBRARY_FAIL     = 0x87771020L,
    BCERR_ALREADY_CREATED       = 0x87771021L,
    BCERR_GET_PROC_ADDRESS_FAIL = 0x87771022L,
    BCERR_LIBRARY_NOT_LOADED    = 0x87771023L,
    BCERR_UNSUPPORTED_OS        = 0x87771024L,

    BCERR_INVALID_VERSION   = 0x87771030L,
    BCERR_NOT_ENOUGH_MEMORY = 0x87771031L
} BCAP_STATUS;

// PRESETS
enum BCAP_PRESET
{
    BCAP_PRESET_DEFAULT,
    BCAP_PRESET_HALFSIZE,
    BCAP_PRESET_320x240,
    BCAP_PRESET_400x300,
    BCAP_PRESET_512x384,
    BCAP_PRESET_576x432,
    BCAP_PRESET_640x480,
    BCAP_PRESET_800x600,

    BCAP_PRESET_MPEG1,
    BCAP_PRESET_MJPEG,
    BCAP_PRESET_MJPEG_HIGH_QUALITY,
    BCAP_PRESET_MPEG4,

    BCAP_PRESET_YOUTUBE,
    BCAP_PRESET_YOUTUBE_HIGH_QUALITY,
    BCAP_PRESET_YOUTUBE_HIGH_DEFINITION,
    BCAP_PRESET_NAVER_BLOG,
    BCAP_PRESET_DAUM_TVPOT,

    BCAP_PRESET_VIDEO_EDITING,
};
