-- 522	Gn 1, 1-19
-- 521	Gn 1, 1 - 2, 2
-- 523	Gn 1, 1. 26-31a
-- 524	Gn 1, 20 - 2, 4a
-- 525	Gn 1, 26 - 2, 3
-- VTROJ_cCIT1_NE	1, 1 – 2, 2
-- 548	Gn 2, 4b-9. 15-17
-- 549	Gn 2, 7-9; 3, 1-7a
-- 546	Gn 2, 18-24
-- 547	Gn 2, 18-25
update biblia set lc_id = 521 where spis = 'Gn' and vers = 1 and k = 1 and v between 1 and 31
update biblia set lc_id = 524 where spis = 'Gn' and vers = 1 and k = 2 and v between 1 and 4
update biblia set lh_id = 'VTROJ_cCIT1_NE' where spis = 'Gn' and vers = 1 and k = 1 and v between 1 and 31
update biblia set lh_id = 'VTROJ_cCIT1_NE' where spis = 'Gn' and vers = 1 and k = 2 and v between 1 and 2
update biblia set lc_id = 548 where spis = 'Gn' and vers = 1 and k = 2 and v between 5 and 9
update biblia set lc_id = 548 where spis = 'Gn' and vers = 1 and k = 2 and v between 15 and 17
update biblia set lc_id = 547 where spis = 'Gn' and vers = 1 and k = 2 and v between 18 and 25
go

update biblia set nvg = 'Na poèiatku stvoril Boh nebo a zem. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 1
update biblia set nvg = 'Ale zem bola pustá a prázdna, tma bola nad priepasou a duch Boí sa vznášal nad vodami.' where spis = 'Gn' and vers = 1 and k = 1 and v = 2
update biblia set nvg = 'Boh povedal: „Buï svetlo!“ A bolo svetlo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 3
update biblia set nvg = 'Boh videl, e svetlo je dobré, a oddelil svetlo od tmy. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 4
update biblia set nvg = 'Svetlo nazval Dòom a tmu nazval Nocou. A nastal veèer a ráno, prvı deò.' where spis = 'Gn' and vers = 1 and k = 1 and v = 5
update biblia set nvg = 'Boh povedal: „Nech je obloha uprostred vôd a nech odde¾uje vody od vôd.“ ' where spis = 'Gn' and vers = 1 and k = 1 and v = 6
update biblia set nvg = 'Boh urobil oblohu a oddelil vody pod oblohou od vôd nad oblohou. A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 7
update biblia set nvg = 'A Boh nazval oblohu Nebom. A nastal veèer a ráno, druhı deò.' where spis = 'Gn' and vers = 1 and k = 1 and v = 8
update biblia set nvg = 'Boh povedal: „Vody pod nebom nech sa zhromadia na jedno miesto a nech sa ukáe súš.“ A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 9
update biblia set nvg = 'Boh nazval súš Zemou a masy vôd nazval Morom. A Boh videl, e je to dobré.' where spis = 'Gn' and vers = 1 and k = 1 and v = 10
update biblia set nvg = 'Ïalej Boh povedal: „Zem nech vyenie zelené rastliny: rastliny prinášajúce semeno a ovocné stromy prinášajúce plody pod¾a svojho druhu a v_nich nech je semeno na zemi.“ A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 11
update biblia set nvg = 'Zem vyhnala zelené rastliny, rastliny prinášajúce semeno pod¾a svojho druhu i stromy prinášajúce plody a v_nich semená pod¾a svojho druhu. A Boh videl, e je to dobré. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 12
update biblia set nvg = 'A nastal veèer a ráno, tretí deò.' where spis = 'Gn' and vers = 1 and k = 1 and v = 13
update biblia set nvg = 'Boh povedal: „Nech sú svetlá na nebeskej oblohe a nech odde¾ujú deò od noci, nech sú znamením období, dní a rokov, ' where spis = 'Gn' and vers = 1 and k = 1 and v = 14
update biblia set nvg = 'nech svietia na nebeskej oblohe a nech osvet¾ujú zem.“ A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 15
update biblia set nvg = 'Boh urobil dvoje ve¾kıch svetiel: väèšie svetlo, eby vládlo vo dne, a menšie svetlo, eby vládlo v_noci, a hviezdy. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 16
update biblia set nvg = 'Umiestnil ich na nebeskej oblohe, aby svietili na zem ' where spis = 'Gn' and vers = 1 and k = 1 and v = 17
update biblia set nvg = 'a vládli vo dne v_noci a odde¾ovali svetlo od tmy. A Boh videl, e je to dobré. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 18
update biblia set nvg = 'A nastal veèer a ráno, štvrtı deò.' where spis = 'Gn' and vers = 1 and k = 1 and v = 19
update biblia set nvg = 'Boh povedal: „Nech sa vody hemia ivımi tvormi a vtáky nech lietajú ponad zem na nebeskej oblohe.“ ' where spis = 'Gn' and vers = 1 and k = 1 and v = 20
update biblia set nvg = 'A Boh stvoril ve¾ryby a všetky ivé tvory, ktoré sa hıbu a hemia vo vodách, pod¾a svojho druhu, i_všetky vtáky pod¾a svojho druhu. A Boh videl, e je to dobré. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 21
update biblia set nvg = 'Boh ich poehnal a povedal: „Vzrastajte, rozmnoujte sa a naplòte morské vody;aj vtáky nech sa rozmnoujú na zemi.“ ' where spis = 'Gn' and vers = 1 and k = 1 and v = 22
update biblia set nvg = 'A nastal veèer a ráno, piaty deò.' where spis = 'Gn' and vers = 1 and k = 1 and v = 23
update biblia set nvg = 'Boh povedal: „Zem nech vydá všetky druhy ivıch bytostí: dobytok, plazy a divú zver pod¾a svojho druhu.“ A tak sa stalo.' where spis = 'Gn' and vers = 1 and k = 1 and v = 24
update biblia set nvg = 'Boh urobil divú zver pod¾a svojho druhu, dobytok pod¾a svojho druhu i_všetky druhy zemskıch plazov. A Boh videl, e je to dobré.' where spis = 'Gn' and vers = 1 and k = 1 and v = 25
update biblia set nvg = 'Potom Boh povedal: „Urobme èloveka na náš obraz, na našu podobu. Nech vládnu nad morskımi rybami a nad nebeskım vtáctvom, nad zverinou i_nad celou zemou; i_nad všetkımi plazmi, èo sa hıbu po zemi.“' where spis = 'Gn' and vers = 1 and k = 1 and v = 26
update biblia set nvg = 'A stvoril Boh èloveka na svoj obraz, / na Boí obraz ho stvoril, / mua a enu ich stvoril.' where spis = 'Gn' and vers = 1 and k = 1 and v = 27
update biblia set nvg = 'Boh ich poehnal a povedal im: // „Vzrastajte a mnote sa. / Naplòte zem a podmaòte si ju. / Panujte nad morskımi rybami, / nad nebeskım vtáctvom / a nad všetkou zverou, / èo sa hıbe po zemi.“' where spis = 'Gn' and vers = 1 and k = 1 and v = 28
update biblia set nvg = 'Potom Boh povedal: „H¾a, dávam vám všetky semenné rastliny na celej zemi a všetky stromy s_ich ovocím, v_ktorom je semeno, aby vám boli za pokrm. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 29
update biblia set nvg = 'A všetkım ivoèíchom zeme, všetkému nebeskému vtáctvu i_všetkému, èo sa hıbe na zemi a má v_sebe ivot, dávam za pokrm všetky zelené rastliny. A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 30
update biblia set nvg = 'A Boh videl všetko, èo urobil; a bolo to ve¾mi dobré. A nastal veèer a ráno, šiesty deò.' where spis = 'Gn' and vers = 1 and k = 1 and v = 31
go
update biblia set nvg = 'Takto boli ukonèené nebo a zem a všetka ich nádhera. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 1
update biblia set nvg = 'Siedmeho dòa Boh ukonèil dielo, ktoré konal, a v_siedmy deò si odpoèinul po všetkıch dielach, èo vytvoril.' where spis = 'Gn' and vers = 1 and k = 2 and v = 2
update biblia set nvg = 'A Boh poehnal siedmy deò a posvätil ho, lebo v ten deò Boh odpoèíval po celom svojom diele, ktoré stvorením vytvoril.' where spis = 'Gn' and vers = 1 and k = 2 and v = 3
update biblia set nvg = 'Toto je pôvod neba a zeme, keï boli stvorené. // Keï Pán, Boh, urobil zem a nebo, ' where spis = 'Gn' and vers = 1 and k = 2 and v = 4
update biblia set nvg = 'ešte nevzišlo na zemi nijaké po¾né krovie a ešte nerástla nijaká po¾ná rastlina, lebo Pán, Boh, nedal dáï na zem a èloveka nebolo, eby obrábal zem; ' where spis = 'Gn' and vers = 1 and k = 2 and v = 5
update biblia set nvg = 'len prameò vyvieral zo zeme a zavlaoval celı povrch zeme.' where spis = 'Gn' and vers = 1 and k = 2 and v = 6
update biblia set nvg = 'Vtedy Pán, Boh, stvárnil èloveka z prachu zeme a vdıchol do jeho nozdier dych ivota. Tak sa stal èlovek ivou bytosou.' where spis = 'Gn' and vers = 1 and k = 2 and v = 7
update biblia set nvg = 'Potom Pán, Boh, vysadil v Edene, na vıchode, záhradu a v nej umiestil èloveka, ktorého bol utvoril. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 8
update biblia set nvg = 'Pán, Boh, dal vyrás zo zeme stromom všetkıch druhov, krásnym na poh¾ad a chutnım na jedenie; uprostred záhrady dal vyrás stromu ivota a stromu poznania dobra a zla.' where spis = 'Gn' and vers = 1 and k = 2 and v = 9
go
update biblia set nvg = 'Pán, Boh, vzal èloveka a umiestil ho v záhrade Edenu, aby ju obrábal a stráil. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 15
update biblia set nvg = 'A Pán, Boh, prikázal èlovekovi: "Môeš jes zo všetkıch stromov záhrady, ' where spis = 'Gn' and vers = 1 and k = 2 and v = 16
update biblia set nvg = 'ale zo stromu poznania dobra a zla nejedz, lebo keï budeš z neho jes, zomrieš."' where spis = 'Gn' and vers = 1 and k = 2 and v = 17
update biblia set nvg = 'Pán, Boh, povedal: "Nie je dobre, e je èlovek sám. Urobím mu pomocníka, ktorı mu bude podobnı."' where spis = 'Gn' and vers = 1 and k = 2 and v = 18
update biblia set nvg = 'Keï Pán, Boh, utvoril z hliny všetku po¾nú zver a všetky nebeské vtáky, priviedol ich k Adamovi, aby videl, ako ich pomenuje. Lebo ako Adam nazval kadú ivú bytos, tak sa ona volá. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 19
update biblia set nvg = 'A Adam dal mená všetkému dobytku, všetkım nebeskım vtákom a všetkım po¾nım zvieratám. Ale pomocník, ktorı by bol podobnı Adamovi, sa nenašiel.' where spis = 'Gn' and vers = 1 and k = 2 and v = 20
update biblia set nvg = 'Pán, Boh, teda dopustil na Adama hlbokı spánok. A keï zaspal, vybral jedno z jeho rebier a jeho miesto zaplnil mäsom. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 21
update biblia set nvg = 'Z rebra, ktoré Pán, Boh, Adamovi vybral, utvoril enu a priviedol ju k Adamovi.' where spis = 'Gn' and vers = 1 and k = 2 and v = 22
update biblia set nvg = 'A Adam zvolal: "Toto je koneène kos z mojich kostí a telo z môjho tela. Bude sa vola Muena, lebo z mua bola vzatá."' where spis = 'Gn' and vers = 1 and k = 2 and v = 23
update biblia set nvg = 'Preto mu opustí svojho otca i matku a pripúta sa k svojej manelke a budú jedno telo.' where spis = 'Gn' and vers = 1 and k = 2 and v = 24
update biblia set nvg = 'Obaja, Adam i jeho ena, boli nahí a nehanbili sa.' where spis = 'Gn' and vers = 1 and k = 2 and v = 25
go

-- 558	Gn 3, 1-8
-- 559	Gn 3, 9-15
-- 560	Gn 3, 9-15. 20
-- 561	Gn 3, 9-15. 20
-- 562	Gn 3, 9-24
-- 08SEP_cCIT1	3, 9-20
update biblia set lc_id = 558 where spis = 'Gn' and vers = 1 and k = 3 and v between 1 and 8
update biblia set lc_id = 562 where spis = 'Gn' and vers = 1 and k = 3 and v between 9 and 24
update biblia set lh_id = '08SEP_cCIT1' where spis = 'Gn' and vers = 1 and k = 1 and v between 9 and 20
go

