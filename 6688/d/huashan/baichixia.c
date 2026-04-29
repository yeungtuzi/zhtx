//百尺峡
//
inherit ROOM;
void create()
{
	set("short","百尺峡");
	set("long",
@LONG
相比千尺幢而言，百尺峡并没有它那么险峻，但也是极其陡峭。后面的人
只能看见前面的人的脚，旁边并无一物可供借力，大家都是很小心的向前走，
生怕一不小心，就会堕入旁边无底的深渊里去。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"northdown"  : __DIR__"qianchizhuang",
		"east": __DIR__"xianrenqiao",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

