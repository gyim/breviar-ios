-- 474	Ezd 1, 1-6
update biblia set lc_id = 474 where spis = 'Ezd' and vers = 1 and k = 1 and v between 1 and 6
go
update biblia set nvg = 'V prvom roku perzsk�ho kr�a K�ra - aby sa vyplnilo P�novo slovo z �st Jeremi�a - P�n pohol ducha perzsk�ho kr�a K�ra a on vydal pre cel� svoje kr�ovstvo aj p�somne toto nariadenie: ' where spis = 'Ezd' and vers = 1 and k = 1 and v = 1
update biblia set nvg = '"Hovor� K�ros, kr� Per�anov: P�n, Boh nebies mi dal v�etky kr�ovstv� a rozk�zal mi, aby som mu v Jeruzaleme, �o je v Judei, postavil dom. ' where spis = 'Ezd' and vers = 1 and k = 1 and v = 2
update biblia set nvg = 'Nech teda ka�d�ho z v�s, kto ak�mko�vek sp�sobom patr� k jeho �udu, sprev�dza Boh, nech vyst�pi do Jeruzalema v Judei a buduje dom P�na, Boha Izraela: to je ten Boh, ktor� b�va v Jeruzaleme. ' where spis = 'Ezd' and vers = 1 and k = 1 and v = 3
update biblia set nvg = 'A v�etk�ch, �o zostali na mnoh�ch miestach - a b�vaj� kdeko�vek -, nech obyvatelia toho miesta podporia striebrom, zlatom, majetkom a dobytkom i dobrovo�n�mi darmi na Bo�� chr�m, �o je v Jeruzaleme."' where spis = 'Ezd' and vers = 1 and k = 1 and v = 4
update biblia set nvg = 'Tak sa vybrali knie�at� J�dov�ch a Benjam�nov�ch rod�n i k�azi a leviti a v�bec ka�d�, komu Boh pohol ducha, a i�li budova� P�nov chr�m v Jeruzaleme. ' where spis = 'Ezd' and vers = 1 and k = 1 and v = 5
update biblia set nvg = 'A v�etci, �o b�vali v�kol nich, naplnili im ruky strieborn�mi a zlat�mi n�dobami, majetkom, dobytkom a vz�cnymi predmetmi, okrem toho, �o im darovali dobrovo�ne.' where spis = 'Ezd' and vers = 1 and k = 1 and v = 6
go

