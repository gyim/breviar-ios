-- OCR2SOc_CIT1 resp.	Nah 2, 1	
-- 1515	Nah 2, 1. 3; 3, 1-3. 6-7
update biblia set lh_id = 'OCR2SOc_CIT1 resp.' where spis = 'Nah' and vers = 1 and k = 2 and v = 1
go
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 2 and v = 1
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 2 and v = 3
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 3 and v between 1 and 3
update biblia set lc_id = 1515 where spis = 'Nah' and vers = 1 and k = 3 and v between 6 and 7
go

update biblia set nvg = 'H�a, na vrchoch s� nohy posla, ktor� zvestuje pokoj. J�da, sl�v svoje sviatky a pl� svoje s�uby, lebo u� nep�jde cez teba Beli�l, ve� celkom zahynul. ' where spis = 'Nah' and vers = 1 and k = 2 and v = 1
update biblia set nvg = 'P�n obnov� Jakubovu d�stojnos� ako d�stojnos� Izraela, lebo zbojn�ci ich spusto�ili a pol�mali ich v�honky.' where spis = 'Nah' and vers = 1 and k = 2 and v = 3
go
update biblia set nvg = 'Beda ti, krvav� mesto, si sam� podvod, pln� koristi! Neprest�va� rabova�. ' where spis = 'Nah' and vers = 1 and k = 3 and v = 1
update biblia set nvg = 'Plieskanie bi�a, rachot kolies; kone cv�laj�, vozy hrkoc�, ' where spis = 'Nah' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'jazdci �to�ia, me�e sa mihaj�, kopije bl�skaj�; mno�stvo zabit�ch, hromada tiel. Niet konca m�tvol�m; potk�naj� sa o tel�.' where spis = 'Nah' and vers = 1 and k = 3 and v = 3
go
update biblia set nvg = '�Vrhnem na teba �pinu a potupou �a zahrniem; urob�m z teba v�strahu. ' where spis = 'Nah' and vers = 1 and k = 3 and v = 6
update biblia set nvg = 'Potom ka�d�, kto �a uvid�, odsko�� od teba a povie: �Spusto�en� je Ninive! Kto by ho �utoval?! Kde ti m�m h�ada� te�ite�a?!��' where spis = 'Nah' and vers = 1 and k = 3 and v = 7
go

