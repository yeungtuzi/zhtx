//云台峰
//
inherit ROOM;
void create()
{
	set("short","云台峰");
	set("long",
@LONG
走过五百多级的老君沟，你就来到了华山北峰--云台峰。这里山势峥嵘，三面
绝空，只有一道小岭和南边山峰相通。因在华山之北而得名北峰。又因常有白
云薄雾，峰好像是云上之台，雅称云台峰。北峰口处有一石牌坊，上刻有“北
峰顶”三字，入北峰通道两边立有石柱铁链，保护人们安全。
　　
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"southdown"  : __DIR__"laojungou",
		"south": __DIR__"ercaya",
		]));
	 
set("outdoors","huashan");
	setup();
	replace_program(ROOM);
}