update biblia set nvg = 'Had bol ¾stivejší ne všetky po¾né zvieratá, ktoré urobil Pán, Boh. I vravel ene: "Naozaj vám Boh zakázal jes zo všetkıch stromov záhrady?"' where spis = 'Gn' and vers = 1 and k = 3 and v = 1
update biblia set nvg = 'ena mu odpovedala: "Jeme ovocie zo všetkıch stromov, èo sú v záhrade. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'Len ovocie stromu, ktorı je uprostred záhrady, nám Boh zakázal jes, ba aj dotknú sa ho, aby sme nezomreli."' where spis = 'Gn' and vers = 1 and k = 3 and v = 3
update biblia set nvg = 'No had povedal ene: "Nie, nezomriete. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 4
update biblia set nvg = 'Ale Boh vie, e v deò, keï budete z neho jes, otvoria sa vám oèi a budete ako Boh, budete pozna dobro i zlo."' where spis = 'Gn' and vers = 1 and k = 3 and v = 5
update biblia set nvg = 'ena videla, e by bolo dobré jes zo stromu, e strom je na poh¾ad krásny a na získanie múdrosti vábivı; vzala z jeho ovocia a jedla a dala aj svojmu muovi, èo bol s òou, a jedol aj on.' where spis = 'Gn' and vers = 1 and k = 3 and v = 6
update biblia set nvg = 'Obom sa otvorili oèi a keï spoznali, e sú nahí, zošili figové listy a urobili si zástery.' where spis = 'Gn' and vers = 1 and k = 3 and v = 7
update biblia set nvg = 'Keï potom poèuli hlas Pána, Boha, ktorı sa za popoludòajšieho vánku prechádzal po záhrade, skryl sa Adam i jeho ena pred Pánom, Bohom, medzi stromy záhrady.' where spis = 'Gn' and vers = 1 and k = 3 and v = 8
update biblia set nvg = 'Pán, Boh, zavolal èloveka a povedal mu: „Kde si?“ ' where spis = 'Gn' and vers = 1 and k = 3 and v = 9
update biblia set nvg = 'On odpovedal: „Poèul som tvoj hlas v_záhrade, na¾akal som sa, pretoe som nahı, a skryl som sa.“ ' where spis = 'Gn' and vers = 1 and k = 3 and v = 10
update biblia set nvg = 'Opıtal sa ho: „Kto a upozornil, e si nahı, ak si nejedol zo stromu, z_ktorého som ti jes zakázal?“ ' where spis = 'Gn' and vers = 1 and k = 3 and v = 11
update biblia set nvg = 'Èlovek odpovedal: „ena, ktorú si mi dal za spoloèníèku, dala mi zo stromu a jedol som.“ ' where spis = 'Gn' and vers = 1 and k = 3 and v = 12
update biblia set nvg = 'Pán, Boh, povedal ene: „Èo si to urobila?“ ena odpovedala: „Had ma naviedol a jedla som.“' where spis = 'Gn' and vers = 1 and k = 3 and v = 13
update biblia set nvg = 'Tu povedal Pán, Boh, hadovi: // „Pretoe si to urobil, prekliaty budeš / medzi všetkımi krotkımi / a divımi zvieratami. / Po bruchu sa budeš plazi / a prach hlta po všetky dni svojho ivota. /' where spis = 'Gn' and vers = 1 and k = 3 and v = 14
update biblia set nvg = 'Nepriate¾stvo ustanovujem medzi tebou a enou, / medzi tvojím potomstvom a jej potomstvom; / ono ti rozšliape hlavu / a ty mu zraníš pätu.“' where spis = 'Gn' and vers = 1 and k = 3 and v = 15
update biblia set nvg = 'ene povedal: // „Rozmnoím tvoje trápenie / a tvoju archavos: / v_bolesti budeš rodi deti, / budeš túi po svojom muovi, / ale on bude nad tebou vládnu.“' where spis = 'Gn' and vers = 1 and k = 3 and v = 16
update biblia set nvg = 'A èlovekovi povedal: // „Pretoe si poèúval hlas svojej eny / a jedol si zo stromu, / z_ktorého som ti jes zakázal, / nech je prekliata zem pre teba: / s_námahou sa z_nej budeš ivi / po všetky dni svojho ivota;' where spis = 'Gn' and vers = 1 and k = 3 and v = 17
update biblia set nvg = 'tànie a bod¾aè ti bude rodi / a ty budeš jes po¾né rastliny. / ' where spis = 'Gn' and vers = 1 and k = 3 and v = 18
update biblia set nvg = 'V_pote svojej tváre budeš jes chlieb, / kım sa nevrátiš do zeme, / z_ktorej si bol vzatı, / lebo prach si a do prachu sa vrátiš.“' where spis = 'Gn' and vers = 1 and k = 3 and v = 19
update biblia set nvg = 'A nazval èlovek svoju enu Eva, pretoe bola matkou všetkıch ijúcich.' where spis = 'Gn' and vers = 1 and k = 3 and v = 20
update biblia set nvg = 'Pán, Boh, urobil Adamovi a jeho ene koené tuniky a obliekol ich. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 21
update biblia set nvg = 'Potom Pán, Boh, povedal: "H¾a, èlovek sa stal ako jeden z nás. Pozná dobro i zlo. Len aby teraz nesiahol svojou rukou na strom ivota a nejedol z neho a neil naveky!"' where spis = 'Gn' and vers = 1 and k = 3 and v = 22
update biblia set nvg = 'A Pán, Boh, ho vykázal zo záhrady Edenu, aby obrábal zem, z ktorej bol vzatı. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 23
update biblia set nvg = 'Vyhnal èloveka a na vıchod od záhrady Edenu postavil cherubov a pohyblivı ohnivı meè, aby stráili cestu k stromu ivota.' where spis = 'Gn' and vers = 1 and k = 3 and v = 24
go

-- 565	Gn 4, 1-15. 25
update biblia set lc_id = 565 where spis = 'Gn' and vers = 1 and k = 4 and v between 1 and 15
update biblia set lc_id = 565 where spis = 'Gn' and vers = 1 and k = 4 and v = 25
go

update biblia set nvg = 'Adam poznal svoju enu Evu, ona poèala a porodila Kaina a povedala: "Dostala som mua od Pána." ' where spis = 'Gn' and vers = 1 and k = 4 and v = 1
update biblia set nvg = 'A opä porodila jeho brata Ábela. Ábel bol pastier oviec, Kain ro¾ník.' where spis = 'Gn' and vers = 1 and k = 4 and v = 2
update biblia set nvg = 'Po istom èase priniesol Kain Pánovi obetu z po¾nıch plodín. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 3
update biblia set nvg = 'Aj Ábel obetoval z prvotín svojho stáda, z tıch najtuènejších. A Pán zhliadol na Ábela a na jeho obetu, ' where spis = 'Gn' and vers = 1 and k = 4 and v = 4
update biblia set nvg = 'ale na Kaina a na jeho obetu nezhliadol. Kain sa ve¾mi nahneval a tvár sa mu zamraèila.' where spis = 'Gn' and vers = 1 and k = 4 and v = 5
update biblia set nvg = 'Pán mu povedal: "Preèo sa hneváš a preèo mraèíš tvár? ' where spis = 'Gn' and vers = 1 and k = 4 and v = 6
update biblia set nvg = 'Nemal by si zdvihnú hlavu, ak robíš dobre? Ale ak zle robíš, hriech èíha pri dverách a zachvacuje a jeho iadostivos, lene ty ju máš ovláda."' where spis = 'Gn' and vers = 1 and k = 4 and v = 7
update biblia set nvg = 'Kain povedal svojmu bratovi Ábelovi: "Poï, vyjdeme si von!" A keï boli na poli, Kain napadol svojho brata Ábela a zabil ho.' where spis = 'Gn' and vers = 1 and k = 4 and v = 8
update biblia set nvg = 'Tu Pán povedal Kainovi: "Kde je tvoj brat Ábel?" On odvetil: "Neviem. Èo som ja stráca svojho brata?" ' where spis = 'Gn' and vers = 1 and k = 4 and v = 9
update biblia set nvg = 'Pán mu povedal: "Èo si to urobil? Hlas krvi tvojho brata krièí ku mne zo zeme. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 10
update biblia set nvg = 'Teraz budeš prekliaty a ïaleko od zeme, ktorá otvorila ústa, aby vypila krv tvojho brata z tvojej ruky. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 11
update biblia set nvg = 'Keï ju budeš obrába, u ti neprinesie úrodu. Budeš nespokojnı a budeš sa túla po zemi."' where spis = 'Gn' and vers = 1 and k = 4 and v = 12
update biblia set nvg = 'Kain povedal Pánovi: "Môj trest je väèší, ne vládzem znies. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 13
update biblia set nvg = 'Ty ma dnes vyháòaš zo zeme a budem sa skrıva pred tebou; budem nespokojnı, túla sa budem po zemi a kto ma stretne, zabije ma."' where spis = 'Gn' and vers = 1 and k = 4 and v = 14
update biblia set nvg = 'Ale Pán mu povedal: "Nie, to sa nestane. Lebo kadı, kto by zabil Kaina, sedemnásobnú pomstu ponesie." A Pán Kaina oznaèil, aby ho nik nezabil, keï ho stretne.' where spis = 'Gn' and vers = 1 and k = 4 and v = 15
update biblia set nvg = 'Adam opä poznal svoju enu, ona porodila syna a dala mu meno Set, lebo povedala: "Boh mi dal iného potomka namiesto Ábela, ktorého zabil Kain."' where spis = 'Gn' and vers = 1 and k = 4 and v = 25
go

-- 571	Gn 6, 5-8; 7, 1-5. 10
update biblia set lc_id = 571 where spis = 'Gn' and vers = 1 and k = 6 and v between 5 and 8
update biblia set lc_id = 571 where spis = 'Gn' and vers = 1 and k = 7 and v between 1 and 5
update biblia set lc_id = 571 where spis = 'Gn' and vers = 1 and k = 7 and v = 10
go

update biblia set nvg = 'Keï Pán videl, e zloba ¾udí na zemi je ve¾ká a e všetko zmıš¾anie ich srdca je ustaviène naklonené k zlu, ' where spis = 'Gn' and vers = 1 and k = 6 and v = 5
update biblia set nvg = 'o¾utoval, e urobil èloveka na zemi, a bolelo ho srdce. Pán povedal: ' where spis = 'Gn' and vers = 1 and k = 6 and v = 6
update biblia set nvg = '"Vyhubím z povrchu zeme èloveka, ktorého som stvoril: èlovekom poènúc a po dobytok, plazy a nebeské vtáctvo, lebo ¾utujem, e som ich urobil."' where spis = 'Gn' and vers = 1 and k = 6 and v = 7
update biblia set nvg = 'Ale Noe našiel milos u Pána.' where spis = 'Gn' and vers = 1 and k = 6 and v = 8
go
update biblia set nvg = 'Preto Pán povedal Noemovi: "Vojdi s celou svojou rodinou do korába, lebo som videl, e si spravodlivı predo mnou uprostred tohoto pokolenia. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 1
update biblia set nvg = 'Zo všetkıch èistıch zvierat vezmi po sedem párov, samca a samicu; z neèistıch zvierat po páre, samca a samicu. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 2
update biblia set nvg = 'Aj z nebeského vtáctva vezmeš po sedem párov, samca a samicu, aby sa zachovalo potomstvo na celej zemi. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 3
update biblia set nvg = 'Lebo ešte sedem dní a potom dám prša na zem štyridsa dní a štyridsa nocí a vyhubím z povrchu zeme všetky bytosti, ktoré som urobil."' where spis = 'Gn' and vers = 1 and k = 7 and v = 4
update biblia set nvg = 'Noe urobil všetko, èo mu Pán rozkázal. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 5
go
update biblia set nvg = 'A keï prešlo sedem dní, privalili sa na zem vody potopy.' where spis = 'Gn' and vers = 1 and k = 7 and v = 10
go

-- 572	Gn 8, 6-13. 20-22
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 6 and 13 -- je tam aj verš 14 pod¾a SSV; NVg má v. 13
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 20 and 22
go

update biblia set nvg = 'Keï uplynulo štyridsa dní, Noe otvoril na korábe okno, ktoré bol urobil, ' where spis = 'Gn' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'a vypustil krkavca. Ten odlietal a prilietal, kım vody na zemi nevyschli.' where spis = 'Gn' and vers = 1 and k = 8 and v = 7
update biblia set nvg = 'Vypustil von aj holubicu, aby zvedel, èi u vody stiekli z povrchu zeme. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 8
update biblia set nvg = 'Ale keï nenašla miesto, kde by spoèinula jej noha, vrátila sa k nemu do korába; po celej zemi boli ešte vody. Noe vystrel ruku, chytil ju a vzal ju do korába.' where spis = 'Gn' and vers = 1 and k = 8 and v = 9
update biblia set nvg = 'Èakal ešte sedem dní a znova vypustil z korába holubicu. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 10
update biblia set nvg = 'A ona k nemu priletela a v podveèer a v zobáku priniesla olivovú ratoles so zelenımi listami. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 11
update biblia set nvg = 'Tu Noe poznal, e vody zo zeme zmizli. Èakal ešte ïalších sedem dní a vypustil holubicu, ktorá sa u k nemu nevrátila.' where spis = 'Gn' and vers = 1 and k = 8 and v = 12
update biblia set nvg = 'V šesstoprvom roku, v prvom mesiaci, v prvı deò mesiaca, vody na zemi vyschli. Noe otvoril strechu korába, pozrel sa von a videl, e povrch zeme je suchı.' where spis = 'Gn' and vers = 1 and k = 8 and v = 13
-- update biblia set nvg = null where spis = 'Gn' and vers = 1 and k = 8 and v = 14
go
update biblia set nvg = 'Potom postavil oltár Pánovi, vzal zo všetkého èistého dobytka a z èistıch vtákov a priniesol zápalnú obetu na oltári.' where spis = 'Gn' and vers = 1 and k = 8 and v = 20
update biblia set nvg = 'Pán zavoòal príjemnú vôòu a povedal si: "U nikdy neprek¾ajem zem pre èloveka, lebo zmıš¾anie ¾udského srdca je od mladosti náklonné na zlé. Preto u nikdy nevyhubím všetky ivé bytosti, ako som to urobil.' where spis = 'Gn' and vers = 1 and k = 8 and v = 21
update biblia set nvg = 'Kım potrvá zem, neprestane sejba a atva, chlad a horúèos, leto a zima, deò a noc."' where spis = 'Gn' and vers = 1 and k = 8 and v = 22
go

