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
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 6 and 13 -- je tam aj verš 14 pod¾a SSV
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 20 and 22
go

update biblia set nvg = 'Keï uplynulo štyridsa dní, Noe otvoril na korábe okno, ktoré bol urobil, ' where spis = 'Gn' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'a vypustil krkavca. Ten odlietal a prilietal, kım vody na zemi nevyschli.' where spis = 'Gn' and vers = 1 and k = 8 and v = 7
update biblia set nvg = 'Vypustil von aj holubicu, aby zvedel, èi u vody stiekli z povrchu zeme. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 8
update biblia set nvg = 'Ale keï nenašla miesto, kde by spoèinula jej noha, vrátila sa k nemu do korába; po celej zemi boli ešte vody. Noe vystrel ruku, chytil ju a vzal ju do korába.' where spis = 'Gn' and vers = 1 and k = 8 and v = 9
update biblia set nvg = 'Èakal ešte sedem dní a znova vypustil z korába holubicu. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 10
update biblia set nvg = 'A ona k nemu priletela a v podveèer a v zobáku priniesla olivovú ratoles so zelenımi listami. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 11
update biblia set nvg = 'Tu Noe poznal, e vody zo zeme zmizli. Èakal ešte ïalších sedem dní a vypustil holubicu, ktorá sa u k nemu nevrátila.' where spis = 'Gn' and vers = 1 and k = 8 and v = 12
update biblia set nvg = 'V šesstoprvom roku, v prvom mesiaci, v prvı deò mesiaca, vody na zemi vyschli. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 13
update biblia set nvg = 'Noe otvoril strechu korába, pozrel sa von a videl, e povrch zeme je suchı.' where spis = 'Gn' and vers = 1 and k = 8 and v = 14
go
update biblia set nvg = 'Potom postavil oltár Pánovi, vzal zo všetkého èistého dobytka a z èistıch vtákov a priniesol zápalnú obetu na oltári.' where spis = 'Gn' and vers = 1 and k = 8 and v = 20
update biblia set nvg = 'Pán zavoòal príjemnú vôòu a povedal si: "U nikdy neprek¾ajem zem pre èloveka, lebo zmıš¾anie ¾udského srdca je od mladosti náklonné na zlé. Preto u nikdy nevyhubím všetky ivé bytosti, ako som to urobil.' where spis = 'Gn' and vers = 1 and k = 8 and v = 21
update biblia set nvg = 'Kım potrvá zem, neprestane sejba a atva, chlad a horúèos, leto a zima, deò a noc."' where spis = 'Gn' and vers = 1 and k = 8 and v = 22
go

-- 573	Gn 9, 1-13
-- 574	Gn 9, 8-15
update biblia set lc_id = 573 where spis = 'Gn' and vers = 1 and k = 9 and v between 1 and 13
update biblia set lc_id = 574 where spis = 'Gn' and vers = 1 and k = 9 and v between 14 and 13
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
