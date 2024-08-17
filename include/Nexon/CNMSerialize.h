class CNMSerializable {
public:
  virtual                  ~CNMSerializable();
  virtual int              Serialize       (struct CNMSerializableEncoder *, struct CNMSimpleStream *);
  virtual int              Serialize       (struct CNMSimpleStream *);
  virtual int              PriorSerialize  (struct CNMSerializableEncoder *, struct CNMSimpleStream *);
  virtual int              DeSerialize     (struct CNMSerializableDecoder *, struct CNMSimpleStream *);
  virtual int              DeSerialize     (struct CNMSimpleStream *);
  virtual int              PriorDeSerialize(struct CNMSerializableDecoder *, struct CNMSimpleStream *);
  virtual CNMSerializable* operatorEqual   (struct CNMSerializable *);

public:
    short m_uMainCode;
    char  m_uSubCode;
    char  m_uVersion;
    char  m_uSerializerVersion;
};

typedef unsigned long long NMIDCode;

typedef enum NMUSERSTATUS {
    kStatus_Unknown       = 0,

    kStatus_Online        = 10,        //    인증 OK, 메신저 OK
    kStatus_Busy          = 11,
    kStatus_Away          = 12,
    kStatus_AppearOffline = 13,
    kStatus_Offline       = 14,        //    인증 --, 메신저 --
    kStatus_GameOnline    = 15,
    kStatus_Error         = 16,
    kStatus_Authenticated = 17,        //    인증 OK, 메신저 --
};

struct NMVirtualKey {
    unsigned int uGameCode;
    unsigned int uVirtualIDCode;
};

class CNMDefaultUserInfo : public CNMSerializable {
#ifdef Unicode
    wchar_t szLoginID[32];
#else
    char szLoginID[64];
#endif
    int fUnk3;
    NMIDCode uIDCode;
    int uFlag;
#ifdef Unicode
    wchar_t szWord[32];
#else
    char szWord[64];
#endif
    NMUSERSTATUS uStatus;
    int uLocalIP;
    int uVirtualIP;
    short uPort;
};

class CNMAvatarItemInfo : public CNMSerializable {
};

class CNMRealFriendInfo : public CNMDefaultUserInfo {
    CNMAvatarItemInfo avatarInfo;
    SYSTEMTIME stBirthday;
    unsigned char uBirthdayType;
};

struct NMFriendKey {
    NMIDCode     uIDCode;
    NMVirtualKey keyOwner;
    NMVirtualKey keyVirtual;
};

class CNMFriendInfo : CNMRealFriendInfo {
    NMFriendKey keyFriend;
    char szNickName[64];
    char szPosition[64];
    char szMetaData[1000];
    char szMemo[32];
    int bIsVirtualOnline;
    unsigned int uLevel;
};

#ifdef ForIDA
struct NMFriendList {
    CNMFriendInfo* first;
    CNMFriendInfo* last;
    CNMFriendInfo* end;
};
#else
typedef std::vector<CNMFriendInfo> NMFriendList;
#endif

class CNMFriendList : public CNMSerializable {
public:
    NMFriendList aMembers;
};

class CNMCategoryInfo : public CNMSerializable {
public:
    unsigned int uCategoryCode;
    NMVirtualKey keyOwner;
#ifdef Unicode
    wchar_t szCategoryName[16];
#else
    char szCategoryName[32];
#endif
    unsigned char uProperty;
    unsigned char uAllowType;
};

class CNMCateFriendInfo : public CNMCategoryInfo {
public:
    NMFriendList aFriends;
};

#ifdef ForIDA
struct NMCategoryUserList {
    CNMCateFriendInfo* first;
    CNMCateFriendInfo* last;
    CNMCateFriendInfo* end;
};
#else
typedef std::vector<CNMCateFriendInfo> NMCategoryUserList;
#endif