-- 573	Gn 9, 1-13
-- 574	Gn 9, 8-15
update biblia set lc_id = 573 where spis = 'Gn' and vers = 1 and k = 9 and v between 1 and 13
update biblia set lc_id = 574 where spis = 'Gn' and vers = 1 and k = 9 and v between 14 and 15
go

update biblia set nvg = 'Boh poehnal Noema a jeho synov a povedal im: "Vzrastajte, mnote sa a naplòte zem! ' where spis = 'Gn' and vers = 1 and k = 9 and v = 1
update biblia set nvg = 'Nech majú pred vami strach a hrôzu všetky pozemské zvieratá i všetko nebeské vtáctvo a všetko, èo sa hıbe na zemi! Vo vašich rukách sú všetky morské ryby. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 2
update biblia set nvg = 'Všetko, èo sa hıbe a ije, bude vám slúi za pokrm; dávam vám všetko, ako kedysi zelené byliny.' where spis = 'Gn' and vers = 1 and k = 9 and v = 3
update biblia set nvg = 'Len mäso s dušou, ktorá je v krvi, nebudete jes. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 4
update biblia set nvg = 'Lebo aj za vašu krv budem bra na zodpovednos kadé zviera. Za ivot èloveka budem bra na zodpovednos èloveka, jeho brata. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 5
update biblia set nvg = 'Ak niekto preleje krv èloveka, inı èlovek nech preleje jeho krv, lebo èlovek bol na Boí obraz stvorenı.' where spis = 'Gn' and vers = 1 and k = 9 and v = 6
update biblia set nvg = 'Vy však vzrastajte, mnote sa, rozšírte sa po zemi a ovládnite ju!"' where spis = 'Gn' and vers = 1 and k = 9 and v = 7
update biblia set nvg = 'Aj toto povedal Boh Noemovi a jeho synom: ' where spis = 'Gn' and vers = 1 and k = 9 and v = 8
update biblia set nvg = '"H¾a, ja uzavriem zmluvu s vami a s vaším potomstvom ' where spis = 'Gn' and vers = 1 and k = 9 and v = 9
update biblia set nvg = 'i so všetkımi ivımi bytosami, èo sú s vami: s vtákmi i s dobytkom a so všetkou zverou zeme, èo je s vami, so všetkım, èo vyšlo z korába; so všetkımi zvieratami na zemi. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 10
update biblia set nvg = 'Uzavriem s vami zmluvu a u nikdy nezahynie všetko ivé vo vodách potopy, u nikdy nebude potopa, ktorá by spustošila zem."' where spis = 'Gn' and vers = 1 and k = 9 and v = 11
update biblia set nvg = 'A Boh povedal: "Toto je znak zmluvy, ktorú uzatváram medzi mnou a vami a medzi všetkımi ivımi bytosami, èo sú s vami, pre všetky budúce pokolenia: ' where spis = 'Gn' and vers = 1 and k = 9 and v = 12
update biblia set nvg = 'Do oblakov vloím svoj oblúk a bude znamením zmluvy medzi mnou a zemou.' where spis = 'Gn' and vers = 1 and k = 9 and v = 13
update biblia set nvg = 'Keï nahromadím oblaky nad zemou a keï sa v oblakoch zjaví dúha, ' where spis = 'Gn' and vers = 1 and k = 9 and v = 14
update biblia set nvg = 'vtedy si spomeniem na svoju zmluvu s vami a s kadou ivou bytosou, ktorá má telo. Nebudú u vody potopy a neznièia nijaké telo."' where spis = 'Gn' and vers = 1 and k = 9 and v = 15
go

-- 526	Gn 11, 1-9
-- 527	Gn 11, 1-9
update biblia set lc_id = 527 where spis = 'Gn' and vers = 1 and k = 11 and v between 1 and 9
go

update biblia set nvg = 'Na celej zemi bol jeden jazyk a rovnaká reè.' where spis = 'Gn' and vers = 1 and k = 11 and v = 1
update biblia set nvg = 'Keï sa ¾udia pohli z vıchodu, našli rovinu v krajine Sennaar a usadili sa na nej.' where spis = 'Gn' and vers = 1 and k = 11 and v = 2
update biblia set nvg = 'Povedali si: "Poïte, narobíme tehál a vypálime ich v ohni." Tehlu pouívali namiesto kameòa a namiesto malty asfalt. ' where spis = 'Gn' and vers = 1 and k = 11 and v = 3
update biblia set nvg = 'Potom povedali: "Poïte, postavíme si mesto a veu, ktorej vrchol bude siaha do neba. A urobíme si meno, aby sme sa nerozptılili po celej zemi."' where spis = 'Gn' and vers = 1 and k = 11 and v = 4
update biblia set nvg = 'Pán však zostúpil, aby sa podíval na mesto a veu, ktorú stavali ¾udia, ' where spis = 'Gn' and vers = 1 and k = 11 and v = 5
update biblia set nvg = 'a povedal: "H¾a, sú jeden národ a všetci hovoria jednım jazykom. Toto je zaèiatok ich èinov a u im nebude ako urobi, èo si zaumienili. ' where spis = 'Gn' and vers = 1 and k = 11 and v = 6
update biblia set nvg = 'Poïte, zostúpime a pomätieme tam ich reè, aby nik nerozumel reèi druhého."' where spis = 'Gn' and vers = 1 and k = 11 and v = 7
update biblia set nvg = 'Tak ich Pán odtia¾ rozptılil po celej zemi a mesto prestali stava. ' where spis = 'Gn' and vers = 1 and k = 11 and v = 8
update biblia set nvg = 'Preto sa ono volá Bábel. Lebo tam bola pomätená reè celej zeme a Pán ich odtia¾ rozptılil po celej zemi.' where spis = 'Gn' and vers = 1 and k = 11 and v = 9
go

-- 528	Gn 12, 1-4a
-- 529	Gn 12, 1-4a
-- 530	Gn 12, 1-7
-- 531	Gn 12, 1-9
update biblia set lc_id = 531 where spis = 'Gn' and vers = 1 and k = 12 and v between 1 and 9
go

update biblia set nvg = 'Pán povedal Abramovi: "Odíï zo svojej krajiny, od svojich príbuznıch a z domu svojho otca do krajiny, ktorú ti ukáem.' where spis = 'Gn' and vers = 1 and k = 12 and v = 1
update biblia set nvg = 'Urobím z teba ve¾kı národ a poehnám a, oslávim tvoje meno a budeš poehnaním. ' where spis = 'Gn' and vers = 1 and k = 12 and v = 2
update biblia set nvg = 'Poehnám tıch, èo a budú ehna, a prek¾ajem tıch, èo a budú preklína. V tebe budú poehnané všetky pokolenia zeme."' where spis = 'Gn' and vers = 1 and k = 12 and v = 3
update biblia set nvg = 'A Abram odišiel, ako mu rozkázal Pán. // Išiel s ním aj Lot. Abram mal sedemdesiatpä rokov, keï odišiel z Charranu. ' where spis = 'Gn' and vers = 1 and k = 12 and v = 4
update biblia set nvg = 'Vzal svoju enu Sarai a svojho synovca Lota i celı majetok, èo nadobudli, aj sluobníctvo, ktoré získali v Charrane. Pohli sa a išli do krajiny Kanaán.' where spis = 'Gn' and vers = 1 and k = 12 and v = 5
update biblia set nvg = 'Keï došli do krajiny Kanaán, Abram prešiel krajinou a k miestu Sichem, a k dubu Moreho. Vtedy bıvali v krajine Kanaánèania.' where spis = 'Gn' and vers = 1 and k = 12 and v = 6
update biblia set nvg = 'Abramovi sa zjavil Pán a povedal mu: "Túto krajinu dám tvojmu potomstvu." A on tam Pánovi, ktorı sa mu zjavil, postavil oltár.' where spis = 'Gn' and vers = 1 and k = 12 and v = 7
update biblia set nvg = 'Odtia¾ odišiel k vrchu, ktorı bol vıchodne od Betelu, a tam postavil svoj stan. Na západe mal Betel, na vıchode Hai. Aj tam postavil Pánovi oltár a vzıval Pánovo meno. ' where spis = 'Gn' and vers = 1 and k = 12 and v = 8
update biblia set nvg = 'A Abram postupoval zo stanoviša na stanovište a k Negebu.' where spis = 'Gn' and vers = 1 and k = 12 and v = 9
go

-- 532	Gn 13, 2. 5-18
update biblia set lc_id = 532 where spis = 'Gn' and vers = 1 and k = 13 and v = 1
update biblia set lc_id = 532 where spis = 'Gn' and vers = 1 and k = 13 and v between 5 and 18
go

update biblia set nvg = 'Abram bol ve¾mi bohatı: mal stáda, striebro a zlato. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 1
update biblia set nvg = 'Ale aj Lot, ktorı šiel s Abramom, mal stáda oviec, dobytok a stany. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 5
update biblia set nvg = 'Nestaèila im krajina, ak mali bıva vedno; mali to¾ko majetku, e nemohli zosta spolu.' where spis = 'Gn' and vers = 1 and k = 13 and v = 6
update biblia set nvg = 'Medzi pastiermi Abramovıch stád a pastiermi Lotovıch stád vznikol spor. A v krajine bıvali vtedy Kanaánèania a Ferezejèania.' where spis = 'Gn' and vers = 1 and k = 13 and v = 7
update biblia set nvg = 'Preto povedal Abram Lotovi: "Nech nie sú rozbroje medzi mnou a tebou, medzi mojimi pastiermi a tvojimi pastiermi; sme predsa bratia! ' where spis = 'Gn' and vers = 1 and k = 13 and v = 8
update biblia set nvg = 'Nie je pred tebou celá krajina? Preto, prosím, odlúè sa odo mòa. Keï pôjdeš na¾avo, ja pôjdem napravo; keï si vyvolíš pravú stranu, ja sa poberiem na ¾avú."' where spis = 'Gn' and vers = 1 and k = 13 and v = 9
update biblia set nvg = 'Lot zdvihol oèi a videl, e celé okolie Jordána a po Segor je zavlaené ako Pánova záhrada a ako Egypt; bolo to predtım, ako Pán znièil Sodomu a Gomoru. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 10
update biblia set nvg = 'Preto si Lot vybral krajinu okolo Jordána a odtiahol na vıchod. Takto sa bratia oddelili jeden od druhého. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 11
update biblia set nvg = 'Abram bıval v krajine Kanaán, Lot sa zdroval v mestách okolo Jordána a prenášal svoje stany a po Sodomu.' where spis = 'Gn' and vers = 1 and k = 13 and v = 12
update biblia set nvg = 'No Sodomèania boli zlí a ve¾mi hrešili proti Pánovi.' where spis = 'Gn' and vers = 1 and k = 13 and v = 13
update biblia set nvg = 'Pán povedal Abramovi, keï sa Lot od neho odlúèil: "Zdvihni oèi a z miesta, na ktorom si, pozri na sever a na juh, na vıchod i na západ: ' where spis = 'Gn' and vers = 1 and k = 13 and v = 14
update biblia set nvg = 'celú krajinu, ktorú vidíš, dám tebe a tvojmu potomstvu naveky.' where spis = 'Gn' and vers = 1 and k = 13 and v = 15
update biblia set nvg = 'Rozmnoím tvoje potomstvo a bude ho ako prachu na zemi; ak môe niekto spoèíta prach na zemi, bude môc aj tvoje potomstvo spoèíta. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 16
update biblia set nvg = 'Vstaò a prejdi krajinu po dåke a po šírke, lebo ju dám tebe."' where spis = 'Gn' and vers = 1 and k = 13 and v = 17
update biblia set nvg = 'Abram vzal svoj stan a odišiel bıva k dubom Mambreho, ktoré sú v Hebrone, a postavil tam oltár Pánovi.' where spis = 'Gn' and vers = 1 and k = 13 and v = 18
go

-- 533	Gn 14, 18-20
update biblia set lc_id = 533 where spis = 'Gn' and vers = 1 and k = 14 and v between 18 and 20
go

update biblia set nvg = 'Melchizedech, krá¾ Salema, priniesol chlieb a víno. Bol toti kòazom najvyššieho Boha. ' where spis = 'Gn' and vers = 1 and k = 14 and v = 18
update biblia set nvg = 'Poehnal Abrama slovami: "Nech Abrama poehná najvyšší Boh, ktorı stvoril nebo i zem. ' where spis = 'Gn' and vers = 1 and k = 14 and v = 19
update biblia set nvg = 'Nech je zvelebenı najvyšší Boh, ktorı ti vydal do rúk tvojich nepriate¾ov." // Abram mu potom dal desiatok zo všetkého.' where spis = 'Gn' and vers = 1 and k = 14 and v = 20
go

-- 534	Gn 15, 1-12. 17-18
-- 535	Gn 15, 1-6; 21, 1-3
-- 536	Gn 15, 5-12. 17-18
update biblia set lc_id = 534 where spis = 'Gn' and vers = 1 and k = 15 and v between 1 and 12
update biblia set lc_id = 534 where spis = 'Gn' and vers = 1 and k = 15 and v between 17 and 18
update biblia set lc_id = 535 where spis = 'Gn' and vers = 1 and k = 21 and v between 1 and 3
go