-- 475	Ezd 6, 7-8. 12b. 14-20
update biblia set lc_id = 475 where spis = 'Ezd' and vers = 1 and k = 6 and v between 7 and 8
update biblia set lc_id = 475 where spis = 'Ezd' and vers = 1 and k = 6 and v = 12
update biblia set lc_id = 475 where spis = 'Ezd' and vers = 1 and k = 6 and v between 14 and 20
go
update biblia set nvg = '(Kr� D�rius nap�sal n��eln�kom za riekou:) "Neha�te pr�cu na Bo�om chr�me! Nech �idovsk� vlad�r a ich star�� postavia Bo�� dom na p�vodnom mieste. ' where spis = 'Ezd' and vers = 1 and k = 6 and v = 7
update biblia set nvg = 'Ba vyd�vam rozkaz, ako m�te pom�ha� �idovsk�m star��m, �o stavaj� Bo�� dom: T�mto mu�om treba ochotne a bez prie�ahov d�va� pr�spevky z kr�ovskej pokladnice, teda z dan�, ktor� sa vyberaj� na �zem� za riekou. ' where spis = 'Ezd' and vers = 1 and k = 6 and v = 8
update biblia set nvg = '... Toto nariadenie som vydal ja, D�rius, a chcem, aby sa pr�sne dodr�iavalo."' where spis = 'Ezd' and vers = 1 and k = 6 and v = 12
update biblia set nvg = 'A �idovsk� star�� �spe�ne pokra�ovali v stavbe pod�a predpovede proroka Aggea i Addovho syna Zachari�a, a� stavbu z rozkazu Boha Izraela a z rozkazu perzsk�ch kr�ov K�ra, D�ria a Artaxerxa dokon�ili. ' where spis = 'Ezd' and vers = 1 and k = 6 and v = 14
update biblia set nvg = 'Tento Bo�� dom dohotovili v tret� de� mesiaca Adar v �iestom roku panovania kr�a D�ria.' where spis = 'Ezd' and vers = 1 and k = 6 and v = 15
update biblia set nvg = 'Potom Izraeliti, k�azi, leviti a ostatn�, �o pri�li zo zajatia, nate�en� sl�vili posviacku tohto Bo�ieho domu. ', juv = 'tohoto -> tohto' where spis = 'Ezd' and vers = 1 and k = 6 and v = 15
update biblia set nvg = 'Pri posviacke tohoto Bo�ieho domu obetovali sto b�kov, dvesto baranov, �tyristo jahniat a dvan�s� capov na obetu za hriech za cel� Izrael, pod�a po�tu izraelsk�ch kme�ov. ' where spis = 'Ezd' and vers = 1 and k = 6 and v = 17
update biblia set nvg = 'Potom ustanovili k�azov pod�a ich tried i levitov pod�a ich zadelenia do Bo�ej slu�by v Jeruzaleme, ako to predpisuje Moj�i�ova kniha. ' where spis = 'Ezd' and vers = 1 and k = 6 and v = 18
update biblia set nvg = 'Synovia Izraela, �o pri�li zo zajatia, sl�vili �trn�steho d�a v prvom mesiaci Ve�k� noc. ' where spis = 'Ezd' and vers = 1 and k = 6 and v = 19
update biblia set nvg = 'Leviti sa v�etci o�istili a o�isten� zab�jali ve�kono�n�ho bar�nka pre v�etk�ch, �o pri�li zo zajatia, aj pre svojich bratov k�azov, aj pre seba.', juv = 'doplnen� �iarka pred ", aj pre seba"' where spis = 'Ezd' and vers = 1 and k = 6 and v = 20
go

-- 21SEP_cCIT2	Porov. Ezd 7, 6. 10. 12
update biblia set lh_id = '21SEP_cCIT2', juv = 'Porov.' where spis = 'Ezd' and vers = 1 and k = 7 and v in (6, 10, 12)
go
update biblia set nvg = '... lebo nad n�m bola dobrotiv� Bo�ia ruka..."' where spis = 'Ezd' and vers = 1 and k = 7 and v = 6
update biblia set nvg = '... S_ochotn�m srdcom sk�mal P�nov z�kon, plnil ho a_u�il prik�zanie..."' where spis = 'Ezd' and vers = 1 and k = 7 and v = 10
update biblia set nvg = '... R�chly pis�r a_u�en� v_z�kone Boha nebies. ..."' where spis = 'Ezd' and vers = 1 and k = 7 and v = 12
go

