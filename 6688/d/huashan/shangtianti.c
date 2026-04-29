//shangtianti.c 
//by emote

inherit ROOM;

void create()
{
	set("short","上天梯");
	set("long",
@LONG
这里的山势更加陡峭起来，向前走的路简直象是笔直的插上天空一般，
旁边也没有任何可以供你扶的地方。你向四周望去，全是雾茫茫的一片，一
个人影也看不见，看来除非是轻功绝顶的高手才能够爬的上去了。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"northdown"  : __DIR__"ercaya",
		"eastup": __DIR__"longwei",
		]));
	set("outdoors","huashan");	 
	setup();
	//	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="eastup")
	if(me->query_skill("dodge")<15
	&& random(4))
	{
	     
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