update biblia set nvg = 'Pán povedal Abramovi vo videní: "Neboj sa, Abram! Ja som tvoj ochranca a tvoja odmena bude nesmierna." ' where spis = 'Gn' and vers = 1 and k = 15 and v = 1
update biblia set nvg = 'Abram povedal: "Pane, Boe, èoe mi dáš? Odchádzam bezdetnı a dedièom môjho domu bude damaskı Eliezer." ' where spis = 'Gn' and vers = 1 and k = 15 and v = 2
update biblia set nvg = 'A Abram dodal: "Veï si mi nedal potomka a môj domáci sluha bude mojím dedièom."' where spis = 'Gn' and vers = 1 and k = 15 and v = 3
update biblia set nvg = 'Ale Pán mu povedal: "Ten nebude tvojím dedièom. Tvojím dedièom bude ten, èo vzíde z tvojho lona."' where spis = 'Gn' and vers = 1 and k = 15 and v = 4
update biblia set nvg = 'Vyviedol ho von a povedal mu: "Pozri na nebo a spoèítaj hviezdy, ak môeš." A uistil ho: "Také bude tvoje potomstvo." ' where spis = 'Gn' and vers = 1 and k = 15 and v = 5
update biblia set nvg = 'On uveril Pánovi a to sa mu poèítalo za spravodlivos.' where spis = 'Gn' and vers = 1 and k = 15 and v = 6
update biblia set nvg = 'Potom mu povedal: "Ja som Pán, ja som a vyviedol z Uru Chaldejcov, aby som ti dal do vlastníctva túto krajinu."' where spis = 'Gn' and vers = 1 and k = 15 and v = 7
update biblia set nvg = 'On sa opıtal: "Pane, Boe, pod¾a èoho spoznám, e ju budem vlastni?"' where spis = 'Gn' and vers = 1 and k = 15 and v = 8
update biblia set nvg = 'Pán odpovedal: "Prines mi trojroènú jalovicu, trojroènú kozu a trojroèného barana, hrdlièku a holubicu."' where spis = 'Gn' and vers = 1 and k = 15 and v = 9
update biblia set nvg = 'On vzal všetky tieto zvieratá, rozpolil ich a obe polovice poloil vzájomne oproti sebe; vtáky však nerozpolil. ' where spis = 'Gn' and vers = 1 and k = 15 and v = 10
update biblia set nvg = 'Na màtve telá zlietali dravé vtáky a Abram ich odháòal.' where spis = 'Gn' and vers = 1 and k = 15 and v = 11
update biblia set nvg = 'Keï zapadalo slnko, na Abrama do¾ahol tvrdı spánok a prenikla ho ve¾ká, príšerná hrôza.' where spis = 'Gn' and vers = 1 and k = 15 and v = 12
go
update biblia set nvg = 'Keï u slnko zapadlo a nastala hustá tma, zjavila sa dymiaca pec a ohnivá pochodeò, ktorá prechádzala pomedzi rozpolené zvieratá.' where spis = 'Gn' and vers = 1 and k = 15 and v = 17
update biblia set nvg = 'V ten deò Pán uzavrel s Abramom zmluvu slovami: "Tvojmu potomstvu dám túto krajinu od Egyptskej rieky a po ve¾kú rieku, Eufrat."' where spis = 'Gn' and vers = 1 and k = 15 and v = 18
go

update biblia set nvg = 'Pán navštívil Sáru, ako pris¾úbil, a splnil Sáre, èo povedal. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 1
update biblia set nvg = 'I poèala a porodila Abrahámovi syna v jeho starobe, v èase, ktorı mu predpovedal Boh. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 2
update biblia set nvg = 'A Abrahám dal svojmu synovi, ktorého mu porodila Sára, meno Izák.' where spis = 'Gn' and vers = 1 and k = 21 and v = 3
go

-- 537	Gn 16, 1-12. 15-16
-- 538	Gn 16, 6b-12. 15-16
update biblia set lc_id = 537 where spis = 'Gn' and vers = 1 and k = 16 and v between 1 and 12
update biblia set lc_id = 537 where spis = 'Gn' and vers = 1 and k = 16 and v between 15 and 16
go

update biblia set nvg = 'Abramova ena Sarai neporodila Abramovi diea. Mala však slúku Egypanku menom Agar. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 1
update biblia set nvg = 'I povedala svojmu manelovi: "Pozri, Pán ma uzavrel, nemôem porodi. Vojdi k mojej slúke. Azda aspoò z nej dostanem synov." On pristal na jej prosbu ' where spis = 'Gn' and vers = 1 and k = 16 and v = 2
update biblia set nvg = 'a ona po desiatich rokoch, ako zaèali bıva v krajine Kanaán, vzala svoju slúku Egypanku Agar a dala ju svojmu muovi za enu. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 3
update biblia set nvg = 'On k nej vošiel a keï spozorovala, e poèala, opovrlivo h¾adela na svoju paniu.' where spis = 'Gn' and vers = 1 and k = 16 and v = 4
update biblia set nvg = 'Sarai povedala Abramovi: "Ubliuješ mi. Ja som dala svoju slúku do tvojho lona a ona, keï vidí, e poèala, mnou opovrhuje. Nech Pán súdi medzi mnou a tebou." ' where spis = 'Gn' and vers = 1 and k = 16 and v = 5
update biblia set nvg = 'Abram jej odvetil: "Veï je tvoja slúka v tvojej moci. Urob s òou, ako sa ti páèi." A Sarai k nej bola tvrdá, a od nej ušla.' where spis = 'Gn' and vers = 1 and k = 16 and v = 6
update biblia set nvg = 'Keï ju našiel Pánov anjel na púšti pri prameni na ceste do Suru, ' where spis = 'Gn' and vers = 1 and k = 16 and v = 7
update biblia set nvg = 'povedal jej: "Agar, Saraina slúka, odkia¾ ideš a kam sa uberáš?" Ona odpovedala: "Utekám od svojej panej Sarai."' where spis = 'Gn' and vers = 1 and k = 16 and v = 8
update biblia set nvg = 'Pánov anjel jej povedal: "Vrá sa k svojej panej a buï jej poddaná." ' where spis = 'Gn' and vers = 1 and k = 16 and v = 9
update biblia set nvg = 'A Pánov anjel jej vravel ïalej: "Tak rozmnoím tvoje potomstvo, e ho pre mnostvo nebude mono spoèíta." ' where spis = 'Gn' and vers = 1 and k = 16 and v = 10
update biblia set nvg = 'A ešte jej Pánov anjel hovoril: "H¾a, poèala si a porodíš syna; nazveš ho menom Izmael, lebo Pán poèul o tvojom trápení. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 11
update biblia set nvg = 'Bude to èlovek ako divı osol, jeho ruka bude proti všetkım a ruky všetkıch budú proti nemu a svoje stany postaví popri svojich bratoch."' where spis = 'Gn' and vers = 1 and k = 16 and v = 12
update biblia set nvg = 'Agar porodila Abramovi syna a on dal svojmu synovi, ktorého porodila Agar, meno Izmael. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 15
update biblia set nvg = 'Osemdesiatšes rokov mal Abram, keï mu Agar porodila Izmaela.' where spis = 'Gn' and vers = 1 and k = 16 and v = 16
go

-- 539	Gn 17, 1. 4-5. 9-10. 15-22
-- 540	Gn 17, 3-9
update biblia set lc_id = 539 where spis = 'Gn' and vers = 1 and k = 17 and v = 1
update biblia set lc_id = 540 where spis = 'Gn' and vers = 1 and k = 17 and v between 3 and 9
update biblia set lc_id = 539 where spis = 'Gn' and vers = 1 and k = 17 and v = 10
update biblia set lc_id = 539 where spis = 'Gn' and vers = 1 and k = 17 and v between 15 and 22
go

update biblia set nvg = 'Keï mal Abram devädesiatdevä rokov, zjavil sa mu Pán a povedal mu: "Ja som Boh, všemohúci, kráèaj predo mnou a buï dokonalı. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 1
update biblia set nvg = 'Abram padol na tvár ' where spis = 'Gn' and vers = 1 and k = 17 and v = 3
update biblia set nvg = 'a Boh mu povedal: "H¾a, moja zmluva s tebou. Budeš otcom mnohıch národov ' where spis = 'Gn' and vers = 1 and k = 17 and v = 4
update biblia set nvg = 'a u sa nebudeš vola Abram; budeš sa vola Abrahám, lebo a urobím otcom mnohıch národov.' where spis = 'Gn' and vers = 1 and k = 17 and v = 5
update biblia set nvg = 'Dám sa ti rozrás prenáramne, urobím z teba národy, aj králi z teba vzídu.' where spis = 'Gn' and vers = 1 and k = 17 and v = 6
update biblia set nvg = 'A uzavriem zmluvu medzi mnou a tebou i medzi tvojím potomstvom po tebe vo všetkıch pokoleniach, zmluvu veènú, e budem Bohom tvojím i tvojho potomstva po tebe.' where spis = 'Gn' and vers = 1 and k = 17 and v = 7
update biblia set nvg = 'Tebe a tvojmu potomstvu po tebe dám krajinu, v ktorej si ako cudzinec; celú zem Kanaán do veèného vlastníctva a budem ich Bohom."' where spis = 'Gn' and vers = 1 and k = 17 and v = 8
update biblia set nvg = 'Potom Boh povedal Abrahámovi: "Ale aj ty zachováš moju zmluvu, aj tvoje potomstvo po tebe vo všetkıch pokoleniach."' where spis = 'Gn' and vers = 1 and k = 17 and v = 9
update biblia set nvg = 'A toto je moja zmluva medzi mnou a vami i tvojím potomstvom po tebe, ktorú budete zachováva: Obrezané bude všetko, èo je medzi vami rodu muského."' where spis = 'Gn' and vers = 1 and k = 17 and v = 10
go
update biblia set nvg = 'Potom Boh povedal Abrahámovi: "Svoju manelku Sarai u nebudeš vola Sarai, lebo bude ma meno Sára. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 15
update biblia set nvg = 'Ja ju poehnám a dám ti aj z nej syna. Poehnám ju a budú z nej pochádza národy; aj králi národov z nej budú pochádza."' where spis = 'Gn' and vers = 1 and k = 17 and v = 16
update biblia set nvg = 'Abrahám padol na tvár a smial sa; povedal si v srdci: "Vari sa môe storoènému narodi syn? A devädesiatroèná Sára porodí?" ' where spis = 'Gn' and vers = 1 and k = 17 and v = 17
update biblia set nvg = 'A povedal Bohu: "Keby aspoò Izmael il pred tvojou tvárou."' where spis = 'Gn' and vers = 1 and k = 17 and v = 18
update biblia set nvg = 'Ale Pán opakoval: "Tvoja ena Sára ti porodí syna a dáš mu meno Izák a ja s ním uzavriem zmluvu: veènú zmluvu s ním a s jeho potomstvom. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 19
update biblia set nvg = 'A vypoèul som a, aj èo sa tıka Izmaela: poehnám ho, dám mu plodnos a rozmnoím ho náramne. Dvanás knieat sa z neho narodí a urobím z neho ve¾kı národ. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 20
update biblia set nvg = 'Ale svoju zmluvu uzavriem s Izákom, ktorého ti porodí Sára o takomto èase na budúci rok." ' where spis = 'Gn' and vers = 1 and k = 17 and v = 21
update biblia set nvg = 'Keï sa s ním Boh prestal rozpráva, odišiel od Abraháma.' where spis = 'Gn' and vers = 1 and k = 17 and v = 22
go

-- SSV preklad nemá verš Gn 18, 33, len verš 32, preto to dávame spoloène do v. 32
-- 541	Gn 18, 1-10a
-- 542	Gn 18, 1-15
-- 543	Gn 18, 16-33
-- 544	Gn 18, 20-32
update biblia set lc_id = 542 where spis = 'Gn' and vers = 1 and k = 18 and v between 1 and 15
update biblia set lc_id = 543 where spis = 'Gn' and vers = 1 and k = 18 and v between 16 and 33
go

