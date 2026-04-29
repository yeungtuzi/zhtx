//changkongzhan1.c 长空栈道1
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
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"eastup"  : __DIR__"zhandao2",
		"north": __DIR__"beike",
		]));
	set("outdoors","huashan");	 
	setup();
	
}

int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="eastup")
	if(random(me->query_skill("dodge"))<10)
	{
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
