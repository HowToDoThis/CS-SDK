#pragma once

typedef struct edict_s edict_t;

typedef struct entvars_s {
    string_t    classname;
    string_t    globalname;
    Vector        origin; // ok
    Vector        oldorigin;
    Vector        velocity;
    Vector        basevelocity;
    Vector     clbasevelocity;
    Vector        movedir;
    Vector        angles;
    Vector        avelocity;
    Vector        punchangle; // ok
    Vector        v_angle;
    Vector        endpos;
    Vector        startpos;
    float        impacttime;
    float        starttime;
    int            fixangle; // ok
    float        idealpitch;
    float        pitch_speed;
    float        ideal_yaw;
    float        yaw_speed;
    short modelindex;
    //int            modelindex;
    string_t    model;
    int            viewmodel;
    int            weaponmodel;
    Vector        absmin;
    Vector        absmax;
    Vector        mins;
    Vector        maxs;
    Vector        size;
    float        ltime;
    float        nextthink;
    int            movetype; // ok
    int            solid; // ok
    int            skin;
    int            body;
    int         effects; // ok
    float        gravity;
    float        friction;
    int            light_level;
    int            sequence;
    int            gaitsequence;
    float        frame; // ok
    float        animtime; // ok
    float        framerate;
    byte        controller[4];
    byte        blending[2];
    float        scale;
    int            rendermode;
    float        renderamt;
    Vector        rendercolor;
    int            renderfx;
    float        health; // OK
    float        frags;

    int            weapons;
    int nf3;
    int nf1;
    int nf2;

    float takedamage; // ok    
    int deadflag; // OK
    Vector view_ofs; // ok

    int            button;
    int            impulse;
    edict_t* chain;
    edict_t* dmg_inflictor;
    edict_t* enemy;
    edict_t* aiment;
    edict_t* owner;
    edict_t* groundentity;
    int            spawnflags; // ok
    int            flags; // OK
    int         cso_add4;
    int            colormap;
    int            team;
    float        max_health;
    float        teleport_time;
    float        armortype;
    float        armorvalue; // ok
    int            waterlevel;
    int            watertype;
    string_t    target;
    string_t    targetname;
    string_t    netname; // ok
    string_t    message;
    float        dmg_take; // ok
    float        dmg_save; // ok
    float        dmg; // ok
    float        dmgtime;
    string_t    noise;
    string_t    noise1;
    string_t    noise2;
    string_t    noise3;
    float        speed;
    float        air_finished; // ok
    float        pain_finished;
    float        radsuit_finished;
    edict_t* pContainingEntity;
    int            playerclass;
    float        maxspeed;
    float        fov;
    int            weaponanim;
    int            pushmsec;
    int            bInDuck;
    int            flTimeStepSound;
    int            flSwimTime;
    int            flDuckTime;
    int            iStepLeft;
    float        flFallVelocity;
    int            gamestate;
    int            oldbuttons;
    int            groupinfo;
    int            iuser1; // ok
    int            iuser2; // ok
    int            iuser3; // ok
    int            iuser4;
    float        fuser1;
    float        fuser2;
    float        fuser3;
    float        fuser4;
    Vector        vuser1;
    Vector        vuser2;
    Vector        vuser3;
    Vector        vuser4;
    edict_t* euser1;
    edict_t* euser2;
    edict_t* euser3;
    edict_t* euser4;
    int userID; // ok
} entvars_t;

typedef struct link_s {
    struct link_s* prev, * next;
} link_t;

struct edict_s {
    int       free;
    int       serialnumber;
    link_t    area;
    int       headnode;
    int       num_leafs;
    short     leafnums[MAX_ENT_LEAFS];
    float     freetime;
    void*     pvPrivateData;
    entvars_t v;
};