update biblia set nvg = 'Abrahámovi sa zjavil Pán pri duboch Mambreho, keï sedel za najväèšej horúèavy dòa pri vchode do svojho stanu. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 1
update biblia set nvg = 'Keï zdvihol oèi, zbadal neïaleko stá troch muov. Len èo ich zazrel, utekal im od vchodu do stanu v ústrety, poklonil sa a po zem ' where spis = 'Gn' and vers = 1 and k = 18 and v = 2
update biblia set nvg = 'a povedal: "Pane, ak som našiel priazeò v tvojich oèiach, neobíï svojho sluobníka. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 3
update biblia set nvg = 'Prinesú trochu vody, umyjete si nohy a odpoèiniete si pod stromom. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 4
update biblia set nvg = 'Donesiem kúsok chleba a posilníte sa; potom môete ís ïalej. Veï preto ste zaboèili k svojmu sluobníkovi." Oni odpovedali: "Urob, ako vravíš!"' where spis = 'Gn' and vers = 1 and k = 18 and v = 5
update biblia set nvg = 'Abrahám sa poponáh¾al do stanu k Sáre a povedal: "Rıchlo zamies tri miery múky a napeè podplamenníky!"' where spis = 'Gn' and vers = 1 and k = 18 and v = 6
update biblia set nvg = 'Sám beal k stádu, vybral pekné mladé te¾a, dal ho sluhovi a ten sa ponáh¾al pripravi ho. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 7
update biblia set nvg = 'Potom vzal maslo, mlieko a pripravené te¾a a predloil im to. Sám stál pri nich pod stromom; a oni jedli.' where spis = 'Gn' and vers = 1 and k = 18 and v = 8
update biblia set nvg = 'Potom sa ho pıtali: "Kde je tvoja ena Sára?" On odpovedal: "Tu, v stane."' where spis = 'Gn' and vers = 1 and k = 18 and v = 9
update biblia set nvg = 'A Pán mu povedal: "O rok o takomto èase sa vrátim k tebe a tvoja manelka Sára bude ma syna." Keï to Sára poèula, smiala sa pri vchode do stanu, ktorı bol za ním. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 10
update biblia set nvg = 'Veï obaja boli starci, vo vysokom veku, a Sáre u dávno prestalo, èo mávajú eny. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 11
update biblia set nvg = 'Preto sa potajomky zasmiala a myslela si: "Teraz, keï som u stará, mám myslie na rozkoš? Aj môj pán je u starec."' where spis = 'Gn' and vers = 1 and k = 18 and v = 12
update biblia set nvg = 'Pán povedal Abrahámovi: "Preèo sa Sára smeje a myslí si: ‚Èi môem naozaj porodi, takáto starena?‘ ' where spis = 'Gn' and vers = 1 and k = 18 and v = 13
update biblia set nvg = 'Vari je Pánovi nieèo nemoné? O rok o takomto èase sa vrátim k tebe a Sára bude ma syna."' where spis = 'Gn' and vers = 1 and k = 18 and v = 14
update biblia set nvg = 'Sára zapierala: "Nesmiala som sa," lebo sa bála. Ale Pán povedal: "Nie. Smiala si sa."' where spis = 'Gn' and vers = 1 and k = 18 and v = 15
update biblia set nvg = 'Muovia sa z údolia Mambreho pobrali a zamierili k Sodome. Abrahám išiel s nimi odprevadi ich.' where spis = 'Gn' and vers = 1 and k = 18 and v = 16
update biblia set nvg = 'A Pán povedal: "Môem pred Abrahámom taji, èo chcem urobi?! ' where spis = 'Gn' and vers = 1 and k = 18 and v = 17
update biblia set nvg = 'Veï z neho má by ve¾kı a mocnı národ a v òom majú by poehnané všetky národy zeme. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 18
update biblia set nvg = 'Lebo jeho som si vyvolil, aby svojim synom a svojmu domu po sebe prikázal zachováva Pánovu cestu a kona pod¾a spravodlivosti a práva, aby Pán mohol splni na Abrahámovi všetko, èo mu s¾úbil."' where spis = 'Gn' and vers = 1 and k = 18 and v = 19
update biblia set nvg = 'Preto Pán povedal: "aloba na Sodomu a Gomoru je ve¾ká a ich hriech je ve¾mi akı. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 20
update biblia set nvg = 'Zostúpim a pozriem sa, èi naozaj robia tak, ako znie aloba, èo došla ku mne, a èi nie. Chcem to vedie."' where spis = 'Gn' and vers = 1 and k = 18 and v = 21
update biblia set nvg = 'Mui sa odtia¾ obrátili a išli do Sodomy, kım Abrahám stále ešte stál pred Pánom.' where spis = 'Gn' and vers = 1 and k = 18 and v = 22
update biblia set nvg = 'Pristúpil blišie a povedal: "Chceš naozaj zahubi spravodlivého s bezbonım? ' where spis = 'Gn' and vers = 1 and k = 18 and v = 23
update biblia set nvg = 'A keby bolo v meste pädesiat spravodlivıch, zahubil by si ich a neodpustil by si mestu kvôli pädesiatim spravodlivım, èo sú v òom?' where spis = 'Gn' and vers = 1 and k = 18 and v = 24
update biblia set nvg = 'Nech je ïaleko od teba urobi nieèo také: spravodlivého usmrti s bezbonım. Spravodlivı by bol na tom rovnako ako bezbonı. To nech je ïaleko od teba. Vari ten, èo súdi celú zem, nebude kona spravodlivo?"' where spis = 'Gn' and vers = 1 and k = 18 and v = 25
update biblia set nvg = 'Pán mu povedal: "Ak v meste Sodome nájdem pädesiat spravodlivıch, odpustím kvôli nim celému mestu."' where spis = 'Gn' and vers = 1 and k = 18 and v = 26
update biblia set nvg = 'Abrahám povedal: "Opováil som sa rozpráva so svojím Pánom, hoci som len prach a popol. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 27
update biblia set nvg = 'Èo ak bude spravodlivıch o pä menej ako pädesiat? Znièíš kvôli piatim celé mesto?" // "Neznièím," odpovedal, "ak ich tam nájdem štyridsapä."' where spis = 'Gn' and vers = 1 and k = 18 and v = 28
update biblia set nvg = 'Abrahám mu znova povedal: "A èo ak sa ich tam nájde len štyridsa?" Odpovedal: "Kvôli štyridsiatim ich neznièím."' where spis = 'Gn' and vers = 1 and k = 18 and v = 29
update biblia set nvg = '"Nehnevaj sa, prosím, Pán môj," pokraèoval ïalej, "e ešte hovorím: A ak sa ich tam nájde len tridsa?" Odpovedal: "Neurobím to, ak ich tam nájdem tridsa."' where spis = 'Gn' and vers = 1 and k = 18 and v = 30
update biblia set nvg = 'Abrahám povedal: "Opováil som sa rozpráva so svojím Pánom: Èo ak sa ich tam nájde dvadsa?" Pán odpovedal: "Nezahubím ich kvôli dvadsiatim."' where spis = 'Gn' and vers = 1 and k = 18 and v = 31
update biblia set nvg = '"Prosím, nech sa nehnevá môj Pán," pokraèoval, "e ešte raz prehovorím: A èo ak sa ich tam nájde len desa?" Odpovedal: "Kvôli desiatim ich nezahubím." // (NVg: v. 33) Keï sa Pán prestal rozpráva s Abrahámom, odišiel a Abrahám sa vrátil na svoje miesto.' where spis = 'Gn' and vers = 1 and k = 18 and v = 32
go

-- 545	Gn 19, 15-29
update biblia set lc_id = 545 where spis = 'Gn' and vers = 1 and k = 19 and v between 15 and 29
go

update biblia set nvg = '[...] Anjeli naliehali na Lota: "Vstaò, vezmi svoju enu a obe dcéry, ktoré tu máš, aby si nezahynul v zloèinnom meste." ' where spis = 'Gn' and vers = 1 and k = 19 and v = 15
update biblia set nvg = 'A keï váhal, chytili ho mui za ruku i jeho enu a obe dcéry, lebo Pán ho chcel zachráni, vyviedli ho von a nechali ho za mestom.' where spis = 'Gn' and vers = 1 and k = 19 and v = 16
update biblia set nvg = 'Tam anjel povedal: "Zachráò sa, ide ti o ivot. Neobzeraj sa a nezastavuj sa nikde v tomto okolí. H¾adaj útoèište v horách, aby si nezahynul."' where spis = 'Gn' and vers = 1 and k = 19 and v = 17
update biblia set nvg = 'Lot im povedal: "Prosím, nie, Pane. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 18
update biblia set nvg = 'Tvoj sluha našiel milos pred tebou a ve¾ké je tvoje milosrdenstvo, ktoré si mi preukázal, keï si mi zachránil ivot. Ale do hôr ujs nevládzem, zachytí ma pohroma a umriem. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 19
update biblia set nvg = 'Pozri, tu neïaleko je malé mesto, tam môem ujs, v òom sa zachránim. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 20
update biblia set nvg = 'Èi nie je malé? A ja ostanem naive." // On mu povedal: "Nu dobre, aj túto tvoju prosbu vyslyším a mesto, za ktoré sa prihováraš, neznièím. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 21
update biblia set nvg = 'Utekaj a skry sa tam, lebo nemôem niè robi, kım ta nedôjdeš." Preto sa to mesto volá Segor.' where spis = 'Gn' and vers = 1 and k = 19 and v = 22
update biblia set nvg = 'Nad krajinu vyšlo slnko, keï Lot došiel do Segoru. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 23
update biblia set nvg = 'Vtedy Pán spustil na Sodomu a Gomoru síru a oheò z neba od Pána ' where spis = 'Gn' and vers = 1 and k = 19 and v = 24
update biblia set nvg = 'a znièil obe mestá i celı okolitı kraj; všetkıch obyvate¾ov miest a všetky po¾né rastliny. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 25
update biblia set nvg = 'Jeho ena sa obzrela za seba a premenila sa na so¾nı ståp.' where spis = 'Gn' and vers = 1 and k = 19 and v = 26
update biblia set nvg = 'Keï Abrahám ráno vstal, išiel na miesto, kde predtım stál s Pánom, ' where spis = 'Gn' and vers = 1 and k = 19 and v = 27
update biblia set nvg = 'pozrel sa na Sodomu a Gomoru a na celı kraj okolo a videl vystupova zo zeme eravı popol a dym ako z pece. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 28
update biblia set nvg = 'Keï Boh nièil mestá a okolie tohoto kraja, spomenul si na Abraháma a Lota zachránil zo skazy miest, v ktorıch bıval.' where spis = 'Gn' and vers = 1 and k = 19 and v = 29
go

-- 550	Gn 21, 5. 8-20
update biblia set lc_id = 550 where spis = 'Gn' and vers = 1 and k = 21 and v = 1
update biblia set lc_id = 550 where spis = 'Gn' and vers = 1 and k = 21 and v between 8 and 20
go

update biblia set nvg = 'Keï mal Abrahám sto rokov, narodil sa mu syn Izák.' where spis = 'Gn' and vers = 1 and k = 21 and v = 1
update biblia set nvg = 'Chlapec vyrástol a odstavili ho. V deò odstavenia urobil Abrahám ve¾kú hostinu.' where spis = 'Gn' and vers = 1 and k = 21 and v = 8
update biblia set nvg = 'A keï Sára videla, ako syn Egypanky Agar šantí s jej synom Izákom, ' where spis = 'Gn' and vers = 1 and k = 21 and v = 9
update biblia set nvg = 'povedala Abrahámovi: "Vyeò slúku i jej syna, lebo syn slúky nesmie dedi s mojím synom Izákom!" ' where spis = 'Gn' and vers = 1 and k = 21 and v = 10
update biblia set nvg = 'Abraháma sa to ve¾mi dotklo, veï to bol jeho syn.' where spis = 'Gn' and vers = 1 and k = 21 and v = 11
update biblia set nvg = 'Ale Boh mu povedal: "Netráp sa kvôli chlapcovi a svojej slúke. Poèúvni všetko, èo ti povedala Sára, lebo pod¾a Izáka sa bude vola tvoje potomstvo. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 12
update biblia set nvg = 'Ale aj zo syna slúky urobím ve¾kı národ, pretoe je tvojím potomkom."' where spis = 'Gn' and vers = 1 and k = 21 and v = 13
update biblia set nvg = 'Abrahám teda skoro ráno vstal, vzal chlieb a mech s vodou, naloil to Agar na chrbát, dal jej chlapca a prepustil ju. Ona odišla a blúdila po púšti Bersabe. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 14
update biblia set nvg = 'A keï sa minula voda z mecha, poloila chlapca pod ker, ' where spis = 'Gn' and vers = 1 and k = 21 and v = 15
update biblia set nvg = 'poodišla a sadla si opodia¾, asi akoby šípom dostrelil, lebo si vravela: "Nemôem h¾adie, ako diea zomiera." Tak sedela obïaleè a nahlas plakala.' where spis = 'Gn' and vers = 1 and k = 21 and v = 16
update biblia set nvg = 'Ale Boh poèul hlas chlapca a boí anjel zavolal z neba na Agar: "Èo ti je, Agar? Neboj sa, Boh poèul hlas chlapca z miesta, kde je. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 17
update biblia set nvg = 'Vstaò, vezmi chlapca a staraj sa oò, lebo z neho urobím ve¾kı národ."' where spis = 'Gn' and vers = 1 and k = 21 and v = 18
update biblia set nvg = 'Boh jej otvoril oèi a zbadala prameò vody. Išla, naplnila si mech a napojila chlapca.' where spis = 'Gn' and vers = 1 and k = 21 and v = 19
update biblia set nvg = 'Boh bol s ním; a keï vyrástol, bıval na púšti a stal sa z neho mladı lukostrelec.' where spis = 'Gn' and vers = 1 and k = 21 and v = 20
go

-- 551	Gn 22, 1-18
-- 552	Gn 22, 1-19
-- 553	Gn 22, 1-2. 9a. 10-13. 15-18
-- 554	Gn 22, 1-2. 9a. 10-13. 15-18
update biblia set lc_id = 552 where spis = 'Gn' and vers = 1 and k = 22 and v between 1 and 19
update biblia set lh_id = 'VTROJ_cCIT2_NE' where spis = 'Gn' and vers = 1 and k = 22 and v between 1 and 18
go

