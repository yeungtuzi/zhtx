//千尺幢
//
inherit ROOM;
void create()
{
	set("short","千尺幢");
	set("long",
@LONG
过了回心石，就来到华山的咽喉要地“千尺幢”。这是一处在山崖极陡处
开出的一条小路，共三百七十多多磴石级，石级的宽度只能容 纳一个人上下，
两旁挂着铁索 ，人们手攀铁索，一步步向上登，往上看，只见一线天开往下
看，就像站在深井上。千尺幢的顶端，就像井口一样。这里的崖壁上刻有“太
华咽喉”、“气吞东瀛”的字样。其形势真像咽喉一样的险要。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"northdown"  : __DIR__"qingkeping",
		"southup": __DIR__"baichixia",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