-- 476	Ezd 9, 5-9
update biblia set lc_id = 476 where spis = 'Ezd' and vers = 1 and k = 9 and v between 5 and 9
go
update biblia set nvg = '(Ja, Ezdr�,) som pri ve�ernej obete premohol svoju sk���enos�, roztrhol som si r�cho a pl᚝, hodil som sa na kolen�, rozprestrel som svoje ruky k P�novi, m�jmu Bohu, ' where spis = 'Ezd' and vers = 1 and k = 9 and v = 5
update biblia set nvg = 'a povedal som: "Bo�e m�j, som zm�ten� a hanb�m sa pozdvihn�� k tebe svoju tv�r, lebo n�m na�e nepr�vosti prer�stli cez hlavu a na�e hriechy sa od �ias na�ich otcov nakopili a� po nebo. ' where spis = 'Ezd' and vers = 1 and k = 9 and v = 6
update biblia set nvg = 'Ve�mi sme hre�ili a� po dne�n� de�. Pre na�e nepr�vosti sme my, i na�i kr�li a na�i k�azi, vydan� do r�k cudz�ch kr�ov pod me�, do zajatia, za koris� a na verejn� hanbu, ako je to v tento de�.' where spis = 'Ezd' and vers = 1 and k = 9 and v = 7
update biblia set nvg = 'Teraz sme na chv�o�ku na�li milos� u P�na, n�ho Boha. N� Boh zachr�nil na�e zvy�ky a postavil n�m stan na svojom sv�tom mieste, osvietil na�e o�i a dal n�m trocha pookria� z na�ej poroby. ' where spis = 'Ezd' and vers = 1 and k = 9 and v = 8
update biblia set nvg = 'Lebo sme otroci, ale n� Boh n�s neopustil v na�ej porobe. Naklonil n�m priaze� perzsk�ch kr�ov a oni n�m dali pookria�, aby sme mohli postavi� dom n�mu Bohu a obnovi� ho z jeho rozval�n, a dal n�m �to�i�te v Judei a v Jeruzaleme."' where spis = 'Ezd' and vers = 1 and k = 9 and v = 9
go

-- 1517	Neh 2, 1-8
update biblia set lc_id = 1517 where spis = 'Neh' and vers = 1 and k = 2 and v between 1 and 8
go
update biblia set nvg = 'Stalo sa to v mesiaci Nisan, v dvadsiatom roku kr�a Artaxerxa. Ke� kr� pil, ja som vzal v�no a podal kr�ovi; nebol som toti� v jeho nemilosti.' where spis = 'Neh' and vers = 1 and k = 2 and v = 1
update biblia set nvg = 'Kr� mi povedal: "�o si tak� smutn�? Vid�m, �e chor� nie si. Akiste ti sm�tok zviera srdce."' where spis = 'Neh' and vers = 1 and k = 2 and v = 2
update biblia set nvg = 'Ve�mi som sa z�akol a povedal som: "Kr� m�j, �i naveky. Ako by som nebol smutn�, ke� je mesto, v ktorom s� hroby mojich otcov, spustnut� a jeho br�ny vyp�len� oh�om?"' where spis = 'Neh' and vers = 1 and k = 2 and v = 3
update biblia set nvg = 'Kr� sa ma op�tal: "�o si teda �el�?"' where spis = 'Neh' and vers = 1 and k = 2 and v = 4
update biblia set nvg = 'Ja som sa pomodlil k Bohu v nebi a kr�ovi som povedal: "Ak uzn� kr� za dobr� a ak ti je tvoj sluha mil�, po�li ma do Judey, do mesta, v ktorom s� hroby mojich otcov, a ja ho znova postav�m."' where spis = 'Neh' and vers = 1 and k = 2 and v = 5
update biblia set nvg = 'Tu sa ma kr� op�tal kr�ovn� sedela ved�a neho "Ako dlho ti potrv� cesta a kedy sa vr�ti�?" A kr� sa rozhodol, �e ma pust�, ke� som mu uviedol �as.' where spis = 'Neh' and vers = 1 and k = 2 and v = 6
update biblia set nvg = 'Potom som povedal kr�ovi: "Ak uzn� kr� za dobr�, nech mi daj� listy pre vl�dcov �zem� za riekou, aby mi dovolili prejs� do Judey; aj list Azafovi, dozorcovi kr�ov�ch lesov, aby mi dal drevo na br�ny chr�movej ve�e, na mestsk� m�ry a na dom, v ktorom budem b�va�."' where spis = 'Neh' and vers = 1 and k = 2 and v = 7
update biblia set nvg = 'A kr� mi to dal, lebo nado mnou bola dobrotiv� ruka m�jho Boha.' where spis = 'Neh' and vers = 1 and k = 2 and v = 8
go