update biblia set nvg = 'Boh skúšal Abraháma a povedal mu: „Abrahám!“ On odpovedal: „Tu som.“' where spis = 'Gn' and vers = 1 and k = 22 and v = 1
update biblia set nvg = 'Boh hovoril: „Vezmi svojho jediného syna Izáka, ktorého miluješ, choï do krajiny Moria a obetuj ho tam ako zápalnú obetu na vrchu, ktorı ti ukáem.“' where spis = 'Gn' and vers = 1 and k = 22 and v = 2
update biblia set nvg = 'Abrahám vstal ešte za noci, osedlal osla, vzal so sebou dvoch sluhov a svojho syna Izáka, naštiepal dreva na zápalnú obetu a vybral sa na miesto, ktoré mu Boh oznaèil. ' where spis = 'Gn' and vers = 1 and k = 22 and v = 3
update biblia set nvg = 'Keï na tretí deò Abrahám zdvihol oèi, zïaleka uzrel to miesto ' where spis = 'Gn' and vers = 1 and k = 22 and v = 4
update biblia set nvg = 'a povedal svojim sluhom: „Èakajte tu s_oslom. Ja a chlapec pôjdeme a ta, pokloníme sa a vrátime sa k_vám.“' where spis = 'Gn' and vers = 1 and k = 22 and v = 5
update biblia set nvg = 'Potom Abrahám vzal drevo na zápalnú obetu a naloil ho na svojho syna Izáka. Sám niesol v_rukách oheò a nô. Ako išli sami dvaja, ' where spis = 'Gn' and vers = 1 and k = 22 and v = 6
update biblia set nvg = 'vravel Izák svojmu otcovi Abrahámovi: „Otèe!“ On mu odpovedal: „Èo chceš, syn môj?“ „Pozri,“ hovorí Izák, „oheò a drevo je tu, a baránok na zápalnú obetu je kde?“ ' where spis = 'Gn' and vers = 1 and k = 22 and v = 7
update biblia set nvg = 'Abrahám odvetil: „Boh si zaobstará baránka na obetu, syn môj.“ A vedno šli ïalej.' where spis = 'Gn' and vers = 1 and k = 22 and v = 8
update biblia set nvg = 'Keï došli na miesto, ktoré mu ukázal Boh, Abrahám postavil oltár, poukladal naò drevo, zviazal svojho syna Izáka a poloil ho na oltár, na drevo. ' where spis = 'Gn' and vers = 1 and k = 22 and v = 9
update biblia set nvg = 'Potom Abrahám vystrel ruku, vzal nô a chcel obetova svojho syna.' where spis = 'Gn' and vers = 1 and k = 22 and v = 10
update biblia set nvg = 'Ale vtom naò zavolal anjel Pána z_neba: „Abrahám, Abrahám!“ // On odpovedal: „Tu som.“' where spis = 'Gn' and vers = 1 and k = 22 and v = 11
update biblia set nvg = 'Anjel mu povedal: „Nevzahuj ruku na chlapca a neublí mu! Teraz viem, e sa bojíš Boha, veï si mi neodoprel svojho jediného syna.“' where spis = 'Gn' and vers = 1 and k = 22 and v = 12
update biblia set nvg = 'Abrahám zdvihol oèi a uzrel barana zachyteného rohami v_kroví. Vzal ho a obetoval namiesto svojho syna ako zápalnú obetu.' where spis = 'Gn' and vers = 1 and k = 22 and v = 13
update biblia set nvg = 'A toto miesto nazval „Pán sa stará“; a tak sa a podnes hovorí: „Na vrchu Pán sa stará“.' where spis = 'Gn' and vers = 1 and k = 22 and v = 14
update biblia set nvg = 'Anjel Pána znova zavolal z_neba na Abraháma: ' where spis = 'Gn' and vers = 1 and k = 22 and v = 15
update biblia set nvg = '„Na seba samého prisahám – takı je vırok Pána –: Pretoe si toto urobil a neodoprel si mi svojho jediného syna, ' where spis = 'Gn' and vers = 1 and k = 22 and v = 16
update biblia set nvg = 'poehnám a a rozmnoím tvoje potomstvo ako hviezdy na nebi a ako piesok na brehu mora a tvoje potomstvo sa zmocní brán svojich nepriate¾ov. ' where spis = 'Gn' and vers = 1 and k = 22 and v = 17
update biblia set nvg = 'A pretoe si poslúchol môj hlas, v_tvojom potomstve budú poehnané všetky národy zeme.“' where spis = 'Gn' and vers = 1 and k = 22 and v = 18
update biblia set nvg = 'Potom sa Abrahám vrátil k svojim sluhom a všetci spolu sa pobrali do Bersaby. A Abrahám ostal bıva v Bersabe.' where spis = 'Gn' and vers = 1 and k = 22 and v = 19
go

-- 555	Gn 23, 1-4. 19; 24, 1-8. 62-67
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 23 and v between 1 and 4
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 23 and v = 19
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 24 and v between 1 and 8
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 24 and v between 62 and 67
go

update biblia set nvg = 'Sára sa doila stodvadsasedem rokov ' where spis = 'Gn' and vers = 1 and k = 23 and v = 1
update biblia set nvg = 'a zomrela v Kariatarbé, èo je Hebron, v krajine Kanaán. Abrahám išiel smúti za òou a oplakáva ju.' where spis = 'Gn' and vers = 1 and k = 23 and v = 2
update biblia set nvg = 'Potom prerušil pohrebnı obrad a povedal Hetejcom: ' where spis = 'Gn' and vers = 1 and k = 23 and v = 3
update biblia set nvg = '"Som u vás len cudzinec a hos. Dajte mi u vás miesto na dediènú hrobku, kde by som mohol pochova svoju màtvu."' where spis = 'Gn' and vers = 1 and k = 23 and v = 4
go
update biblia set nvg = 'Potom Abrahám pochoval svoju enu Sáru v jaskyni na pozemku Makpela oproti Mambre, èo je Hebron, v krajine Kanaán. ' where spis = 'Gn' and vers = 1 and k = 23 and v = 19
go
update biblia set nvg = 'Abrahám bol u starec vysokého veku a Pán ho vo všetkom poehnával.' where spis = 'Gn' and vers = 1 and k = 24 and v = 1
update biblia set nvg = 'Tu Abrahám povedal najstaršiemu sluhovi svojho domu, ktorı spravoval celı jeho majetok: "Polo svoju ruku pod moje bedrá ' where spis = 'Gn' and vers = 1 and k = 24 and v = 2
update biblia set nvg = 'a zaprisahám a na Pána, Boha neba i zeme, e môjmu synovi nevezmeš enu z dcér Kanaáncov, medzi ktorımi bıvam, ' where spis = 'Gn' and vers = 1 and k = 24 and v = 3
update biblia set nvg = 'ale pôjdeš do mojej vlasti, k mojim príbuznım a tam vyberieš enu pre môjho syna Izáka."' where spis = 'Gn' and vers = 1 and k = 24 and v = 4
update biblia set nvg = 'Sluha odvetil: "A ak ena nebude chcie ís so mnou do tejto krajiny, mám tvojho syna zavies naspä do krajiny, z ktorej si vyšiel?"' where spis = 'Gn' and vers = 1 and k = 24 and v = 5
update biblia set nvg = 'Abrahám mu povedal: "Neopová sa; nikdy ta nesmieš zavies môjho syna! ' where spis = 'Gn' and vers = 1 and k = 24 and v = 6
update biblia set nvg = 'Pán, Boh nebies, ktorı ma vyviedol z domu môjho otca a z môjho rodného kraja, ktorı so mnou hovoril a prisahal mi: ‚Túto zem dám tvojmu potomstvu,‘ pošle pred tebou svojho anjela, aby si tam vybral enu môjmu synovi. ' where spis = 'Gn' and vers = 1 and k = 24 and v = 7
update biblia set nvg = 'A keby ena nechcela ís s tebou, táto prísaha a neviae. Len môjho syna ta nevoï!"' where spis = 'Gn' and vers = 1 and k = 24 and v = 8
go
update biblia set nvg = 'Izák prišiel od studne Lachajroi a bıval v Negebe. ' where spis = 'Gn' and vers = 1 and k = 24 and v = 62
update biblia set nvg = 'Na sklonku dòa vyšiel Izák do po¾a iali. Keï zdvihol oèi, videl prichádza avy.' where spis = 'Gn' and vers = 1 and k = 24 and v = 63
update biblia set nvg = 'Aj Rebeka zdvihla oèi a zbadala Izáka. Zosadla z avy ' where spis = 'Gn' and vers = 1 and k = 24 and v = 64
update biblia set nvg = 'a opıtala sa sluhu: "Kto je tamten èlovek, èo nám ide oproti po poli?" On jej odpovedal: "To je môj pán." Rıchlo vzala závoj a zahalila sa.' where spis = 'Gn' and vers = 1 and k = 24 and v = 65
update biblia set nvg = 'Sluha potom porozprával Izákovi všetko, èo vykonal, ' where spis = 'Gn' and vers = 1 and k = 24 and v = 66
update biblia set nvg = 'a Izák ju voviedol do stanu svojej matky Sáry. Vzal si Rebeku za enu a tak ju miloval, e sa uspokojil nad smrou svojej matky.' where spis = 'Gn' and vers = 1 and k = 24 and v = 67
go

-- 556	Gn 27, 1-5. 15-29
update biblia set lc_id = 556 where spis = 'Gn' and vers = 1 and k = 27 and v between 1 and 5
update biblia set lc_id = 556 where spis = 'Gn' and vers = 1 and k = 27 and v between 15 and 29
go

update biblia set nvg = 'Izák zostarel a oèi mu tak zoslabli, e nevidel. Zavolal si svojho staršieho syna Ezaua a povedal mu: "Syn môj." On odvetil: "Tu som."' where spis = 'Gn' and vers = 1 and k = 27 and v = 1
update biblia set nvg = 'Otec mu povedal: "Vidíš, u som starı a neviem, kedy zomriem. ' where spis = 'Gn' and vers = 1 and k = 27 and v = 2
update biblia set nvg = 'Vezmi si zbraò, tulec a luk, a vyjdi na pole. Keï nieèo ulovíš, ' where spis = 'Gn' and vers = 1 and k = 27 and v = 3
update biblia set nvg = 'priprav mi z toho pokrm, veï vieš, akı mám rád, a prines mi ho. Zajem si a poehnám a prv, ako zomriem."' where spis = 'Gn' and vers = 1 and k = 27 and v = 4
update biblia set nvg = 'Ale Rebeka poèula, èo Izák hovoril svojmu synovi Ezauovi. Ezau odišiel na pole, aby nieèo ulovil a priniesol, ' where spis = 'Gn' and vers = 1 and k = 27 and v = 5
go
update biblia set nvg = 'a Rebeka obliekla Jakuba do najlepších Ezauovıch šiat, èo mala v dome pri ruke, ' where spis = 'Gn' and vers = 1 and k = 27 and v = 15
update biblia set nvg = 'a koz¾acími kokami mu ovinula ruky a holı krk. ' where spis = 'Gn' and vers = 1 and k = 27 and v = 16
update biblia set nvg = 'Potom dala svojmu synovi Jakubovi do rúk chutné jedlo a chlieb, èo pripravila.' where spis = 'Gn' and vers = 1 and k = 27 and v = 17
update biblia set nvg = 'On išiel k otcovi a povedal: "Otèe môj." // Ten odvetil: "Poèúvam. Kto si, syn môj?"' where spis = 'Gn' and vers = 1 and k = 27 and v = 18
update biblia set nvg = 'A Jakub povedal svojmu otcovi: "Ja som Ezau, tvoj prvorodenı. Urobil som, ako si mi rozkázal. Poï, sadni si, jedz, èo som ulovil, a poehnaj ma."' where spis = 'Gn' and vers = 1 and k = 27 and v = 19
update biblia set nvg = 'Ale Izák sa opıtal svojho syna: "Ako si mohol tak rıchlo nieèo nájs, syn môj?" On odvetil: "Pán, tvoj Boh, chcel, aby som na to natrafil."' where spis = 'Gn' and vers = 1 and k = 27 and v = 20
update biblia set nvg = 'Izák povedal Jakubovi: "Pristúp blišie, nech sa a dotknem, syn môj, a zistím, èi si ty môj syn Ezau alebo nie." ' where spis = 'Gn' and vers = 1 and k = 27 and v = 21
update biblia set nvg = 'On pristúpil k otcovi a keï ho Izák ohmatal, povedal: "Hlas, hlas je síce Jakubov, ale ruky, ruky sú Ezauove."' where spis = 'Gn' and vers = 1 and k = 27 and v = 22
update biblia set nvg = 'Nepoznal ho, lebo mal ruky chlpaté ako jeho starší syn. Preto ho poehnal. ' where spis = 'Gn' and vers = 1 and k = 27 and v = 23
update biblia set nvg = 'A znova sa ho spıtal: "Naozaj si to ty, môj syn Ezau?" on odpovedal: "Áno, ja som to."' where spis = 'Gn' and vers = 1 and k = 27 and v = 24
update biblia set nvg = 'Izák povedal: "Prines mi to. Budem jes z tvojho úlovku, syn môj, a poehnám a." Podal mu to a on jedol. A podal mu aj víno. Jeho otec Izák si upil ' where spis = 'Gn' and vers = 1 and k = 27 and v = 25
update biblia set nvg = 'a povedal mu: "Poï ku mne, syn môj, a pobozkaj ma!"' where spis = 'Gn' and vers = 1 and k = 27 and v = 26
update biblia set nvg = 'Podišiel k nemu a pobozkal ho. Izák zacítil vôòu jeho šiat a ehnal ho, hovoriac: "H¾a, vôòa môjho syna je ako vôòa úrodného po¾a, ktoré poehnal Pán.' where spis = 'Gn' and vers = 1 and k = 27 and v = 27
update biblia set nvg = 'Nech ti Boh dá nebeskú rosu, írnos zeme a hojnos zrna i muštu.' where spis = 'Gn' and vers = 1 and k = 27 and v = 28
update biblia set nvg = 'Nech ti slúia ¾udia a nech sa sklonia pred tebou národy. Buï pánom nad svojimi bratmi a nech sa pred tebou skláòajú synovia tvojej matky. Nech je prekliaty, kto a bude preklína, a poehnanı, kto a bude ehna."' where spis = 'Gn' and vers = 1 and k = 27 and v = 29
go

