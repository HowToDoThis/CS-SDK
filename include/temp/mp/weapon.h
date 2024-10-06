class IKnifeHelper {
public:
    virtual void Init(CBasePlayerWeapon* pWeapon); // deploy?
    virtual int  CanHolster();
    virtual void Func03(); // think?
    virtual void WeaponIdle(CBasePlayerWeapon* pWeapon);
    virtual void Swing(CBasePlayerWeapon* pWeapon); // left
    virtual void Stab(CBasePlayerWeapon* pWeapon); // right
    virtual void DelayPrimaryAttack(CBasePlayerWeapon* pWeapon);
    virtual void DelaySecondaryAttack(CBasePlayerWeapon* pWeapon);
    virtual void Func09(CBasePlayerWeapon* pWeapon, float*, float*);
    virtual void Func10(CBasePlayerWeapon* pWeapon, float*);
    virtual void Func11(); // get something
    virtual void Func12();
    virtual void Func13();
    virtual void Func14();
    virtual void Func15();
    virtual void Func16();
};

class CKnifeHelperMonkeyWPNSet3 : public IKnifeHelper {
public:
    char nf1;
    float nf2;
    float nf3;
    float nf4;
    float nf5;
    float nf6;
    float nf7;
    float nf8;
    float nf9;
    float nf10;
    float nf11;
    float nf12;
    float nf13;
    float nf14;
    float nf15;
    float nf16;
    float nf17;
    float nf18;
    float nf19;
    float nf20;
    float nf21;
    float nf22;
    float nf23;
    float nf24;
    float nf25;
    float nf26;
    float nf27;
};