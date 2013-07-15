-- OCR2SOc_CIT1 resp.	Nah 2, 1	
-- 1515	Nah 2, 1. 3; 3, 1-3. 6-7
update biblia set lh_id = 'OCR2SOc_CIT1 resp.' where spis = 'Nah' and vers = 1 and k = 2 and v = 1
go
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 2 and v = 1
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 2 and v = 3
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 3 and v between 1 and 3
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 3 and v between 6 and 7
go

update biblia set nvg = 'H¾a, na vrchoch sú nohy posla, ktorı zvestuje pokoj. Júda, sláv svoje sviatky a plò svoje s¾uby, lebo u nepôjde cez teba Beliál, veï celkom zahynul. ' where spis = 'Nah' and vers = 1 and k = 2 and v = 1
update biblia set nvg = 'Pán obnoví Jakubovu dôstojnos ako dôstojnos Izraela, lebo zbojníci ich spustošili a polámali ich vıhonky.' where spis = 'Nah' and vers = 1 and k = 2 and v = 3
go
update biblia set nvg = 'Beda ti, krvavé mesto, si samı podvod, plné koristi! Neprestávaš rabova. ' where spis = 'Nah' and vers = 1 and k = 3 and v = 1
update biblia set nvg = 'Plieskanie bièa, rachot kolies; kone cválajú, vozy hrkocú, ' where spis = 'Nah' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'jazdci útoèia, meèe sa mihajú, kopije blıskajú; mnostvo zabitıch, hromada tiel. Niet konca màtvolám; potkınajú sa o telá.' where spis = 'Nah' and vers = 1 and k = 3 and v = 3
go
update biblia set nvg = '„Vrhnem na teba špinu a potupou a zahrniem; urobím z teba vıstrahu. ' where spis = 'Nah' and vers = 1 and k = 3 and v = 6
update biblia set nvg = 'Potom kadı, kto a uvidí, odskoèí od teba a povie: »Spustošené je Ninive! Kto by ho ¾utoval?! Kde ti mám h¾ada tešite¾a?!«“' where spis = 'Nah' and vers = 1 and k = 3 and v = 7
go