-- 557	Gn 28, 10-22a
update biblia set lc_id = 557 where spis = 'Gn' and vers = 1 and k = 28 and v between 10 and 22
go

update biblia set nvg = 'Jakub odišiel z Bersaby a putoval do Charranu. ' where spis = 'Gn' and vers = 1 and k = 28 and v = 10
update biblia set nvg = 'Keï došiel na isté miesto a rozhodol sa tam po západe slnka prenocova, vzal jeden z kameòov, èo tam leali, poloil si ho pod hlavu a zaspal na tom mieste.' where spis = 'Gn' and vers = 1 and k = 28 and v = 11
update biblia set nvg = 'Vo sne videl rebrík postavenı na zemi, ktorého vrchol sa dotıkal neba, videl Boích anjelov, ako po òom vystupujú a zostupujú, ' where spis = 'Gn' and vers = 1 and k = 28 and v = 12
update biblia set nvg = 'a Pána, ako sa opiera o rebrík a hovorí mu: "Ja som Pán, Boh tvojho otca Abraháma a Boh Izáka. Zem, na ktorej spíš, dám tebe a tvojmu potomstvu. ' where spis = 'Gn' and vers = 1 and k = 28 and v = 13
update biblia set nvg = 'Tvojho potomstva bude ako prachu na zemi; rozšíriš sa na západ a na vıchod, na sever a na juh; v tebe a v tvojom potomstve budú poehnané všetky pokolenia zeme.' where spis = 'Gn' and vers = 1 and k = 28 and v = 14
update biblia set nvg = 'Ja som s tebou a budem a chráni všade, kam pôjdeš, a privediem a spä do tejto krajiny; neopustím a, kım nesplním, èo som ti s¾úbil."' where spis = 'Gn' and vers = 1 and k = 28 and v = 15
update biblia set nvg = 'Keï sa Jakub prebudil zo sna, povedal: "Skutoène, Pán je na tomto mieste a ja som o tom nevedel." ' where spis = 'Gn' and vers = 1 and k = 28 and v = 16
update biblia set nvg = 'A s chvením hovoril: "Aké hrozné je toto miesto! Tu je naozaj dom Boí a brána do neba." ' where spis = 'Gn' and vers = 1 and k = 28 and v = 17
update biblia set nvg = 'Keï Jakub ráno vstal, vzal kameò, èo mal poloenı pod hlavou, postavil ho ako pamätnı ståp a vylial naò olej. ' where spis = 'Gn' and vers = 1 and k = 28 and v = 18
update biblia set nvg = 'A toto miesto nazval Betel. Predtım sa mesto volalo Luza.' where spis = 'Gn' and vers = 1 and k = 28 and v = 19
update biblia set nvg = 'A Jakub urobil s¾ub: "Ak bude Boh so mnou, ak ma bude chráni na ceste, po ktorej idem, ak mi dá chlieb na jedenie a šaty na zaodiatie, ' where spis = 'Gn' and vers = 1 and k = 28 and v = 20
update biblia set nvg = 'keï sa šastne vrátim do domu svojho otca, Pán bude mojím Bohom ' where spis = 'Gn' and vers = 1 and k = 28 and v = 21
update biblia set nvg = 'a tento kameò, ktorı som postavil ako pomník, bude Boím domom. [...]"' where spis = 'Gn' and vers = 1 and k = 28 and v = 22
go

-- 563	Gn 32, 22-32
-- NVg èísluje 22-32; Vg/SSV 23-33
update biblia set lc_id = 563 where spis = 'Gn' and vers = 1 and k = 32 and v between /* 22 and 32 */ 23 and 33
go

update biblia set nvg = '(NVg 22)Jakub vstal za noci, vzal so sebou svoje dve eny, obe slúky i jedenás svojich synov a prešiel cez brod Jabok. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 23
update biblia set nvg = '(NVg 23)Vzal ich a previedol ich i všetko, èo mu patrilo, cez potok ' where spis = 'Gn' and vers = 1 and k = 32 and v = 24
update biblia set nvg = '(NVg 24)a ostal sám. Tu s ním a do rána zápasil nejakı mu. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 25
update biblia set nvg = '(NVg 25)Keï onen videl, e ho nemôe zdola, dotkol sa mu bedrového kåbu a Jakubovi sa bedrovı kåb pri zápase s ním vykåboval. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 26
update biblia set nvg = '(NVg 26)Neznámy povedal: "Pus ma, lebo u vychodí zora." On odvetil: "Nepustím a, kım ma nepoehnáš."' where spis = 'Gn' and vers = 1 and k = 32 and v = 27
update biblia set nvg = '(NVg 27)Ten mu povedal: "Ako sa voláš?" On odpovedal: "Jakub." ' where spis = 'Gn' and vers = 1 and k = 32 and v = 28
update biblia set nvg = '(NVg 28)A tamten povedal: "Nebudeš sa u vola Jakub, ale Izrael, lebo si zápasil s Bohom i s ¾uïmi a zvíazil si!"' where spis = 'Gn' and vers = 1 and k = 32 and v = 29
update biblia set nvg = '(NVg 29)Jakub sa ho pıtal: "Povedz mi svoje meno." Onen mu odpovedal: "Preèo chceš vedie moje meno?" A poehnal ho tam.' where spis = 'Gn' and vers = 1 and k = 32 and v = 30
update biblia set nvg = '(NVg 30)Jakub nazval to miesto Fanuel, lebo si povedal: "Videl som Boha z tváre do tváre a ostal som naive."' where spis = 'Gn' and vers = 1 and k = 32 and v = 31
update biblia set nvg = '(NVg 31)Keï prešiel Fanuel, vyšlo slnko a on kríval pre svoje bedro. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 32
update biblia set nvg = '(NVg 32)Preto Izraeliti a dodnes nejedia š¾achy bedrového kåbu, lebo onen sa dotkol š¾achy Jakubovho bedrového kåbu.' where spis = 'Gn' and vers = 1 and k = 32 and v = 33
go

-- 564	Gn 37, 3-4. 12-13a. 17b-28
update biblia set lc_id = 564 where spis = 'Gn' and vers = 1 and k = 37 and v between 3 and 4
update biblia set lc_id = 564 where spis = 'Gn' and vers = 1 and k = 37 and v between 12 and 13
update biblia set lc_id = 564 where spis = 'Gn' and vers = 1 and k = 37 and v between 17 and 28
go

update biblia set nvg = 'Izrael miloval Jozefa viac ako všetkıch svojich synov, lebo sa mu narodil v starobe, a dal mu urobi dlhú tuniku. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 3
update biblia set nvg = 'Keï jeho bratia videli, e ho má otec radšej ako všetkıch ostatnıch synov, zaèali ho nenávidie a nevedeli sa s ním prívetivo rozpráva.' where spis = 'Gn' and vers = 1 and k = 37 and v = 4
update biblia set nvg = 'Raz jeho bratia pásli ovce svojho otca pri Sicheme. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 12
update biblia set nvg = 'A Izrael povedal Jozefovi: "Tvoji bratia pasú ovce pri Sicheme, poï, pošlem a za nimi." [...]' where spis = 'Gn' and vers = 1 and k = 37 and v = 13
update biblia set nvg = '[...] A Jozef išiel za svojimi bratmi a našiel ich v Dotaine.' where spis = 'Gn' and vers = 1 and k = 37 and v = 17
update biblia set nvg = 'Oni ho zïaleka zbadali a prv ne k nim prišiel, sa dohodli, e ho zabijú. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 18
update biblia set nvg = 'Medzi sebou hovorili: "H¾a, snár prichádza; ' where spis = 'Gn' and vers = 1 and k = 37 and v = 19
update biblia set nvg = 'poïte, zabijeme ho a hodíme do niektorej cisterny. A povieme, e ho zorala divá zver. Potom sa ukáe, èo mu pomôu jeho sny."' where spis = 'Gn' and vers = 1 and k = 37 and v = 20
update biblia set nvg = 'Keï to poèul Ruben, usiloval sa vyslobodi ho z ich rúk a vravel: "Neberme mu ivot." ' where spis = 'Gn' and vers = 1 and k = 37 and v = 21
update biblia set nvg = 'A ïalej im hovoril: "Neprelievajte krv. Hoïte ho do cisterny tu na pustatine a nepoškvròujte si ruky." To povedal preto, e ho chcel vyslobodi z ich rúk a vráti jeho otcovi.' where spis = 'Gn' and vers = 1 and k = 37 and v = 22
update biblia set nvg = 'A len èo Jozef došiel k svojim bratom, zobliekli mu jeho dlhú tuniku ' where spis = 'Gn' and vers = 1 and k = 37 and v = 23
update biblia set nvg = 'a hodili ho do cisterny, v ktorej nebolo vody.' where spis = 'Gn' and vers = 1 and k = 37 and v = 24
update biblia set nvg = 'Potom si posadali a jedli chlieb. A keï zdvihli oèi, videli prichádza karavánu Izmaelitov z Galaádu. Ich avy niesli balzam, mastixovú ivicu a ladánum do Egypta. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 25
update biblia set nvg = 'Tu povedal Júda svojim bratom: "Èo by sme mali z toho, keby sme zabili svojho brata a zatajili jeho krv? ' where spis = 'Gn' and vers = 1 and k = 37 and v = 26
update biblia set nvg = 'Bude lepšie preda ho Izmaelitom a nepoškvrni si ruky. Veï je to náš brat a naše telo." A bratia s ním súhlasili.' where spis = 'Gn' and vers = 1 and k = 37 and v = 27
update biblia set nvg = 'A keï madiánski kupci prechádzali okolo, vytiahli Jozefa z cisterny a predali ho za dvadsa striebornıch Izmaelitom. A tí ho odviedli do Egypta.' where spis = 'Gn' and vers = 1 and k = 37 and v = 28
go

-- 566	Gn 41, 55-57; 42, 5-7a. 17-24a
update biblia set lc_id = 566 where spis = 'Gn' and vers = 1 and k = 41 and v between 55 and 57
go
update biblia set lc_id = 566 where spis = 'Gn' and vers = 1 and k = 42 and v between 5 and 7
update biblia set lc_id = 566 where spis = 'Gn' and vers = 1 and k = 42 and v between 17 and 24
go

update biblia set nvg = 'Egyptská krajina zaèala hladova a ¾ud volal k faraónovi o chlieb. On im povedal: "Choïte k Jozefovi a urobte všetko, èo vám povie." ' where spis = 'Gn' and vers = 1 and k = 41 and v = 55
update biblia set nvg = 'Hlad do¾ahol na celú egyptskú krajinu; Jozef otvoril všetky sıpky a predával Egypanom obilie, lebo ich moril hlad. ' where spis = 'Gn' and vers = 1 and k = 41 and v = 56
update biblia set nvg = 'A k Jozefovi do Egypta prichádzali aj všetky okolité krajiny kupova obilie, lebo núdza zachvátila celı svet.' where spis = 'Gn' and vers = 1 and k = 41 and v = 57
go
update biblia set nvg = 'S tımi, èo putovali do Egypta nakúpi obilie, prišli aj Izraelovi synovia, lebo aj v Kanaáne bol hlad. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 5
update biblia set nvg = 'A Jozef bol vladárom v egyptskej krajine, na jeho pokyn sa predávalo ¾uïom obilie. // Keï teda k nemu prišli jeho bratia a poklonili sa a po zem, ' where spis = 'Gn' and vers = 1 and k = 42 and v = 6
update biblia set nvg = 'on ich poznal; ale rozprával sa s nimi prísnejšie ako s cudzími [...]' where spis = 'Gn' and vers = 1 and k = 42 and v = 7
go
update biblia set nvg = 'a dal ich na tri dni do väzenia. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 17
update biblia set nvg = '(Na tretí deò ich z väzenia vyviedol) a povedal: "Ak chcete i, urobte, èo som povedal; lebo ja sa bojím Boha. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 18
update biblia set nvg = 'Ak ste úprimní, jeden váš brat ostane vo väzení. Vy choïte, zaneste domov obilie, èo ste kúpili, ' where spis = 'Gn' and vers = 1 and k = 42 and v = 19
update biblia set nvg = 'a priveïte ku mne vášho najmladšieho brata, aby sa dokázalo, e sú vaše reèi pravdivé, aby ste neprišli o ivot." // Oni urobili, ako povedal, ' where spis = 'Gn' and vers = 1 and k = 42 and v = 20
update biblia set nvg = 'a medzi sebou si vraveli: "Právom takto trpíme, lebo sme sa previnili proti nášmu bratovi: videli sme úzkos jeho duše, keï nás úpenlivo prosil, a nepoèúvali sme. Preto na nás do¾ahlo toto trápenie."' where spis = 'Gn' and vers = 1 and k = 42 and v = 21
update biblia set nvg = 'A Ruben hovoril: "Nevravel som vám: Neprehrešte sa proti chlapcovi? A nepoèúvali ste ma. Teraz sa od nás poaduje jeho krv."' where spis = 'Gn' and vers = 1 and k = 42 and v = 22
update biblia set nvg = 'No nevedeli, e Jozef im rozumie, lebo sa s nimi rozprával prostredníctvom tlmoèníka. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 23
update biblia set nvg = 'Na chví¾ku sa od nich odvrátil a plakal. [...]' where spis = 'Gn' and vers = 1 and k = 42 and v = 24
go

