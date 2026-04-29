//longtou.c
//by emote

inherit ROOM;

void create()
{
	set("short","苍龙岭－－龙头");
	set("long",
@LONG
这里的山势又陡然险峻了起来，四周深谷万丈，云雾弥漫，山风呼啸。
让人一看之下，顿时觉得头晕目眩，四肢无力，好象整座大山都在晃动一般。
传说韩愈曾在八仙的帮助之下，登上华山绝顶。游后下到苍龙岭，只觉得心
神欲裂，便卧倒在神逸崖下，放声大哭，并写下遗书，投到山下。后经别人
救助才得以下岭。至今此处还有”韩退之投书处”的一块大石刻在这里保存着。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"southdown"  : __DIR__"longji",
		"northup": __DIR__"beike",
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
