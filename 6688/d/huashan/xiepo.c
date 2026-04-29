//xiepo.c 斜坡
//by emote

inherit ROOM;

void create()
{
	set("short","斜坡");
	set("long",
@LONG
这是去华山西峰的必经之地，也是华山险路之一。小路弯弯曲曲，而且
十分狭窄，只能一人行走，两个人都无法并排前行，前面就是绝壁。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"northwest"  : __DIR__"juebi",
		"east": __DIR__"jintian",
		]));
	set("outdoors","huashan");	 
	setup();
	
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="northwest")
	if(random(me->query_skill("dodge"))<10)
	{
	     me->receive_wound("kee",50,me);
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
