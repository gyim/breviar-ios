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
-- ‚‘

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

