#define _troj_hymnus(anchor) {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_troj_hymnus
_krkrala_hymnus
_telakrvi_hymnus
_srdca_hymnus
_krst_hymnus
_zds_hymnus

#define _troj_kcitanie {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_troj_kcitanie
_krkrala_kcitanie
_telakrvi_kcitanie
_srdca_kcitanie
_krst_kcitanie
_zds_kcitanie
_sv_rodiny_kcitanie

/* 2006-01-24: _troj_citanie1 a _troj_citanie2 - doplnené pre posv. èítanie */
#define _troj_citanie1 {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_citanie2 {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_troj_citanie1 a _troj_citanie2
_krkrala_citanie1 a _krkrala_citanie2
_telakrvi_citanie1 a _telakrvi_citanie2
_srdca_citanie1 a _srdca_citanie2
_krst_citanie1 a _krst_citanie2

/* 2006-02-05: doplnené posvätné èítanie */
#define _bohorod_citanie1 {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _bohorod_citanie2 {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
_bohorod_citanie1 a _bohorod_citanie2
_sv_rodiny_citanie1 a _sv_rodiny_citanie2
_zds_citanie1 a _zds_citanie2

#define _troj_kresponz {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_troj_kresponz
_krkrala_kresponz
_telakrvi_kresponz
_srdca_kresponz
_krst_kresponz
_zds_kresponz

#define _bohorod_magnifikat {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_bohorod_magnifikat
_troj_magnifikat
_krkrala_magnifikat
_telakrvi_magnifikat
_srdca_magnifikat
_krst_magnifikat
_zds_magnifikat

#define _bohorod_prosby {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_bohorod_prosby
_troj_prosby
_krkrala_prosby
_telakrvi_prosby
_srdca_prosby
_krst_prosby
_zds_prosby

#define _bohorod_benediktus {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_bohorod_benediktus
_troj_benediktus
_krkrala_benediktus
_telakrvi_benediktus
_srdca_benediktus
_krst_benediktus
_zds_benediktus

#define _sv_rodiny_modlitba(vlastny_anchor) {\
	sprintf(_anchor, "%s_%s", vlastny_anchor, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_sv_rodiny_modlitba
_troj_modlitba
_krkrala_modlitba
_telakrvi_modlitba
_srdca_modlitba
_krst_modlitba
_srdca_pm_modlitba

/* 2007-10-02: upravené antifóny pre modlitbu cez deò - sú rovnaké, použitý anchor ANCHOR_ANTIFONY */
#define _troj_ne_antifony {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
_troj_ne_antifony
_krkrala_ne_antifony
_telakrvi_ne_antifony
_srdca_ne_antifony
_krst_ne_antifony
_zds_antifony
