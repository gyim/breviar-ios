/*---------------------------------------------------------------------*/
/* _export_rozbor_dna_batch()
 *
 * exportuje udaje, ktore nacitala _rozbor_dna()
 * zalozene na _export_rozbor_dna();
 * ale tento ich exportuje do batch suboru (pre dalsie davkove spracovanie)
 *
 */
#define BATCH_COMMAND(a)	{ 
	strcat(batch_command, " -x%d", a); 
	/* napokon to vyprintujeme do batch suboru, 2003-07-07 */
	fprintf(batch_file, "%s -pmrch\n", batch_command); /* ranne chvaly */
	fprintf(batch_file, "%s -pmv\n", batch_command); /* vespery */
	}
void _export_rozbor_dna_batch(int typ){
/* poznamky bez uvedenia datumu su prevzate z _export_rozbor_dna; 2003-07-07 */

/* treba brat do uvahy:
 * 1. ked ma sviatok prioritu, tak ide on
 *    (ulozeny v _global_den, ak pocet_svatych == 0;
 *       resp. v _global_svaty1, ak pocet_svatych > 0;)
 * 2. ked su lubovolne spomienky, su ulozene v premennych
 *    _global_svaty1 (_global_pocet_svatych == 1),
 *    _global_svaty2 (_global_pocet_svatych == 2),
 *    _global_svaty3 (_global_pocet_svatych == 3),
 *    naviac treba napisat _global_den (ako vsedny den)
 * 3. ak ide o sobotu v OBD_CEZ_ROK, treba ponuknut moznost _global_pm_sobota
 *    (spomienka panny marie v sobotu)
 */
	char batch_command[MAX_STR] = "";
	/* pripravime si command line string pre dany datum */
	sprintf(batch_command, "%s -qpdt -d%d -m%d -r%d", 
		name_binary_executable, _global_den.den, _global_den.mesiac, _global_den.rok);

	/* pozor, hoci je nedela, predsa na nu mohlo pripadnut slavenie s vyssou
	 * prioritou */
	if((_global_den.denvt == DEN_NEDELA) ||
		(_global_den.prik == PRIKAZANY_SVIATOK) ||
		(_global_den.smer < 5)){
		/* nedele a prikazane sviatky - cervenou, velkymi pismenami */
		/* slavnosti - velkymi pismenami */

		/* 23/02/2000A.D. -- teraz este testujeme, ci nema nahodou pred nedelou
		 * (trebars v obdobi cez rok, smer == 6)
		 * prednost napr. sviatok Pana (smer == 5); dalsia cast je skopirovana
		 * podla casti v _rozbor_dna, v poznamke SVATY_VEDIE
		 */
		/* ... alebo c. 60: "ak na jeden den pripadnu viacere slavenia,
		 * uprednostni sa to, ktore ma v tabulke liturgickych dni vyssi stupen
		 * [t.j. .smer]. */
		if(_global_den.smer > _global_svaty1.smer){
			BATCH_COMMAND(1);
		}
		else{
			BATCH_COMMAND(0);
		}
	}/* if((_global_den.denvt == DEN_NEDELA) || (_global_den.prik == PRIKAZANY_SVIATOK) || (_global_den.smer < 5)) */
	else if(_global_pocet_svatych > 0){
		/* sviatky (spomienky, ls) svatych */
		if((_global_den.smer > _global_svaty1.smer) ||
			(_global_den.smer == 9) && (_global_svaty1.smer == 12)){
		/* svaty */
			BATCH_COMMAND(1);
			if(_global_pocet_svatych > 1){
				BATCH_COMMAND(2);
				if(_global_pocet_svatych > 2){
					BATCH_COMMAND(3);
				}
			}
			if((_global_svaty1.smer >= 12) &&
				(typ != EXPORT_DNA_VIAC_DNI)){
				/* ak je to iba lubovolna spomienka, tak vsedny den */
				BATCH_COMMAND(0);
			}
		}/* svaty ma prednost */
		else{
		/* prednost ma den */
			BATCH_COMMAND(0);
		}
	}/* if(_global_pocet_svatych > 0) */
	else{
		/* obycajne dni, nie sviatok */
		BATCH_COMMAND(0);
	}/* if(equals(_global_den.meno, "")) */

	/* este spomienka panny marie v sobotu, cl. 15 */
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 12) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 12) && (_global_pocet_svatych > 0))) &&
		(typ != EXPORT_DNA_VIAC_DNI)){
		BATCH_COMMAND(4);
	}

}/* _export_rozbor_dna_batch() */
