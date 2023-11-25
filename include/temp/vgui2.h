// handle to an internal vgui panel
// this is the only handle to a panel that is valid across dll boundaries
typedef unsigned int VPANEL;

// handles to vgui objects
// NULL_HANDLE values signify an invalid value
typedef unsigned long HScheme;
typedef unsigned long HTexture;
typedef unsigned long HCursor;
typedef unsigned long HPanel;
const HPanel INVALID_PANEL = 0xffffffff;
typedef unsigned long HFont;
const HFont INVALID_FONT; // the value of an invalid font handle

enum EInterfaceID {
    ICLIENTPANEL_STANDARD_INTERFACE = 0,
};

typedef int HContext;

enum { DEFAULT_VGUI_CONTEXT = ((HContext)~0), };

struct IClientPanel {
    virtual VPANEL GetVPanel();
    virtual void (Think)();
    virtual void (PerformApplySchemeSettings)();
    virtual void (PaintTraverse)(bool forceRepaint, bool allowForce);
    virtual void (Repaint)();
    virtual VPANEL (IsWithinTraverse)(int x, int y, bool traversePopups);
    virtual void (GetInset)(int& top, int& left, int& right, int& bottom);
    virtual void (GetClipRect)(int& x0, int& y0, int& x1, int& y1);
    virtual void (OnChildAdded)(VPANEL child);
    virtual void (OnSizeChanged)(int newWide, int newTall);
    virtual void (InternalFocusChanged)(bool lost);
    virtual bool (RequestInfo)(struct KeyValues* outputData);
    virtual void (RequestFocus)(int direction);
    virtual void (RequestFocusPrev)(VPANEL existingPanel);
    virtual void (RequestFocusNext)(VPANEL existingPanel);
    virtual void (OnMessage)(struct KeyValues* params, VPANEL ifromPanel);
    virtual VPANEL (GetCurrentKeyFocus)();
    virtual int  (GetTabPosition)();
    virtual const char* (GetName)();
    virtual const char* (GetClassName)();
    virtual HScheme (GetScheme)();
    virtual bool (IsProportional)();
    virtual bool (IsAutoDeleteSet)();
    virtual void (DeletePanel)();
    virtual void* (QueryInterface)(EInterfaceID id);
    virtual struct Panel* (GetPanel)();
    virtual const char* (GetModuleName)();
};

struct IPanel : IBaseInterface {
    virtual void Init(VPANEL vguiPanel, IClientPanel* panel);
    virtual void SetPos(VPANEL vguiPanel, int x, int y);
    virtual void GetPos(VPANEL vguiPanel, int& x, int& y);
    virtual void SetSize(VPANEL vguiPanel, int wide, int tall);
    virtual void GetSize(VPANEL vguiPanel, int& wide, int& tall);
    virtual void SetMinimumSize(VPANEL vguiPanel, int wide, int tall);
    virtual void GetMinimumSize(VPANEL vguiPanel, int& wide, int& tall);
    virtual void SetZPos(VPANEL vguiPanel, int z);
    virtual int GetZPos(VPANEL vguiPanel);
    virtual void GetAbsPos(VPANEL vguiPanel, int& x, int& y);
    virtual void GetClipRect(VPANEL vguiPanel, int& x0, int& y0, int& x1, int& y1);
    virtual void SetInset(VPANEL vguiPanel, int left, int top, int right, int bottom);
    virtual void GetInset(VPANEL vguiPanel, int& left, int& top, int& right, int& bottom);
    virtual void SetVisible(VPANEL vguiPanel, bool state);
    virtual bool IsVisible(VPANEL vguiPanel);
    virtual void SetParent(VPANEL vguiPanel, VPANEL newParent);
    virtual int GetChildCount(VPANEL vguiPanel);
    virtual VPANEL GetChild(VPANEL vguiPanel, int index);
    virtual VPANEL GetParent(VPANEL vguiPanel);
    virtual void MoveToFront(VPANEL vguiPanel);
    virtual void MoveToBack(VPANEL vguiPanel);
    virtual bool HasParent(VPANEL vguiPanel, VPANEL potentialParent);
    virtual bool IsPopup(VPANEL vguiPanel);
    virtual void SetPopup(VPANEL vguiPanel, bool state);
    virtual bool Render_GetPopupVisible(VPANEL vguiPanel);
    virtual void Render_SetPopupVisible(VPANEL vguiPanel, bool state);
    virtual HScheme GetScheme(VPANEL vguiPanel);
    virtual bool IsProportional(VPANEL vguiPanel);
    virtual bool IsAutoDeleteSet(VPANEL vguiPanel);
    virtual void DeletePanel(VPANEL vguiPanel);
    virtual void SetKeyBoardInputEnabled(VPANEL vguiPanel, bool state);
    virtual void SetMouseInputEnabled(VPANEL vguiPanel, bool state);
    virtual bool IsKeyBoardInputEnabled(VPANEL vguiPanel);
    virtual bool IsMouseInputEnabled(VPANEL vguiPanel);
    virtual void Solve(VPANEL vguiPanel);
    virtual const char* GetName(VPANEL vguiPanel);
    virtual const char* GetClassName(VPANEL vguiPanel);
    virtual void SendMessage(VPANEL vguiPanel, struct KeyValues* params, VPANEL ifromPanel);
    virtual void Think(VPANEL vguiPanel);
    virtual void PerformApplySchemeSettings(VPANEL vguiPanel);
    virtual void PaintTraverse(VPANEL vguiPanel, bool forceRepaint, bool allowForce = true);
    virtual void Repaint(VPANEL vguiPanel);
    virtual VPANEL IsWithinTraverse(VPANEL vguiPanel, int x, int y, bool traversePopups);
    virtual void OnChildAdded(VPANEL vguiPanel, VPANEL child);
    virtual void OnSizeChanged(VPANEL vguiPanel, int newWide, int newTall);
    virtual void InternalFocusChanged(VPANEL vguiPanel, bool lost);
    virtual bool RequestInfo(VPANEL vguiPanel, struct KeyValues* outputData);
    virtual void RequestFocus(VPANEL vguiPanel, int direction = 0);
    virtual bool RequestFocusPrev(VPANEL vguiPanel, VPANEL existingPanel);
    virtual bool RequestFocusNext(VPANEL vguiPanel, VPANEL existingPanel);
    virtual VPANEL GetCurrentKeyFocus(VPANEL vguiPanel);
    virtual int GetTabPosition(VPANEL vguiPanel);
    virtual struct SurfacePlat* Plat(VPANEL vguiPanel);
    virtual void SetPlat(VPANEL vguiPanel, struct SurfacePlat* Plat);
    virtual Panel* GetPanel(VPANEL vguiPanel, const char* destinationModule);
    virtual bool IsEnabled(VPANEL vguiPanel);
    virtual void SetEnabled(VPANEL vguiPanel, bool state);
    virtual IClientPanel* Client(VPANEL vguiPanel);
    virtual const char* GetModuleName(VPANEL vguiPanel);
};

