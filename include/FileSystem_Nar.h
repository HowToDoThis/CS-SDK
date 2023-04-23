typedef void *FileHandle_t;
typedef int FileFindHandle_t;
typedef int WaitForResourcesHandle_t;

typedef enum
{
	FILESYSTEM_SEEK_HEAD,
	FILESYSTEM_SEEK_CURRENT,
	FILESYSTEM_SEEK_TAIL,
} FileSystemSeek_t;
typedef enum
{
	FILESYSTEM_WARNING = -1,					// A problem!
	FILESYSTEM_WARNING_QUIET,				// Don't print anything
	FILESYSTEM_WARNING_REPORTUNCLOSED,			// On shutdown, report names of files left unclosed
	FILESYSTEM_WARNING_REPORTUSAGE,				// Report number of times a file was opened, closed
	FILESYSTEM_WARNING_REPORTALLACCESSES		// Report all open/close events to console (!slow!)
} FileWarningLevel_t;
typedef void (*WarningFunc_t)(const char *fmt, ...);

struct CFileSystem_Nar_Vtables
{
    void (__thiscall* descructor)(struct CFileSystem_Nar* ptr, struct CFileSystem_Nar* ptr);
	void (* Mount)(void);
	void (* Unmount)(void);
	void (* RemoveAllSearchPaths)(void);
	void (__thiscall* AddSearchPath)(struct CFileSystem_Nar* ptr, const char *pPath, const char *pathID);
	bool (__thiscall* RemoveSearchPath)(struct CFileSystem_Nar* ptr, const char *pPath);
	void (__thiscall* RemoveFile)(struct CFileSystem_Nar* ptr, const char *pRelativePath, const char *pathID);
	void (__thiscall* CreateDirHierarchy)(struct CFileSystem_Nar* ptr, const char *path, const char *pathID);
	bool (__thiscall* FileExists)(struct CFileSystem_Nar* ptr, const char *pFileName);
	bool (__thiscall* IsDirectory)(struct CFileSystem_Nar* ptr, const char *pFileName);
	FileHandle_t (__thiscall* Open)(struct CFileSystem_Nar* ptr, const char *pFileName, const char *pOptions, const char *pathID);
	void (__thiscall* Close)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	void (__thiscall* Seek)(struct CFileSystem_Nar* ptr, FileHandle_t file, int pos, FileSystemSeek_t seekType);
	unsigned (__thiscall* Tell)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	unsigned (__thiscall* Size)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	unsigned (__thiscall* Size2)(struct CFileSystem_Nar* ptr, const char *pFileName);
	long (__thiscall* GetFileTime)(struct CFileSystem_Nar* ptr, const char *pFileName);
	void (__thiscall* FileTimeToString)(struct CFileSystem_Nar* ptr, char *pStrip, int maxCharsIncludingTerminator, long fileTime);
	bool (__thiscall* IsOk)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	void (__thiscall* Flush)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	bool (__thiscall* EndOfFile)(struct CFileSystem_Nar* ptr, FileHandle_t file);
	int (__thiscall* Read)(struct CFileSystem_Nar* ptr, void *pOutput, int size, FileHandle_t file);
	int (__thiscall* Write)(struct CFileSystem_Nar* ptr, void const *pInput, int size, FileHandle_t file);
	char *(__thiscall* ReadLine)(struct CFileSystem_Nar* ptr, char *pOutput, int maxChars, FileHandle_t file);
	int (__thiscall* FPrintf)(struct CFileSystem_Nar* ptr, FileHandle_t file, char *pFormat, ...);
	char *(__thiscall* GetReadBuffer)(struct CFileSystem_Nar* ptr, FileHandle_t file, char *pBuffer);
	void (__thiscall* ReleaseReadBuffer)(struct CFileSystem_Nar* ptr, FileHandle_t file, char *pBuffer);
	const char *(__thiscall* FindFirst)(struct CFileSystem_Nar* ptr, const char *pWildCard, FileFindHandle_t *pHandle, const char *pathID);
	const char *(__thiscall* FindNext)(struct CFileSystem_Nar* ptr, FileFindHandle_t handle);
	bool (__thiscall* FindIsDirectory)(struct CFileSystem_Nar* ptr, FileFindHandle_t handle);
	void (__thiscall* FindClose)(struct CFileSystem_Nar* ptr, FileFindHandle_t handle);
	void (__thiscall* GetLocalCopy)(struct CFileSystem_Nar* ptr, const char *pFileName);
	const char *(__thiscall* GetLocalPath)(struct CFileSystem_Nar* ptr, const char *pFileName, char *pLocalPath, int maxlen);
	char *(__thiscall* ParseFile)(struct CFileSystem_Nar* ptr, char *data, char *token, bool *wasquoted);
	bool (__thiscall* FullPathToRelativePath)(struct CFileSystem_Nar* ptr, const char *pFullpath, char *pRelative);
	bool (__thiscall* GetCurrentDirectory)(struct CFileSystem_Nar* ptr, char *pDirectory, int maxlen);
	void (* PrintOpenedFiles)(void);
	void (__thiscall* SetWarningFunc)(struct CFileSystem_Nar* ptr, void (*pfnWarning)(const char *fmt, ...));
	void (__thiscall* SetWarningLevel)(struct CFileSystem_Nar* ptr, FileWarningLevel_t level);
	void (__thiscall* LogLevelLoadStarted)(struct CFileSystem_Nar* ptr, const char *name);
	void (__thiscall* LogLevelLoadFinished)(struct CFileSystem_Nar* ptr, const char *name);
	int (__thiscall* HintResourceNeed)(struct CFileSystem_Nar* ptr, const char *hintlist, int forgetEverything);
	int (* PauseResourcePreloading)(void);
	int (* ResumeResourcePreloading)(void);
	int (__thiscall* SetVBuf)(struct CFileSystem_Nar* ptr, FileHandle_t stream, char *buffer, int mode, long size);
	void (__thiscall* GetInterfaceVersion)(struct CFileSystem_Nar* ptr, char *p, int maxlen);
	bool (__thiscall* IsFileImmediatelyAvailable)(struct CFileSystem_Nar* ptr, const char *path);
	void *(__thiscall* WaitForResources)(struct CFileSystem_Nar* ptr, const char *pFileName);
	bool (__thiscall* GetWaitForResourcesProgress)(struct CFileSystem_Nar* ptr, WaitForResourcesHandle_t handle, float *progress, bool *complete);
	void (__thiscall* CancelWaitForResources)(struct CFileSystem_Nar* ptr, WaitForResourcesHandle_t handle);
	bool (* IsAppReadyForOfflinePlay)(void);
	void (__thiscall* AddPackFile)(struct CFileSystem_Nar* ptr, const char *pPath, const char *pathID);
	void *(__thiscall* OpenFromCacheForRead)(struct CFileSystem_Nar* ptr, const char *pFileName, const char *pOptions, const char *pathID);
	// CSO Functions
	void  (__thiscall* LoadNar)(struct CFileSystem_Nar* ptr, const char* pFileName, const char* pathID);
	void  (__thiscall* SetNarFilePath)(struct CFileSystem_Nar* ptr, const char* dataPath);
	void  (__thiscall* Unknown03)(struct CFileSystem_Nar* ptr, const char* pFileName, char* a1);
	int   (__thiscall* GetChecksum)(struct CFileSystem_Nar* ptr);
	void  (__thiscall* NarOpen)(struct CFileSystem_Nar* ptr, const char* filePath, const char* mode, const char* pathID);
	int   (__thiscall* Unknown05)(struct CFileSystem_Nar* ptr, int(__thiscall*** a1)(void*, int));
	void  (__thiscall* NarSeek)(struct CFileSystem_Nar* ptr, int a1, int a2, int a3, int a4);
	void  (__thiscall* NarTell)(struct CFileSystem_Nar* ptr, int a1);
	void  (__thiscall* Unknown08)(struct CFileSystem_Nar* ptr, int a1);
	void  (__thiscall* Unknown09)(struct CFileSystem_Nar* ptr, int a1, int a2, int a3, int a4);
	void  (__thiscall* Unknown10)(struct CFileSystem_Nar* ptr, int a1, int a2, int a3, void* a4);
	void  (* Unknown11)();
	void  (* Unknown12)();
	void  (* Unknown13)();
	char* (__thiscall* NarReadLine)(struct CFileSystem_Nar* ptr, char* a1, int a2, int a3);
	void  (__thiscall* NarStat)(struct CFileSystem_Nar* ptr, char* FileName, struct _stat32* Stat);
	void  (__thiscall* FindFirstFile2)(struct CFileSystem_Nar* ptr, LPCSTR lpFileName, void* lpFindFileData);
	void  (__thiscall* FindNextFile2)(struct CFileSystem_Nar* ptr, HANDLE hFindFile, void* lpFindFileData);
	void  (__thiscall* FindClose2)(struct CFileSystem_Nar* ptr, HANDLE hFile);
	void  (__thiscall* Unknown15)(struct CFileSystem_Nar* ptr, void* a1);
};