-- POST1_rNECIT
update biblia set lh_id = 'POST1_rNECIT' where spis = 'Neh' and vers = 1 and k = 8 and v between 9 and 10
-- 1518	Neh 8, 1-4a. 5-6. 7b-12
-- 1519	Neh 8, 2-4a. 5-6. 8-10
update biblia set lc_id = 1518 where spis = 'Neh' and vers = 1 and k = 8 and v between 1 and 12
go
update biblia set nvg = 'V�etok �ud sa ako jeden mu� zhroma�dil na n�mest� pred Vodnou br�nou. Z�konn�kovi Ezdr�ovi rozk�zali prinies� knihu Moj�i�ovho z�kona, ktor� dal P�n Izraelu.' where spis = 'Neh' and vers = 1 and k = 8 and v = 1
update biblia set nvg = 'K�az Ezdr� teda v prv� de� siedmeho mesiaca priniesol Z�kon pred zhroma�denie mu�ov a �ien i v�etk�ch, �o boli schopn� ch�pa�, ' where spis = 'Neh' and vers = 1 and k = 8 and v = 2
update biblia set nvg = 'a od skor�ho r�na do poludnia z neho ��tal na n�mest� pred Vodnou br�nou mu�om a �en�m i v�etk�m, �o boli schopn� porozumie�. A pozornos� v�etk�ho �udu bola upret� ku knihe z�kona.' where spis = 'Neh' and vers = 1 and k = 8 and v = 3
update biblia set nvg = 'Z�konn�k Ezdr� si stal na dreven� vyv��eninu, ktor� zhotovili na t�to pr�le�itos�. ...' where spis = 'Neh' and vers = 1 and k = 8 and v = 4
update biblia set nvg = 'Ezdr� otvoril pred o�ami v�etk�ho �udu knihu st�l toti� vy��ie ne� ostatn� �udia a ke� ju otvoril, v�etok �ud povstal. ' where spis = 'Neh' and vers = 1 and k = 8 and v = 5
update biblia set nvg = 'Potom Ezdr� velebil P�na, ve�k�ho Boha, a v�etok �ud dv�hal ruky a hovoril: "Amen, amen." ' where spis = 'Neh' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'Padli na kolen�, skl��ali sa k zemi a kla�ali sa Bohu. Leviti [...] vyu�ovali �ud v Z�kone a �ud st�l na svojom mieste. ' where spis = 'Neh' and vers = 1 and k = 8 and v = 7
update biblia set nvg = '��tali z knihy Bo�ieho z�kona, sta� za sta�ou, vykladali zmysel a vysvet�ovali, �o sa ��talo. ' where spis = 'Neh' and vers = 1 and k = 8 and v = 8
update biblia set nvg = 'Miestodr�ite� Nehemi�, k�az a z�konn�k Ezdr� a leviti, �o po��ali �ud, povedali v�etk�mu �udu: "Dne�n� de� je zasv�ten� P�novi, n�mu Bohu. Ne�ia�te a nepla�te!" Lebo v�etok �ud plakal, ke� po�ul slov� Z�kona.' where spis = 'Neh' and vers = 1 and k = 8 and v = 9
update biblia set nvg = 'Ezdr� im povedal: "Cho�te, jedzte tu�n� m�so a pite medovinu; a nie�o z toho po�lite aj t�m, ktor� si nemaj� �o pripravi�. Lebo tento de� je zasv�ten� n�mu P�novi. A nerm��te sa, ve� rados� z P�na je va�a sila!"' where spis = 'Neh' and vers = 1 and k = 8 and v = 10
update biblia set nvg = 'Leviti uti�ovali v�etok �ud a hovorili: "Ut�te sa, lebo tento de� je sv�t�; nebu�te smutn�." ' where spis = 'Neh' and vers = 1 and k = 8 and v = 11
update biblia set nvg = 'A tak v�etok �ud i�iel jes�, pi�, deli� pokrmy a sl�vi� ve�k� radostn� sviatok, lebo pochopili slov�, ktor� im ozn�mil.' where spis = 'Neh' and vers = 1 and k = 8 and v = 12
go
