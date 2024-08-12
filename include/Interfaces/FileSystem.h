#include "IBaseInterface.h"

typedef void *FileHandle_t;
typedef int FileFindHandle_t;
typedef int WaitForResourcesHandle_t;

typedef enum {
    FILESYSTEM_SEEK_HEAD,
    FILESYSTEM_SEEK_CURRENT,
    FILESYSTEM_SEEK_TAIL,
} FileSystemSeek_t;

typedef enum {
    FILESYSTEM_WARNING = -1,             // A problem!
    FILESYSTEM_WARNING_QUIET,            // Don't print anything
    FILESYSTEM_WARNING_REPORTUNCLOSED,   // On shutdown, report names of files left unclosed
    FILESYSTEM_WARNING_REPORTUSAGE,      // Report number of times a file was opened, closed
    FILESYSTEM_WARNING_REPORTALLACCESSES // Report all open/close events to console (!slow!)
} FileWarningLevel_t;

typedef void (*WarningFunc_t)(const char *fmt, ...);

class IFileSystem : public IBaseInterface {
public:
    virtual void Mount(void);
    virtual void Unmount(void);
    virtual void RemoveAllSearchPaths(void);
    virtual void AddSearchPath(const char *pPath, const char *pathID);
    virtual bool RemoveSearchPath(const char *pPath);
    virtual void RemoveFile(const char *pRelativePath, const char *pathID);
    virtual void CreateDirHierarchy(const char *path, const char *pathID);
    virtual bool FileExists(const char *pFileName);
    virtual bool IsDirectory(const char *pFileName);
    virtual FileHandle_t Open(const char *pFileName, const char *pOptions, const char *pathID);
    virtual void Close(FileHandle_t file);
    virtual void Seek(FileHandle_t file, int pos, FileSystemSeek_t seekType);
    virtual unsigned Tell(FileHandle_t file);
    virtual unsigned Size(FileHandle_t file);
    virtual unsigned Size2(const char *pFileName);
    virtual long GetFileTime(const char *pFileName);
    virtual void FileTimeToString(char *pStrip, int maxCharsIncludingTerminator, long fileTime);
    virtual bool IsOk(FileHandle_t file);
    virtual void Flush(FileHandle_t file);
    virtual bool EndOfFile(FileHandle_t file);
    virtual int Read(void *pOutput, int size, FileHandle_t file);
    virtual int Write(void const *pInput, int size, FileHandle_t file);
    virtual char *ReadLine(char *pOutput, int maxChars, FileHandle_t file);
    virtual int FPrintf(FileHandle_t file, char *pFormat, ...);
    virtual char *GetReadBuffer(FileHandle_t file, char *pBuffer);
    virtual void ReleaseReadBuffer(FileHandle_t file, char *pBuffer);
    virtual const char *FindFirst(const char *pWildCard, FileFindHandle_t *pHandle, const char *pathID);
    virtual const char *FindNext(FileFindHandle_t handle);
    virtual bool FindIsDirectory(FileFindHandle_t handle);
    virtual void FindClose(FileFindHandle_t handle);
    virtual void GetLocalCopy(const char *pFileName);
    virtual const char *GetLocalPath(const char *pFileName, char *pLocalPath, int maxlen);
    virtual char *ParseFile(char *data, char *token, bool *wasquoted);
    virtual bool FullPathToRelativePath(const char *pFullpath, char *pRelative);
    virtual bool GetCurrentDirectory(char *pDirectory, int maxlen);
    virtual void PrintOpenedFiles(void);
    virtual void SetWarningFunc(void (*pfnWarning)(const char *fmt, ...));
    virtual void SetWarningLevel(FileWarningLevel_t level);
    virtual void LogLevelLoadStarted(const char *name);
    virtual void LogLevelLoadFinished(const char *name);
    virtual int HintResourceNeed(const char *hintlist, int forgetEverything);
    virtual int PauseResourcePreloading(void);
    virtual int ResumeResourcePreloading(void);
    virtual int SetVBuf(FileHandle_t stream, char *buffer, int mode, long size);
    virtual void GetInterfaceVersion(char *p, int maxlen);
    virtual bool IsFileImmediatelyAvailable(const char *path);
    virtual void *WaitForResources(const char *pFileName);
    virtual bool GetWaitForResourcesProgress(WaitForResourcesHandle_t handle, float *progress, bool *complete);
    virtual void CancelWaitForResources(WaitForResourcesHandle_t handle);
    virtual bool IsAppReadyForOfflinePlay(void);
    virtual void AddPackFile(const char *pPath, const char *pathID);
    virtual void *OpenFromCacheForRead(const char *pFileName, const char *pOptions, const char *pathID);
    // CSO Functions
    virtual void  LoadNar(const char* pFileName, const char* pathID);
    virtual void  SetNarFilePath(const char* dataPath);
    virtual void  Unknown03(const char* pFileName, char* a1);
    virtual int   GetChecksum(struct CFileSystem_Nar* ptr);
    virtual void  NarOpen(const char* filePath, const char* mode, const char* pathID);
    virtual int   Unknown05(int(__thiscall*** a1)(void*, int));
    virtual void  NarSeek(int a1, int a2, int a3, int a4);
    virtual void  NarTell(int a1);
    virtual void  Unknown08(int a1);
    virtual void  Unknown09(int a1, int a2, int a3, int a4);
    virtual void  Unknown10(int a1, int a2, int a3, void* a4);
    virtual void  Unknown11();
    virtual void  Unknown12();
    virtual void  Unknown13();
    virtual char* NarReadLine(char* a1, int a2, int a3);
    virtual void  NarStat(char* FileName, struct _stat32* Stat);
    virtual void  FindFirstFile2(LPCSTR lpFileName, void* lpFindFileData);
    virtual void  FindNextFile2(HANDLE hFindFile, void* lpFindFileData);
    virtual void  FindClose2(HANDLE hFile);
    virtual void  Unknown15(void* a1);
};
