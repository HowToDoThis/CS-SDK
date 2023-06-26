typedef enum LanguageCode {
    kr0,
    kr1,
    chn,
    tw,
    jpn,
    sgp,
    idn,
    th,
    tur,
    vn,
};

struct CLanguage
{
    char langName[16];
    LanguageCode langCode;
};