struct IClientVGUI : IBaseInterface {
    virtual void Initialize(CreateInterfaceFn* factories, int count);
	virtual void Start();
	virtual void SetParent(VPANEL parent);
	virtual bool UseVGUI1();
	virtual void HideScoreBoard();
	virtual void HideAllVGUIMenu();
	virtual void ActivateClientUI();
	virtual void HideClientUI();
};

struct IVGui : IBaseInterface {
    // must be called first - provides interfaces for vgui to access
    virtual bool Init(CreateInterfaceFn* factoryList, int numFactories);

    // call to free memory on shutdown
    virtual void Shutdown();

    // activates vgui message pump
    virtual void Start();

    // signals vgui to Stop running
    virtual void Stop();

    // returns true if vgui is current active
    virtual bool IsRunning();

    // runs a single frame of vgui
    virtual void RunFrame();

    // broadcasts "ShutdownRequest" "id" message to all top-level panels in the app
    virtual void ShutdownMessage(unsigned int shutdownID);

    // panel allocation
    virtual VPANEL AllocPanel();
    virtual void FreePanel(VPANEL panel);

    // debugging prints
    virtual void DPrintf(const char* format, ...);
    virtual void DPrintf2(const char* format, ...);
    virtual void SpewAllActivePanelNames();

    // safe-pointer handle methods
    virtual HPanel PanelToHandle(VPANEL panel);
    virtual VPANEL HandleToPanel(HPanel index);
    virtual void MarkPanelForDeletion(VPANEL panel);

    // makes panel receive a 'Tick' message every frame (~50ms, depending on sleep times/framerate)
    // panel is automatically removed from tick signal list when it's deleted
    virtual void AddTickSignal(VPANEL panel, int intervalMilliseconds = 0);
    virtual void RemoveTickSignal(VPANEL panel);

    // message sending
    virtual void PostMessage(VPANEL target, KeyValues* params, VPANEL from, float delaySeconds = 0.0f);

    // Creates/ destroys vgui contexts, which contains information
    // about which controls have mouse + key focus, for example.
    virtual HContext CreateContext();
    virtual void DestroyContext(HContext context);

    // Associates a particular panel with a vgui context
    // Associating NULL is valid; it disconnects the panel from the context
    virtual void AssociatePanelWithContext(HContext context, VPANEL pRoot);

    // Activates a particular context, use DEFAULT_VGUI_CONTEXT
    // to get the one normally used by VGUI
    virtual void ActivateContext(HContext context);

    // whether to sleep each frame or not, true = sleep
    virtual void SetSleep(bool state);

    // data accessor for above
    virtual bool GetShouldVGuiControlSleep();
};

struct Panel : IClientPanel {
    virtual void Func1();
    virtual void Func2();
    virtual void Func3();

    int u1;
    int u2;
    char u3;
    char u44;
    char u45;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    VPANEL _vpanel;
    int _cursor;
    char u12;
    int u13;
    char u14;
    int u15;
    int u16;
    int u17;
    int u18;
    char* _panelName;
    char u19;
    char u20a; // 257 with short...
    int u20;
    int u42;
    int u21;
    int u22;
    int u23;
    int u24;
    int u25;
    ushort u26; // flags
    char u43;
    int u27;
    int u28;
    char u29;
    char unk1[3];
    char u31;
    char u47;
    int u32;
    int u33;
    int u34;
    int u35;
    int u36;
    int u37;
    int u38;
    int u39;
    int u40;
    int u41;
};