struct CFileSystem_Nar
{
    CFileSystem_Nar_Vtables* vfptr;
    int unk1;
    int unk2;
    int unk3;
    int m_OpenedFiles;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int m_PackFileHandles;
    int m_FindData;
    int m_SearchPaths;
    FileWarningLevel_t m_fwLevel;
    WarningFunc_t m_pfnWarning;
    int m_nOpenCount;
    char m_bMounted;
};

struct COpenedFile
{
    FILE* pFile;
    char* szName;
};

struct CFileHandle
{
    FILE* pFile;
    bool bPack;
    bool bErrorFlagged;
    long long nStartOffset;
    long long nLength;
    long nFileTime;
};

typedef struct
{
	char        name[56];
	int         filepos;
	int         filelen;
} packfile_t;

typedef struct
{
	char id[4];
	int dirofs;
	int dirlen;
} packheader_t;

typedef struct
{
	char        name[112];
	int64_t     filepos;
	int64_t     filelen;
} packfile64_t;

typedef struct
{
	char        id[4];
	int64_t     dirofs;
	int64_t     dirlen;
} packheader64_t;

typedef struct
{
	char        id[8];
	int64_t     packheaderpos;
	int64_t     originalfilesize;
} packappenededheader_t;

// CUtlSymbol
typedef unsigned short CUtlSymbol;

