//juebi.c绝壁
//by emote

inherit ROOM;

void create()
{
	set("short","绝壁");
	set("long",
@LONG
这是去华山西峰的必经之地，也是华山险路之一。小路弯弯曲曲，而且
十分狭窄，只能一人行走，两个人都无法并排前行，而且路好象都在迷茫的
云雾中时隐时现。头顶上遥遥的莲花峰隐约可见。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"southeast"  : __DIR__"xiepo",
		"westup": __DIR__"lianhua",
		]));
	set("outdoors","huashan");	 
	setup();
	
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="westup")
	if(random(me->query_skill("dodge"))<10)
	{
	     me->receive_wound("kee",50,me);
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
