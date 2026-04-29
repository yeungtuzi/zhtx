//longwei.c
//by emote

inherit ROOM;

void create()
{
	set("short","苍龙岭－－龙脊");
	set("long",
@LONG
这里的山势略微平坦了一点，但是地形依然很险峻。前面的小路，仅宽
不到两尺。两旁万丈深壑，势陡如削。岭脊上下高差约百丈。四周白云缭绕，
山脊在云雾中若隐若现，恍若一条青龙在空中舞动。在这里遥望青松白云，
耳听风声大作，令人心惊目眩。游人到此，莫不惊叹
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"northdown"  : __DIR__"longwei",
		"northup": __DIR__"longtou",
		]));
	set("outdoors","huashan");	 
	setup();
	
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="northup")
	if(random(me->query_skill("dodge"))<10)
	{
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
