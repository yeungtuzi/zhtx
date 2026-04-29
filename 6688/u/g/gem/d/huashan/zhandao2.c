//zhandao2.c 长空栈道2
//by emote

inherit ROOM;

void create()
{
	set("short","长空栈道");
	set("long",
@LONG
这便是华山最险之景－－长空栈道，此道开凿在南峰腰间，上下皆是悬崖
绝壁，铁索横悬，由条石搭成尺许路面，下由石柱固定。由于栈道险峻，故当
地人有“小心小心九厘三分，要寻尸首，洛南商州”之说。这里只是探险之道，
并非登山必由之路，胆小人就在升表台看看也就行了。所以石刻上不少警告之
语：“悬崖勒马”等。
    再往前走就是“九节朽木椽”了。从这里往西走就是玉女峰，往东走则是
华山的东主峰--朝阳峰。
    
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"westdown"  : __DIR__"zhandao1",
		"west":__DIR__"9jiechuan",
		"south":  __DIR__"jintian",
		"westup":__DIR__"yunv",
		"eastup":__DIR__"chaoyang",
		]));
	 
	set("outdoors","huashan"); 
	setup();
	
}