-- 567	Gn 44, 18-21. 23b-29; 45, 1-5
update biblia set lc_id = 567 where spis = 'Gn' and vers = 1 and k = 44 and v between 18 and 21
update biblia set lc_id = 567 where spis = 'Gn' and vers = 1 and k = 44 and v between 24 and 29 -- v. 23b je len naznaèenı
go
update biblia set lc_id = 567 where spis = 'Gn' and vers = 1 and k = 45 and v between 1 and 5
go

update biblia set nvg = 'Júda pristúpil blišie k Jozefovi a dôverne vravel: "Prosím, pane môj, dovo¾, aby ti tvoj sluha povedal nieko¾ko slov, a nehnevaj sa na svojho sluhu; veï ty si ako faraón!' where spis = 'Gn' and vers = 1 and k = 44 and v = 18
update biblia set nvg = 'Môj pán sa prvı raz pıtal svojich sluhov: ‚Máte ešte otca alebo brata?‘ ' where spis = 'Gn' and vers = 1 and k = 44 and v = 19
update biblia set nvg = 'A my sme vtedy odpovedali môjmu pánovi: ‚Máme staruèkého otca a malého brata, ktorı sa mu narodil v starobe. Jeho brat po matke je u màtvy, a tak mu ostal len on po svojej matke; preto ho otec nene miluje.‘' where spis = 'Gn' and vers = 1 and k = 44 and v = 20
update biblia set nvg = 'A ty si svojím sluhom rozkázal: ‚Priveïte ho ku mne, aby som ho videl na vlastné oèi. Ak nepríde s vami váš najmladší brat, neukazujte sa mi na oèi!‘' where spis = 'Gn' and vers = 1 and k = 44 and v = 21
go
update biblia set nvg = 'Keï sme potom došli k tvojmu sluhovi, nášmu otcovi, rozpovedali sme mu všetko, èo povedal môj pán.' where spis = 'Gn' and vers = 1 and k = 44 and v = 24
update biblia set nvg = 'A náš otec vravel: ‚Choïte znova a kúpte trochu pšenice.‘' where spis = 'Gn' and vers = 1 and k = 44 and v = 25
update biblia set nvg = 'My sme mu odvrávali: ‚Nemôeme ís. Ak pôjde s nami náš najmladší brat, pôjdeme aj my; lebo bez neho sa nesmieme ukáza na oèi tomu muovi.‘' where spis = 'Gn' and vers = 1 and k = 44 and v = 26
update biblia set nvg = 'Na to nám tvoj sluha, náš otec, povedal: ‚Vy viete, e moja ena mi porodila len dvoch. ' where spis = 'Gn' and vers = 1 and k = 44 and v = 27
update biblia set nvg = 'Jeden odo mòa odišiel a ja som povedal: Divá zver ho zorala! A doteraz ho niet. ' where spis = 'Gn' and vers = 1 and k = 44 and v = 28
update biblia set nvg = 'Ak vezmete odo mòa aj tohoto a nieèo sa mu na ceste stane, privediete moje šediny bô¾om do hrobu.‘"' where spis = 'Gn' and vers = 1 and k = 44 and v = 29
go
update biblia set nvg = 'Jozef u nebol ïalej schopnı ovláda sa pred tımi, èo stáli okolo, a zvolal: "Vyjdite von všetci!" A tak nebol nik pri òom, keï sa dal pozna svojim bratom. ' where spis = 'Gn' and vers = 1 and k = 45 and v = 1
update biblia set nvg = 'Dal sa do hlasitého plaèu, e ho poèuli aj Egypania a celı faraónov dom.' where spis = 'Gn' and vers = 1 and k = 45 and v = 2
update biblia set nvg = 'Potom Jozef povedal svojim bratom: "Ja som Jozef! ije ešte môj otec?" Ale bratia sa tak pre¾akli, e mu nemohli odpoveda. ' where spis = 'Gn' and vers = 1 and k = 45 and v = 3
update biblia set nvg = 'On sa im v¾údne prihováral: "No, poïte ku mne." // A keï pristúpili blišie, povedal: "Ja som Jozef, váš brat, ktorého ste predali do Egypta. ' where spis = 'Gn' and vers = 1 and k = 45 and v = 4
update biblia set nvg = 'No netrápte sa a nesuujte, e ste ma predali do tejto krajiny, lebo to ma Boh poslal pred vami do Egypta na vašu záchranu."' where spis = 'Gn' and vers = 1 and k = 45 and v = 5
go

-- 568	Gn 46, 1-7. 28-30
update biblia set lc_id = 568 where spis = 'Gn' and vers = 1 and k = 46 and v between 1 and 7
update biblia set lc_id = 568 where spis = 'Gn' and vers = 1 and k = 46 and v between 28 and 30
go

update biblia set nvg = 'Izrael sa vydal na cestu so všetkım, èo mal. Keï došiel do Bersaby a priniesol Bohu svojho otca Izáka krvavú obetu, ' where spis = 'Gn' and vers = 1 and k = 46 and v = 1
update biblia set nvg = 'poèul, ako ho Boh v noènom videní volá: "Jakub, Jakub!" On odpovedal: "Tu som!"' where spis = 'Gn' and vers = 1 and k = 46 and v = 2
update biblia set nvg = 'Hovoril mu: "Ja som Boh, Boh tvojho otca. Neboj sa zostúpi do Egypta, lebo tam z teba urobím ve¾kı národ. ' where spis = 'Gn' and vers = 1 and k = 46 and v = 3
update biblia set nvg = 'Ja ta pôjdem s tebou a ja a odtia¾ privediem spä; a Jozef ti vlastnou rukou zatlaèí oèi."' where spis = 'Gn' and vers = 1 and k = 46 and v = 4
update biblia set nvg = 'Jakub sa teda pohol z Bersaby. Jeho synovia naloili jeho i svoje deti a eny na vozy, èo poslal faraón na prevezenie starca, ' where spis = 'Gn' and vers = 1 and k = 46 and v = 5
update biblia set nvg = 'a vzali so sebou všetko, èo mali v krajine Kanaán. Tak prišli do Egypta Jakub a všetci jeho potomci: ' where spis = 'Gn' and vers = 1 and k = 46 and v = 6
update biblia set nvg = 'jeho synovia a vnuci, dcéry a celé jeho potomstvo. ' where spis = 'Gn' and vers = 1 and k = 46 and v = 7
go
update biblia set nvg = 'Jakub poslal Júdu napred k Jozefovi, aby mu oznámil, e sa stretnú v Gessene. Keï prišli do kraja Gessen, ' where spis = 'Gn' and vers = 1 and k = 46 and v = 28
update biblia set nvg = 'Jozef dal zapriahnu do svojho voza a išiel do Gessenu naproti svojmu otcovi. Keï ho uvidel, hodil sa mu okolo krku a dlho plakal v jeho objatí.' where spis = 'Gn' and vers = 1 and k = 46 and v = 29
update biblia set nvg = 'Tu Izrael povedal Jozefovi: "Teraz u spokojne zomriem, lebo som videl tvoju tvár a viem, e ma preiješ."' where spis = 'Gn' and vers = 1 and k = 46 and v = 30
go

-- 569	Gn 49, 1-2. 8-10
update biblia set lc_id = 569 where spis = 'Gn' and vers = 1 and k = 49 and v between 1 and 2
update biblia set lc_id = 569 where spis = 'Gn' and vers = 1 and k = 49 and v between 8 and 10
go

update biblia set nvg = 'Jakub zavolal svojich synov a povedal im: "Zhromadite sa a oznámim vám, èo vás èaká v ïalekej budúcnosti: ' where spis = 'Gn' and vers = 1 and k = 49 and v = 1
update biblia set nvg = 'Zhromadite sa a poèúvajte, Jakubovi synovia, poèujte Izraela, svojho otca!' where spis = 'Gn' and vers = 1 and k = 49 and v = 2
go
update biblia set nvg = 'Júda, teba budú chváli tvoji bratia, tvoja ruka bude na šiji tvojich nepriate¾ov, tebe sa budú klaòa synovia tvojho otca. ' where spis = 'Gn' and vers = 1 and k = 49 and v = 8
update biblia set nvg = 'Mladım levom si Júda, od koristi vstávaš, syn môj; líha si a odpoèíva ako lev a ako levica: kto sa ho odvái vyruši?' where spis = 'Gn' and vers = 1 and k = 49 and v = 9
update biblia set nvg = 'Nebude odòaté ezlo od Júdu ani vladárska berla od jeho nôh, kım nepríde ten, komu patrí, ktorého budú poslúcha národy."' where spis = 'Gn' and vers = 1 and k = 49 and v = 10
go

-- 570	Gn 49, 29-32; 50, 15-26
-- verš 32 nie je explicitne v texte; zato je tam v. 33
update biblia set lc_id = 570 where spis = 'Gn' and vers = 1 and k = 49 and v between 29 and 33
go
update biblia set lc_id = 570 where spis = 'Gn' and vers = 1 and k = 50 and v between 15 and 26
go

update biblia set nvg = 'Jakub prikázal svojim synom: "Ja sa pripojím k svojmu ¾udu; pochovajte ma s mojimi otcami v jaskyni Makpela, èo je na pozemku Hetejca Efrona ' where spis = 'Gn' and vers = 1 and k = 49 and v = 29
update biblia set nvg = 'oproti Mambre v krajine Kanaán, ktorú kúpil Abrahám aj s pozemkom od Hetejca Efrona na dedièné pohrebisko.' where spis = 'Gn' and vers = 1 and k = 49 and v = 30
update biblia set nvg = 'Tam pochovali jeho enu Sáru, tam je pochovanı Izák so svojou manelkou Rebekou a tam leí pochovaná aj Lia."' where spis = 'Gn' and vers = 1 and k = 49 and v = 31
update biblia set nvg = '(NVg tento verš vynecháva)' where spis = 'Gn' and vers = 1 and k = 49 and v = 32
update biblia set nvg = '(NVg 32)Keï skonèil túto reè, ktorou poúèal svojich synov, vyloil si nohy na lôko a zomrel; a tak sa pripojil k svojmu ¾udu.' where spis = 'Gn' and vers = 1 and k = 49 and v = 33
go
update biblia set nvg = 'Keï Jakub zomrel, Jozefovi bratia sa báli a vraveli si: "Len aby si nespomenul na príkorie, ktoré musel znies, a aby sa nám nepomstil za všetko zlo, èo sme mu vykonali!"' where spis = 'Gn' and vers = 1 and k = 50 and v = 15
update biblia set nvg = 'Preto mu odkázali: "Tvoj otec nám prikázal skôr, ako zomrel, aby sme ti jeho slovami povedali: ' where spis = 'Gn' and vers = 1 and k = 50 and v = 16
update biblia set nvg = '‚Prosím a, zabudni na zloèin svojich bratov, na ich hriech a nehanebnos, ktorej sa na tebe dopustili.‘ Aj my a prosíme, aby si nám odpustil tento nehanebnı èin; veï my uctievame Boha tvojho otca." Keï mu to hovorili, Jozef plakal.' where spis = 'Gn' and vers = 1 and k = 50 and v = 17
update biblia set nvg = 'Potom išli za ním sami bratia, sklonili sa pred ním a vraveli: "Sme tvoji sluhovia."' where spis = 'Gn' and vers = 1 and k = 50 and v = 18
update biblia set nvg = 'Ale on im povedal: "Nebojte sa! Môeme sa vari vzoprie Boej vôli? ' where spis = 'Gn' and vers = 1 and k = 50 and v = 19
update biblia set nvg = 'Vy ste osnovali proti mne zlo, ale Boh to obrátil na dobré. Povıšil ma, ako vidíte, a tak zachránil mnoho ¾udu. ' where spis = 'Gn' and vers = 1 and k = 50 and v = 20
update biblia set nvg = 'Nebojte sa u! Ja vás budem ivi, aj vaše deti." // Tešil ich a milo a v¾údne sa im prihováral.' where spis = 'Gn' and vers = 1 and k = 50 and v = 21
update biblia set nvg = 'Tak bıval Jozef i celı dom jeho otca v Egypte. il stodesa rokov ' where spis = 'Gn' and vers = 1 and k = 50 and v = 22
update biblia set nvg = 'a videl Efraimovıch synov a do tretieho pokolenia; aj synovia Machira, syna Manasseho, sa narodili na Jozefovıch kolenách.' where spis = 'Gn' and vers = 1 and k = 50 and v = 23
update biblia set nvg = 'Po tom všetkom povedal Jozef svojim bratom: "Po mojej smrti sa vás Boh ujme a vyvedie vás z tejto krajiny do krajiny, o ktorej prisahal Abrahámovi, Izákovi a Jakubovi."' where spis = 'Gn' and vers = 1 and k = 50 and v = 24
update biblia set nvg = 'A keï ich zaprisahal a povedal: "Boh vás navštívi; odneste z tohto miesta moje kosti so sebou," ' where spis = 'Gn' and vers = 1 and k = 50 and v = 25
update biblia set nvg = 'zomrel stodesa roènı. Zabalzamovali ho a uloili do rakvy v Egypte.' where spis = 'Gn' and vers = 1 and k = 50 and v = 26
go
-- ‚‘
