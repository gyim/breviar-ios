	Log("/* rozparsovanie parametrov opt1...opt5 */\n");

	/* option 1 */
	if(equals(pom_MODL_OPT1, STR_ANO) || equals(pom_MODL_OPT1, "1")){
		_global_opt1 = ANO;
	}
	else if(equals(pom_MODL_OPT1, STR_NIE) || equals(pom_MODL_OPT1, "0")){
		_global_opt1 = NIE;
	}/* inak ostane _global_opt1 default */
	Log("opt1 == `%s' (%d)\n", pom_MODL_OPT1, _global_opt1);

	/* option 2 */
	if(equals(pom_MODL_OPT2, STR_MODL_ZALMY_ZO_DNA) || equals(pom_MODL_OPT2, "0")){
		_global_opt2 = MODL_ZALMY_ZO_DNA;
	}
	else if(equals(pom_MODL_OPT2, STR_MODL_ZALMY_ZO_SV) || equals(pom_MODL_OPT2, "1")){
		_global_opt2 = MODL_ZALMY_ZO_SV;
	}/* inak ostane _global_opt2 default - upravena copy-paste chyba; 2005-03-22 */
	Log("opt2 == `%s' (%d)\n", pom_MODL_OPT2, _global_opt2);

	/* option 3 */
	i = atoi(pom_MODL_OPT3);
	/* povodne pre debuggovanie v DOSe, potom sa ukazalo, ze je to uzitocne
	 * aj pod linuxom (v ostrej prevadzke); 18/02/2000A.D.
	 * predpokladam, ze tento parameter moze byt
	 * zadany eventualne cislom (teda retazcom, kt. hodnota pri konverzii
	 * na int je int, urcujuci opt3
	 */
	if((i > MODL_SPOL_CAST_NEBRAT) || (i <= 0)){
		i = 0;
		/* ide o znakovy retazec nekonvertovatelny na cislo */
	}
	else{
		mystrcpy(pom_MODL_OPT3, nazov_spolc[i], SMALL);
		/* ak je zadane cislo spravne, tak i bude spravny int
		 * a pom_MODL_OPT3 bude spravny char* */
	}
	Log("opt3: i == %d\n", i);
	while(i <= MODL_SPOL_CAST_NEBRAT){
		if(equals(pom_MODL_OPT3, nazov_spolc[i])){
			_global_opt3 = i;
			break;
		}
		i++;
	}
	if(i > MODL_SPOL_CAST_NEBRAT){
		_global_opt3 = MODL_SPOL_CAST_NEURCENA;
	}
	Log("opt3 == `%s' (%d)\n", pom_MODL_OPT3, _global_opt3);

	/* option 4 */
	if(equals(pom_MODL_OPT4, STR_ANO) || equals(pom_MODL_OPT4, "1")){ /* 2003-07-08 opravene z "4" na "1" */
		_global_opt4 = ANO;
	}
	else if(equals(pom_MODL_OPT4, STR_NIE) || equals(pom_MODL_OPT4, "0")){
		_global_opt4 = NIE;
	}/* inak ostane _global_opt4 default */
	Log("opt4 == `%s' (%d)\n", pom_MODL_OPT4, _global_opt4);

	/* option 5, pridana 2003-08-12, upravena 2003-08-13 */
	if(equals(pom_MODL_OPT5, STR_MODL_CEZ_DEN_ZALMY_ZO_DNA) || equals(pom_MODL_OPT5, "0")){
		_global_opt5 = MODL_CEZ_DEN_ZALMY_ZO_DNA;
	}
	else if(equals(pom_MODL_OPT5, STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA) || equals(pom_MODL_OPT5, "1")){
		_global_opt5 = MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA;
	}/* inak ostane _global_opt5 default */
	Log("opt5 == `%s' (%d)\n", pom_MODL_OPT5, _global_opt5);

