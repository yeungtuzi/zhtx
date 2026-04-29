//longwei.c
//by emote

inherit ROOM;

void create()
{
	set("short","苍龙岭－－龙尾");
	set("long",
@LONG
就要进入华山的险要之处苍龙岭的，这里就是苍龙岭的龙尾。虽然只是
刚刚进入苍龙岭，但是山势的险峻已经不是刚才的耳擦崖和上天体所能比拟
的了。向前看去，它莽莽苍苍，蜿蜒盘旋，好像苍龙腾空，所以被称“苍龙
岭”。前面根本没有路，有的只是山壁上前人一个个凿出来的小石窝。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"westdown"  : __DIR__"shangtianti",
		"southup": __DIR__"longji",
		]));
	set("outdoors","huashan");	 
	setup();
	
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="southup")
	if(random(me->query_skill("dodge"))<10)
	{
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
