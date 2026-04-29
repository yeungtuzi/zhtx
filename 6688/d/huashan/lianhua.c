//lianhua.c绝壁
//by emote

inherit ROOM;

void create()
{
	set("short","莲花峰");
	set("long",
@LONG
莲花峰是华山西主峰，又因石叶如莲瓣覆盖峰巅，古又名莲花峰。它是
由一块巨石浑然天成，西北临空，绝壁悬崖如刀削　锯截。东南陡坡下松柏
苍翠，清泉如琴。峰南有一通道，长一百余米，一面为绝壁，一边是斜坡，
也是华山险道之一。向南走则是供奉三圣母的翠云宫。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"eastdown"  : __DIR__"juebi",
		"south": __DIR__"cuiyun",
		]));
	set("outdoors","huashan");	 
	setup();
	
}