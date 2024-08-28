#define BIT(n) (1<<(n))

typedef enum _IN_BUTTONS {
    IN_ATTACK    = BIT(0),
    IN_JUMP      = BIT(1),
    IN_DUCK      = BIT(2),
    IN_FORWARD   = BIT(3),
    IN_BACK      = BIT(4),
    IN_USE       = BIT(5),
    IN_CANCEL    = BIT(6),
    IN_LEFT      = BIT(7),
    IN_RIGHT     = BIT(8),
    IN_MOVELEFT  = BIT(9),
    IN_MOVERIGHT = BIT(10),
    IN_ATTACK2   = BIT(11),
    IN_RUN       = BIT(12),
    IN_RELOAD    = BIT(13),
    IN_ALT1      = BIT(14),
    IN_SCORE     = BIT(15),
    
    IN_ACTIVE = IN_ATTACK | IN_ATTACK2 | IN_JUMP | IN_DUCK | IN_FORWARD | IN_BACK | IN_MOVELEFT | IN_MOVERIGHT,
} IN_BUTTONS;