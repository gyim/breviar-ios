			/* premenná DEN 
			 * 
			 * 2006-08-01: dynamické zisovanie hodnôt parametrov */
			i = 0; /* param[0] by mal síce obsahova query type, ale radšej kontrolujeme od 0 */
			Log("pokúšam sa zisti hodnotu parametra %s...\n", STR_DEN);
			while((equalsi(pom_DEN, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DEN)){
					/* ide o parameter STR_DEN */
					mystrcpy(pom_DEN, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DEN, pom_DEN);
				}
				i++;
			}
			if(equalsi(pom_DEN, STR_EMPTY)){
				Export("Nebola zadaná premenná %s.\n", STR_DEN);
				ALERT;
				return FAILURE; /* failure */
			}
