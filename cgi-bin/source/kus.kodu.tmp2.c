			/* premenn· MODLITBA (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					/* ide o parameter STR_MODLITBA */
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODLITBA);
			}