struct CSearchPath
{
    CUtlSymbol path;
    CUtlSymbol pathID;

    bool bIsMapPath;
    bool bIsPackFile;
    long lPackFileTime;
    CFileHandle* hPackFile;
    int nNumPackFiles;
    size_t iCurSearchFile;
    bool bAllowWrite;

    int packFiles;
};

// CUtlSymbol
class CPackFileEntry
{
	CUtlSymbol m_Name;
	int64_t    m_nPosition;
	int64_t    m_nLength;
};

struct FindData_t
{
	WIN32_FIND_DATA  m_FindData;
	int              m_CurrentSearchPathID;
	int              m_LimitedPathID;
	int              m_WildCardString;
	HANDLE           m_FindHandle;
};

struct CNarUnknown_vtables
{
    void (__thiscall* descructor)(struct CNarUnknown* ptr);
    void (__thiscall* Function1)(struct CNarUnknown* ptr);
    void (__thiscall* Function2)(struct CNarUnknown* ptr);
    void (__thiscall* Function3)(struct CNarUnknown* ptr);
    void (__thiscall* Function4)(struct CNarUnknown* ptr);
    void (__thiscall* Function5)(struct CNarUnknown* ptr);
};
struct CNarUnknown2_vtables
{
    void (__thiscall* descructor)(struct CNarUnknown* ptr);
    void (__thiscall* Function1)(struct CNarUnknown* ptr);
};

struct CNarUnknown
{
    CNarUnknown_vtables* vfptr;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    FILE* file;
    int unk07;
    char unk08;
    char unk08a[3];
    CNarUnknown2_vtables* vfptr2;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    volatile LONG* unk15;
    char unk16;
    char unk16a[3];
};

// Related Nar File
struct CNarUnknown2
{
    int unk01;
    HANDLE file;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    char unk09;
    char unk09a[3];
    int unk10;
    int unk11;
    char unk12;
    char unk12a[3];
    int unk13;
    int unk14;
    char unk15;
    char unk15a[3];
};

struct CNarUnknown4
{
    int* vfptr; // 2 Function
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int readFile;
    int unk7;
    int unk8;
    int unk9;
    int unk10;
    char unk11;
};

struct CNarUnknown3Unk3
{
    int unk1;
    int unk2;
    int unk3;
    int unk4;
    int unk5;
    int unk6;
    int unk7;
    int unk8;
    int unk9; // set by malloc
    void* fMalloc; // malloc
    void* fFree; // delete
    int unk12;
};

struct CNarUnknown3_vtables
{
    void (__thiscall* descructor)(struct CNarUnknown3* ptr);
    void (__thiscall* Function1)(struct CNarUnknown3* ptr);
};
struct CNarUnknown3
{
    CNarUnknown3_vtables* vfptr;
    CNarUnknown4* unk2; // func
    CNarUnknown3Unk3* unk3; // array 48
    char* unk4; // array 4096
    char* unk5; // array 4096
    int unk6;
    int unk7;
    char unk8a;
    char unk8b;
};